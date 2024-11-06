cmake_minimum_required(VERSION 3.0.0)
project(rpg_combat_kata VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(utils)

find_package(GTest REQUIRED)

add_executable(combat_kata test.cpp character.cpp combat_rules.cpp)
target_link_libraries(combat_kata ${GTEST_LIBRARIES} gtest pthread utils) # aggiungi qua le subdir

enable_testing()
add_test(add combat_kata)

# cmake -Bbuild
# cmake --build build
