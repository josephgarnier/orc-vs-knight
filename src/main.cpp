/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "iostream"

#include "game.h"
#include "resource_exception.h"

int main()
{
	try
	{
		FastSimDesign::Game game{1000, 600};
		game.run(30);
	} catch (FastSimDesign::ResourceException const& e)
	{
		std::cerr << "EXCEPTION :" << e.what() << std::endl;
		return -1;
	}
	return 0;
}
