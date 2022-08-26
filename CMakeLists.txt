cmake_minimum_required(VERSION 3.16)

project(sol_client_launcher VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Gui) 

qt_add_resources(sol_client_launcher "resources"
	FILES
		qml/main.qml
)

add_executable(sol_client_launcher main.cpp Launcher.cpp)

target_link_libraries(sol_client_launcher PRIVATE Qt6::Gui Qt6::Quick)
