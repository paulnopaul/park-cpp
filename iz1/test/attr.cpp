#include "gtest/gtest.h"
#include <cstring>

extern "C" {
#include "html_tag/attr.h"
}

TEST(correct_input, no_quotes)
{
    char correct_name[] = "attr1";
    char correct_value[] = "value1";
    char line[] = "attr1=value1";
    int attr_end = 0;
    tag_attr *attr = parse_attr(line, &attr_end);
    ASSERT_EQ(strcmp(attr->name, correct_name), 0);
    ASSERT_EQ(strcmp(attr->value, correct_value), 0);
    free_attr(attr);
}

TEST(correct_input, quotes_one)
{
    char correct_name[] = "attr1";
    char correct_value[] = "value1";
    char line[] = "attr1=\"value1\"";
    int attr_end = 0;
    tag_attr *attr = parse_attr(line, &attr_end);
    ASSERT_EQ(strcmp(attr->name, correct_name), 0);
    ASSERT_EQ(strcmp(attr->value, correct_value), 0);
    free_attr(attr);
}

TEST(correct_input, quotes_two)
{
    char correct_name[] = "attr1";
    char correct_value[] = "value1 value2";
    char line[] = "attr1=\"value1 value2\"";
    int attr_end = 0;
    tag_attr *attr = parse_attr(line, &attr_end);
    ASSERT_EQ(strcmp(attr->name, correct_name), 0);
    ASSERT_EQ(strcmp(attr->value, correct_value), 0);
    free_attr(attr);
}
