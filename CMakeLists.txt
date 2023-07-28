cmake_minimum_required(VERSION 3.5)

project(dfa-cli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dfa-cli
    src/main.cpp
    src/State.cpp
    src/UserMenu.cpp
    src/UserMenu.h
    src/State.h
)

include(GNUInstallDirs)
install(TARGETS dfa-cli
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
