/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "shield.h"

#include <algorithm>

namespace FastSimDesign {
	/*****************************************************************************
	Shield::Methods
	*****************************************************************************/
	Shield::Shield() noexcept
	 : Parent{}
	 , m_defense_points{50}
	 , m_description{"shield"}
	{
	}

	void Shield::absorbDamages(int16_t amount) noexcept
	{
		int16_t new_defense_points = m_defense_points - amount;
		new_defense_points = std::clamp(new_defense_points, static_cast<int16_t>(0), static_cast<int16_t>(INT16_MAX));
		m_defense_points = new_defense_points;
	}
}