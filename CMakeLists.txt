cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr)
project(blackpill_base_project)

target_sources(app PRIVATE src/main.c)
target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Include the library (via directory)
# add_subdirectory(lib/custom_lib)

# Link the custom library to the application
# target_link_libraries(app PRIVATE custom_lib)
