cmake_minimum_required(VERSION 3.3)
project(kaiju_flambeaux_corps)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    kaiju_program/src/Patterns/BluePattern.cpp
    kaiju_program/src/Patterns/BluePattern.h
    kaiju_program/src/Patterns/GradientPattern.cpp
    kaiju_program/src/Patterns/GradientPattern.h
    kaiju_program/src/Patterns/GreenPattern.cpp
    kaiju_program/src/Patterns/GreenPattern.h
    kaiju_program/src/Patterns/Pattern.cpp
    kaiju_program/src/Patterns/Pattern.h
    kaiju_program/src/Patterns/PulsingSaturationPattern.cpp
    kaiju_program/src/Patterns/PulsingSaturationPattern.h
    kaiju_program/src/Patterns/RainbowFadePattern.cpp
    kaiju_program/src/Patterns/RainbowFadePattern.h
    kaiju_program/src/Patterns/SparksPattern.cpp
    kaiju_program/src/Patterns/SparksPattern.h
    kaiju_program/src/config.h
    kaiju_program/src/cplusplus.h
    kaiju_program/src/kaiju_program.h
    kaiju_program/src/kaiju_program.ino
    kaiju_program/src/patterns.cpp
    kaiju_program/src/Playlist.cpp
    kaiju_program/src/Playlist.h
    kaiju_program/src/RadioMessage.h)

include_directories(./kaiju_program/src)
include_directories(./kaiju_program/lib/FastLED)
include_directories(./kaiju_program/lib/RadioHead)
include_directories(~/ArduinoSDK/1.6.6/hardware/arduino/avr/cores/arduino/)
include_directories(~/ArduinoSDK/1.6.6/hardware/tools/avr/avr/include/)

add_custom_target(kaiju_flambeaux_corps COMMAND +make all -C ${kaiju_flambeaux_corps_SOURCE_DIR}/kaiju_program
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})

add_executable(fake_project_for_clion ${SOURCE_FILES})