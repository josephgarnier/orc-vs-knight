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
		World::EntityContainerPtr potential_targets = m_world.getEntitiesInFront(*this);
		std::string message{};
		if (potential_targets.empty())
		{
			message += "No entity to target ";
		} else
		{
			FastSimDesign::Entity& selected_target = *potential_targets.front();
			int16_t armor_before_attack = selected_target.armor().defensePoints();
			weapon().attack(selected_target);
			int16_t attack_damage_absorbed = armor_before_attack - selected_target.armor().defensePoints();
			message += "Attack ";
			message += selected_target.name();
			message += " with ";
			message += weapon().description();
			message += ": ";
			message += std::to_string(weapon().attackDamage());
			message += " damages\n";
			message += "Its armor absorbed: ";
			message += std::to_string(attack_damage_absorbed);
			message += " points";
		}
		m_sprite.setActionDescription(message);
		flagTurnAsCompleted();
	}
}