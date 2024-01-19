//
// Created by maxya on 19.01.2024.
//

#ifndef CONSOLE_FORMATTER_INCLUDE_TEXTFORMATTING_HPP_
#define CONSOLE_FORMATTER_INCLUDE_TEXTFORMATTING_HPP_

#include <iostream>
#include <string>

namespace tf
{

//enum class Sequences
//{
//  ESC = 27
//};

const std::string ESC = "\x1b";

enum class TextStyle
{
  DEFAULT = 0,

  BOLD = 1,
  BRIGHT = 1,
  NO_BOLD = 22,
  NO_BRIGHT = 22,

  UNDERLINE = 4,
  NO_UNDERLINE = 24,

  NEGATIVE = 7,
  NO_NEGATIVE = 27
};

inline std::ostream& operator<<(std::ostream& out, TextStyle&& ts)
{
  out << ESC
    << '['
    << std::to_string(static_cast<int>(ts))
    << 'm';

  return out;
}

enum class TextColor
{

  BLACK = 30,
  RED = 31,
  GREEN = 32,
  YELLOW = 33,
  BLUE = 34,
  MAGENTA = 35,
  CYAN = 36,
  WHITE = 37,

  DEFAULT = 39,

  BRIGHT_BLACK = 90,
  BRIGHT_RED = 91,
  BRIGHT_GREEN = 92,
  BRIGHT_YELLOW = 93,
  BRIGHT_BLUE = 94,
  BRIGHT_MAGENTA = 95,
  BRIGHT_CYAN = 96,
  BRIGHT_WHITE = 97
};


inline std::ostream& operator<<(std::ostream& out, TextColor&& tc)
{
  out << ESC
    << '['
    << std::to_string(static_cast<int>(tc))
    << 'm';

  return out;
}

}


template<typename T>
concept IsTextColor = std::same_as<T, tf::TextColor>;

template<typename T>
concept IsTextStyle = std::same_as<T, tf::TextStyle>;

template<typename... Args>
concept ParamsRequires = ((IsTextColor<Args> || IsTextStyle<Args>) && ...);

template <typename... Ts>
requires ParamsRequires<Ts...>
std::string makeParams(Ts && ... params)
{
  std::string result;

  for (const auto& arg : {static_cast<int>(params)...})
    result += std::to_string(arg) + ";";

  result.pop_back();
  return result;
}

#endif //CONSOLE_FORMATTER_INCLUDE_TEXTFORMATTING_HPP_
