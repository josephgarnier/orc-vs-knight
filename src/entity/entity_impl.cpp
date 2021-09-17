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
		Impl::Entity::Methods
		*****************************************************************************/
		Entity::Entity(FastSimDesign::World& world, FastSimDesign::Entity::Id id, Sprite sprite) noexcept
			: Parent{}
			, m_world{world}
			, m_sprite{std::move(sprite)}
			, m_id{id}
			, m_name{""}
			, m_hp{0}
			, m_have_token{false}
			, m_turn_completed{false}
		{
		}

		void Entity::update(sf::Time const& delta_time) noexcept
		{
			flagTurnAsCompleted();
		}

		void Entity::setName(std::string name) noexcept
		{
			m_name = std::move(name);
			m_sprite.setName(m_name);
		}

		void Entity::setPosition(float x, float y) noexcept
		{
			assert(m_world.isCoordValid(x, y) && "Coordinates are out of world limits");
			m_sprite.setPosition(sf::Vector2f{x, y});
		}

		void Entity::setHp(uint16_t hp) noexcept
		{
			assert(hp >= 0 && "HP must be a positive value");
			m_hp = hp;
		}

		void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			target.draw(m_sprite, states);
		}
	}
}