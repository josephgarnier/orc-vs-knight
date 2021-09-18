/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "world.h"

#include <cassert>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>

namespace FastSimDesign {
	/*****************************************************************************
	TurnLoop::Methods
	*****************************************************************************/
	World::TurnLoop::TurnLoop(EntityContainer const& entity_storage)
		: m_entity_storage{entity_storage}
		, m_current_Turn{0}
		, m_entity_iterator{m_entity_storage.begin()}
	{
	}

	void World::TurnLoop::beginNewTurn() noexcept
	{
		assert(!m_entity_storage.empty() && "Entity storage is empty");
		m_current_Turn++;
		for (std::unique_ptr<Entity> const& entity : m_entity_storage)
		{
			entity->beginNewTurn();
		}
		m_entity_iterator = m_entity_storage.begin();
		(*m_entity_iterator)->giveToken();
	}

	Entity& World::TurnLoop::currentTokenOwner() const noexcept
	{
		assert(!m_entity_storage.empty() && "Entity storage is empty");
		Entity& token_owner = *(*m_entity_iterator).get();
		assert(token_owner.hasToken() && "Entity doesn't have the token");
		return token_owner;
	}

	void World::TurnLoop::passTokenToNext() noexcept
	{
		if (!isTurnOver())
		{
			assert(!m_entity_storage.empty() && "Entity storage is empty");
			Entity& token_owner = *(*m_entity_iterator).get();
			assert(token_owner.hasToken() && "Entity doesn't have the token");
			token_owner.retrieveToken();
			m_entity_iterator++;
			(*m_entity_iterator)->giveToken();
		}
	}

	bool World::TurnLoop::isTurnOver() const noexcept
	{
		return m_entity_iterator == m_entity_storage.end();
	}

	/*****************************************************************************
	World::Methods
	*****************************************************************************/
	World::World(unsigned int width, unsigned int height) noexcept
		: m_width{width}
		, m_height{height}
		, m_entities{}
		, m_entity_loop{m_entities}
	{
	}

	void World::beginNewTurn() noexcept
	{
		m_entity_loop.beginNewTurn();
	}
	
	int64_t World::currentTurn() const noexcept
	{
		return m_entity_loop.currentTurn();
	}
	
	Entity const & World::currentTokenOwner() const noexcept
	{
		return m_entity_loop.currentTokenOwner();
	}

	void World::passTokenToNextIfComplete() noexcept
	{
		if (!m_entity_loop.isTurnOver())
		{
			if (m_entity_loop.currentTokenOwner().isTurnCompleted())
				m_entity_loop.passTokenToNext();
		}
	}

	void World::update(sf::Time const& delta_time) noexcept
	{
		if (!m_entity_loop.isTurnOver())
		{
			Entity& currentTokenOwner = m_entity_loop.currentTokenOwner();
			if (!currentTokenOwner.isTurnCompleted())
				currentTokenOwner.update(delta_time);
		}
	}

	bool World::isTurnCompletedByOwner() const noexcept
	{
		return m_entity_loop.currentTokenOwner().isTurnCompleted();
	}

	bool World::isTurnCompletedByAll() const noexcept
	{
		for (std::unique_ptr<Entity> const& entity : m_entities)
		{
			if (!entity->isTurnCompleted())
				return false;
		}
		return true;
	}

	bool World::isCoordValid(float x, float y) const noexcept
	{
		return x >= 0.0f && x < static_cast<float>(m_width) && y >= 0.0f && y < static_cast<float>(m_height);
	}

	World::EntityContainerPtr World::getEntities() const noexcept
	{
		EntityContainerPtr entities{};
		for (std::unique_ptr<Entity> const& entity : m_entities)
		{
			if (entity.get() != nullptr)
			{
				entities.push_back(entity.get());
			}
		}
		assert(entities.size() == m_entities.size() && "Can't get all entity, something wrong happened");
		return entities;
	}

	void World::destroyAllEntities() noexcept
	{
		for (auto& entity : m_entities)
		{
			entity.reset();
		}
		m_entities.clear();
	}

	int64_t World::aliveEntityCount() const noexcept
	{
		int64_t alive_counter = 0;
		for (auto const& entity : m_entities)
		{
			if (entity->hp() > 0)
				alive_counter++;
		}
		return alive_counter;
	}

	World::EntityContainerPtr World::getAliveEntities() const noexcept
	{
		EntityContainerPtr alive_entities{};
		for (auto const& entity : m_entities)
		{
			if (entity->hp() > 0)
				alive_entities.push_back(entity.get());
		}
		return alive_entities;
	}

	void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (auto const& entity : m_entities)
		{
			target.draw(*entity.get(), states);
		}
	}
}