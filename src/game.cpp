/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "game.h"

#include <SFML/Window/Event.hpp>
#include <iostream>

namespace FastSimDesign {
	/*****************************************************************************
	Game::Methods
	*****************************************************************************/
	Game::Game(unsigned int width, unsigned int height)
		: m_window{sf::VideoMode{width, height}, "Orc vs Knight"}
		, m_world{width, height}
		, m_gui{m_world, m_window}
	{
	}

	void Game::run(int min_frame_per_seconds) noexcept
	{
		sf::Clock clock;
		sf::Time taget_frame_time = sf::seconds(1.0f / static_cast<float>(min_frame_per_seconds));
		sf::Time time_since_last_update = sf::Time::Zero;
		while (m_window.isOpen())
		{
			processEvents();
			sf::Time elapsed_time = clock.restart();
			time_since_last_update += elapsed_time;
			while (time_since_last_update > taget_frame_time)
			{
				time_since_last_update -= taget_frame_time;
				update(taget_frame_time);
			}
			m_gui.updateStatistics(elapsed_time);
			render();
		}
	}

	void Game::processEvents() noexcept
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					m_window.close();
					break;
				case sf::Event::KeyPressed:
					switch (event.key.code)
					{
						case sf::Keyboard::Escape:
							m_window.close();
							break;
						case sf::Keyboard::Space:
							// TODO : start and automatically switch turn
							break;
						case sf::Keyboard::Backslash:
							// TODO : start and manually switch turn
							break;
						default:
							m_gui.processEvent(event);
							break;
					}
				default:
					m_gui.processEvent(event);
					break;
			}
		}
	}

	void Game::update(sf::Time const& delta_time) noexcept
	{
		//m_world.update(delta_time);
		m_gui.update(delta_time);
	}

	void Game::render() noexcept
	{
		m_window.clear();
		m_gui.draw();
		// m_window.draw(m_world);
		m_window.display();
	}
}