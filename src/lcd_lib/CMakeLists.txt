project(lcd_lib CXX)

file(GLOB HEADERS "*.h")
file(GLOB SOURCES "*.cpp")
file(GLOB INTERFACES "${CMAKE_CURRENT_SOURCE_DIR}/interface/*.h")
file(GLOB INTERFACES "${CMAKE_SOURCE_DIR}/interfaces/*.h")
file(GLOB UTILS "${CMAKE_SOURCE_DIR}/utils/*.h")

add_library(lcd_lib SHARED ${HEADERS} ${SOURCES} ${INTERFACES} ${UTILS})

# === Generate export headers ==================================================
include(GenerateExportHeader)
generate_export_header(lcd_lib
	EXPORT_MACRO_NAME LCD_EXPORT
	EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/lcd_export.h
)
# === Generate export headers ==================================================

source_group("Interfaces" FILES ${INTERFACES})
source_group("Utilities" FILES ${UTILS})
target_precompile_headers(lcd_lib
REUSE_FROM pch
)
target_include_directories(lcd_lib
PRIVATE
	${CONAN_INCLUDE_DIRS}
	${CMAKE_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/src/pch
	${CMAKE_SOURCE_DIR}/interfaces/
	${CMAKE_SOURCE_DIR}/utils/
	${CMAKE_BINARY_DIR}/exports
	${CMAKE_CURRENT_SOURCE_DIR}
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
