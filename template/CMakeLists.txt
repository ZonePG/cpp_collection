# ------------------------------------------------------------------------------
# Header
# ------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.6)
project(template)

set(CMAKE_CXX_STANDARD 17)

# ------------------------------------------------------------------------------
# template_auto
# ------------------------------------------------------------------------------

add_custom_target(template_auto)

function(example number)
    add_executable(template_auto_example${number} template_auto.cpp)
    target_compile_definitions(template_auto_example${number} PRIVATE EXAMPLE${number})
    add_dependencies(template_auto template_auto_example${number})
endfunction(example)

example(01)
example(02)
example(03)