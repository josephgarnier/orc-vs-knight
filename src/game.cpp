/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "game.h"

#include <SFML/Window/Event.hpp>

#include "knight.h"
#include "orc.h"

namespace FastSimDesign {
	/*****************************************************************************
	Game::Methods
	*****************************************************************************/
	Game::Game(unsigned int width, unsigned int height)
		: m_window{sf::VideoMode{width, height}, "Orc vs Knight"}
		, m_world{width, height}
		, m_gui{m_world, m_window}
		, m_game_status{Status::Game_Unstarted}
		, m_automatic_turn_change{true}
		, m_delay_time{sf::Time::Zero}
	{
		initEntities();
	}

	void Game::run(int min_frame_per_seconds) noexcept
	{
		sf::Clock clock;
		sf::Time target_frame_time = sf::seconds(1.0f / static_cast<float>(min_frame_per_seconds));
		sf::Time time_since_last_update = sf::Time::Zero;
		while (m_window.isOpen())
		{
			processEvents();
			sf::Time elapsed_time = clock.restart();
			time_since_last_update += elapsed_time;
			while (time_since_last_update > target_frame_time)
			{
				time_since_last_update -= target_frame_time;
				update(target_frame_time);
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
							if (m_game_status == Status::Game_Unstarted)
							{
								m_automatic_turn_change = true;
								m_gui.clearStartMessage();
								m_game_status = Status::Game_Started;
							}
							break;
						case sf::Keyboard::Backspace:
							if (m_game_status == Status::Game_Unstarted)
							{
								m_automatic_turn_change = false;
								m_gui.clearStartMessage();
								m_gui.setGameStatus("Press backspace to begin a turn...");
								m_game_status = Status::Game_Started;
							} else if (!m_automatic_turn_change && m_game_status == Status::Game_Started)
							{
								m_world.beginNewTurn();
								std::string status_message = m_world.currentTokenOwner().name();
								status_message += " is playing";
								m_gui.setGameStatus(status_message);
								m_game_status = Status::Owner_Pending;
							} else
							{
								m_gui.processEvent(event);
							}
							break;
						default:
							if (m_game_status != Status::Game_Unstarted && !m_automatic_turn_change)
								m_gui.processEvent(event);
							break;
					}
					break;
				default:
					if (m_game_status != Status::Game_Unstarted && !m_automatic_turn_change)
						m_gui.processEvent(event);
					break;
			}
		}
	}

	void Game::update(sf::Time const& fixed_delta_time) noexcept
	{
		switch (m_game_status)
		{
			case Status::Game_Started:
				if (m_automatic_turn_change)
				{
					m_world.beginNewTurn();
					std::string status_message = m_world.currentTokenOwner().name();
					status_message += " is playing";
					m_gui.setGameStatus(status_message);
					m_game_status = Status::Owner_Pending;
				}
				break;
			case Status::Owner_Pending:
				{
					if (m_world.isTurnCompletedByOwner())
						m_game_status = Status::Owner_Completed;
					else
						m_world.update(fixed_delta_time);
				}
				break;
			case Status::Owner_Completed:
				{
					// Apply a delay to give the player time to read all information.
					m_delay_time += fixed_delta_time;
					if (m_delay_time <= sf::seconds(1.0f))
						break;
					else
						m_delay_time = sf::Time::Zero;

					if (m_world.isTurnCompletedByAll())
					{
						m_game_status = Status::All_Completed;
					} else
					{
						m_world.passTokenToNextIfComplete();
						std::string status_message = m_world.currentTokenOwner().name();
						status_message += " is playing";
						m_gui.setGameStatus(status_message);
						m_game_status = Status::Owner_Pending;
					}
				}
				break;
			case Status::All_Completed:
				{
					if (m_world.aliveEntityCount() == 1)
					{
						m_game_status = Status::Game_Over;
					} else
					{
						if (!m_automatic_turn_change)
							m_gui.setGameStatus("Press backspace to begin a turn...");
						m_game_status = Status::Game_Started;
					}
				}
				break;
			default:
				break;
		}
		if (m_game_status != Status::Game_Unstarted && m_game_status != Status::Game_Started)
		{
			m_gui.update(fixed_delta_time);
		}
	}

	void Game::render() noexcept
	{
		m_window.clear();
		m_gui.draw();
		m_window.draw(m_world);
		m_window.display();
	}

	void Game::initEntities()
	{
		// Create the Knight entity.
		std::unique_ptr<sf::RectangleShape> knight_body = std::make_unique<sf::RectangleShape>();
		knight_body->setSize(sf::Vector2f(100, 100));
		knight_body->setOutlineColor(sf::Color(20, 20, 200));
		knight_body->setOutlineThickness(1);
		knight_body->setFillColor(sf::Color::Transparent);
		knight_body->setPosition(1, 1);
		Sprite knight_sprite{std::move(knight_body)};
		Entity::Id knight_id = m_world.createEntity<Knight>(m_world, 0, std::move(knight_sprite));
		Knight& knight_entity = m_world.getEntity<Knight>(knight_id);
		knight_entity.setName("Knight");
		knight_entity.setPosition(350, 300);
		knight_entity.setHp(100);

		// Create the Orc entity.
		std::unique_ptr<sf::RectangleShape> orc_body = std::make_unique<sf::RectangleShape>();
		orc_body->setSize(sf::Vector2f(100, 100));
		orc_body->setOutlineColor(sf::Color(20, 200, 20));
		orc_body->setOutlineThickness(1);
		orc_body->setFillColor(sf::Color::Transparent);
		orc_body->setPosition(1, 1);
		Sprite orc_sprite{std::move(orc_body)};
		Entity::Id orc_id = m_world.createEntity<Orc>(m_world, 1, std::move(orc_sprite));
		Orc& orc_entity = m_world.getEntity<Orc>(orc_id);
		orc_entity.setName("Orc");
		orc_entity.setPosition(650, 300);
		orc_entity.setHp(100);
	}
}