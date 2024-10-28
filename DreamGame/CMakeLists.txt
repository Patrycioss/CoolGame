cmake_minimum_required(VERSION 3.23)
project(DreamGame)

set(CMAKE_CXX_STANDARD 20)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_MakeAvailable(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    endif()
endif()

# Our Project

file(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCES})
#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)
target_compile_definitions(${PROJECT_NAME} PRIVATE RESOURCES="${CMAKE_CURRENT_BINARY_DIR}/resources")


# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "index")
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1 --preload-file ${CMAKE_CURRENT_BINARY_DIR}/resources")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()