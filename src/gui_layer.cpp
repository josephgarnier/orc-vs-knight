/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "gui_layer.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "resource_exception.h"
#include "util/render_util.h"
#include "world.h"
#include "entity/knight.h"
#include "entity/orc.h"

namespace FastSimDesign {
	/*****************************************************************************
	GuiLayer::Methods
	*****************************************************************************/
	GuiLayer::GuiLayer(World& world, sf::RenderWindow& window)
		: m_world{world}
		, m_window{window}
		, m_font{}
		, m_orc_border{}
		, m_orc_label{}
		, m_orc_hp_label{}
		, m_orc_hp_value{}
		, m_orc_weapon_label{}
		, m_orc_weapon_value{}
		, m_orc_armor_label{}
		, m_orc_armor_value{}
		, m_orc_ability_label{}
		, m_orc_ability_value{}
		, m_orc_active_effects_label{}
		, m_orc_active_effects_value{}
		, m_knight_border{}
		, m_knight_label{}
		, m_knight_hp_label{}
		, m_knight_hp_value{}
		, m_knight_weapon_label{}
		, m_knight_weapon_value{}
		, m_knight_armor_label{}
		, m_knight_armor_value{}
		, m_knight_ability_label{}
		, m_knight_ability_value{}
		, m_knight_active_effects_label{}
		, m_knight_active_effects_value{}
		, m_stats_label{}
		, m_stats_value{}
		, m_stats_time_since_last_update{}
		, m_stats_frame_counter{}
		, m_round_label{}
		, m_round_value{}
		, m_game_status_label{}
		, m_game_status_value{}
		, m_start_message{}
	{
		if (!m_font.loadFromFile("./assets/fonts/arial.ttf"))
		{
			throw ResourceException{"Failed to load a font resource!"};
		}

		initOrcPanel();
		initKnightPanel();
		initInfoPanel();
		initStartingMessagePanel();
	}

	void GuiLayer::initOrcPanel() noexcept
	{
		m_orc_border.setSize(sf::Vector2f(150, 200));
		m_orc_border.setOutlineColor(sf::Color(255, 255, 255));
		m_orc_border.setOutlineThickness(1);
		m_orc_border.setFillColor(sf::Color(20, 200, 20));
		m_orc_border.setPosition(1, 1);

		m_orc_label.setString("Orc");
		m_orc_label.setFont(m_font);
		m_orc_label.setCharacterSize(18);
		centerOrigin(m_orc_label);
		m_orc_label.setPosition(m_orc_border.getPosition().x + m_orc_border.getGlobalBounds().width / 2.0f, m_orc_border.getPosition().y + 15.0f);

		m_orc_hp_label.setString("HP:");
		m_orc_hp_label.setFont(m_font);
		m_orc_hp_label.setCharacterSize(14);
		m_orc_hp_label.setPosition(m_orc_border.getPosition().x + 7.0f, m_orc_border.getPosition().y + 35.0f);

		m_orc_hp_value.setString("0");
		m_orc_hp_value.setFont(m_font);
		m_orc_hp_value.setCharacterSize(14);
		m_orc_hp_value.setPosition(m_orc_hp_label.getPosition().x + m_orc_hp_label.getGlobalBounds().width + 5.0f, m_orc_hp_label.getPosition().y);

		m_orc_weapon_label.setString("Weapon:");
		m_orc_weapon_label.setFont(m_font);
		m_orc_weapon_label.setCharacterSize(14);
		m_orc_weapon_label.setPosition(m_orc_border.getPosition().x + 7.0f, m_orc_hp_label.getPosition().y + 25.0f);

		m_orc_weapon_value.setString("None (+0)");
		m_orc_weapon_value.setFont(m_font);
		m_orc_weapon_value.setCharacterSize(14);
		m_orc_weapon_value.setPosition(m_orc_weapon_label.getPosition().x + m_orc_weapon_label.getGlobalBounds().width + 5.0f, m_orc_weapon_label.getPosition().y);

		m_orc_armor_label.setString("Armor:");
		m_orc_armor_label.setFont(m_font);
		m_orc_armor_label.setCharacterSize(14);
		m_orc_armor_label.setPosition(m_orc_border.getPosition().x + 7.0f, m_orc_weapon_label.getPosition().y + 25.0f);

		m_orc_armor_value.setString("None (+0)");
		m_orc_armor_value.setFont(m_font);
		m_orc_armor_value.setCharacterSize(14);
		m_orc_armor_value.setPosition(m_orc_armor_label.getPosition().x + m_orc_armor_label.getGlobalBounds().width + 5.0f, m_orc_armor_label.getPosition().y);

		m_orc_ability_label.setString("Ability:");
		m_orc_ability_label.setFont(m_font);
		m_orc_ability_label.setCharacterSize(14);
		m_orc_ability_label.setPosition(m_orc_border.getPosition().x + 7.0f, m_orc_armor_label.getPosition().y + 25.0f);

		m_orc_ability_value.setString("None (0)");
		m_orc_ability_value.setFont(m_font);
		m_orc_ability_value.setCharacterSize(14);
		m_orc_ability_value.setPosition(m_orc_ability_label.getPosition().x + m_orc_ability_label.getGlobalBounds().width + 5.0f, m_orc_ability_label.getPosition().y);

		m_orc_active_effects_label.setString("Active effects:");
		m_orc_active_effects_label.setFont(m_font);
		m_orc_active_effects_label.setCharacterSize(14);
		m_orc_active_effects_label.setPosition(m_orc_border.getPosition().x + 7.0f, m_orc_ability_label.getPosition().y + 25.0f);
	}

