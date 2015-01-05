A simple example demonstrating gtest integration in a cmake C++ project.

How to run (on Windows):
1. You need SVN command line tools installed.
2. Go into the build directory and type: cmake ..
3. Open the created solution file in Visual Studio
4. Build all the projects.
5. Set the gtest_lib project as the startup project, and Ctrl+F5.

How it works (on Windows):
cmake will create a solution file for Visual Studio. Inside it will be 3 projects excluding ALL_BUILD and ZERO_CHECK projects. These 3 projects are gtest, gtest_lib, lib. 
1. gtest is the google test library downloaded using SVN
2. gtest_lib is a gtest test that tests the single function exposed in lib
3. lib is just a library project that contains a single fake square root function

When you build the projects, the test will be compiled into an executable that uses the gtest library, and lib library. When you run this executable it runs the test and shows you the pass/fail (assuming you Ctrl+F5 so the console doesn't go away after the executable finishes).

Some notes:
* Maybe ctest can be used so there is more integration with cmake/CI tools?
* You can turn off the tests by doing cmake -DTEST_ENABLED=OFF ..
