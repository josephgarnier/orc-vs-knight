/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "gui_layer.h"

#include "world.h"

namespace FastSimDesign {
	/*****************************************************************************
	Statics
	*****************************************************************************/

	/*****************************************************************************
	Methods
	*****************************************************************************/
	GuiLayer::GuiLayer(World& world, sf::RenderWindow& window)
		: m_world{world}
		, m_window{window}
		, m_font{}
		, m_knight_border{}
		, m_knight_label{}
		, m_knight_hp_label{}
		, m_knight_hp_value{}
		, m_orc_border{}
		, m_orc_label{}
		, m_orc_hp_label{}
		, m_orc_hp_value{}
		, m_stats_label{}
		, m_stats_value{}
		, m_round_label{}
		, m_round_value{}
		, m_stats_time_since_last_update{}
		, m_stats_frame_counter{}
		, m_start_message{}
	{
		m_font.loadFromFile("./assets/fonts/arial.ttf");
		initKnightPanel();
		initOrcPanel();
		initInfoPanel();
		initStartingMessagePanel();
	}

	void GuiLayer::initKnightPanel() noexcept
	{
		m_knight_border.setSize(sf::Vector2f(100, 80));
		m_knight_border.setOutlineColor(sf::Color(255, 255, 255));
		m_knight_border.setOutlineThickness(1);
		m_knight_border.setFillColor(sf::Color(20, 20, 200));
		m_knight_border.setPosition(1, 1);

		m_knight_label.setString("Knight");
		m_knight_label.setFont(m_font);
		m_knight_label.setCharacterSize(18);
		centerOrigin(m_knight_label);
		m_knight_label.setPosition(m_knight_border.getPosition().x + m_knight_border.getGlobalBounds().width / 2.0f, m_knight_border.getPosition().y + 15.0f);

		m_knight_hp_label.setString("HP:");
		m_knight_hp_label.setFont(m_font);
		m_knight_hp_label.setCharacterSize(14);
		m_knight_hp_label.setPosition(m_knight_border.getPosition().x + 7.0f, m_knight_border.getPosition().y + 35.0f);

		m_knight_hp_value.setString("100");
		m_knight_hp_value.setFont(m_font);
		m_knight_hp_value.setCharacterSize(14);
		m_knight_hp_value.setPosition(m_knight_hp_label.getPosition().x + m_knight_hp_label.getGlobalBounds().width + 5.0f, m_knight_hp_label.getPosition().y);
	}

	void GuiLayer::initOrcPanel() noexcept
	{
		m_orc_border.setSize(sf::Vector2f(100, 80));
		m_orc_border.setOutlineColor(sf::Color(255, 255, 255));
		m_orc_border.setOutlineThickness(1);
		m_orc_border.setFillColor(sf::Color(20, 200, 20));
		m_orc_border.setPosition(static_cast<float>(m_window.getSize().x) - m_orc_border.getSize().x - 1.0f, 1.0f);

		m_orc_label.setString("Orc");
		m_orc_label.setFont(m_font);
		m_orc_label.setCharacterSize(18);
		centerOrigin(m_orc_label);
		m_orc_label.setPosition(m_orc_border.getPosition().x + m_orc_border.getGlobalBounds().width / 2.0f, m_orc_border.getPosition().y + 15.0f);

		m_orc_hp_label.setString("HP:");
		m_orc_hp_label.setFont(m_font);
		m_orc_hp_label.setCharacterSize(14);
		m_orc_hp_label.setPosition(m_orc_border.getPosition().x + 7.0f, m_orc_border.getPosition().y + 35.0f);

		m_orc_hp_value.setString("100");
		m_orc_hp_value.setFont(m_font);
		m_orc_hp_value.setCharacterSize(14);
		m_orc_hp_value.setPosition(m_orc_hp_label.getPosition().x + m_orc_hp_label.getGlobalBounds().width + 5.0f, m_orc_hp_label.getPosition().y);
	}

	void GuiLayer::initInfoPanel() noexcept
	{
		sf::Vector2f window_size(m_window.getSize());

		m_stats_label.setString("Stats:");
		m_stats_label.setFont(m_font);
		m_stats_label.setCharacterSize(18);
		m_stats_label.setPosition(window_size.x / 2.0f - m_stats_label.getGlobalBounds().width - 10.0f, 15.0f);

		m_stats_value.setString("60 fps");
		m_stats_value.setFont(m_font);
		m_stats_value.setCharacterSize(18);
		m_stats_value.setPosition(window_size.x / 2.0f + 5.0f, m_stats_label.getPosition().y);

		m_round_label.setString("Round:");
		m_round_label.setFont(m_font);
		m_round_label.setCharacterSize(18);
		m_round_label.setPosition(m_stats_label.getPosition().x, m_stats_label.getPosition().y + m_stats_label.getGlobalBounds().height + 15.0f);

		m_round_value.setString("0");
		m_round_value.setFont(m_font);
		m_round_value.setCharacterSize(18);
		m_round_value.setPosition(window_size.x / 2.0f + 5.0f, m_round_label.getPosition().y);
	}

	void GuiLayer::initStartingMessagePanel() noexcept
	{
		sf::Vector2f window_size(m_window.getSize());

		std::string message{};
		message += "Press space Key to run all turn automatically \n";
		message += "                                OR\n";
		message += "Press backslash Key to run turn one-by-one \n";
		m_start_message.setString(message);
		m_start_message.setFont(m_font);
		m_start_message.setCharacterSize(15);
		centerOrigin(m_start_message);
		m_start_message.setPosition(window_size.x / 2, window_size.y / 2 + 100);
	}

	void GuiLayer::processEvents() noexcept
	{
	}

	void GuiLayer::processEvent(sf::Event const& event) noexcept
	{
	}

	void GuiLayer::update(sf::Time const& delta_time) noexcept
	{
		// TODO update round + other informations
		updateStatistics(delta_time);
	}

	void GuiLayer::updateStatistics(sf::Time const& delta_time) noexcept
	{
		m_stats_time_since_last_update += delta_time;
		m_stats_frame_counter += 1;
		if (m_stats_time_since_last_update >= sf::seconds(1.0f))
		{
			std::string message = std::to_string(m_stats_frame_counter);
			message += " fps"; // the most efficient way, @see https://stackoverflow.com/questions/18892281/most-optimized-way-of-concatenation-in-strings/18892355
			m_stats_value.setString(message);
			m_stats_time_since_last_update -= sf::seconds(1.0f);
			m_stats_frame_counter = 0;
		}
	}

	void GuiLayer::draw() noexcept
	{
		m_window.draw(m_knight_border);
		m_window.draw(m_knight_label);
		m_window.draw(m_knight_hp_label);
		m_window.draw(m_knight_hp_value);

		m_window.draw(m_orc_border);
		m_window.draw(m_orc_label);
		m_window.draw(m_orc_hp_label);
		m_window.draw(m_orc_hp_value);

		m_window.draw(m_stats_label);
		m_window.draw(m_stats_value);
		m_window.draw(m_round_label);
		m_window.draw(m_round_value);

		m_window.draw(m_start_message);
	}
}