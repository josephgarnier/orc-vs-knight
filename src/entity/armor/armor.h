/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_ARMOR_H
#define ORC_VS_KNIGHT_ARMOR_H

#include <string>

namespace FastSimDesign {
	class Armor
	{
	public:
		explicit Armor() = default; // Default constructor
		Armor(Armor const&) = delete; // Copy constructor
		Armor(Armor&&) = delete; // Move constructor
		Armor& operator=(Armor const&) = delete; // Copy assignment operator
		Armor& operator=(Armor&&) = delete; // Move assignment operator
		virtual ~Armor() = default; // Destructor

		virtual int16_t const& defensePoints() const noexcept = 0;
		virtual std::string const& description() const noexcept = 0;
		virtual void absorbDamages(int16_t amount) noexcept = 0;

	protected:
	private:
	};
}
#endif