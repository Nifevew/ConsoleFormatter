#include <iostream>

#include <sstream>

#include "./include/TextFormatting.hpp"

int main()
{
  std::cout << tf::TextColor::RED << tf::TextStyle::BOLD << "TEST_TEXT" << std::endl;
  std::cout << tf::TextStyle::DEFAULT << tf::TextColor::DEFAULT;
  std::cout << tf::setTextParams(tf::TextColor::GREEN, tf::TextStyle::UNDERLINE, tf::TextStyle::BOLD) << "TEST_TEXT" << std::endl;

  return 0;
}
