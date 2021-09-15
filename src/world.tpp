/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "world.h"

#include <cassert>

#include "entity.h"

namespace FastSimDesign {
	/*****************************************************************************
	World::Methods
	*****************************************************************************/
	template<typename TEntityType>
	TEntityType& World::getEntity(Entity::Id const& id) const noexcept
	{
		assert(isExists(id) && "Entity does not exists");
		TEntityType* casted_entity = dynamic_cast<TEntityType*>(m_entities[id].get());
		assert(casted_entity != nullptr && "This entity cannot be cast to T type");
		return *casted_entity;
	}

	template<typename TEntityType, typename... TEntityArgs>
	Entity::Id World::createEntity(TEntityArgs&&... args) noexcept
	{
		std::unique_ptr<Entity> new_entity = std::make_unique<TEntityType>(std::forward<TEntityArgs>(args)...);
		assert(!std::count(std::begin(m_entities), std::end(m_entities), new_entity) && "Entity with same id already exists, you have to erase it before push it again");
		Entity::Id new_entity_id = new_entity->id();
		m_entities.push_back(std::move(new_entity));
		return new_entity_id;
	}
}