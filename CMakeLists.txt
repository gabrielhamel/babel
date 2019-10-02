project(Babel)
cmake_minimum_required(VERSION 2.8.12)
add_definitions("-fPIC")
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
include_directories(${CMAKE_INCLUDE_PATH})

# Boost
find_package(Boost 1.71.0 REQUIRED COMPONENTS system thread)
find_package(Threads)

# QT
find_package(Qt5Widgets CONFIG REQUIRED)

# Client
add_executable( client
                Client/src/main.cpp
                Client/src/Form.cpp
                Client/src/RegisterForm.cpp
              )
target_include_directories( client PUBLIC
                            Client/include
                          )
target_link_libraries(client ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY})
target_link_libraries(client ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(client ${CONAN_LIBS} Qt5::Widgets)

# Server
add_executable( server
                Server/src/main.cpp
                Server/src/BoostNetworkClient.cpp
                Server/src/BoostNetworkServer.cpp
                Server/src/NetworkManager.cpp
                )
target_include_directories( server PUBLIC
                            Server/include
                          )
target_link_libraries(server ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY})
target_link_libraries(server ${CMAKE_THREAD_LIBS_INIT})
