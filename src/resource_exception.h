/******************************************************************************
* Copyright 2019-present, Joseph Garnier
* All rights reserved.
*
* This source code is licensed under the license found in the
* LICENSE file in the root directory of this source tree.
******************************************************************************/

#pragma once

#ifndef ORC_VS_KNIGHT_RESOURCE_EXCEPTION_H
#define ORC_VS_KNIGHT_RESOURCE_EXCEPTION_H

#include <string>

namespace FastSimDesign {
	class ResourceException final : public std::exception
	{
	private:
		using Parent = std::exception;

	public:
		explicit ResourceException() = default; // Default constructor
		explicit ResourceException(std::string what) noexcept;
		ResourceException(ResourceException const&) = default; // Copy constructor
		ResourceException(ResourceException&&) = default; // Move constructor
		ResourceException& operator=(ResourceException const&) = default; // Copy assignment operator
		ResourceException& operator=(ResourceException&&) = default; // Move assignment operator
		virtual ~ResourceException() = default; // Destructor

		virtual char const* what() const noexcept override;

	protected:
	private:
		std::string m_what_message;
	};
}
#endif