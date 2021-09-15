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
	class Sprite : public sf::Drawable
	{
	public:
		explicit Sprite(std::unique_ptr<sf::Shape> shape, std::unique_ptr<sf::Text> text) noexcept; // Default constructor
		Sprite(Sprite const&) = delete; // Copy constructor
		Sprite(Sprite&&) = default; // Move constructor
		Sprite& operator=(Sprite const&) = delete; // Copy assignment operator
		Sprite& operator=(Sprite&&) = default; // Move assignment operator
		virtual ~Sprite() = default; // Destructor

		inline sf::Vector2f const& position() const noexcept { return m_shape->getPosition(); }
		inline sf::Vector2f const& origin() const noexcept { return m_shape->getOrigin(); }

		void setPosition(sf::Vector2f const& position) noexcept;
		void setOrigin(sf::Vector2f const& origin) noexcept;

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		std::unique_ptr<sf::Shape> m_shape;
		std::unique_ptr<sf::Text> m_text;
	};
}
#endif