#include "gtest/gtest.h"
#include <string>

using namespace std;


string construct_path(const string &filename)
{
    const static string examples = "examples/";
    return examples + filename;
}

extern "C" {
#include "moodfinder.h"
#include "moodfinder_errors.h"
}

TEST(find_mood_positive, clear)
{
    const string filename = "clear_positive.txt";
    ASSERT_EQ(find_mood(construct_path(filename).c_str()), POSITIVE);
}

TEST(find_mood_positive, dirty)
{
    const string filename = "dirty_positive.txt";
    ASSERT_EQ(find_mood(construct_path(filename).c_str()), POSITIVE);
}

TEST(find_mood_negative, clear)
{
    const string filename = "clear_negative.txt";
    ASSERT_EQ(find_mood(construct_path(filename).c_str()), NEGATIVE);
}

TEST(find_mood_negative, dirty)
{
    const string filename = "dirty_negative.txt";
    ASSERT_EQ(find_mood(construct_path(filename).c_str()), NEGATIVE);
}

TEST(find_mood_neutral, dirty)
{
    const string filename = "neutral.txt";
    ASSERT_EQ(find_mood(construct_path(filename).c_str()), NEUTRAL);
}

TEST(find_mood_errors, empty)
{
    const string filename = "empty.txt";
    ASSERT_EQ(find_mood(construct_path(filename).c_str()), EMPTY_FILE_ERROR);
}

TEST(find_mood_errors, not_exitsing)
{
    const string s = construct_path("not_existing.txt");
    static const char *filename = s.c_str();
    ASSERT_EQ(find_mood(filename), FILE_NOT_EXIST_ERROR);
}
