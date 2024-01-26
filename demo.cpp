#include <iostream>
#include <sstream>

#include "./include/TextFormatting.hpp"

int main()
{
  std::cout << "\t\tDemonstration of the library's operation\n";
  std::cout << tf::TextStyle::ITALIC << "Some terminals may not support some of the graphic mode or colors." << tf::reset << '\n';

  std::cout << "\nGraphics Mode [TextStyle]\n\n";

  std::cout << tf::TextStyle::BOLD          << "BOLD_TEXT"          << tf::reset << '\n';
  std::cout << tf::TextStyle::DIM           << "DIM_TEXT"           << tf::reset << '\n';
  std::cout << tf::TextStyle::ITALIC        << "ITALIC_TEXT"        << tf::reset << '\n';
  std::cout << tf::TextStyle::UNDERLINE     << "UNDERLINE_TEXT"     << tf::reset << '\n';
  std::cout << tf::TextStyle::BLINKING      << "BLINKING_TEXT"      << tf::reset << '\n';
  std::cout << tf::TextStyle::INVERSE       << "INVERSE_TEXT"       << tf::reset << '\n';
  std::cout << tf::TextStyle::HIDDEN        << "HIDDEN_TEXT"        << tf::reset << '\n';
  std::cout << tf::TextStyle::STRIKETHROUGH << "STRIKETHROUGH_TEXT" << tf::reset << '\n';

  std::cout << "\nText color [TextColor]\n\n";

  std::cout << tf::TextColor::BLACK   << "BLACK_TEXT"   << tf::reset << '\n';
  std::cout << tf::TextColor::RED     << "RED_TEXT"     << tf::reset << '\n';
  std::cout << tf::TextColor::GREEN   << "GREEN_TEXT"   << tf::reset << '\n';
  std::cout << tf::TextColor::YELLOW  << "YELLOW_TEXT"  << tf::reset << '\n';
  std::cout << tf::TextColor::BLUE    << "BLUE_TEXT"    << tf::reset << '\n';
  std::cout << tf::TextColor::MAGENTA << "MAGENTA_TEXT" << tf::reset << '\n';
  std::cout << tf::TextColor::CYAN    << "CYAN_TEXT"    << tf::reset << '\n';
  std::cout << tf::TextColor::WHITE   << "WHITE_TEXT"   << tf::reset << '\n';

  std::cout << "\nText bright color [TextColor]\n\n";

  std::cout << tf::TextColor::BRIGHT_BLACK    << "BRIGHT_BLACK_TEXT"    << tf::reset << '\n';
  std::cout << tf::TextColor::BRIGHT_RED      << "BRIGHT_RED_TEXT"      << tf::reset << '\n';
  std::cout << tf::TextColor::BRIGHT_GREEN    << "BRIGHT_GREEN_TEXT"    << tf::reset << '\n';
  std::cout << tf::TextColor::BRIGHT_YELLOW   << "BRIGHT_YELLOW_TEXT"   << tf::reset << '\n';
  std::cout << tf::TextColor::BRIGHT_BLUE     << "BRIGHT_BLUE_TEXT"     << tf::reset << '\n';
  std::cout << tf::TextColor::BRIGHT_MAGENTA  << "BRIGHT_MAGENTA_TEXT"  << tf::reset << '\n';
  std::cout << tf::TextColor::BRIGHT_CYAN     << "BRIGHT_CYAN_TEXT"     << tf::reset << '\n';
  std::cout << tf::TextColor::BRIGHT_WHITE    << "BRIGHT_WHITE_TEXT"    << tf::reset << '\n';

  std::cout << "\nBackground color [BackgroundColor]\n\n";

  std::cout << tf::BackgroundColor::BLACK   << "BLACK_BACKGROUND_TEXT"   << tf::reset << '\n';
  std::cout << tf::BackgroundColor::RED     << "RED_BACKGROUND_TEXT"     << tf::reset << '\n';
  std::cout << tf::BackgroundColor::GREEN   << "GREEN_BACKGROUND_TEXT"   << tf::reset << '\n';
  std::cout << tf::BackgroundColor::YELLOW  << "YELLOW_BACKGROUND_TEXT"  << tf::reset << '\n';
  std::cout << tf::BackgroundColor::BLUE    << "BLUE_BACKGROUND_TEXT"    << tf::reset << '\n';
  std::cout << tf::BackgroundColor::MAGENTA << "MAGENTA_BACKGROUND_TEXT" << tf::reset << '\n';
  std::cout << tf::BackgroundColor::CYAN    << "CYAN_BACKGROUND_TEXT"    << tf::reset << '\n';
  std::cout << tf::BackgroundColor::WHITE   << "WHITE_BACKGROUND_TEXT"   << tf::reset << '\n';

  std::cout << "\nBackground bright color [BackgroundColor]\n\n";

  std::cout << tf::BackgroundColor::BRIGHT_BLACK    << "BRIGHT_BACKGROUND_BLACK_TEXT"   << tf::reset << '\n';
  std::cout << tf::BackgroundColor::BRIGHT_RED      << "BRIGHT_BACKGROUND_RED_TEXT"     << tf::reset << '\n';
  std::cout << tf::BackgroundColor::BRIGHT_GREEN    << "BRIGHT_BACKGROUND_GREEN_TEXT"   << tf::reset << '\n';
  std::cout << tf::BackgroundColor::BRIGHT_YELLOW   << "BRIGHT_BACKGROUND_YELLOW_TEXT"  << tf::reset << '\n';
  std::cout << tf::BackgroundColor::BRIGHT_BLUE     << "BRIGHT_BACKGROUND_BLUE_TEXT"    << tf::reset << '\n';
  std::cout << tf::BackgroundColor::BRIGHT_MAGENTA  << "BRIGHT_BACKGROUND_MAGENTA_TEXT" << tf::reset << '\n';
  std::cout << tf::BackgroundColor::BRIGHT_CYAN     << "BRIGHT_BACKGROUND_CYAN_TEXT"    << tf::reset << '\n';
  std::cout << tf::BackgroundColor::BRIGHT_WHITE    << "BRIGHT_BACKGROUND_WHITE_TEXT"   << tf::reset << '\n';

  std::cout << "\n256 text colors\n\n";

  for(int i = 0; i < 256; ++i)
    std::cout << tf::setTextParams(i) << i << tf::reset << ((i+1) % 16 == 0? "\n" : "\t");

  std::cout << "\n256 text background colors\n\n";

  for(int i = 0; i < 256; ++i)
    std::cout << tf::setTextParams(-i) << i << tf::reset << ((i+1) % 16 == 0? "\n" : "\t");

  std::cout << "\nYou can also combine colors and graphic mods.\n\n";

  std::cout << tf::setTextParams(tf::TextColor::GREEN, tf::TextStyle::BOLD, tf::TextStyle::BLINKING) << "BOLD_AND_BLICKING_GREEEN_TEXT" << tf::reset << '\n';
  std::cout << tf::setTextParams(tf::BackgroundColor::BRIGHT_BLUE, tf::TextStyle::BOLD, tf::TextStyle::ITALIC) << "BOLD_AND_ITALIC_TEXT_ON_BRIGHT_BLUE_BACKGROUND" << tf::reset << '\n';
  std::cout << tf::setTextParams(tf::TextColor::MAGENTA, tf::TextStyle::UNDERLINE, tf::BackgroundColor::YELLOW) << "UNDERLINE_MAGENTA_TEXT_ON_YELLOW_BACKGROUND" << tf::reset << '\n';

  return 0;
}
