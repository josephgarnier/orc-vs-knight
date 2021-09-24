# Copyright 2019-present, Joseph Garnier
# All rights reserved.
#
# This source code is licensed under the license found in the
# LICENSE file in the root directory of this source tree.
# =============================================================================
# What Is This?
# -------------
# See README file in the root directory of this source tree.


#------------------------------------------------------------------------------
# Import and link external libraries from here.
#------------------------------------------------------------------------------

#---- Import and link SFML. ----
message(STATUS "Import and link SFML")
if(DEFINED ENV{SFML_DIR}) 
	set(SFML_DIR "$ENV{SFML_DIR}")
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
	if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
		set(SFML_DIR "D:/Documents/Software_Libraries/SFML-2.5.1/vc15-64")
	else()
		set(SFML_DIR "D:/Documents/Software_Libraries/SFML-2.5.1/gcc-7.3.0-mingw-64")
	endif()
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
	set(SFML_DIR "/opt/SFML-2.5.1")
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
	set(SFML_DIR "/opt/SFML-2.5.1")
endif()
if(DEFINED ENV{CMAKE_PREFIX_PATH}) 
	set(CMAKE_PREFIX_PATH "$ENV{CMAKE_PREFIX_PATH}")
else()
	set(CMAKE_PREFIX_PATH "${SFML_DIR}")
endif()

# Find SFML.
find_package(SFML COMPONENTS system graphics window audio network REQUIRED)

# Link SFML to the main binary build target.
message(STATUS "Link SFML library to the target \"${${PROJECT_NAME}_MAIN_BIN_TARGET}\"")
target_link_libraries("${${PROJECT_NAME}_MAIN_BIN_TARGET}"
	PRIVATE
		"sfml-system;sfml-graphics;sfml-window;sfml-audio;sfml-network"
)
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set_target_properties("${${PROJECT_NAME}_MAIN_BIN_TARGET}" PROPERTIES
		VS_DEBUGGER_ENVIRONMENT "PATH=%PATH%;D:/Documents/Software_Libraries/SFML-2.5.1/vc15-64/bin"
	)
endif()
message(STATUS "Import and link SFML - done")