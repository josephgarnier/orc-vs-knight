/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "knight.h"

#include "world.h"

namespace FastSimDesign {
	/*****************************************************************************
	Knight::Methods
	*****************************************************************************/
	Knight::Knight(FastSimDesign::World& world, FastSimDesign::Entity::Id id, Sprite sprite) noexcept
		: Parent{world, id, std::move(sprite)}
	{
	}

	void Knight::update(sf::Time const& delta_time) noexcept
	{
		std::string message{};

		// Try to use CHARGE ability on self
		if (ability().isReady())
		{
			if (ability().tryToPerformEffect(*this))
				message += "Try to use Charge: Success\n";
			else
				message += "Try to use Charge: Failed\n";
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
				case Effect::Property::ATTACK :
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

		// Find a target
		World::EntityContainerPtr potential_targets = m_world.getEntitiesInFront(*this);
		if (potential_targets.empty())
		{
			message += "No entity to target";
			m_sprite.setActionDescription(message);
			flagTurnAsCompleted();
			return;
		}
		FastSimDesign::Entity& selected_target = *potential_targets.front();
		
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
		message += selected_target.name();
		message += " armor absorbed: ";
		message += std::to_string(attack_damage_absorbed);
		message += " points";
		m_sprite.setActionDescription(message);
		flagTurnAsCompleted();
	}
}