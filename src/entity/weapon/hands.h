/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_HANDS_H
#define ORC_VS_KNIGHT_HANDS_H

#include <string>

#include "weapon.h"

namespace FastSimDesign {
	class Hands final : public Weapon
	{
	private:
		using Parent = Weapon;

	public:
		explicit Hands() noexcept; // Default constructor
		Hands(Hands const&) = delete; // Copy constructor
		Hands(Hands&&) = delete; // Move constructor
		Hands& operator=(Hands const&) = delete; // Copy assignment operator
		Hands& operator=(Hands&&) = delete; // Move assignment operator
		virtual ~Hands() = default; // Destructor

		inline int16_t const& attackDamage() const noexcept override { return m_attack_damage; }
		inline std::string const& description() const noexcept override { return m_description; }
		void attack(Entity& target, int16_t attack_amplifier) const noexcept override;

	protected:
	private:
		int16_t m_attack_damage;
		std::string m_description;
	};
}
#endif