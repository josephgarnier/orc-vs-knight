/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "world.h"

#include <cassert>
#include <iostream>

#include <SFML/Graphics/RenderTarget.hpp>

namespace FastSimDesign {
	/*****************************************************************************
	Statics
	*****************************************************************************/

	/*****************************************************************************
	Methods
	*****************************************************************************/

	World::World(unsigned int width, unsigned int height) noexcept
		: m_width{width}
		, m_height{height}
		, m_entities{}
	{
	}

	void World::init() noexcept
	{
		std::cout << "World::init" << std::endl;
	}

	void World::update(sf::Time const& delta_time) noexcept
	{
		std::cout << "World::update at delta time => " << delta_time.asMilliseconds() << std::endl;
	}

	void World::term() noexcept
	{
		std::cout << "World::term" << std::endl;
		m_entities.clear();
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
		for (std::unique_ptr<Entity>& entity : m_entities)
		{
			entity.reset();
		}
		m_entities.clear();
	}

	void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (std::unique_ptr<Entity>const & entity : m_entities)
		{
			target.draw(*entity.get(), states);
		}
	}
}