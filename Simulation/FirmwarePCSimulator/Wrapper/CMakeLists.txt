cmake_minimum_required(VERSION 3.2)
set(CMAKE_C_OUTPUT_EXTENSION ".so")
set(CMAKE_C_COMPILER gcc)
set(CMAKE_SYSTEM_NAME Generic) # No linux target etc

# Prevent default configuration
set(CMAKE_C_FLAGS_INIT "")
set(CMAKE_EXE_LINKER_FLAGS_INIT "")
project(DDSGenerator C)
SET(CMAKE_C_FLAGS "-shared ")

set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_SUFFIX ".lib")
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_SUFFIX ".lib")
set(CMAKE_IMPORT_LIBRARY_PREFIX )
set(CMAKE_IMPORT_LIBRARY_SUFFIX )
set(CMAKE_EXECUTABLE_SUFFIX ".so")
set(CMAKE_LINK_LIBRARY_SUFFIX ".lib")
set(CMAKE_DL_LIBS "")

set(FORTH_LIB_PATH "${CMAKE_SOURCE_DIR}/../Common/Libraries/zForth/src/zforth")
set(U8G2_LIB_PATH "${CMAKE_SOURCE_DIR}/../Common/Libraries/u8g2/csrc")
set(BUSINESSLOGIC_PATH "${CMAKE_SOURCE_DIR}/../Common/BusinessLogic")

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${FORTH_LIB_PATH})
include_directories(${U8G2_LIB_PATH})
include_directories(${BUSINESSLOGIC_PATH})

add_library(forth_lib STATIC
        ${FORTH_LIB_PATH}/zforth.c
        ${BUSINESSLOGIC_PATH}/dds_zforth_callbacks.c)


