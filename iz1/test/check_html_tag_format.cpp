#include "gtest/gtest.h"
#include <cstring>

extern "C" {
#include "html_tag/html_tag.h"
}

TEST(tag_format_check_correct, simple_opening)
{
    char str[] = "<opening_tag>";
    ASSERT_EQ(check_html_tag_format(str), true);
}

TEST(tag_format_check_correct, simple_closing)
{
    char str[] = "</closing_tag>";
    ASSERT_EQ(check_html_tag_format(str), true);
}

TEST(tag_format_check_correct, opening_one_attr)
{
    char str[] = "<tag attr1=value1>";
    ASSERT_EQ(check_html_tag_format(str), true);
}

TEST(tag_format_check_correct, opening_two_attr)
{
    char str[] = "<tag attr1=value1 attr2=value2>";
    ASSERT_EQ(check_html_tag_format(str), true);
}

TEST(tag_format_check_correct, opening_two_quoted_attr)
{
    char str[] = "<tag attr1=value1 attr2=\"value2\">";
    ASSERT_EQ(check_html_tag_format(str), true);
}

TEST(tag_format_check_correct, opening_two_quoted_attr_r)
{
    char str[] = "<tag attr1=\"value1\" attr2=value2>";
    ASSERT_EQ(check_html_tag_format(str), true);
}


TEST(tag_format_check_correct, opening_two_quoted_attr_)
{
    char str[] = "<tag attr1=\"value1\" attr2=\"value2\">";
    ASSERT_EQ(check_html_tag_format(str), true);
}

TEST(tag_format_check_correct, opening_three_quoted_attr)
{
    char str[] = "<tag attr1=\"value1\" attr3=value3 attr2=\"value2\">";
    ASSERT_EQ(check_html_tag_format(str), true);
}

TEST(tag_format_check_correct, opening_three_quoted_attr_)
{
    char str[] = "<tag attr1=\"value1\" attr3=\"value3\" attr2=value2>";
    ASSERT_EQ(check_html_tag_format(str), true);
}
