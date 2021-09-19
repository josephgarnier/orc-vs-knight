/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_ABILITY_EFFECT_H
#define ORC_VS_KNIGHT_ABILITY_EFFECT_H

#include <string>

namespace sf {
	class Time;
}

namespace FastSimDesign {
	class Effect
	{
	public:
		enum class Target
		{
			SELF,
			ENEMY,
			ALLY
		};
		enum class Property
		{
			HP,
			ATTACK,
			DEFENSE,
			STUNED
		};

	public:
		explicit Effect(std::string description, Effect::Target target_type, Effect::Property target_property, int16_t amplifier, int16_t duration) noexcept; // Default constructor
		Effect(Effect const&) = default; // Copy constructor
		Effect(Effect&&) = default; // Move constructor
		Effect& operator=(Effect const&) = default; // Copy assignment operator
		Effect& operator=(Effect&&) = default; // Move assignment operator
		virtual ~Effect() = default; // Destructor

		inline std::string const& description() const noexcept { return m_description; }
		inline Effect::Target const& targetType() const noexcept { return m_target_type; }
		inline Effect::Property const& targetProperty() const noexcept { return m_target_property; }
		inline int16_t const& amplifier() const noexcept { return m_amplifier; }
		inline int16_t const& remainingDuration() const noexcept { return m_duration; }

		void update(sf::Time const& delta_time) noexcept;

	protected:
	private:
		std::string m_description;
		Effect::Target m_target_type;
		Effect::Property m_target_property;
		int16_t m_amplifier;
		int16_t m_duration;
	};
}
#endif