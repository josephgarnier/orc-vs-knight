/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_ABILITY_H
#define ORC_VS_KNIGHT_ABILITY_H

#include <string>

namespace sf {
	class Time;
}

namespace FastSimDesign {
	class Entity;
	class Ability
	{
	public:
		explicit Ability() = default; // Default constructor
		Ability(Ability const&) = delete; // Copy constructor
		Ability(Ability&&) = delete; // Move constructor
		Ability& operator=(Ability const&) = delete; // Copy assignment operator
		Ability& operator=(Ability&&) = delete; // Move assignment operator
		virtual ~Ability() = default; // Destructor

		virtual std::string const& description() const noexcept = 0;
		virtual int16_t const& cooldown() const noexcept = 0;
		virtual bool isReady() const noexcept = 0;
		
		virtual void update(sf::Time const& delta_time) noexcept = 0;

		virtual void activateCooldown() noexcept = 0;
		virtual bool tryToPerformEffect(Entity& target) noexcept = 0;

	protected:
	private:
	};
}
#endif