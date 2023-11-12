//(0.2) Check that the variables u and v are the same size.

#include <gtest/gtest.h>
#include "gs.cpp" // 假设 gs.cpp 包含了上述的代码

TEST(GrayScottTest, TestUVSameSize) {
    init();

    // check rows
    ASSERT_EQ(u.size(), v.size()) << "u and v vectors have different number of rows.";

    // check units
    for (size_t i = 0; i < u.size(); ++i) {
        ASSERT_EQ(u[i].size(), v[i].size()) << "Unit " << i << " of u and v vectors have different sizes.";
    }
}

// 主函数
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
