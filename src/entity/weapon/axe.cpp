/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "axe.h"

#include <algorithm>

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

	void Axe::attack(Entity& target, int16_t attack_amplifier) const noexcept
	{
		int16_t realt_attack_damage = m_attack_damage* attack_amplifier;
		int16_t attack_damage_absorbed = std::min(target.armor().defensePoints(), realt_attack_damage);
		target.armor().absorbDamages(attack_damage_absorbed);
		int16_t new_hp = target.hp() - realt_attack_damage + attack_damage_absorbed;
		new_hp = std::clamp(new_hp, static_cast<int16_t>(0), static_cast<int16_t>(INT16_MAX));
		target.setHp(new_hp);
	}
}