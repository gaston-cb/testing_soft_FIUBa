cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(myproject_test C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()


add_subdirectory(main)
add_subdirectory(app/dht11)
#add_subdirectory(app/dht11/src)


# create map/bin/hex file etc.
#pico_add_extra_outputs(myproject_test)