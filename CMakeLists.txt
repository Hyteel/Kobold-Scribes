cmake_minimum_required(VERSION 3.5)
project(Kobold_Scribes CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SDL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/SDL")
set(SDL_net_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/SDL_net")

# Example: Manually specify the SDL_net library path
set(SDL_net_LIBRARY_PATH "${CMAKE_CURRENT_SOURCE_DIR}/external/SDL_net")

add_subdirectory(external/SDL)
add_subdirectory(external/SDL_net)

include_directories(${SDL3_INCLUDE_DIRS} ${SDL_net_INCLUDE_DIRS})

# Adding our source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/sources/*.cpp") # Define PROJECT_SOURCES as a list of all source files
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/sources/headers/") # Define PROJECT_INCLUDE to be the path to the include directory of the project
set(EXTERNAL_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/sources/headers/external/")

# Declaring our executable
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME}
  PRIVATE ${PROJECT_INCLUDE}
  SYSTEM  ${EXTERNAL_INCLUDE}
)


target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL_net_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL_net_LIBRARIES})


# Setting ASSETS_PATH
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
