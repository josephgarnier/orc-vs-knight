/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "no_armor.h"

namespace FastSimDesign {
	/*****************************************************************************
	NoArmor::Methods
	*****************************************************************************/
	NoArmor::NoArmor() noexcept
		: Parent{}
		, m_defense_points{0}
		, m_description{"no armor"}
	{
	}

	void NoArmor::absorbDamages(int16_t amount) noexcept
	{
	}
}