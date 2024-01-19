#include <sstream>

#include "gtest/gtest.h"

#include "TextFormatting.hpp"

TEST(TextFormattingTextStyleTest, BoldTest)
{
  std::stringstream ss;
  ss << tf::TextStyle::BOLD << "TEST_TEXT";

  std::string test_str { ss.str() };
  std::string true_str { "\x1b[1mTEST_TEXT" };

  testing::PrintToStringParamName();
  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextStyleTest, BrightTest)
{
  std::stringstream ss;
  ss << tf::TextStyle::BRIGHT << "TEST_TEXT";

  std::string test_str { ss.str() };
  std::string true_str { "\x1b[1mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextStyleTest, EQBoldBrightTest)
{
  std::stringstream ss;

  ss << tf::TextStyle::BOLD << "TEST_TEXT";
  std::string bold_str { ss.str() };

  ss.str("");

  ss << tf::TextStyle::BRIGHT << "TEST_TEXT";
  std::string bright_str { ss.str() };

  EXPECT_EQ(bold_str, bright_str);
}

TEST(TextFormattingTextStyleTest, NoBoldTest)
{
  std::string test_str { "TEST_TEXT\x1b[22mTEST_TEXT_2" };

  std::stringstream ss;
  ss << "TEST_TEXT" << tf::TextStyle::NO_BOLD << "TEST_TEXT_2";

  std::string true_str { ss.str() };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextStyleTest, NoBrightTest)
{
  std::string test_str { "TEST_TEXT\x1b[22mTEST_TEXT_2" };

  std::stringstream ss;
  ss << "TEST_TEXT" << tf::TextStyle::NO_BRIGHT << "TEST_TEXT_2";

  std::string true_str { ss.str() };

  EXPECT_EQ(test_str, true_str);
}