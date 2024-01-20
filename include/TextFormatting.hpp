//
// Created by maxya on 19.01.2024.
//

#ifndef CONSOLE_FORMATTER_INCLUDE_TEXTFORMATTING_HPP_
#define CONSOLE_FORMATTER_INCLUDE_TEXTFORMATTING_HPP_

#include <iostream>
#include <string>


namespace tf
{

const std::string ESC = "\x1b";

enum class TextStyle
{

  RESET = 0,

  BOLD = 1,
  DIM = 2,
  ITALIC = 3,
  UNDERLINE = 4,
  BLINKING = 5,
  INVERSE = 7,
  HIDDEN = 8,
  STRIKETHROUGH = 9,

  NO_BOLD = 21,
  NO_DIM = 22,
  NO_ITALIC = 23,
  NO_UNDERLINE = 24,
  NO_BLINKING = 25,
  NO_INVERSE = 27,
  NO_HIDDEN = 28,
  NO_STRIKETHROUGH = 29

};


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

enum class BackgroundColor
{

  BLACK = 40,
  RED = 41,
  GREEN = 42,
  YELLOW = 43,
  BLUE = 44,
  MAGENTA = 45,
  CYAN = 46,
  WHITE = 47,

  DEFAULT = 49,

  BRIGHT_BLACK = 100,
  BRIGHT_RED = 101,
  BRIGHT_GREEN = 102,
  BRIGHT_YELLOW = 103,
  BRIGHT_BLUE = 104,
  BRIGHT_MAGENTA = 105,
  BRIGHT_CYAN = 106,
  BRIGHT_WHITE = 107

};


template<typename T>
concept IsTextColor = std::same_as<T, tf::TextColor>;

template<typename T>
concept IsTextStyle = std::same_as<T, tf::TextStyle>;

template<typename T>
concept IsBackgroundColor = std::same_as<T, tf::BackgroundColor>;

template<typename... Args>
concept ParamsRequires = ((IsTextColor<Args> || IsTextStyle<Args> || IsBackgroundColor<Args>) && ...);

template <typename... Ts>
requires ParamsRequires<Ts...>
std::string makeParams(const Ts &... params)
{
  std::string result;

  for (const auto& arg : {static_cast<int>(params)...})
    result += std::to_string(arg) + ";";

  result.pop_back();
  return result;
}

inline std::ostream& operator<<(std::ostream& out, TextStyle&& ts)
{
  out << ESC
      << '['
      << makeParams(ts)
      << 'm';

  return out;
}

inline std::ostream& operator<<(std::ostream& out, TextColor&& tc)
{
  out << ESC
    << '['
    << makeParams(tc)
    << 'm';

  return out;
}


//  Кастомный манипулятор вывода
template<typename... Ts>
struct TextParamManip
{
  explicit TextParamManip(const Ts &... params)
  { this->params = makeParams(params...); }

  std::string params;
};

template<typename... Ts>
inline TextParamManip<Ts...> setTextParams(const Ts &... params) noexcept
{
  return TextParamManip(params...);
}

template<typename... Ts>
inline std::ostream& operator<<(std::ostream& out, const TextParamManip<Ts...>& t_params)
{
  out << ESC
      << '['
      << t_params.params
      << 'm';

  return out;
}

}

#endif //CONSOLE_FORMATTER_INCLUDE_TEXTFORMATTING_HPP_
