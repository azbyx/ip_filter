#include "ip_filter.h"
#include <gtest/gtest.h>
#include <vector>


TEST(ip_filter, Empty) {

    // Arrange

    int i = 1;

    // Act (empty for this test)

    // Assert

    ASSERT_EQ(i, 1);

}

int main(int argc, char** argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
