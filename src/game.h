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

#include <SFML/Graphics/RenderWindow.hpp>

#include "world.h"
#include "gui_layer.h"

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
		void render() noexcept;

	private:
		sf::RenderWindow m_window;
		World m_world;
		GuiLayer m_gui;
	};
}
#endif