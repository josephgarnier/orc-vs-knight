/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_AXE_H
#define ORC_VS_KNIGHT_AXE_H

#include <string>

#include "weapon.h"

namespace FastSimDesign {
	class Axe final : public Weapon
	{
	private:
		using Parent = Weapon;

	public:
		explicit Axe() noexcept; // Default constructor
		Axe(Axe const&) = delete; // Copy constructor
		Axe(Axe&&) = delete; // Move constructor
		Axe& operator=(Axe const&) = delete; // Copy assignment operator
		Axe& operator=(Axe&&) = delete; // Move assignment operator
		virtual ~Axe() = default; // Destructor

		inline int16_t const& attackDamage() const noexcept override { return m_attack_damage; }
		inline std::string const& description() const noexcept override { return m_description; }
		void attack(Entity& target) const noexcept override;

	protected:
	private:
		int16_t m_attack_damage;
		std::string m_description;
	};
}
#endif