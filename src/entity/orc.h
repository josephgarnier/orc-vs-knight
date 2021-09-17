/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_ORC_H
#define ORC_VS_KNIGHT_ORC_H

#include "entity_impl.h"

namespace FastSimDesign {
	class Orc : public FastSimDesign::Impl::Entity
	{
	private:
		using Parent = FastSimDesign::Impl::Entity;

	public:
		explicit Orc(FastSimDesign::World& world, FastSimDesign::Entity::Id id, Sprite sprite) noexcept; // Default constructor
		Orc(Orc const&) = delete; // Copy constructor
		Orc(Orc&&) = delete; // Move constructor
		Orc& operator=(Orc const&) = delete; // Copy assignment operator
		Orc& operator=(Orc&&) = delete; // Move assignment operator
		virtual ~Orc() = default; // Destructor

		virtual void update(sf::Time const& delta_time) noexcept override;

	protected:
	private:
	};
}
#endif