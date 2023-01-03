# SPDX-License-Identifier: GPL-3.0-or-later

cmake_minimum_required(VERSION 3.16)

project(sol_client_launcher VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Quick Network)

qt5_add_resources(APP_RESOURCES src/resources/resources.qrc)

add_definitions(-DCMAKE_APP_VERSION="${PROJECT_VERSION}")

add_executable(
	${PROJECT_NAME}
	src/cpp/main.cpp
	src/cpp/Launcher.cpp
	src/cpp/Instance.cpp
	src/cpp/Util.cpp

	src/cpp/piston/MetaParseException.cpp
	src/cpp/piston/Util.cpp
	src/cpp/piston/VersionHandle.cpp
	src/cpp/piston/VersionManifest.cpp
	${APP_RESOURCES}
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Quick Qt5::Network)

include_directories(src/cpp)