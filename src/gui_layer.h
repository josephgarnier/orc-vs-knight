/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_GUI_LAYER_H
#define ORC_VS_KNIGHT_GUI_LAYER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace FastSimDesign {
	class World;
	class GuiLayer
	{
	public:
		explicit GuiLayer(World& world, sf::RenderWindow& window); // Default constructor
		GuiLayer(GuiLayer const&) = delete; // Copy constructor
		GuiLayer(GuiLayer&&) = delete; // Move constructor
		GuiLayer& operator=(GuiLayer const&) = delete; // Copy assignment operator
		GuiLayer& operator=(GuiLayer&&) = delete; // Move assignment operator
		virtual ~GuiLayer() = default; // Destructor

		void initKnightPanel() noexcept;
		void initOrcPanel() noexcept;
		void initInfoPanel() noexcept;
		void initStartingMessagePanel() noexcept;

		void processEvents() noexcept;
		void processEvent(sf::Event const & event) noexcept;
		void update(sf::Time const& delta_time) noexcept;
		void updateStatistics(sf::Time const& delta_time) noexcept;
		void draw() noexcept;

	private:
		template<typename TUi>
		void centerOrigin(TUi& ui_component) const noexcept;

	protected:
	private:
		World& m_world;
		sf::RenderWindow& m_window;

		sf::Font m_font;

		sf::RectangleShape m_knight_border;
		sf::Text m_knight_label;
		sf::Text m_knight_hp_label;
		sf::Text m_knight_hp_value;

		sf::RectangleShape m_orc_border;
		sf::Text m_orc_label;
		sf::Text m_orc_hp_label;
		sf::Text m_orc_hp_value;

		sf::Text m_stats_label;
		sf::Text m_stats_value;
		sf::Text m_round_label;
		sf::Text m_round_value;
		sf::Time m_stats_time_since_last_update;
		std::size_t m_stats_frame_counter;

		sf::Text m_start_message;
	};
}
#include "gui_layer.tpp"
#endif