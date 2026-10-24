aux_source_directory(src/Fonts FONTS_SOURCES)
set(WAVESHARE_SOURCES src/Config/DEV_Config.c src/e-Paper/EPD_4in2_V2.c
                      src/GUI/GUI_Paint.c ${FONTS_SOURCES})

add_library(waveshare_epaper STATIC ${WAVESHARE_SOURCES})
target_include_directories(waveshare_epaper PUBLIC include)

target_link_libraries(waveshare_epaper PUBLIC pico_stdlib hardware_spi)
