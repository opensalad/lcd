project(lcd_lib CXX)

file(GLOB HEADERS "*.h")
file(GLOB SOURCES "*.cpp")
file(GLOB INTERFACES "${CMAKE_SOURCE_DIR}/interfaces/*.h")
file(GLOB UTILS "${CMAKE_SOURCE_DIR}/utils/*.h")

add_library(lcd_lib SHARED ${HEADERS} ${SOURCES} ${INTERFACES} ${UTILS})
source_group("Interfaces" FILES ${INTERFACES})
source_group("Utilities" FILES ${UTILS})
target_precompile_headers(lcd_lib
PRIVATE
	stdafx.h
)
target_include_directories(lcd_lib
PRIVATE
	${CONAN_INCLUDE_DIR}
	${CMAKE_SOURCE_DIR}/interfaces/
	${CMAKE_SOURCE_DIR}/utils/
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
