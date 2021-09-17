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

#include <SFML/Graphics/Drawable.hpp>

namespace sf
{
	class Time;
}

namespace FastSimDesign {
	class Sprite;
	class World;
	class Entity : public sf::Drawable
	{
	public:
		using Id = uint64_t;

	public:
		virtual ~Entity() = default; // Destructor

		virtual Entity::Id const& id() const noexcept = 0;
		virtual std::string const& name() const noexcept = 0;
		virtual World const& world() const noexcept = 0;
		virtual sf::Vector2f const& position() const noexcept = 0;
		virtual uint16_t const& hp() const noexcept = 0;
		virtual Sprite const& sprite() const noexcept = 0;

		virtual void update(sf::Time const& delta_time) noexcept = 0;
		virtual void term() noexcept = 0;

		virtual void setName(std::string name) noexcept = 0;
		virtual void setPosition(float x, float y) noexcept = 0;
		virtual void setHp(uint16_t hp) noexcept = 0;

	protected:
	private:
	};
}
#endif