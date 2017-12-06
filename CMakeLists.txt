cmake_minimum_required(VERSION 3.8)
project(GroupProject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main2.cpp Character.h Character.cpp Item.h Item.cpp Spells.h Weapons.h Potion.h Potion.cpp Weapons.cpp Consumable.cpp Consumable.h Spells.cpp)
add_executable(GroupProject ${SOURCE_FILES})