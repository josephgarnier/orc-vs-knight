/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "sprite.h"

#include <SFML/Graphics/RenderTarget.hpp>

namespace FastSimDesign {
	/*****************************************************************************
	Sprite::Methods
	*****************************************************************************/
	Sprite::Sprite(std::unique_ptr<sf::Shape> shape, std::unique_ptr<sf::Text> text) noexcept
		: m_shape{std::move(shape)}
		, m_text{std::move(text)}
	{
	}

	void Sprite::setPosition(sf::Vector2f const& position) noexcept
	{
		m_shape->setPosition(position);
	}

	void Sprite::setName(std::string name) noexcept
	{
		m_shape->setOrigin(origin);
	}

	void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(*m_shape.get(), states);
		target.draw(*m_text.get(), states);
	}
}