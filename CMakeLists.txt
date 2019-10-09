cmake_minimum_required(VERSION 3.5)

add_definitions("-fPIC")

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

add_executable(client
    Client/src/main.cpp
    Client/src/Graphic/ContactList.cpp
    Client/include/Graphic/ContactList.hpp
    Client/src/Graphic/Form.cpp
    Client/include/Graphic/Form.hpp
    Client/src/Graphic/LoginForm.cpp
    Client/include/Graphic/LoginForm.hpp
    Client/src/Graphic/RegisterForm.cpp
    Client/include/Graphic/RegisterForm.hpp
    Client/src/Graphic/MainWindow.cpp
    Client/include/Graphic/MainWindow.hpp
    Client/src/Network/BoostTcpClient.cpp
    Client/src/Core/Client.cpp
    Client/src/Audio/AudioData.cpp
    Client/src/Audio/AudioManager.cpp
    Client/src/Audio/PortAudioInput.cpp
    Client/src/Audio/PortAudioOutput.cpp
    Client/src/Audio/PortAudioStream.cpp
)

# No Qt header
target_include_directories(
                            client PUBLIC
                            Client/include/Network
                            Client/include/Core
                            Client/include/Audio
                          )

target_link_libraries(client PRIVATE ${CONAN_LIBS} Qt5::Widgets)

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

target_link_libraries(server PRIVATE ${CONAN_LIBS})