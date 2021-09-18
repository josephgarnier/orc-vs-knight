/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_SHIELD_H
#define ORC_VS_KNIGHT_SHIELD_H

#include <string>

#include "armor.h"

namespace FastSimDesign {
	class Shield final : public Armor
	{
	private:
		using Parent = Armor;

	public:
		explicit Shield() noexcept; // Default constructor
		Shield(Shield const&) = delete; // Copy constructor
		Shield(Shield&&) = delete; // Move constructor
		Shield& operator=(Shield const&) = delete; // Copy assignment operator
		Shield& operator=(Shield&&) = delete; // Move assignment operator
		virtual ~Shield() = default; // Destructor

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