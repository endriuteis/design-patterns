# Untested with previous versions, yet should work
cmake_minimum_required(VERSION 2.8.11)

project(Prototype)

find_package(Boost 1.55 REQUIRED system serialization)

# Boost dependency
find_package(Boost 1.55 REQUIRED system serialization)

# Create the target
add_executable(${PROJECT_NAME} prototype_serialization.cpp)

include_directories(${Boost_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES})
