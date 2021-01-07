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

# ------------------------------------------------------------------------------
# Header
# ------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.6)
project(explicit_template_declaration)

set(CMAKE_CXX_STANDARD 17)

# ------------------------------------------------------------------------------
# explicit_template_declaration
# ------------------------------------------------------------------------------

add_custom_target(explicit_template_declaration)

function(example number src)
    add_executable(explicit_template_declaration_example${number} ${src})
    target_compile_definitions(explicit_template_declaration_example${number} PRIVATE EXAMPLE${number})
    add_dependencies(explicit_template_declaration explicit_template_declaration_example${number})
endfunction(example)

example(01 "explicit_template_declaration.cpp")
example(02 "explicit_template_declaration.cpp;explicit_template_declaration_helper.cpp")