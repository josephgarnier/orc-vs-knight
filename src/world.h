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
	private:
		class TurnLoop
		{
		public:
			explicit TurnLoop(EntityContainer const& container); // Default constructor
			TurnLoop(TurnLoop const&) = delete; // Copy constructor
			TurnLoop(TurnLoop&&) = delete; // Move constructor
			TurnLoop& operator=(TurnLoop const&) = delete; // Copy assignment operator
			TurnLoop& operator=(TurnLoop&&) = delete; // Move assignment operator
			virtual ~TurnLoop() = default; // Destructor
		
			void beginNewTurn() noexcept;
			inline uint64_t currentTurn() const noexcept {return m_current_Turn;}
			Entity& currentTokenOwner() const noexcept;
			void passTokenToNext() noexcept;
			bool isTurnOver() const noexcept;
		protected:
		
		private:
			EntityContainer const& m_entity_storage;
			uint64_t m_current_Turn;
			EntityContainer::const_iterator m_entity_iterator;
		};

	public:
		explicit World(unsigned int width, unsigned int height) noexcept; // Default constructor
		World(World const&) = delete; // Copy constructor
		World(World&&) = delete; // Move constructor
		World& operator=(World const&) = delete; // Copy assignment operator
		World& operator=(World&&) = delete; // Move assignment operator
		virtual ~World() = default; // Destructor

		void beginNewTurn() noexcept;
		uint64_t currentTurn() const noexcept;
		Entity const & currentTokenOwner() const noexcept;
		void passTokenToNextIfComplete() noexcept;
		void update(sf::Time const& delta_time) noexcept;
		bool isTurnCompletedByOwner() const noexcept;
		bool isTurnCompletedByAll() const noexcept;

		bool isCoordValid(float x, float y) const noexcept;

		inline bool isExists(Entity::Id const& id) const noexcept { return id >= 0 && id < m_entities.size(); }
		inline std::size_t entityCount() const noexcept { return m_entities.size(); }
		World::EntityContainerPtr getEntities() const noexcept;
		template<typename TEntityType>
		TEntityType& getEntity(Entity::Id const& id) const noexcept;

		template<typename TEntityType, typename... TEntityArgs>
		Entity::Id createEntity(TEntityArgs&&... args) noexcept;
		void destroyAllEntities() noexcept;

		uint64_t aliveEntityCount() const noexcept;
		World::EntityContainerPtr getAliveEntities() const noexcept;

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		unsigned int m_width;
		unsigned int m_height;

		EntityContainer m_entities;
		TurnLoop m_entity_loop;
	};
}
#include "world.tpp"
#endif