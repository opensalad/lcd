project(lcd_lib CXX)

file(GLOB HEADERS "*.h")
file(GLOB SOURCES "*.cpp")

add_library(lcd_lib SHARED ${HEADERS} ${SOURCES})
target_precompile_headers(lcd_lib
PRIVATE
	stdafx.h
)
target_include_directories(lcd_lib
PRIVATE
	${CONAN_INCLUDE_DIR}
)
target_link_directories(lcd_lib
PRIVATE
	${CONAN_LIB_DIRS}
)
target_link_libraries(lcd_lib
PRIVATE
	${CONAN_LIBS}
	${CONAN_SYSTEM_LIBS}
)
