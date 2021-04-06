# cmake_minimum_required(VERSION 3.5)

# target_sources(${PROJECT_NAME}
#     PUBLIC
#         ${CMAKE_CURRENT_LIST_DIR}/main.cpp
#         ${CMAKE_CURRENT_LIST_DIR}/connectiondialog.cpp
#         ${CMAKE_CURRENT_LIST_DIR}/gamepadmonitor.cpp
#         ${CMAKE_CURRENT_LIST_DIR}/mainwindow.cpp
#         ${CMAKE_CURRENT_LIST_DIR}/mytcp.cpp
#         ${CMAKE_CURRENT_LIST_DIR}/myudp.cpp
#         ${CMAKE_CURRENT_LIST_DIR}/packet.cpp
        
# )

# target_include_directories(${PROJECT_NAME}
#     PUBLIC
#         ${PROJECT_SOURCE_DIR}/inc
#         ${PROJECT_SOURCE_DIR}/ui
# )



# set(SRC_LIST
#     ${SRC_LIST}
#     ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
#     ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
#     ${CMAKE_CURRENT_SOURCE_DIR}/gamepadmonitor.cpp
#     ${CMAKE_CURRENT_SOURCE_DIR}/myudp.cpp
#     ${CMAKE_CURRENT_SOURCE_DIR}/mytcp.cpp
#     ${CMAKE_CURRENT_SOURCE_DIR}/connectiondialog.cpp
#     ${CMAKE_CURRENT_SOURCE_DIR}/packet.hpp
#     ${CMAKE_CURRENT_SOURCE_DIR}/packet.cpp
#     PARENT_SCOPE
# )