add_library(u8g2_lib STATIC
        ${U8G2_LIB_PATH}/u8x8_byte.c
        ${U8G2_LIB_PATH}/u8x8_cad.c
        ${U8G2_LIB_PATH}/u8g2_bitmap.c
        ${U8G2_LIB_PATH}/u8g2_buffer.c
        ${U8G2_LIB_PATH}/u8g2_cleardisplay.c
        ${U8G2_LIB_PATH}/u8g2_d_setup.c
        ${U8G2_LIB_PATH}/u8g2_fonts.c
        ${U8G2_LIB_PATH}/u8g2_input_value.c
        ${U8G2_LIB_PATH}/u8g2_kerning.c
        ${U8G2_LIB_PATH}/u8g2_ll_hvline.c
        ${U8G2_LIB_PATH}/u8g2_polygon.c
        ${U8G2_LIB_PATH}/u8g2_setup.c
        ${U8G2_LIB_PATH}/u8g2_box.c
        ${U8G2_LIB_PATH}/u8g2_circle.c
        ${U8G2_LIB_PATH}/u8g2_d_memory.c
        ${U8G2_LIB_PATH}/u8g2_font.c
        ${U8G2_LIB_PATH}/u8g2_hvline.c
        ${U8G2_LIB_PATH}/u8g2_intersection.c
        ${U8G2_LIB_PATH}/u8g2_line.c
        ${U8G2_LIB_PATH}/u8g2_message.c
        ${U8G2_LIB_PATH}/u8g2_selection_list.c
        ${U8G2_LIB_PATH}/u8x8_8x8.c
        ${U8G2_LIB_PATH}/u8x8_byte.c
        ${U8G2_LIB_PATH}/u8x8_cad.c
        ${U8G2_LIB_PATH}/u8x8_capture.c
        ${U8G2_LIB_PATH}/u8x8_d_a2printer.c
        ${U8G2_LIB_PATH}/u8x8_d_il3820_296x128.c
        ${U8G2_LIB_PATH}/u8x8_d_ist3020.c
        ${U8G2_LIB_PATH}/u8x8_d_ist7920.c
        ${U8G2_LIB_PATH}/u8x8_d_ks0108.c
        ${U8G2_LIB_PATH}/u8x8_d_lc7981.c
        ${U8G2_LIB_PATH}/u8x8_d_ld7032_60x32.c
        ${U8G2_LIB_PATH}/u8x8_d_ls013b7dh03.c
        ${U8G2_LIB_PATH}/u8x8_d_max7219.c
        ${U8G2_LIB_PATH}/u8x8_d_pcd8544_84x48.c
        ${U8G2_LIB_PATH}/u8x8_d_pcf8812.c
        ${U8G2_LIB_PATH}/u8x8_d_pcf8814_hx1230.c
        ${U8G2_LIB_PATH}/u8x8_d_sbn1661.c
        ${U8G2_LIB_PATH}/u8x8_d_sed1330.c
        ${U8G2_LIB_PATH}/u8x8_d_sh1106_64x32.c
        ${U8G2_LIB_PATH}/u8x8_d_sh1106_72x40.c
        ${U8G2_LIB_PATH}/u8x8_d_sh1107.c
        ${U8G2_LIB_PATH}/u8x8_d_sh1108.c
        ${U8G2_LIB_PATH}/u8x8_d_sh1122.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1305.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1306_128x32.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1306_128x64_noname.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1306_2040x16.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1306_48x64.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1306_64x32.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1306_64x48.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1306_72x40.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1306_96x16.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1309.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1316.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1317.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1318.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1322.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1325.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1326.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1327.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1329.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1606_172x72.c
        ${U8G2_LIB_PATH}/u8x8_d_ssd1607_200x200.c
        ${U8G2_LIB_PATH}/u8x8_d_st7511.c
        ${U8G2_LIB_PATH}/u8x8_d_st75256.c
        ${U8G2_LIB_PATH}/u8x8_d_st7528.c
        ${U8G2_LIB_PATH}/u8x8_d_st75320.c
        ${U8G2_LIB_PATH}/u8x8_d_st7565.c
        ${U8G2_LIB_PATH}/u8x8_d_st7567.c
        ${U8G2_LIB_PATH}/u8x8_d_st7586s_erc240160.c
        ${U8G2_LIB_PATH}/u8x8_d_st7586s_s028hn118a.c
        ${U8G2_LIB_PATH}/u8x8_d_st7588.c
        ${U8G2_LIB_PATH}/u8x8_d_st7920.c
        ${U8G2_LIB_PATH}/u8x8_d_stdio.c
        ${U8G2_LIB_PATH}/u8x8_d_t6963.c
        ${U8G2_LIB_PATH}/u8x8_d_uc1601.c
        ${U8G2_LIB_PATH}/u8x8_d_uc1604.c
        ${U8G2_LIB_PATH}/u8x8_d_uc1608.c
        ${U8G2_LIB_PATH}/u8x8_d_uc1610.c
        ${U8G2_LIB_PATH}/u8x8_d_uc1611.c
        ${U8G2_LIB_PATH}/u8x8_d_uc1617.c
        ${U8G2_LIB_PATH}/u8x8_d_uc1638.c
        ${U8G2_LIB_PATH}/u8x8_d_uc1701_dogs102.c
        ${U8G2_LIB_PATH}/u8x8_d_uc1701_mini12864.c
        ${U8G2_LIB_PATH}/u8x8_debounce.c
        ${U8G2_LIB_PATH}/u8x8_display.c
        ${U8G2_LIB_PATH}/u8x8_fonts.c
        ${U8G2_LIB_PATH}/u8x8_gpio.c
        ${U8G2_LIB_PATH}/u8x8_input_value.c
        ${U8G2_LIB_PATH}/u8x8_message.c
        ${U8G2_LIB_PATH}/u8x8_selection_list.c
        ${U8G2_LIB_PATH}/u8x8_setup.c
        ${U8G2_LIB_PATH}/u8x8_string.c
        ${U8G2_LIB_PATH}/u8x8_u16toa.c
        ${U8G2_LIB_PATH}/u8x8_u8toa.c)


add_executable(simulation
        simulation.c
        dds_u8g2_callbacks_sim.c
        dds_forth_scripts_loader_sim.c
        ${BUSINESSLOGIC_PATH}/dds_business_logic_wrapper.c
        ${BUSINESSLOGIC_PATH}/dds_scpi_gate.c
        ${BUSINESSLOGIC_PATH}/dds_user_interface.c
        ${BUSINESSLOGIC_PATH}/dds_view_main.c
        ${BUSINESSLOGIC_PATH}/dds_view_settings.c)


target_link_libraries(simulation
        forth_lib
        u8g2_lib)
