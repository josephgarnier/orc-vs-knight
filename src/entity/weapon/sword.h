/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_SWORD_H
#define ORC_VS_KNIGHT_SWORD_H

#include "weapon.h"

namespace FastSimDesign {
	class Sword final : public Weapon
	{
	private:
		using Parent = Weapon;

	public:
		explicit Sword() noexcept; // Default constructor
		Sword(Sword const&) = delete; // Copy constructor
		Sword(Sword&&) = delete; // Move constructor
		Sword& operator=(Sword const&) = delete; // Copy assignment operator
		Sword& operator=(Sword&&) = delete; // Move assignment operator
		virtual ~Sword() = default; // Destructor

		inline int16_t const& attackDamage() const noexcept override { return m_attack_damage; }
		inline std::string const& description() const noexcept override { return m_description; }
		int16_t attack(Entity& target) noexcept override;

	protected:
	private:
		int16_t m_attack_damage;
		std::string m_description;
	};
}
#endif