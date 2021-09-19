/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_STUN_H
#define ORC_VS_KNIGHT_STUN_H

#include <string>

#include "ability_impl.h"

namespace FastSimDesign {
	class Stun final : public FastSimDesign::Impl::Ability
	{
	private:
		using Parent = FastSimDesign::Impl::Ability;

	public:
		explicit Stun() noexcept; // Default constructor
		Stun(Stun const&) = delete; // Copy constructor
		Stun(Stun&&) = delete; // Move constructor
		Stun& operator=(Stun const&) = delete; // Copy assignment operator
		Stun& operator=(Stun&&) = delete; // Move assignment operator
		virtual ~Stun() = default; // Destructor

		bool tryToPerformEffect(Entity& target) noexcept override;

	protected:
	private:
	};
}
#endif