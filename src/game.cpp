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
	Game::Game(unsigned int width, unsigned int height)
		: m_window{sf::VideoMode{width, height}, "Orc vs Knight"}
		, m_world{width, height}
		, m_gui_font{}
		, m_gui_knight_border{}
		, m_gui_knight_label{}
		, m_gui_knight_hp_label{}
		, m_gui_knight_hp_value{}
		, m_gui_orc_border{}
		, m_gui_orc_label{}
		, m_gui_orc_hp_label{}
		, m_gui_orc_hp_value{}
		, m_gui_stats_label{}
		, m_gui_stats_value{}
		, m_gui_round_label{}
		, m_gui_round_value{}
		, m_stats_time_since_last_update{}
		, m_stats_frame_counter{}
		, m_gui_start_message{}
	{
		sf::Vector2f window_size(m_window.getSize());
		
		m_gui_font.loadFromFile("./assets/fonts/arial.ttf");
		
		m_gui_knight_border.setSize(sf::Vector2f(100, 80));
		m_gui_knight_border.setOutlineColor(sf::Color(255, 255, 255));
		m_gui_knight_border.setOutlineThickness(1);
		m_gui_knight_border.setFillColor(sf::Color(20, 20, 200));
		m_gui_knight_border.setPosition(1, 1);

		m_gui_knight_label.setString("Knight");
		m_gui_knight_label.setFont(m_gui_font);
		m_gui_knight_label.setCharacterSize(18);
		centerOrigin(m_gui_knight_label);
		m_gui_knight_label.setPosition(m_gui_knight_border.getPosition().x + m_gui_knight_border.getGlobalBounds().width/2, m_gui_knight_border.getPosition().y + 15);

		m_gui_knight_hp_label.setString("HP:");
		m_gui_knight_hp_label.setFont(m_gui_font);
		m_gui_knight_hp_label.setCharacterSize(14);
		m_gui_knight_hp_label.setPosition(m_gui_knight_border.getPosition().x + 7, m_gui_knight_border.getPosition().y + 35);

		m_gui_knight_hp_value.setString("100");
		m_gui_knight_hp_value.setFont(m_gui_font);
		m_gui_knight_hp_value.setCharacterSize(14);
		m_gui_knight_hp_value.setPosition(m_gui_knight_hp_label.getPosition().x + m_gui_knight_hp_label.getGlobalBounds().width + 5, m_gui_knight_hp_label.getPosition().y);

		m_gui_orc_border.setSize(sf::Vector2f(100, 80));
		m_gui_orc_border.setOutlineColor(sf::Color(255, 255, 255));
		m_gui_orc_border.setOutlineThickness(1);
		m_gui_orc_border.setFillColor(sf::Color(20, 200, 20));
		m_gui_orc_border.setPosition(window_size.x - m_gui_orc_border.getSize().x - 1, 1);

		m_gui_orc_label.setString("Orc");
		m_gui_orc_label.setFont(m_gui_font);
		m_gui_orc_label.setCharacterSize(18);
		centerOrigin(m_gui_orc_label);
		m_gui_orc_label.setPosition(m_gui_orc_border.getPosition().x + m_gui_orc_border.getGlobalBounds().width / 2, m_gui_orc_border.getPosition().y + 15);

		m_gui_orc_hp_label.setString("HP:");
		m_gui_orc_hp_label.setFont(m_gui_font);
		m_gui_orc_hp_label.setCharacterSize(14);
		m_gui_orc_hp_label.setPosition(m_gui_orc_border.getPosition().x + 7, m_gui_orc_border.getPosition().y + 35);

		m_gui_orc_hp_value.setString("100");
		m_gui_orc_hp_value.setFont(m_gui_font);
		m_gui_orc_hp_value.setCharacterSize(14);
		m_gui_orc_hp_value.setPosition(m_gui_orc_hp_label.getPosition().x + m_gui_orc_hp_label.getGlobalBounds().width + 5, m_gui_orc_hp_label.getPosition().y);

		m_gui_stats_label.setString("Stats:");
		m_gui_stats_label.setFont(m_gui_font);
		m_gui_stats_label.setCharacterSize(18);
		m_gui_stats_label.setPosition(window_size.x / 2 - m_gui_stats_label.getGlobalBounds().width - 10, 15);

		m_gui_stats_value.setString("60 fps");
		m_gui_stats_value.setFont(m_gui_font);
		m_gui_stats_value.setCharacterSize(18);
		m_gui_stats_value.setPosition(window_size.x / 2 + 5, m_gui_stats_label.getPosition().y);

		m_gui_round_label.setString("Round:");
		m_gui_round_label.setFont(m_gui_font);
		m_gui_round_label.setCharacterSize(18);
		m_gui_round_label.setPosition(m_gui_stats_label.getPosition().x, m_gui_stats_label.getPosition().y + m_gui_stats_label.getGlobalBounds().height + 15);

		m_gui_round_value.setString("0");
		m_gui_round_value.setFont(m_gui_font);
		m_gui_round_value.setCharacterSize(18);
		m_gui_round_value.setPosition(window_size.x / 2 + 5, m_gui_round_label.getPosition().y);

		m_gui_start_message.setString("Press any Key to start");
		m_gui_start_message.setFont(m_gui_font);
		m_gui_start_message.setCharacterSize(15);
		centerOrigin(m_gui_start_message);
		m_gui_start_message.setPosition(window_size.x / 2, window_size.y / 2 + 100);
	}

		// TODO : créer les entités ici, comme dans initLevel()
	}

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
			updateGui(elapsed_time);
			updateStatistics(elapsed_time);
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
					if (event.key.code == sf::Keyboard::Escape)
						m_window.close();
				default:
					break;
			}
		}
	}

	void Game::update(sf::Time const& delta_time) noexcept
	{
		//m_world.update(delta_time);
	}

	void Game::updateGui(sf::Time const& delta_time) noexcept
	{
	}

	void Game::updateStatistics(sf::Time const& delta_time) noexcept
	{
		m_stats_time_since_last_update += delta_time;
		m_stats_frame_counter += 1;

		if (m_stats_time_since_last_update >= sf::seconds(1.0f))
		{
			m_gui_stats_value.setString(std::to_string(m_stats_frame_counter) + " fps");
			m_stats_time_since_last_update -= sf::seconds(1.0f);
			m_stats_frame_counter = 0;
		}
	}

	void Game::render() noexcept
	{
		m_window.clear();

		m_window.draw(m_gui_knight_border);
		m_window.draw(m_gui_knight_label);
		m_window.draw(m_gui_knight_hp_label);
		m_window.draw(m_gui_knight_hp_value);

		m_window.draw(m_gui_orc_border);
		m_window.draw(m_gui_orc_label);
		m_window.draw(m_gui_orc_hp_label);
		m_window.draw(m_gui_orc_hp_value);

		m_window.draw(m_gui_stats_label);
		m_window.draw(m_gui_stats_value);
		m_window.draw(m_gui_round_label);
		m_window.draw(m_gui_round_value);

		m_window.draw(m_gui_start_message);
		// m_window.draw(m_world);

		m_window.setView(m_window.getDefaultView());
		// m_window.draw(m_statistics_text);
		
		m_window.display();
	}
}