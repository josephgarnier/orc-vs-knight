/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_ENTITY_IMPL_H
#define ORC_VS_KNIGHT_ENTITY_IMPL_H

#include <string>
#include <memory>

#include "entity.h"
#include "sprite.h"

namespace sf {
	class Time;
	class RenderTarget;
	class RenderStates;
}

namespace FastSimDesign {
	namespace Impl {
		class World;
		class Entity : public FastSimDesign::Entity
		{
		private:
			using Parent = FastSimDesign::Entity;

		public:
			explicit Entity(FastSimDesign::World& world, FastSimDesign::Entity::Id id, Sprite sprite) noexcept; // Default constructor
			Entity(Entity const&) = delete; // Copy constructor
			Entity(Entity&&) = delete; // Move constructor
			Entity& operator=(Entity const&) = delete; // Copy assignment operator
			Entity& operator=(Entity&&) = delete; // Move assignment operator
			virtual ~Entity() = default; // Destructor

			inline FastSimDesign::Entity::Id const& id() const noexcept override { return m_id; }
			inline std::string const& name() const noexcept override { return m_name; }
			inline FastSimDesign::World const& world() const noexcept override { return m_world; }
			inline sf::Vector2f const& position() const noexcept override { return m_sprite.position(); }
			inline int16_t const& hp() const noexcept override { return m_hp; }
			inline bool const& isStuned() const noexcept override { return m_stuned; }
			inline Sprite const& sprite() const noexcept override { return m_sprite; }

			inline bool hasToken() const noexcept override { return m_have_token; }
			inline void beginNewTurn() noexcept override { m_turn_completed = false; }
			inline void giveToken() noexcept override { m_have_token = true; }
			virtual void update(sf::Time const& delta_time) noexcept override;
			inline bool isTurnCompleted() noexcept override { return m_turn_completed; }
			inline void retrieveToken() noexcept override { m_have_token = false; };

			void setName(std::string name) noexcept override;
			void setPosition(float x, float y) noexcept override;
			void setHp(int16_t hp) noexcept override;
			void setStuned(bool stuned) noexcept override;

			friend inline bool operator==(Entity const& left, Entity const& right) noexcept;
			friend inline bool operator!=(Entity const& left, Entity const& right) noexcept;
			friend inline bool operator<(Entity const& left, Entity const& right) noexcept;
			friend inline bool operator>(Entity const& left, Entity const& right) noexcept;

		protected:
			inline void flagTurnAsCompleted() noexcept { m_turn_completed = true; }

		private:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		protected:
			FastSimDesign::World& m_world;
			Sprite m_sprite;

		private:
			FastSimDesign::Entity::Id m_id;
			std::string m_name;
			int16_t m_hp;
			bool m_stuned;

			bool m_have_token;
			bool m_turn_completed;
		};

		/*****************************************************************************
		Operator functions
		*****************************************************************************/
		inline bool operator==(Entity const& left, Entity const& right) noexcept
		{
			return left.m_id == right.m_id;
		}

		inline bool operator!=(Entity const& left, Entity const& right) noexcept
		{
			return left.m_id != right.m_id;
		}

		inline bool operator<(Entity const& left, Entity const& right) noexcept
		{
			return left.m_id < right.m_id;
		}

		inline bool operator>(Entity const& left, Entity const& right) noexcept
		{
			return left.m_id > right.m_id;
		}
	}
}
#endif