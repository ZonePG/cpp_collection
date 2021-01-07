# ------------------------------------------------------------------------------
# Header
# ------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.6)
project(constexpr)

set(CMAKE_CXX_STANDARD 17)

# ------------------------------------------------------------------------------
# tuple_parameter_packs
# ------------------------------------------------------------------------------

add_custom_target(tuple_parameter_packs)

function(example number)
    add_executable(tuple_parameter_packs_example${number} tuple_parameter_packs.cpp)
    target_compile_definitions(tuple_parameter_packs_example${number} PRIVATE EXAMPLE${number})
    add_dependencies(tuple_parameter_packs tuple_parameter_packs_example${number})
endfunction(example)

example(01)
example(02)
example(03)
example(04)
example(05)