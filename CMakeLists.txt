cmake_minimum_required(VERSION 3.12)

# initialize the SDK based on PICO_SDK_PATH note: this must happen before
# project()
include(pico_sdk_import.cmake)

project(quote_screen C CXX ASM)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_subdirectory(lib/epaper)

set(QUOTE_SCREEN_SOURCES src/main.c)
add_executable(quote_screen ${QUOTE_SCREEN_SOURCES})

target_include_directories(quote_screen PRIVATE include)

target_link_libraries(quote_screen PRIVATE waveshare_epaper pico_stdlib)

# if(PICO_CYW43_SUPPORTED) target_link_libraries(blink pico_cyw43_arch_none)
# endif()

pico_enable_stdio_usb(quote_screen 1)
pico_enable_stdio_uart(quote_screen 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(quote_screen)

# add url via pico_set_program_url pico_set_program_url(blink
# "https://github.com/j-dumas/quote-board")

add_executable(clear_screen src/clear_screen.c)

target_link_libraries(clear_screen PRIVATE waveshare_epaper pico_stdlib)

pico_enable_stdio_usb(clear_screen 1)
pico_enable_stdio_uart(clear_screen 0)
pico_add_extra_outputs(clear_screen)
