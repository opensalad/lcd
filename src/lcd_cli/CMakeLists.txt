project(lcd_cli CXX)

file (GLOB HEADERS "*.h")
file (GLOB SOURCES "*.cpp")

add_executable(lcd_cli ${HEADERS} ${SOURCES})
target_link_libraries(lcd_lib)
target_precompile_headers(lcd_cli
	REUSE_FROM lcd_lib
)