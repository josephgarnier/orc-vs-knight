/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "ability_impl.h"

#include <algorithm>
#include <cassert>

namespace FastSimDesign {
	namespace Impl {
		/*****************************************************************************
		Impl::Ability::Methods
		*****************************************************************************/
		Ability::Ability(std::string description, int16_t cooldown) noexcept
			: Parent{}
			, m_description{std::move(description)}
			, m_max_cooldown_level{cooldown}
			, m_current_cooldown_level{0}
		{
			assert(cooldown >= 0 && "Cooldown must be a positive value");
		}

		bool Ability::isReady() const noexcept
		{
			return m_current_cooldown_level == 0;
		}

		void Ability::update(sf::Time const& delta_time) noexcept
		{
			if (!isReady())
			{
				int16_t new_cooldown_level = m_current_cooldown_level - 1;
				new_cooldown_level = std::clamp(new_cooldown_level, static_cast<int16_t>(0), m_max_cooldown_level);
				m_current_cooldown_level = new_cooldown_level;
			}
		}

		void Ability::activateCooldown() noexcept
		{
			m_current_cooldown_level = m_max_cooldown_level;
		}

		bool Ability::tryToPerformEffect(FastSimDesign::Entity& target) noexcept
		{
			if (isReady())
			{
				activateCooldown();
				return true;
			}
			return false;
		}
	}
}