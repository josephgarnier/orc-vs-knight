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
		TEntityType* castedEntity = dynamic_cast<TEntityType*>(m_entities[id].get());
		assert(castedEntity != nullptr && "This entity cannot be cast to T type");
		return *castedEntity;
	}

	template<typename TEntityType, typename... TEntityArgs>
	Entity::Id World::createEntity(TEntityArgs&&... args) noexcept
	{
		std::unique_ptr<Entity> newEntity = std::make_unique<TEntityType>(std::forward<TEntityArgs>(args)...);
		assert(!std::count(std::begin(m_entities), std::end(m_entities), newEntity) && "Entity with same id already exists, you have to erase it before push it again");
		m_entities.push_back(std::move(newEntity));
		return newEntity->id();
	}
}