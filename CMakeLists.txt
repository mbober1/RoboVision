cmake_minimum_required(VERSION 3.5)
project(RoboVision LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5Gamepad)
find_package(Qt53DCore)
find_package(Qt53DExtras)
find_package(Qt53DInput)
find_package(Qt53DRender)
find_package(Qt5Gui)
find_package(Qt5Network)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        gamepadmonitor.h
        gamepadmonitor.cpp
        myudp.hpp
        myudp.cpp
        mytcp.hpp
        mytcp.cpp
        connectiondialog.h
        connectiondialog.cpp
        connectiondialog.ui
)

# Tell CMake to create the helloworld executable
add_executable(RoboVision ${PROJECT_SOURCES})

# Use the Widgets module from Qt 5.
target_link_libraries(RoboVision 
Qt5::Widgets 
Qt5::Gamepad
Qt5::3DCore
Qt5::3DExtras
Qt5::3DInput
Qt5::3DRender
Qt5::Gui
Qt5::Network
)