/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "stun.h"

#include <cassert>

#include "entity/entity.h"
#include "effect.h"

namespace FastSimDesign {
	/*****************************************************************************
	Stun::Methods
	*****************************************************************************/
	Stun::Stun() noexcept
		: Parent{"stun", 5}
	{
	}

	bool Stun::tryToPerformEffect(Entity& target) noexcept
	{
		if (isReady())
		{
			if (rand() % 100 < 20)
			{
				Effect stun_effect{"stun", Effect::Target::ENEMY, Effect::Property::STUNED, 0, 1};
				target.addActiveEffect(std::move(stun_effect));
				activateCooldown();
				return true;
			}
		}
		return false;
	}
}