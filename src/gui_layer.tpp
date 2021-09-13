/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "gui_layer.h"

#include <cmath>

namespace FastSimDesign {

	template<typename TUi>
	void GuiLayer::centerOrigin(TUi& ui_component) const noexcept
	{
		sf::FloatRect bounds = ui_component.getLocalBounds();
		ui_component.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
	}
}