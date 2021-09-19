/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_ABILITY_IMPL_H
#define ORC_VS_KNIGHT_ABILITY_IMPL_H

#include "ability.h"

namespace FastSimDesign {
	namespace Impl {
		class Ability : public FastSimDesign::Ability
		{
		private:
			using Parent = FastSimDesign::Ability;

		public:
			explicit Ability(std::string description, int16_t cooldown) noexcept; // Default constructor
			Ability(Ability const&) = delete; // Copy constructor
			Ability(Ability&&) = delete; // Move constructor
			Ability& operator=(Ability const&) = delete; // Copy assignment operator
			Ability& operator=(Ability&&) = delete; // Move assignment operator
			virtual ~Ability() = default; // Destructor

			inline std::string const& description() const noexcept override { return m_description; }
			int16_t const& cooldown() const noexcept override { return m_max_cooldown_level; }
			bool isReady() const noexcept override;

			void update(sf::Time const& delta_time) noexcept override;

			void activateCooldown() noexcept override;
			virtual bool tryToPerformEffect(FastSimDesign::Entity& target) noexcept override;

		protected:
		private:
			std::string m_description;
			int16_t m_max_cooldown_level;
			int16_t m_current_cooldown_level;
		};
	}
}
#endif