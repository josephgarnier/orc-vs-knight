/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_ENTITY_H
#define ORC_VS_KNIGHT_ENTITY_H

#include <string>
#include <memory>
#include <vector>

#include <SFML/Graphics/Drawable.hpp>

#include "entity/weapon/weapon.h"
#include "entity/armor/armor.h"

namespace sf {
	class Time;
}

namespace FastSimDesign {
	class Sprite;
	class World;
	class Ability;
	class Effect;
	class Entity : public sf::Drawable
	{
	public:
		using Id = uint64_t;

	public:
		explicit Entity() = default; // Default constructor
		Entity(Entity const&) = delete; // Copy constructor
		Entity(Entity&&) = delete; // Move constructor
		Entity& operator=(Entity const&) = delete; // Copy assignment operator
		Entity& operator=(Entity&&) = delete; // Move assignment operator
		virtual ~Entity() = default; // Destructor

		virtual Entity::Id const& id() const noexcept = 0;
		virtual std::string const& name() const noexcept = 0;
		virtual World const& world() const noexcept = 0;
		virtual sf::Vector2f const& position() const noexcept = 0;
		virtual int16_t const& hp() const noexcept = 0;
		virtual bool const& isStuned() const noexcept = 0;
		virtual Sprite const& sprite() const noexcept = 0;
		virtual Weapon& weapon() const noexcept = 0;
		virtual Armor& armor() const noexcept = 0;
		virtual Ability& ability() const noexcept = 0;
		virtual std::vector<FastSimDesign::Effect> const& activeEffects() const noexcept = 0;
		
		virtual bool hasToken() const noexcept = 0;
		virtual void beginNewTurn() noexcept = 0;
		virtual void giveToken() noexcept = 0;
		virtual void updateAbility(sf::Time const& delta_time) noexcept = 0;
		virtual void updateActiveEffects(sf::Time const& delta_time) noexcept = 0;
		virtual void update(sf::Time const& delta_time) noexcept = 0;
		virtual bool isTurnCompleted() noexcept = 0;
		virtual void retrieveToken() noexcept = 0;

		virtual void setName(std::string name) noexcept = 0;
		virtual void setPosition(float x, float y) noexcept = 0;
		virtual void setHp(int16_t hp) noexcept = 0;
		virtual void setStuned(bool stuned) noexcept = 0;
		virtual void setWeapon(std::unique_ptr<Weapon> weapon) noexcept = 0;
		virtual void setArmor(std::unique_ptr<Armor> armor) noexcept = 0;
		virtual void setAbility(std::unique_ptr<Ability> ability) noexcept = 0;
		virtual void addActiveEffect(Effect effect) noexcept = 0;
	protected:
	private:
	};
}
#endif