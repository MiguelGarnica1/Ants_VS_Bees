cmake_minimum_required(VERSION 3.17)
project(ants_v_bees)

set(CMAKE_CXX_STANDARD 14)

add_executable(ants_v_bees main.cpp game.cpp game.h ant.cpp ant.h bee.cpp bee.h bodyguard.cpp bodyguard.h fire.cpp fire.h harvester.cpp harvester.h insect.cpp insect.h long_thrower.cpp long_thrower.h ninja.cpp ninja.h place.cpp place.h short_thrower.cpp short_thrower.h thrower.cpp thrower.h wall.cpp wall.h)