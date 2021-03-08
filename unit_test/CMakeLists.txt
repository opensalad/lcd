include_directories(
    ${CMAKE_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/interfaces
	${CMAKE_SOURCE_DIR}/utils
	${CMAKE_BINARY_DIR}/exports
    ${CONAN_INCLUDE_DIRS}
)

link_directories(
    ${CONAN_LIB_DIRS}
)

link_libraries(
    lcd_lib
    ${CONAN_LIBS_boost}
)

add_executable(controller_unit_test physical_interface.cpp)

enable_testing()
add_test(NAME ControllerTests COMMAND controller_unit_test)