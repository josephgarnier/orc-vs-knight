/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "hands.h"

namespace FastSimDesign {
	/*****************************************************************************
	Hands::Methods
	*****************************************************************************/
	Hands::Hands() noexcept
		: Parent{}
		, m_attack_damage{0}
		, m_description{"hands"}
	{
	}

	int16_t Hands::attack(Entity& target) noexcept
	{
		return m_attack_damage;
	}
}