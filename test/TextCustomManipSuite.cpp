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

TEST(TextFormattingTextCustomManipSuite, OneBackground)
{
  std::stringstream ss;

  ss << tf::setTextParams(tf::BackgroundColor::BLUE) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[44mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, TwoBackground)
{
  std::stringstream ss;

  ss << tf::setTextParams(tf::BackgroundColor::BLUE, tf::BackgroundColor::WHITE) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[44;47mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, One256Color)
{
  std::stringstream ss;

  ss << tf::setTextParams(1) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[38;5;1mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, Two256Color)
{
  std::stringstream ss;

  ss << tf::setTextParams(45, 66) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[38;5;45;38;5;66mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, One256BgColor)
{
  std::stringstream ss;

  ss << tf::setTextParams(-1) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[48;5;1mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, Two256BgColor)
{
  std::stringstream ss;

  ss << tf::setTextParams(-45, -66) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[48;5;45;48;5;66mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, BgAndText256Color)
{
  std::stringstream ss;

  ss << tf::setTextParams(-45, 66) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[48;5;45;38;5;66mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, TextAndBg256Color)
{
  std::stringstream ss;

  ss << tf::setTextParams(45, -66) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[38;5;45;48;5;66mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST (TextFormattingTextCustomManipSuite, ThreeParams)
{
  std::stringstream ss;

  ss << tf::setTextParams(tf::BackgroundColor::BLUE, tf::BackgroundColor::WHITE, tf::TextStyle::ITALIC) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[44;47;3mTEST_TEXT" };

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

TEST(TextFormattingTextCustomManipSuite, StyleColorBackground)
{
  std::stringstream ss;

  ss << tf::setTextParams(tf::TextStyle::BOLD, tf::TextColor::RED, tf::BackgroundColor::CYAN) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[1;31;46mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, BackgroundColorStyle)
{
  std::stringstream ss;

  ss << tf::setTextParams(tf::BackgroundColor::MAGENTA, tf::TextColor::RED, tf::TextStyle::BOLD) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[45;31;1mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, ColorBackgroundStyle)
{
  std::stringstream ss;

  ss << tf::setTextParams( tf::TextColor::RED, tf::BackgroundColor::YELLOW, tf::TextStyle::BOLD) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[31;43;1mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, Color256BackgroundStyle)
{
  std::stringstream ss;

  ss << tf::setTextParams( 3, tf::BackgroundColor::YELLOW, tf::TextStyle::BOLD) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[38;5;3;43;1mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, Background256ColorStyle)
{
  std::stringstream ss;

  ss << tf::setTextParams(tf::BackgroundColor::YELLOW, 3, tf::TextStyle::BOLD) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[43;38;5;3;1mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, BackgroundStyle256Color)
{
  std::stringstream ss;

  ss << tf::setTextParams(tf::BackgroundColor::YELLOW, tf::TextStyle::BOLD, 3) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[43;1;38;5;3mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}

TEST(TextFormattingTextCustomManipSuite, BgAndText256ColorStyle)
{
  std::stringstream ss;

  ss << tf::setTextParams(-54, 43, tf::TextStyle::ITALIC) << "TEST_TEXT";
  std::string test_str { ss.str() };

  std::string true_str { "\x1b[48;5;54;38;5;43;3mTEST_TEXT" };

  EXPECT_EQ(test_str, true_str);
}