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
		World::EntityContainerPtr potential_targets = m_world.getEntitiesInFront(*this);
		std::string message{};
		if (potential_targets.empty())
		{
			message += "No entity to target ";
		} else
		{
			FastSimDesign::Entity& selected_target = *potential_targets.front();
			int16_t damage_of_attack = weapon().attack(selected_target);
			message += "Attack ";
			message += selected_target.name();
			message += " with ";
			message += weapon().description();
			message += ": ";
			message += std::to_string(damage_of_attack);
			message += " damages";
		}
		m_sprite.setActionDescription(message);
		flagTurnAsCompleted();
	}
}