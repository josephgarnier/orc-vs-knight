/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_GAME_H
#define ORC_VS_KNIGHT_GAME_H

#include <cmath>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "world.h"

namespace FastSimDesign {
	class Game
	{
	public:
		explicit Game(unsigned int width, unsigned int height);
		Game(Game const&) = delete; // Copy constructor
		Game(Game&&) = delete; // Move constructor
		Game& operator=(Game const&) = delete; // Copy assignment operator
		Game& operator=(Game&&) = delete; // Move assignment operator
		virtual ~Game() = default; // Destructor

		void run(int min_frame_per_seconds) noexcept;

	protected:
	private:
		void processEvents() noexcept;
		void update(sf::Time const& delta_time) noexcept;
		void updateGui(sf::Time const& delta_time) noexcept;
		void updateStatistics(sf::Time const& delta_time) noexcept;
		void render() noexcept;

		template<typename UI>
		void centerOrigin(UI& ui_component) const noexcept
		{
			sf::FloatRect bounds = ui_component.getLocalBounds();
			ui_component.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
		}

	private:
		sf::RenderWindow m_window;
		World m_world;

		sf::Font m_gui_font;

		sf::RectangleShape m_gui_knight_border;
		sf::Text m_gui_knight_label;
		sf::Text m_gui_knight_hp_label;
		sf::Text m_gui_knight_hp_value;

		sf::RectangleShape m_gui_orc_border;
		sf::Text m_gui_orc_label;
		sf::Text m_gui_orc_hp_label;
		sf::Text m_gui_orc_hp_value;

		sf::Text m_gui_stats_label;
		sf::Text m_gui_stats_value;
		sf::Text m_gui_round_label;
		sf::Text m_gui_round_value;
		sf::Time m_stats_time_since_last_update;
		std::size_t m_stats_frame_counter;
		
		sf::Text m_gui_start_message;
	};
}
#endif