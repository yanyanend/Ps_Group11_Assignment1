//
// Created by YuboXu on 14/11/2023.
//

#include "gs.h"
#include <gtest/gtest.h>

TEST(GrayScott_GoogleTest, parametertype_check) {
    /*
     *  Test 1：
     *  Check that the type of the model parameters (F, k) matches that of the element type of the u and v vectors.
     */

    std::cout << "Test 1 Running..." << std::endl;

    // Check that the type of (F, k)
    std::cout << "The type of 'F' is : " << typeid(F).name() << std::endl;
    std::cout << "The type of 'k' is : " << typeid(k).name() << std::endl;
    ASSERT_TRUE((std::is_same<decltype(F), double>::value));
    ASSERT_TRUE((std::is_same<decltype(k), double>::value));

    // Check that the element type of the u and v vectors.
    std::cout << "The type of 'u([0][0])' is : " << typeid(decltype(u[0][0])).name() << std::endl;
    std::cout << "The type of 'v([0][0])' is : " << typeid(decltype(v[0][0])).name() << std::endl;
    ASSERT_TRUE(typeid(F).name() == typeid(decltype(u[0][0])).name() &&
    typeid(k).name() == typeid(decltype(v[0][0])).name());

    std::cout << "Test 1 Passed!" << std::endl;
}

TEST(GrayScott_GoogleTest, uv_check_size) {
    /*
     *  Test 2:
     *  Check that the variables u and v are the same size.
     */
    std::cout << "Test 2 Running..." << std::endl;

    // Check if both u and v have the same number of rows
    std::cout << "The u.size() is : " << u.size() << std::endl;
    std::cout << "The v.size() is : " << v.size() << std::endl;
    EXPECT_EQ(u.size(), v.size());

    for (int i = 0; i < u.size(); i++){
        // Check if each corresponding row in u and v have the same number of elements
        EXPECT_EQ(u[i].size(), v[i].size());
    }
    std::cout << "Test 2 Passed!" << std::endl;
}

TEST(GrayScott_GoogleTest, uv_both_zero) {
    /*
     *  Test 3:
     *  Check that the simulation produces the mathematically correct answer when u = 0 and v = 0.
     */
    std::cout << "Test 3 Running..." << std::endl;

    // Initialize u and v to 0
    std::cout << "Setting u = 0 and v = 0..." << std::endl;
    for (auto &row : u) std::fill(row.begin(), row.end(), 0.0);
    for (auto &row : v) std::fill(row.begin(), row.end(), 0.0);
    std::cout << "Finished." << std::endl;

    std::cout << "simulateStep() Running..." << std::endl;
    simulateStep();
    std::cout << "Finished." << std::endl;

    std::cout << "Check that the simulation produces the mathematically correct answer when u = 0 and v = 0..." << std::endl;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            EXPECT_EQ(u[x][y], 0.0);
            EXPECT_EQ(u[x][y], 0.0);
        }
    }
    std::cout << "Finished." << std::endl;
    std::cout << "Test 3 Passed!" << std::endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
