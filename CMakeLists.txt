cmake_minimum_required(VERSION 3.5)
project(RoboVision LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)
find_package(Qt5Gamepad)
find_package(Qt53DCore)
find_package(Qt53DExtras)
find_package(Qt53DInput)
find_package(Qt53DRender)
find_package(Qt5Gui)
find_package(Qt5Network)
find_package(Qt5Charts)


set(SOURCES
    src/main.cpp
    src/connectiondialog.cpp
    src/gamepadmonitor.cpp
    src/mainwindow.cpp
    src/mytcp.cpp
    src/myudp.cpp
    src/chart.cpp
    src/scene.cpp
    src/packet.cpp)
set(HEADERS
    include/connectiondialog.h
    include/gamepadmonitor.h
    include/mainwindow.h
    include/mytcp.hpp
    include/myudp.hpp
    include/chart.hpp
    include/scene.hpp
    include/crc.h
    include/packet.hpp)
set(UIS
    ui/ui_mainwindow.h
    ui/ui_connectiondialog.h)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${UIS})
target_include_directories(${PROJECT_NAME} PUBLIC include ui)


target_link_libraries(RoboVision 
Qt5::Widgets 
Qt5::Gamepad
Qt5::3DCore
Qt5::3DExtras
Qt5::3DInput
Qt5::3DRender
Qt5::Gui
Qt5::Network
Qt5::Charts
)