project(pch CXX)

add_library(pch stdafx.h stdafx.cpp)
target_precompile_headers(pch PUBLIC stdafx.h)
target_include_directories(pch PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})