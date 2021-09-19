/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "effect.h"

#include <cassert>

namespace FastSimDesign {
	/*****************************************************************************
	Effect::Methods
	*****************************************************************************/
	Effect::Effect(std::string description, Effect::Target target_type, Effect::Property target_property, int16_t amplifier, int16_t duration) noexcept
		: m_description{std::move(description)}
		, m_target_type{target_type}
		, m_target_property{target_property}
		, m_amplifier{amplifier}
		, m_duration{duration}
	{
		assert(duration >= 0 && "Duration must be a positive value");
	}

	void Effect::update(sf::Time const& delta_time) noexcept
	{
		if (m_duration > 0)
		{
			m_duration--;
		}
	}
}