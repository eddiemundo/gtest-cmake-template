enable_testing()
include(ExternalProject)
ExternalProject_Add(
	gtest
	SVN_REPOSITORY http://googletest.googlecode.com/svn/tags/release-1.7.0
	TIMEOUT 10
	# Disable install step
	INSTALL_COMMAND ""
	# Wrap download, configure and build steps in a script to log output
	LOG_DOWNLOAD ON
	LOG_CONFIGURE ON
	LOG_BUILD ON
	PREFIX "gtest"
)
ExternalProject_Get_Property(gtest SOURCE_DIR)
ExternalProject_Get_Property(gtest BINARY_DIR)
set(TARGET lib)
set(GTEST_TARGET ${TARGET}_gtest)
set(TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/lib_test.cpp)
add_executable(${GTEST_TARGET} ${TEST_FILES})
include_directories(
	${SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include
)
add_dependencies(${GTEST_TARGET} gtest)
target_link_libraries(${GTEST_TARGET}
	${TARGET}
	# TODO OP should work but with something around ENABLE_EXPORTS
	# gtest gtest_main
	${BINARY_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}Debug/gtest${CMAKE_STATIC_LIBRARY_SUFFIX}
	${BINARY_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}Debug/gtest_main${CMAKE_STATIC_LIBRARY_SUFFIX}
)
if(CMAKE_COMPILER_IS_GNUC OR CMAKE_COMPILER_IS_GNUCXX)
	target_link_libraries(${GTEST_TARGET} pthread)
endif()