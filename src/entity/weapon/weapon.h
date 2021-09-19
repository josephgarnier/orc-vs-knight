/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_WEAPON_H
#define ORC_VS_KNIGHT_WEAPON_H

#include <string>

namespace FastSimDesign {
	class Entity;
	class Weapon
	{
	public:
		explicit Weapon() = default; // Default constructor
		Weapon(Weapon const&) = delete; // Copy constructor
		Weapon(Weapon&&) = delete; // Move constructor
		Weapon& operator=(Weapon const&) = delete; // Copy assignment operator
		Weapon& operator=(Weapon&&) = delete; // Move assignment operator
		virtual ~Weapon() = default; // Destructor

		virtual int16_t const& attackDamage() const noexcept = 0;
		virtual std::string const& description() const noexcept = 0;
		virtual void attack(Entity& target, int16_t attack_amplifier) const noexcept = 0;

	protected:
	private:
	};
}
#endif