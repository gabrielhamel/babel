project(Babel)
cmake_minimum_required(VERSION 2.8.12)
add_definitions("-fPIC")
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
include_directories(${CMAKE_INCLUDE_PATH})


# Client
add_executable( client
                Client/src/main.cpp
              )
target_include_directories( client PUBLIC
                            Client/include
                          )

# Server
add_executable( server
                Server/src/main.cpp
                )
target_include_directories( server PUBLIC
                            Server/include
                          )

# find_package(Qt5Widgets CONFIG REQUIRED)
# target_link_libraries(babel ${CONAN_LIBS} Qt5::Widgets)
