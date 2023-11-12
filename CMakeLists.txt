cmake_minimum_required(VERSION 3.10)
project(Ps_Group11_Assignment1 VERSION 1.0)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 如果你的项目中有头文件，请在这里添加对应的目录
# include_directories(include)

# 添加主程序的可执行文件，这里使用 'gs.cpp' 作为源文件
add_executable(${PROJECT_NAME} gs.cpp)

# 添加 Google Test 子目录，以便可以使用 Google Test
# 假设 Google Test 的源码在 'googletest/' 子目录中
add_subdirectory(googletest)

# 包含 Google Test 的头文件
include_directories(googletest/include)

# 创建一个名为 'Test2' 的测试可执行文件
# 'test2.cpp' 应包含你的测试代码，确保这个文件存在
add_executable(Test2 test2.cpp)

# 链接 Google Test 库到你的测试可执行文件 'Test2'
target_link_libraries(Test2 gtest gtest_main)

# 启用测试功能
enable_testing()

# 添加测试用例，告诉 CMake 如何运行你的测试
add_test(NAME Test2 COMMAND Test2)