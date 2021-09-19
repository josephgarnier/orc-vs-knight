/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_CHARGE_H
#define ORC_VS_KNIGHT_CHARGE_H

#include <string>

#include "ability_impl.h"

namespace FastSimDesign {
	class Charge final : public FastSimDesign::Impl::Ability
	{
	private:
		using Parent = FastSimDesign::Impl::Ability;

	public:
		explicit Charge() noexcept; // Default constructor
		Charge(Charge const&) = delete; // Copy constructor
		Charge(Charge&&) = delete; // Move constructor
		Charge& operator=(Charge const&) = delete; // Copy assignment operator
		Charge& operator=(Charge&&) = delete; // Move assignment operator
		virtual ~Charge() = default; // Destructor

		bool tryToPerformEffect(Entity& target) noexcept override;

	protected:
	private:
	};
}
#endif