	void GuiLayer::initKnightPanel() noexcept
	{
		m_knight_border.setSize(sf::Vector2f(150, 200));
		m_knight_border.setOutlineColor(sf::Color(255, 255, 255));
		m_knight_border.setOutlineThickness(1);
		m_knight_border.setFillColor(sf::Color(20, 20, 200));
		m_knight_border.setPosition(static_cast<float>(m_window.getSize().x) - m_knight_border.getSize().x - 1.0f, 1.0f);

		m_knight_label.setString("Knight");
		m_knight_label.setFont(m_font);
		m_knight_label.setCharacterSize(18);
		centerOrigin(m_knight_label);
		m_knight_label.setPosition(m_knight_border.getPosition().x + m_knight_border.getGlobalBounds().width / 2.0f, m_knight_border.getPosition().y + 15.0f);

		m_knight_hp_label.setString("HP:");
		m_knight_hp_label.setFont(m_font);
		m_knight_hp_label.setCharacterSize(14);
		m_knight_hp_label.setPosition(m_knight_border.getPosition().x + 7.0f, m_knight_border.getPosition().y + 35.0f);

		m_knight_hp_value.setString("0");
		m_knight_hp_value.setFont(m_font);
		m_knight_hp_value.setCharacterSize(14);
		m_knight_hp_value.setPosition(m_knight_hp_label.getPosition().x + m_knight_hp_label.getGlobalBounds().width + 5.0f, m_knight_hp_label.getPosition().y);

		m_knight_weapon_label.setString("Weapon:");
		m_knight_weapon_label.setFont(m_font);
		m_knight_weapon_label.setCharacterSize(14);
		m_knight_weapon_label.setPosition(m_knight_border.getPosition().x + 7.0f, m_knight_hp_label.getPosition().y + 25.0f);

		m_knight_weapon_value.setString("None(+0)");
		m_knight_weapon_value.setFont(m_font);
		m_knight_weapon_value.setCharacterSize(14);
		m_knight_weapon_value.setPosition(m_knight_weapon_label.getPosition().x + m_knight_weapon_label.getGlobalBounds().width + 5.0f, m_knight_weapon_label.getPosition().y);

		m_knight_armor_label.setString("Armor:");
		m_knight_armor_label.setFont(m_font);
		m_knight_armor_label.setCharacterSize(14);
		m_knight_armor_label.setPosition(m_knight_border.getPosition().x + 7.0f, m_knight_weapon_label.getPosition().y + 25.0f);

		m_knight_armor_value.setString("None(+0)");
		m_knight_armor_value.setFont(m_font);
		m_knight_armor_value.setCharacterSize(14);
		m_knight_armor_value.setPosition(m_knight_armor_label.getPosition().x + m_knight_armor_label.getGlobalBounds().width + 5.0f, m_knight_armor_label.getPosition().y);

		m_knight_ability_label.setString("Ability:");
		m_knight_ability_label.setFont(m_font);
		m_knight_ability_label.setCharacterSize(14);
		m_knight_ability_label.setPosition(m_knight_border.getPosition().x + 7.0f, m_knight_armor_label.getPosition().y + 25.0f);

		m_knight_ability_value.setString("None (0)");
		m_knight_ability_value.setFont(m_font);
		m_knight_ability_value.setCharacterSize(14);
		m_knight_ability_value.setPosition(m_knight_ability_label.getPosition().x + m_knight_ability_label.getGlobalBounds().width + 5.0f, m_knight_ability_label.getPosition().y);

		m_knight_active_effects_label.setString("Active effects:");
		m_knight_active_effects_label.setFont(m_font);
		m_knight_active_effects_label.setCharacterSize(14);
		m_knight_active_effects_label.setPosition(m_knight_border.getPosition().x + 7.0f, m_knight_ability_label.getPosition().y + 25.0f);
	}

