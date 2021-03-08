project(lcd_windows_console_gui CXX)

file (GLOB HEADERS "*.h")
file (GLOB SOURCES "*.cpp")

add_library(lcd_windows_console_gui SHARED ${HEADERS} ${SOURCES})

# === Generate export headers ==================================================
include(GenerateExportHeader)
generate_export_header(lcd_windows_console_gui
	EXPORT_MACRO_NAME LCD_GUI_EXPORT
	EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/lcd_gui_export.h
)
# === Generate export headers ==================================================

target_precompile_headers(lcd_windows_console_gui
REUSE_FROM pch
)

target_link_libraries(lcd_windows_console_gui PUBLIC lcd_lib)

target_include_directories(lcd_windows_console_gui
PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/../lcd_lib
	${CMAKE_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/src/pch
	${CMAKE_SOURCE_DIR}/interfaces
	${CMAKE_SOURCE_DIR}/utils
	${CMAKE_BINARY_DIR}/exports
)
