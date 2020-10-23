#include "gtest/gtest.h"

extern "C" {
#include "header.h"
}

TEST(simple_test, test1)
{
    ASSERT_EQ(f(), 10);
}
