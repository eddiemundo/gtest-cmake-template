add_library(lib lib.cpp)
include_directories(
	${PROJECT_SOURCE_DIR}/include
)
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})