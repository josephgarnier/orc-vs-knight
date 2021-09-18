/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_NO_ARMOR_H
#define ORC_VS_KNIGHT_NO_ARMOR_H

#include <string>

#include "armor.h"

namespace FastSimDesign {
	class NoArmor final : public Armor
	{
	private:
		using Parent = Armor;

	public:
		explicit NoArmor() noexcept; // Default constructor
		NoArmor(NoArmor const&) = delete; // Copy constructor
		NoArmor(NoArmor&&) = delete; // Move constructor
		NoArmor& operator=(NoArmor const&) = delete; // Copy assignment operator
		NoArmor& operator=(NoArmor&&) = delete; // Move assignment operator
		virtual ~NoArmor() = default; // Destructor

		inline int16_t const& defensePoints() const noexcept override { return m_defense_points; }
		inline std::string const& description() const noexcept override { return m_description; }
		void absorbDamages(int16_t amount) noexcept override;

	protected:
	private:
		int16_t m_defense_points;
		std::string m_description;
	};
}
#endif