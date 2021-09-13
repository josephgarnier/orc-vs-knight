/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#include "resource_exception.h"

namespace FastSimDesign {
	/*****************************************************************************
	ResourceException::Methods
	*****************************************************************************/
	ResourceException::ResourceException(std::string what) noexcept
		: Parent{}
		, m_what_message{std::move(what)}
	{
	}

	char const* ResourceException::what() const noexcept
	{
		return m_what_message.c_str();
	}
}