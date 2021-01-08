# ------------------------------------------------------------------------------
# Header
# ------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.6)
project(thread)

set(CMAKE_CXX_STANDARD 17)

# ------------------------------------------------------------------------------
# use_mutex
# ------------------------------------------------------------------------------

add_custom_target(use_mutex)

function(example number src)
    add_executable(use_mutex_example${number} ${src})
    target_compile_definitions(use_mutex_example${number} PRIVATE EXAMPLE${number})
    target_link_libraries(use_mutex_example${number} pthread)
    add_dependencies(use_mutex use_mutex_example${number})
endfunction(example)

example(01 "use_mutex")
example(02 "use_mutex")