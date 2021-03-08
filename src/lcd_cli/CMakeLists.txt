project(lcd_cli CXX)

file (GLOB HEADERS "*.h")
file (GLOB SOURCES "*.cpp")

add_executable(lcd_cli ${HEADERS} ${SOURCES})
target_link_libraries(lcd_cli
	lcd_lib
	lcd_windows_console_gui
)
target_include_directories(lcd_cli
PRIVATE
	${CMAKE_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/src/pch
	${CMAKE_SOURCE_DIR}/interfaces
	${CMAKE_SOURCE_DIR}/utils
	${CMAKE_BINARY_DIR}/exports
)
target_precompile_headers(lcd_cli
	REUSE_FROM pch
)
