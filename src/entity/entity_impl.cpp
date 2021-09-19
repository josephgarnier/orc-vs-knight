/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "entity_impl.h"

#include <cassert>

#include <SFML/Graphics/RenderTarget.hpp>

#include "world.h"
#include "entity/weapon/hands.h"
#include "entity/armor/no_armor.h"
#include "entity/ability/no_ability.h"

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
			, m_stuned{false}
			, m_weapon{std::make_unique<Hands>()}
			, m_armor{std::make_unique<NoArmor>()}
			, m_ability{std::make_unique<NoAbility>()}
			, m_active_effects{}
			, m_have_token{false}
			, m_turn_completed{false}
		{
		}

		void Entity::updateAbility(sf::Time const& delta_time) noexcept
		{
			m_ability->update(delta_time);
		}

		void Entity::updateActiveEffects(sf::Time const& delta_time) noexcept
		{
			for (auto& effect : m_active_effects)
			{
				effect.update(delta_time);
			}

			// Garbage unactive effects.
			auto removed = std::remove_if(std::begin(m_active_effects), std::end(m_active_effects), [](Effect const & e) {
				return e.remainingDuration() == 0;
			});
			m_active_effects.erase(removed, std::end(m_active_effects));
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

		void Entity::setHp(int16_t hp) noexcept
		{
			assert(hp >= 0 && "HP must be a positive value");
			m_hp = hp;
		}

		void Entity::setStuned(bool stuned) noexcept
		{
			m_stuned = stuned;
		}

		void Entity::setWeapon(std::unique_ptr<Weapon> weapon) noexcept
		{
			m_weapon = std::move(weapon);
		}

		void Entity::setArmor(std::unique_ptr<Armor> armor) noexcept
		{
			m_armor = std::move(armor);
		}

		void Entity::setAbility(std::unique_ptr<FastSimDesign::Ability> ability) noexcept
		{
			m_ability = std::move(ability);
		}

		void Entity::addActiveEffect(FastSimDesign::Effect effect) noexcept
		{
			m_active_effects.push_back(std::move(effect));
		}

		void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			target.draw(m_sprite, states);
		}
	}
}