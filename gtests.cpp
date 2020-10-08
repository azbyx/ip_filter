#include "ip_filter.h"
#include <gtest/gtest.h>
#include <vector>


TEST(split_string, without_TAB) {

    // Arrange
    std::string str{""};

    // Act (empty for this test)
    std::vector<std::string> keeper = split(str);

    // Assert
    ASSERT_EQ(keeper.size(), 1);

}

TEST(split_string, one_TAB) {

    // Arrange
    std::string keeper{"1\t2"};

    // Act (empty for this test)
    std::vector<std::string> keeper = split(str);

    // Assert
    ASSERT_EQ(keeper.size(), 2);

}

TEST(split_string, two_TAB) {

    // Arrange
    std::string keeper{"1\t2\tnexttxt"};

    // Act (empty for this test)
    std::vector<std::string> keeper = split(str);

    // Assert
    ASSERT_EQ(keeper.size(), 3);

}

TEST(split_string, more_than_two_TAB) {

    // Arrange
    std::string keeper{"1\t2\tn\ne\tx\tt\nt\vx\tt"};

    // Act (empty for this test)
    std::vector<std::string> keeper = split(str);

    // Assert
    ASSERT_EQ(keeper.size(), 6);

}

int main(int argc, char** argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
