#include "gtest/gtest.h"
#include <string>
#include <sstream>

using namespace std;


string construct_path(const string &filename)
{
    const static string examples = "./examples/";
    return examples + filename;
}

extern "C" {
#include "moodfinder.h"
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

