/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "orc.h"

namespace FastSimDesign {
	/*****************************************************************************
	Orc::Methods
	*****************************************************************************/
	Orc::Orc(FastSimDesign::World& world, FastSimDesign::Entity::Id id, Sprite sprite) noexcept
		: Parent{world, id, std::move(sprite)}
	{
	}

	void Orc::update(sf::Time const& delta_time) noexcept
	{
		flagTurnAsCompleted();
	}
}