/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "sprite.h"

#include <SFML/Graphics/RenderTarget.hpp>

#include "resource_exception.h"
#include "util/render_util.h"

namespace FastSimDesign {
	/*****************************************************************************
	Sprite::Methods
	*****************************************************************************/
	Sprite::Sprite(std::unique_ptr<sf::Shape> shape)
		: m_font{}
		, m_name{}
		, m_shape{std::move(shape)}
		, m_action_description{}
	{
		if (!m_font.loadFromFile("./assets/fonts/arial.ttf"))
		{
			throw ResourceException{"Failed to load a font resource!"};
		}
		centerOrigin(*m_shape.get());

		m_name.setString("");
		m_name.setFont(m_font);
		m_name.setCharacterSize(18);
		centerOrigin(m_name);
		m_name.setPosition(m_shape->getPosition().x, m_shape->getPosition().y - (m_shape->getGlobalBounds().height / 2.0f) - 15.0f);

		m_action_description.setString("Actions: <>");
		m_action_description.setFont(m_font);
		m_action_description.setCharacterSize(12);
		centerOrigin(m_action_description);
		m_action_description.setPosition(m_shape->getPosition().x, m_shape->getPosition().y + (m_shape->getGlobalBounds().height / 2.0f) + (std::round(m_action_description.getGlobalBounds().height / 2.0f)) + 15.0f); // round text position to avoid a blur effect
	}

	Sprite::Sprite(Sprite&& copy) noexcept
		: m_font{std::move(copy.m_font)}
		, m_name{std::move(copy.m_name)}
		, m_shape{std::move(copy.m_shape)}
		, m_action_description{std::move(copy.m_action_description)}
	{
		m_name.setFont(m_font);
		m_action_description.setFont(m_font);
	}

	Sprite& Sprite::operator=(Sprite&& copy) noexcept
	{
		swap(*this, copy);
		return *this;
	}

	void Sprite::setPosition(sf::Vector2f const& position) noexcept
	{
		sf::Vector2f distance_to_travel = position - this->position(); // "this" is needed to avoir confusion with the function parameter
		m_name.move(distance_to_travel);
		m_shape->move(distance_to_travel);
		m_action_description.move(distance_to_travel);
	}

	void Sprite::setName(std::string name) noexcept
	{
		m_name.setString(std::move(name));
		centerOrigin(m_name);
	}

	void Sprite::setActionDescription(std::string action) noexcept
	{
		m_action_description.setString(std::move(action));
		centerOrigin(m_action_description);
		m_action_description.setPosition(m_shape->getPosition().x, m_shape->getPosition().y + (m_shape->getGlobalBounds().height / 2.0f) + (std::round(m_action_description.getGlobalBounds().height / 2.0f)) + 15.0f); // round text position to avoid a blur effect
	}

	void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_name, states);
		target.draw(*m_shape.get(), states);
		target.draw(m_action_description, states);
	}
}