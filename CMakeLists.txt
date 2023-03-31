cmake_minimum_required(VERSION 3.24)
project("Deus Engine")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set(SOURCE_FILES Src/Main.cpp Src/ECS/Component.cpp Src/ECS/ComponentManager.cpp Src/ECS/Entity.cpp Src/ECS/EntityManager.cpp)


add_executable(CLion ${SOURCE_FILES})
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(CLion ${SFML_LIBRARIES})
endif()