	void GuiLayer::initInfoPanel() noexcept
	{
		sf::Vector2f window_size(m_window.getSize());

		m_stats_label.setString("Stats:");
		m_stats_label.setFont(m_font);
		m_stats_label.setCharacterSize(18);
		m_stats_label.setPosition(window_size.x / 2.0f - m_stats_label.getGlobalBounds().width - 80.0f, 15.0f);

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

		m_game_status_label.setString("Game status:");
		m_game_status_label.setFont(m_font);
		m_game_status_label.setCharacterSize(18);
		m_game_status_label.setPosition(m_stats_label.getPosition().x, m_round_label.getPosition().y + m_round_label.getGlobalBounds().height + 15.0f);

		m_game_status_value.setString("none");
		m_game_status_value.setFont(m_font);
		m_game_status_value.setCharacterSize(18);
		m_game_status_value.setPosition(window_size.x / 2.0f + 5.0f, m_game_status_label.getPosition().y);
	}

	void GuiLayer::initStartingMessagePanel() noexcept
	{
		sf::Vector2f window_size(m_window.getSize());

		std::string message{};
		message += "Press space Key to run all turn automatically (with 1 sec of delay) \n";
		message += "                                              OR\n";
		message += "               Press backslash Key to run turn one-by-one \n";
		m_start_message.setString(message);
		m_start_message.setFont(m_font);
		m_start_message.setCharacterSize(15);
		centerOrigin(m_start_message);
		m_start_message.setPosition(window_size.x / 2.0f, window_size.y / 2.0f + 200.0f);
	}

	void GuiLayer::setGameStatus(std::string status) noexcept
	{
		m_game_status_value.setString(status);
	}

	void GuiLayer::clearStartMessage() noexcept
	{
		m_start_message.setString("");
	}

	void GuiLayer::processEvents() noexcept
	{
	}

	void GuiLayer::processEvent(sf::Event const& event) noexcept
	{
	}

