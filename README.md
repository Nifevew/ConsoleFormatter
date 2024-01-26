# Wrapper over ANSI ESC Codes

It is a headeronly library that adds color and visual effects to text in terminals.  
Currently, the library supports only Graphics Mode and colors for Foreground and Background.

> Note: Some terminals may not support some of the graphic mode sequences.

### Output

#### operator<<

The `<<` operator is overloaded for each enumeration, so you can write like this.
```c++
std::cout << tf::TextStyle::GREEN << "GREEN_TEXT";
```


#### setTextParam

For convenience, there is a `setTextParam` output manipulator, it accepts 1+ text parameters (they are described below).
```c++
std::cout << tf::setTextParams(tf::TextStyle::BOLD) << "BOLD_TEXT";
```

If you have 2 or more text parameters, always use `setTextParams`.

> Note: if there are 2 color parameters in the parameters, then only the last one is used.  
> Example: `tf::setTextParams(tf::TextColor::YELLOW, tf::TextColor::GREEN)` the output text will be green.


#### reset

There is also a `reset` manipulator that removes all set styles.  
```c++
std::cout << tf::setTextParams(tf::TextColor::YELLOW) << "YELLOW_TEXT" << tf::reset << " DEFAULT_TEXT";
```

> Note: based on some tests, it was found out that `\n` is better to use after applying `tf::reset`.



### Graphics Mode

Enable graphics mode:
```
  tf::TextStyle::BOLD 
  tf::TextStyle::DIM
  tf::TextStyle::ITALIC
  tf::TextStyle::UNDERLINE
  tf::TextStyle::BLINKING 
  tf::TextStyle::INVERSE
  tf::TextStyle::HIDDEN 
  tf::TextStyle::STRIKETHROUGH 
```

Disable graphics mode:
```
  tf::TextStyle::NO_BOLD
  tf::TextStyle::NO_DIM
  tf::TextStyle::NO_ITALIC
  tf::TextStyle::NO_UNDERLINE
  tf::TextStyle::NO_BLINKING
  tf::TextStyle::NO_INVERSE
  tf::TextStyle::NO_HIDDEN
  tf::TextStyle::NO_STRIKETHROUGH
```

Example:
```c++
std::cout << tf::setTextParams(tf::TextStyle::BOLD) << "BOLD_TEXT" << tf::reset;
std::cout << tf::TextStyle::BLINKING << "BLINKING_TEXT" << tf::TextStyle::NO_BLINKING;
```

### Colors

#### Foreground colors

You can choose the same term (they have common meanings).
```
    tf::TextStyle::BLACK
    tf::TextStyle::RED
    tf::TextStyle::GREEN
    tf::TextStyle::YELLOW
    tf::TextStyle::BLUE
    tf::TextStyle::MAGENTA
    tf::TextStyle::CYAN
    tf::TextStyle::WHITE
```

Terminals that support the _aixterm specification_ provides bright versions of the ISO colors, without the need to use the `bold` modifier.
```
    tf::TextStyle::BRIGHT_BLACK
    tf::TextStyle::BRIGHT_RED
    tf::TextStyle::BRIGHT_GREEN
    tf::TextStyle::BRIGHT_YELLOW
    tf::TextStyle::BRIGHT_BLUE
    tf::TextStyle::BRIGHT_MAGENTA
    tf::TextStyle::BRIGHT_CYAN
    tf::TextStyle::BRIGHT_WHITE
```

To disable the color, use `tf::textColor::DEFAULT` or `tf::reset` for the `<<` operator.

Example:
```c++
std::cout << tf::setTextParams(tf::TextStyle::BLACK) << "BLACK_TEXT" << tf::reset;
std::cout << tf::TextStyle::BRIGHT_GREEN << "BRIGHT_GREEN_TEXT" << tf::TextStyle::DEFAULT;
```


#### Background colors

Similarly to `textColor`, you can use colors for the Background.
```
    tf::BackgroundColor::BLACK
    tf::BackgroundColor::RED
    tf::BackgroundColor::GREEN
    tf::BackgroundColor::YELLOW
    tf::BackgroundColor::BLUE
    tf::BackgroundColor::MAGENTA
    tf::BackgroundColor::CYAN
    tf::BackgroundColor::WHITE
```

And bright version
```
    tf::BackgroundColor::BRIGHT_BLACK
    tf::BackgroundColor::BRIGHT_RED
    tf::BackgroundColor::BRIGHT_GREEN
    tf::BackgroundColor::BRIGHT_YELLOW
    tf::BackgroundColor::BRIGHT_BLUE
    tf::BackgroundColor::BRIGHT_MAGENTA
    tf::BackgroundColor::BRIGHT_CYAN
    tf::BackgroundColor::BRIGHT_WHITE
```

To disable the background color, use `tf::BackgroundColor::DEFAULT` or `tf::reset` for the `<<` operator.

Example:
```c++
std::cout << tf::setTextParams(tf::BackgroundColor::GREEN) << "TEXT_ON_GREEN_BACKGROUND" << tf::reset;
std::cout << tf::BackgroundColor::BRIGHT_MAGENTA << "TEXT_ON_BRIGHT_MAGENTA_BACKGROUND" << tf::BackgroundColor::DEFAULT;
```

#### 256 colors

The terminals also support 8-bit colors (256 Colors [0-255]). The `setTextParam` manipulator is used for this.  
To set the foreground color, the colors are defined as **positive**, to set the background color, the same color values are used, but **negative**.

Example:
```c++
std::cout << tf::setTextParams(45) << "FOR_FOREGROUND" << tf::reset;
std::cout << tf::setTextParams(-45) << "FOR_BACKGROUND" << tf::reset;
```


### Demo

Using cmake, you can build a demo code.

```commandline
mkdir build 
cd ./build
cmake ..
cmake --build . --target console_formatter
```