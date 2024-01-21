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
concept IsTextColor = std::same_as<std::remove_cvref_t<T>, tf::TextColor>;

template<typename T>
concept IsTextStyle = std::same_as<std::remove_cvref_t<T>, tf::TextStyle>;

template<typename T>
concept IsBackgroundColor = std::same_as<std::remove_cvref_t<T>, tf::BackgroundColor>;

template<typename T>
concept IsEnums = (IsTextColor<T> || IsTextStyle<T> || IsBackgroundColor<T>);

template<typename T>
concept Is256Color = std::signed_integral<T>;

template<typename... Args>
concept ParamsRequires = ((IsEnums<Args> || Is256Color<Args>) && ...);

template<typename T>
requires ParamsRequires<T>
std::string makeParams(const T& param)
{
  const std::string k256ColorTextCode = "38;5;";
  const std::string k256ColorBgCode = "48;5;";

  std::string result;

  if (IsEnums<decltype(param)>)
    result += std::to_string(static_cast<int>(param));
  else if (static_cast<int>(param) > 0)
    result += k256ColorTextCode + std::to_string(static_cast<int>(param));
  else
    result += k256ColorBgCode + std::to_string(static_cast<int>(param) * -1);

  return result;
}

template<typename T, typename... Ts>
requires ParamsRequires<T> && ParamsRequires<Ts...>
std::string makeParams(const T& param, const Ts &... params)
{
  auto out = makeParams(param) + ';';
  out += makeParams(params...) + ';';

  out.pop_back();
  return out;
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
