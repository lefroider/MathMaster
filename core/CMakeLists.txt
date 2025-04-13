cmake_minimum_required(VERSION 3.5)

add_library(core_includes INTERFACE)
target_include_directories(core_includes INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_subdirectory(src)
enable_testing()
add_subdirectory(tests)
