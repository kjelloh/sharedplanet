# Todo: Programming - Consider to understand Clion project model (created files, Cmake binds, folder structure)?

```#311e5e94``` *As of 2016-07-25 16:35*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to understand how Clion IDE defines a project in terms of what tool-chains it binds to, how it configures CMake to use them and the files and folders it creates for the project?

1) Consider to study the contents of created project “C:\\Users\\kjell-olovhogdahl\\ClionProjects\\Trudelutt”

==&gt; NOTE: The root folder “C:\\Users\\kjell-olovhogdahl\\ClionProjects\\” is not readily visible in Windows explorer (e.g., it is not in exposed Documents folder)?

==&gt; It seems CLion does not polite the project location with any Cmake generator output nor build binaries?

> Kjell-Olovs-MacBook-Pro:Trudelutt kjell-olovhogdahl$ pwd  
> /Volumes/C/Users/kjell-olovhogdahl/ClionProjects/Trudelutt  
> Kjell-Olovs-MacBook-Pro:Trudelutt kjell-olovhogdahl$ tree  
> .  
> ├── CMakeLists.txt  
> └── main.cpp

> 0 directories, 2 files  
> Kjell-Olovs-MacBook-Pro:Trudelutt kjell-olovhogdahl$

…

2) It seems to create a hidden folder .ideas in which it stores project files as xml?

==&gt; It suggests adding ./.ideas/vcs.xml to version control (required to pass Clion project between Git repositories?

==&gt; No, It seems just passing ./.ideas/vcs.xml is NOT sufficient (hen tested it fails to understand the project if the other xml-files was not present)?

...

…

Consider to delve into the “world of Clion” to understand how it interacts with local files and code?

{% endraw %}
