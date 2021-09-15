/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_WORLD_H
#define ORC_VS_KNIGHT_WORLD_H

#include <memory>

#include <SFML/Graphics/Drawable.hpp>

#include "entity.h"

namespace FastSimDesign {
	class World final : public sf::Drawable
	{
	public:
		using EntityContainer = std::vector<std::unique_ptr<Entity>>;
		using EntityContainerPtr = std::vector<Entity*>;
		using EntityContainerConstPtr = std::vector<Entity const*>;

	public:
		explicit World(unsigned int width, unsigned int height) noexcept; // Default constructor
		World(World const&) = delete; // Copy constructor
		World(World&&) = delete; // Move constructor
		World& operator=(World const&) = delete; // Copy assignment operator
		World& operator=(World&&) = delete; // Move assignment operator
		virtual ~World() = default; // Destructor

		void init() noexcept;
		void update(sf::Time const& delta_time) noexcept;
		void term() noexcept;
		bool isCoordValid(float x, float y) const noexcept;

		inline bool isExists(Entity::Id const& id) const noexcept { return id >= 0 && id < m_entities.size(); }
		inline std::size_t entityCount() const noexcept { return m_entities.size(); }
		World::EntityContainerPtr getEntities() const noexcept;
		template<typename TEntityType>
		TEntityType& getEntity(Entity::Id const& id) const noexcept;

		template<typename TEntityType, typename... TEntityArgs>
		Entity::Id createEntity(TEntityArgs&&... args) noexcept;
		void destroyAllEntities() noexcept;

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		unsigned int m_width;
		unsigned int m_height;

		EntityContainer m_entities;
	};
}
#include "world.tpp"
#endif