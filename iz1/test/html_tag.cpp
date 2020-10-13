#include "gtest/gtest.h"
#include <cstring>

extern "C" {
#include "html_tag/tag.h"
}

TEST(tag_correct_input, no_quotes)
{
    char src[] = "<opening_tag attr1=value1>";
    char expected_name[] = "opening_tag";
    bool expected_opening = true;
    size_t expected_attr_count = 1;
    char expected_attr_names[][10] = {"attr1"};
    char expected_attr_values[][10] = {"value1"};

    html_tag *res = parse_tag(src);
    ASSERT_EQ(strcmp(res->name, expected_name), 0);
    ASSERT_EQ(res->is_opening, expected_opening);
    ASSERT_EQ(res->attributes_count, expected_attr_count);
    for (size_t i = 0; i < res->attributes_count; ++i)
    {
        ASSERT_EQ(strcmp(res->attributes[i]->name, expected_attr_names[i]), 0);
        ASSERT_EQ(strcmp(res->attributes[i]->value, expected_attr_values[i]), 0);
    }
    free_tag(&res);
}

TEST(tag_correct_input, quotes_one)
{
    char src[] = "<opening_tag attr1=\"value1\">";
    char expected_name[] = "opening_tag";
    bool expected_opening = true;
    size_t expected_attr_count = 1;
    char expected_attr_names[][10] = {"attr1"};
    char expected_attr_values[][10] = {"value1"};

    html_tag *res = parse_tag(src);
    ASSERT_EQ(strcmp(res->name, expected_name), 0);
    ASSERT_EQ(res->is_opening, expected_opening);
    ASSERT_EQ(res->attributes_count, expected_attr_count);
    for (size_t i = 0; i < res->attributes_count; ++i)
    {
        ASSERT_EQ(strcmp(res->attributes[i]->name, expected_attr_names[i]), 0);
        ASSERT_EQ(strcmp(res->attributes[i]->value, expected_attr_values[i]), 0);
    }
    free_tag(&res);
}

TEST(tag_correct_input, quotes_two)
{
    char src[] = "<opening_tag attr1=\"value1 value2\">";
    char expected_name[] = "opening_tag";
    bool expected_opening = true;
    size_t expected_attr_count = 1;
    char expected_attr_names[][20] = {"attr1"};
    char expected_attr_values[][20] = {"value1 value2"};

    html_tag *res = parse_tag(src);
    ASSERT_EQ(strcmp(res->name, expected_name), 0);
    ASSERT_EQ(res->is_opening, expected_opening);
    ASSERT_EQ(res->attributes_count, expected_attr_count);
    for (size_t i = 0; i < res->attributes_count; ++i)
    {
        ASSERT_EQ(strcmp(res->attributes[i]->name, expected_attr_names[i]), 0);
        ASSERT_EQ(strcmp(res->attributes[i]->value, expected_attr_values[i]), 0);
    }
    free_tag(&res);
}


TEST(tag_correct_input, two_attrs)
{
    char src[] = "<opening_tag attr1=\"value1 value2\" attr2=value3>";
    char expected_name[] = "opening_tag";
    bool expected_opening = true;
    size_t expected_attr_count = 2;
    char expected_attr_names[][20] = {"attr1", "attr2"};
    char expected_attr_values[][20] = {"value1 value2", "value3"};

    html_tag *res = parse_tag(src);
    ASSERT_EQ(strcmp(res->name, expected_name), 0);
    ASSERT_EQ(res->is_opening, expected_opening);
    ASSERT_EQ(res->attributes_count, expected_attr_count);
    for (size_t i = 0; i < res->attributes_count; ++i)
    {
        ASSERT_EQ(strcmp(res->attributes[i]->name, expected_attr_names[i]), 0);
        ASSERT_EQ(strcmp(res->attributes[i]->value, expected_attr_values[i]), 0);
    }
    free_tag(&res);
}

TEST(tag_correct_input, three_attrs)
{
    char src[] = R"(<opening_tag attr1="value1 value2" attr2=value3 attr3="value4">)";
    char expected_name[] = "opening_tag";
    bool expected_opening = true;
    size_t expected_attr_count = 3;
    char expected_attr_names[][20] = {"attr1", "attr2", "attr3"};
    char expected_attr_values[][20] = {"value1 value2", "value3", "value4"};

    html_tag *res = parse_tag(src);
    ASSERT_EQ(strcmp(res->name, expected_name), 0);
    ASSERT_EQ(res->is_opening, expected_opening);
    ASSERT_EQ(res->attributes_count, expected_attr_count);
    for (size_t i = 0; i < res->attributes_count; ++i)
    {
        ASSERT_EQ(strcmp(res->attributes[i]->name, expected_attr_names[i]), 0);
        ASSERT_EQ(strcmp(res->attributes[i]->value, expected_attr_values[i]), 0);
    }
    free_tag(&res);
}


TEST(tag_correct_input, closing)
{
    char src[] = "</closing_tag>";
    char expected_name[] = "closing_tag";
    bool expected_opening = false;
    size_t expected_attr_count = 0;

    html_tag *res = parse_tag(src);
    ASSERT_EQ(strcmp(res->name, expected_name), 0);
    ASSERT_EQ(res->is_opening, expected_opening);
    ASSERT_EQ(res->attributes_count, expected_attr_count);
    free_tag(&res);
}
