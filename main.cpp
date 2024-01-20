#include <iostream>

#include <sstream>

#include "./include/TextFormatting.hpp"

int main()
{
  std::cout << tf::TextColor::RED << tf::TextStyle::BOLD << "TEST_TEXT" << std::endl;
  std::cout << tf::TextStyle::RESET << tf::TextColor::DEFAULT;
  std::cout << tf::setTextParams(tf::TextColor::GREEN, tf::TextStyle::UNDERLINE, tf::TextStyle::BOLD) << "TEST_TEXT" << std::endl;


  std::cout << tf::TextStyle::BOLD << "BOLD_TEXT\n";
  std::cout << tf::TextStyle::RESET;

  std::cout << tf::TextStyle::DIM << "DIM_TEXT\n";
  std::cout << tf::TextStyle::RESET;

  std::cout << tf::TextStyle::ITALIC << "ITALIC_TEXT\n";
  std::cout << tf::TextStyle::RESET;

  std::cout << tf::TextStyle::UNDERLINE << "UNDERLINE_TEXT\n";
  std::cout << tf::TextStyle::RESET;

  std::cout << tf::TextStyle::BLINKING << "BLINKING_TEXT\n";
  std::cout << tf::TextStyle::RESET;

  std::cout << tf::TextStyle::INVERSE << "INVERSE_TEXT\n";
  std::cout << tf::TextStyle::RESET;

  std::cout << tf::TextStyle::HIDDEN << "HIDDEN_TEXT\n";
  std::cout << tf::TextStyle::RESET;

  std::cout << tf::TextStyle::STRIKETHROUGH << "STRIKETHROUGH_TEXT\n";
  std::cout << tf::TextStyle::RESET;

  std::cout << tf::setTextParams(tf::TextStyle::ITALIC, tf::TextColor::GREEN, tf::BackgroundColor::BLUE) << "TEST_TEXT\n";

  return 0;
}
