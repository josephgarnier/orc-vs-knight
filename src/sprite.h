/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_SPRIT_H
#define ORC_VS_KNIGHT_SPRIT_H

#include <memory>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Text.hpp>

namespace FastSimDesign {
	class Sprite final : public sf::Drawable
	{
	public:
		explicit Sprite(std::unique_ptr<sf::Shape> shape); // throw ResourceException
		Sprite(Sprite const&) = delete; // Copy constructor
		Sprite(Sprite&& copy) noexcept; // Move constructor
		Sprite& operator=(Sprite const&) = delete; // Copy assignment operator
		Sprite& operator=(Sprite&& copy) noexcept; // Move assignment operator (with copy-and-swap idiom)
		virtual ~Sprite() = default; // Destructor

		friend inline void swap(Sprite& left, Sprite& right) noexcept; // Copy-and-swap idiom

		inline sf::Vector2f const& position() const noexcept { return m_shape->getPosition(); }
		inline sf::Vector2f const& origin() const noexcept { return m_shape->getOrigin(); }

		void setPosition(sf::Vector2f const& position) noexcept;
		void setName(std::string name) noexcept;
		void setActionDescription(std::string action) noexcept;

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		sf::Font m_font;

		sf::Text m_name;
		std::unique_ptr<sf::Shape> m_shape;
		sf::Text m_action_description;
	};

	/*****************************************************************************
	Operator functions
	*****************************************************************************/
	inline void swap(Sprite& left, Sprite& right) noexcept
	{
		using std::swap;
		swap(left.m_font, right.m_font);
		swap(left.m_name, right.m_name);
		swap(left.m_shape, right.m_shape);
		swap(left.m_action_description, right.m_action_description);
	}
}
#endif