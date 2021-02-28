add_executable(unit_test physical_interface.cpp)

target_include_directories(unit_test
PUBLIC
    ${CMAKE_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/interfaces
	${CMAKE_SOURCE_DIR}/utils
	${CMAKE_BINARY_DIR}/exports
    ${CONAN_INCLUDE_DIRS}
)

target_link_directories(unit_test
PUBLIC
    ${CONAN_LIB_DIRS}
)

target_link_libraries(unit_test
PUBLIC
    lcd_lib
    ${CONAN_LIBS_boost}
)