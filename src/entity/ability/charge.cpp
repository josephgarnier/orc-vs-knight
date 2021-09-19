/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "charge.h"

#include <cassert>

#include "entity/entity.h"
#include "effect.h"

namespace FastSimDesign {
	/*****************************************************************************
	Charge::Methods
	*****************************************************************************/
	Charge::Charge() noexcept
		: Parent{"charge", 3}
	{
	}

	bool Charge::tryToPerformEffect(Entity& target) noexcept
	{
		if (isReady())
		{
			if (rand() % 100 < 60)
			{
				Effect charge_effect{"charge", Effect::Target::ENEMY, Effect::Property::ATTACK, 2, 1};
				target.addActiveEffect(std::move(charge_effect));
				activateCooldown();
				return true;
			}
		}
		return false;
	}
}