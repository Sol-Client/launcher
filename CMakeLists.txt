cmake_minimum_required(VERSION 3.16)

project(sol_client_launcher VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Quick)

qt6_add_resources(APP_RESOURCES src/resources/resources.qrc)

add_definitions(-DCMAKE_APP_VERSION="${PROJECT_VERSION}")

add_executable(
	${PROJECT_NAME}
	src/cpp/main.cpp
	src/cpp/Launcher.cpp
	${APP_RESOURCES}
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Quick)
