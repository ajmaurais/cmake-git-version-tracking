
cmake_minimum_required(VERSION 3.2)

# Define the two required variables before including
# the source code for watching a git repository.
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include)
set(PRE_CONFIGURE_FILE "${CMAKE_CURRENT_LIST_DIR}/git.h.in")
set(POST_CONFIGURE_FILE "${CMAKE_CURRENT_BINARY_DIR}/include/git.h")
include(git_watcher.cmake)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)

# Create a demo executable.
# Note that one of the dependencies is the configured git header.
add_executable(demo ${POST_CONFIGURE_FILE} main.cc)
add_dependencies( demo check_git_repository )
