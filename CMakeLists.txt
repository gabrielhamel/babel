cmake_minimum_required(VERSION 3.5)

project(Babel LANGUAGES CXX)

# Conan
include(build/conanbuildinfo.cmake)
conan_basic_setup()

# QT
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# SQLite3
find_package(SQLite3)

# Boost
find_package(Boost 1.71.0 REQUIRED COMPONENTS system thread)
find_package(Threads)

add_executable(client
    Client/src/main.cpp
    Client/src/MainWindow.cpp
    Client/include/MainWindow.hpp
)

target_link_libraries(client PRIVATE Qt5::Widgets)

# Server
add_executable( server
                Server/src/main.cpp
                Server/src/Network/BoostNetworkClient.cpp
                Server/src/Network/BoostNetworkServer.cpp
                Server/src/Network/NetworkManager.cpp
                Server/src/Storage/SqlClient.cpp
                Server/src/Core/CommandParser.cpp
                Server/src/Core/User.cpp
              )
target_include_directories( server PUBLIC
                            Server/include
                            Server/include/Network
                            Server/include/Storage
                            Server/include/Core
                          )
target_include_directories( server PUBLIC
                            ${SQLITE3_INCLUDE_DIRS}
                          )
target_link_libraries(server ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY})
target_link_libraries(server ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(server ${SQLITE3_LIBRARIES})
