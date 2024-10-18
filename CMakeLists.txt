cmake_minimum_required(VERSION 3.10)

project(sp-commander VERSION 0.1)

# Set the C standard version (optional)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the executable target
add_executable(main main.cpp)

# Link ncurses library
find_package(Curses REQUIRED)
target_link_libraries(main ${CURSES_LIBRARIES})

# Add ncurses include directory
target_include_directories(main PUBLIC ${CURSES_INCLUDE_DIR})
