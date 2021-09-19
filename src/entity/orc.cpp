/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "orc.h"

#include "world.h"

namespace FastSimDesign {
	/*****************************************************************************
	Orc::Methods
	*****************************************************************************/
	Orc::Orc(FastSimDesign::World& world, FastSimDesign::Entity::Id id, Sprite sprite) noexcept
		: Parent{world, id, std::move(sprite)}
	{
	}

	void Orc::update(sf::Time const& delta_time) noexcept
	{
		std::string message{};

		// Find a target
		World::EntityContainerPtr potential_targets = m_world.getEntitiesInFront(*this);
		if (potential_targets.empty())
		{
			message += "No entity to target ";
			m_sprite.setActionDescription(message);
			flagTurnAsCompleted();
			return;
		}
		FastSimDesign::Entity& selected_target = *potential_targets.front();
		
		// Try to use STUN ability on target
		if (ability().isReady())
		{
			if (ability().tryToPerformEffect(selected_target))
				message += "Try to use Stun: Success\n";
			else
				message += "Try to use Stun: Failed\n";
		}

		// Apply active effects.
		setStuned(false);
		int16_t attack_domage_factor = 1;
		for (auto const& effect : activeEffects())
		{
			switch (effect.targetProperty())
			{
				case Effect::Property::STUNED:
					setStuned(true);
					break;
				case Effect::Property::ATTACK:
					attack_domage_factor = effect.amplifier();
					break;
				default:
					break;
			}
		}
		if (isStuned())
		{
			message += "Affected by Stun, can't play";
			m_sprite.setActionDescription(message);
			flagTurnAsCompleted();
			return;
		}

		// Fight the enemy
		int16_t armor_before_attack = selected_target.armor().defensePoints();
		int16_t hp_before_attack = selected_target.hp();
		weapon().attack(selected_target, attack_domage_factor);
		int16_t attack_damage_absorbed = armor_before_attack - selected_target.armor().defensePoints();
		int16_t hp_losted = hp_before_attack - selected_target.hp();
		message += "Attack ";
		message += selected_target.name();
		message += " with ";
		message += weapon().description();
		message += ": ";
		message += std::to_string(hp_losted);
		message += " damages\n";
		message += "Its armor absorbed: ";
		message += std::to_string(attack_damage_absorbed);
		message += " points";
		m_sprite.setActionDescription(message);
		flagTurnAsCompleted();
	}
}