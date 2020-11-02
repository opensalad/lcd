project(lcd_cli CXX)

file (GLOB HEADERS "*.h")
file (GLOB SOURCES "*.cpp")

add_executable(lcd_cli ${HEADERS} ${SOURCES})
target_link_libraries(lcd_cli lcd_lib)
target_include_directories(lcd_cli
PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/../lcd_lib
	${CMAKE_SOURCE_DIR}/interfaces
	${CMAKE_SOURCE_DIR}/utils
	${CMAKE_BINARY_DIR}/exports
)
target_precompile_headers(lcd_cli
	REUSE_FROM lcd_lib
)
