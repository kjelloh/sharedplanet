# Todo: Consider to add Lua scripting to my open source Cratchit application to expose run time operations on book keeping data

```#a7f48374``` *As of 2022-07-01 12:17*

[mail plain/text](mail.txt)

{% raw %}
It seems I can do some fun stuff by exposing Cratching functionality to the user though Lua scipting?

1) Consider this youtube video "Embedding Lua in C++ #1" as a good introduction to Lua scripting from C++ code (<https://youtu.be/4l5HdmPoynw?list=LL> )?

2) The Lua scripting language framework seems to live here on the web (<https://www.lua.org> )?

3) Consider the C++ Lua wrapper library Sol2 as presented in youtube video "CppCon 2018: JeanHeyd Meneide “Scripting at the Speed of Thought: Lua and C++ with sol3”" (<https://youtu.be/xQAmGBfKnas> )?

> sol2 is a C++ library binding to Lua. It currently supports all Lua versions 5.1+ (LuaJIT 2.0+ and MoonJIT included). sol2 aims to be easy to use and easy to add to a project. The library is header-only for easy integration with projects, and a single header can be used for drag-and-drop start up.

  
> ```
> #include <sol/sol.hpp>
> #include <cassert>

> int main() {
>     sol::state lua;
>     int x = 0;
>     lua.set_function("beep", [&x]{ ++x; });
>     lua.script("beep()");
>     assert(x == 1);
> }
> ```



4) The Lua C++ Wrapper library Sol3 (now version 3) seems to live here on Github (<https://github.com/ThePhD/sol2> )?

...

{% endraw %}