	void GuiLayer::update(sf::Time const& delta_time) noexcept
	{
		// Orc update.
		Orc& orc_entity = m_world.getEntity<Orc>(0);
		m_orc_hp_value.setString(std::to_string(orc_entity.hp()));
		std::string orc_weapon_value = orc_entity.weapon().description();
		orc_weapon_value += " (+";
		orc_weapon_value += std::to_string(orc_entity.weapon().attackDamage());
		orc_weapon_value += ")";
		m_orc_weapon_value.setString(orc_weapon_value);
		std::string orc_armor_value = orc_entity.armor().description();
		orc_armor_value += " (+";
		orc_armor_value += std::to_string(orc_entity.armor().defensePoints());
		orc_armor_value += ")";
		m_orc_armor_value.setString(orc_armor_value);
		std::string orc_ability_value = orc_entity.ability().description();
		orc_ability_value += " (";
		orc_ability_value += std::to_string(orc_entity.ability().cooldown());
		orc_ability_value += ")";
		m_orc_ability_value.setString(orc_ability_value);

		float orc_previous_widget_position_y = m_orc_active_effects_label.getPosition().y;
		m_orc_active_effects_value.clear();
		for (auto const & active_effect : orc_entity.activeEffects())
		{
			std::string active_effect_value_message = active_effect.description();
			active_effect_value_message += " (";
			active_effect_value_message += std::to_string(active_effect.remainingDuration());
			active_effect_value_message += ")";

			sf::Text active_effect_value{};
			active_effect_value.setString(active_effect_value_message);
			active_effect_value.setFont(m_font);
			active_effect_value.setCharacterSize(14);
			active_effect_value.setPosition(m_orc_active_effects_label.getPosition().x + 10.0f, orc_previous_widget_position_y + 25.0f);

			m_orc_active_effects_value.push_back(std::move(active_effect_value));
			orc_previous_widget_position_y = active_effect_value.getPosition().y;
		}

		// Knight update.
		Knight& knight_entity = m_world.getEntity<Knight>(1);
		m_knight_hp_value.setString(std::to_string(knight_entity.hp()));
		std::string knight_weapon_value = knight_entity.weapon().description();
		knight_weapon_value += " (+";
		knight_weapon_value += std::to_string(knight_entity.weapon().attackDamage());
		knight_weapon_value += ")";
		m_knight_weapon_value.setString(knight_weapon_value);
		std::string knight_armor_value = knight_entity.armor().description();
		knight_armor_value += " (+";
		knight_armor_value += std::to_string(knight_entity.armor().defensePoints());
		knight_armor_value += ")";
		m_knight_armor_value.setString(knight_armor_value);
		std::string knight_ability_value = knight_entity.ability().description();
		knight_ability_value += " (";
		knight_ability_value += std::to_string(knight_entity.ability().cooldown());
		knight_ability_value += ")";
		m_knight_ability_value.setString(knight_ability_value);

		float knight_previous_widget_position_y = m_knight_active_effects_label.getPosition().y;
		m_knight_active_effects_value.clear();
		for (auto const& active_effect : knight_entity.activeEffects())
		{
			std::string active_effect_value_message = active_effect.description();
			active_effect_value_message += " (";
			active_effect_value_message += std::to_string(active_effect.remainingDuration());
			active_effect_value_message += ")";

			sf::Text active_effect_value{};
			active_effect_value.setString(active_effect_value_message);
			active_effect_value.setFont(m_font);
			active_effect_value.setCharacterSize(14);
			active_effect_value.setPosition(m_knight_active_effects_label.getPosition().x + 10.0f, knight_previous_widget_position_y + 25.0f);
			
			m_knight_active_effects_value.push_back(std::move(active_effect_value));
			knight_previous_widget_position_y = active_effect_value.getPosition().y;
		}

		// Info update.
		m_round_value.setString(std::to_string(m_world.currentTurn()));
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
		m_window.draw(m_orc_border);
		m_window.draw(m_orc_label);
		m_window.draw(m_orc_hp_label);
		m_window.draw(m_orc_hp_value);
		m_window.draw(m_orc_weapon_label);
		m_window.draw(m_orc_weapon_value);
		m_window.draw(m_orc_armor_label);
		m_window.draw(m_orc_armor_value);
		m_window.draw(m_orc_ability_label);
		m_window.draw(m_orc_ability_value);
		m_window.draw(m_orc_active_effects_label);
		for (auto const & active_effect_value : m_orc_active_effects_value)
		{
			m_window.draw(active_effect_value);
		}

		m_window.draw(m_knight_border);
		m_window.draw(m_knight_label);
		m_window.draw(m_knight_hp_label);
		m_window.draw(m_knight_hp_value);
		m_window.draw(m_knight_weapon_label);
		m_window.draw(m_knight_weapon_value);
		m_window.draw(m_knight_armor_label);
		m_window.draw(m_knight_armor_value);
		m_window.draw(m_knight_ability_label);
		m_window.draw(m_knight_ability_value);
		m_window.draw(m_knight_active_effects_label);
		for (auto const& active_effect_value : m_knight_active_effects_value)
		{
			m_window.draw(active_effect_value);
		}
		
		m_window.draw(m_stats_label);
		m_window.draw(m_stats_value);
		m_window.draw(m_round_label);
		m_window.draw(m_round_value);
		m_window.draw(m_game_status_label);
		m_window.draw(m_game_status_value);

		m_window.draw(m_start_message);
	}
}