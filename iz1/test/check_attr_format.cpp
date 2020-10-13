#include "gtest/gtest.h"
#include <cstring>

extern "C" {
#include "html_tag/attr.h"
}

TEST(format_checker_correct, test1)
{
    char str[] = "attr1=value1 ";
    size_t attr_end;
    ASSERT_EQ(check_attr_format(str, &attr_end), true);
}

TEST(format_checker_correct, test2)
{
    char str[] = "attr1=\"value1\" ";
    size_t attr_end;
    ASSERT_EQ(check_attr_format(str, &attr_end), true);
}

TEST(format_checker_correct, test3)
{
    char str[] = "attr1=\"value1 value2\" ";
    size_t attr_end;
    ASSERT_EQ(check_attr_format(str, &attr_end), true);
}


TEST(format_checker_correct, test1_last)
{
    char str[] = "attr1=value1>";
    size_t attr_end;
    ASSERT_EQ(check_attr_format(str, &attr_end), true);
}

TEST(format_checker_correct, test2_last)
{
    char str[] = "attr1=\"value1\">";
    size_t attr_end;
    ASSERT_EQ(check_attr_format(str, &attr_end), true);
}

TEST(format_checker_correct, test3_last)
{
    char str[] = "attr1=\"value1 value2\">";
    size_t attr_end;
    ASSERT_EQ(check_attr_format(str, &attr_end), true);
}

TEST(format_checker_incorrect, random_word)
{
    char str[] = "random_word";
    size_t attr_end;
    ASSERT_EQ(check_attr_format(str, &attr_end), false);
}

TEST(format_checker_incorrect, space_before_eq)
{
    char str[] = "word attr=val";
    size_t attr_end;
    ASSERT_EQ(check_attr_format(str, &attr_end), false);
}
