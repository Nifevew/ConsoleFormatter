#include "gtest/gtest.h"

#include "TextFormatting.hpp"

TEST(TextFormattingTextCustomManipSuite, OneColor)
{
  std::stringstream ss;

  ss << tf::setTextParams(tf::TextColor::RED) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[31mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, TwoColor) // но будет все равно только послдений
{
  std::stringstream ss;

  ss << tf::setTextParams(tf::TextColor::RED, tf::TextColor::GREEN) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[31;32mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, OneStyle)
{
  std::stringstream ss;

  ss << tf::setTextParams(tf::TextStyle::UNDERLINE) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[4mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, TwoStyle)
{
  std::stringstream ss;

  ss << tf::setTextParams(tf::TextStyle::UNDERLINE, tf::TextStyle::BOLD) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[4;1mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, StyleBoldBright)
{
  std::stringstream ss;

  ss << tf::setTextParams(tf::TextStyle::BOLD, tf::TextStyle::BRIGHT) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[1;1mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, StyleColor)
{
  std::stringstream ss;

  ss << tf::setTextParams(tf::TextStyle::BOLD, tf::TextColor::RED) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[1;31mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, ColorStyle)
{
  std::stringstream ss;

  ss << tf::setTextParams(tf::TextColor::RED, tf::TextStyle::BOLD) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[31;1mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}