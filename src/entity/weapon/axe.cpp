/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "axe.h"

#include "entity/entity.h"

namespace FastSimDesign {
	/*****************************************************************************
	Axe::Methods
	*****************************************************************************/
	Axe::Axe() noexcept
		: Parent{}
		, m_attack_damage{8}
		, m_description{"axe"}
	{
	}

	int16_t Axe::attack(Entity& target) const noexcept
	{
		int16_t new_hp = target.hp() - m_attack_damage;
		if (new_hp < 0)
			new_hp = 0;
		target.setHp(new_hp);
		return m_attack_damage;
	}
}