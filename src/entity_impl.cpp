/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "entity_impl.h"

#include <SFML/Graphics/RenderTarget.hpp>

#include "world.h"

namespace FastSimDesign {
	namespace Impl {
		/*****************************************************************************
		Statics
		*****************************************************************************/

		/*****************************************************************************
		Methods
		*****************************************************************************/
		Entity::Entity(FastSimDesign::World& world, FastSimDesign::Entity::Id id, std::unique_ptr<Sprite> sprite)
			: Parent{}
			, m_world{world}
			, m_sprite{std::move(sprite)}
			, m_id{id}
			, m_name{""}
		{
		}

		void Entity::init() noexcept
		{
		}

		void Entity::update(sf::Time const& delta_time) noexcept
		{
		}

		void Entity::term() noexcept
		{
		}

		void Entity::setName(std::string name) noexcept
		{
			m_name = std::move(name);
		}

		void Entity::setPosition(float x, float y) noexcept
		{
			// TODO: tester si outofbound avec assert
			m_sprite->setPosition(sf::Vector2f{x,y});
		}

		void Entity::setOrigin(float x, float y) noexcept
		{
			// TODO: tester si outofbound avec assert
			m_sprite->setOrigin(sf::Vector2f{x, y});
		}

		void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			target.draw(*m_sprite.get(), states);
		}
	}
}