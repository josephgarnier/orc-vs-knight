/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_NO_ABILITY_H
#define ORC_VS_KNIGHT_NO_ABILITY_H

#include "ability_impl.h"

namespace FastSimDesign {
	class NoAbility final : public FastSimDesign::Impl::Ability
	{
		private:
			using Parent = FastSimDesign::Impl::Ability;

		public:
			explicit NoAbility() noexcept; // Default constructor
			NoAbility(NoAbility const&) = delete; // Copy constructor
			NoAbility(NoAbility&&) = delete; // Move constructor
			NoAbility& operator=(NoAbility const&) = delete; // Copy assignment operator
			NoAbility& operator=(NoAbility&&) = delete; // Move assignment operator
			virtual ~NoAbility() = default; // Destructor

		protected:
		private:
	};
}
#endif