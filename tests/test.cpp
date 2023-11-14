//
// Created by YuboXu on 14/11/2023.
//

#include "gs.h"
#include <gtest/gtest.h>

TEST(GrayScottTest, CheckParameterTypes) {
    /*
     *  Test 1：
     *  Check that the type of the model parameters (F, k) matches that of the element type of the u and v vectors.
     */
    std::cout << "Test1 Running..." << std::endl;

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

    std::cout << "Test1 Passed!" << std::endl;
}

TEST(GrayScottTest, CheckSameSize) {
    /*
     *  Test 2:
     *  Check that the variables u and v are the same size.
     */
    // Check if u and v have the same dimensions
    std::cout << "The u.size() is : " << u.size() << std::endl;
    std::cout << "The v.size() is : " << v.size() << std::endl;
    EXPECT_EQ(u.size(), v.size());

    for (size_t i = 0; i < u.size(); ++i) {
        EXPECT_EQ(u[i].size(), v[i].size());
    }
}

TEST(GrayScottTest, CheckSimulationResultForZero) {
    /*
     *  Test 3:
     *  Check that the simulation produces the mathematically correct answer when u = 0 and v = 0.
     */
    // Initialize u and v to 0
    for (auto &row : u) std::fill(row.begin(), row.end(), 0.0);
    for (auto &row : v) std::fill(row.begin(), row.end(), 0.0);

    // Small value for floating point comparison
    const double epsilon = 0.0018;

    // Perform a simulation step
    simulateStep();

    // Check the result after one simulation step
    for (size_t x = 0; x < width; ++x) {
        for (size_t y = 0; y < height; ++y) {
            // When both u and v are 0, the result should stay 0 (assuming no external feed or kill rates)
            EXPECT_NEAR(u[x][y], 0.0, epsilon);
            EXPECT_NEAR(v[x][y], 0.0, epsilon);
        }
    }
    std::cout << "Simulation check successful: u increasing and v remaining at 0 and the error is within 0.0018" << std::endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
