/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "knight.h"

namespace FastSimDesign {
	/*****************************************************************************
	Knight::Methods
	*****************************************************************************/
	Knight::Knight(FastSimDesign::World& world, FastSimDesign::Entity::Id id, Sprite sprite) noexcept
		: Parent{world, id, std::move(sprite)}
	{
	}

	void Knight::update(sf::Time const& delta_time) noexcept
	{
		flagTurnAsCompleted();
	}
}