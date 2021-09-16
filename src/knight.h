/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_KNIGHT_H
#define ORC_VS_KNIGHT_KNIGHT_H

#include "entity_impl.h"

namespace FastSimDesign {
	class Knight : public FastSimDesign::Impl::Entity
	{
	private:
		using Parent = FastSimDesign::Impl::Entity;

	public:
		explicit Knight(FastSimDesign::World& world, FastSimDesign::Entity::Id id, Sprite sprite) noexcept; // Default constructor
		Knight(Knight const&) = delete; // Copy constructor
		Knight(Knight&&) = delete; // Move constructor
		Knight& operator=(Knight const&) = delete; // Copy assignment operator
		Knight& operator=(Knight&&) = delete; // Move assignment operator
		virtual ~Knight() = default; // Destructor
	protected:
	private:
	};
}
#endif