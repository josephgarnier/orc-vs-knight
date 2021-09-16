/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_RENDER_UTIL_H
#define ORC_VS_KNIGHT_RENDER_UTIL_H

#include <cmath>

#include <SFML/Graphics/Transformable.hpp>

namespace FastSimDesign {
	template<typename TSfmlUi>
	void centerOrigin(TSfmlUi& ui_component) noexcept
	{
		sf::FloatRect bounds = ui_component.getLocalBounds();
		ui_component.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
	}
}
#endif