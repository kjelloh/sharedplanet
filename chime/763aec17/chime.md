# Todo: Elm - Consider to install and play with the Elm language to get a grip of how it works and what we can do with it?

```#763aec17``` *As of 2017-02-19 18:34*

[mail plain/text](mail.txt)

{% raw %}
Consider it would be good idea to install and play with the Elm language to be able to play with it and understand what we can use it for?

-3) Consider to start of with the recommended elm examples at Github (<https://github.com/evancz/elm-architecture-tutorial>)?

> Kjell-Olovs-MacBook-Pro:~ kjell-olovhogdahl$ cd Documents/  
> Kjell-Olovs-MacBook-Pro:Documents kjell-olovhogdahl$ cd GitHub/  
> Kjell-Olovs-MacBook-Pro:GitHub kjell-olovhogdahl$ **git clone <https://github.com/evancz/elm-architecture-tutorial.git>**  
> Cloning into 'elm-architecture-tutorial'...  
> remote: Counting objects: 649, done.  
> remote: Total 649 (delta 0), reused 0 (delta 0), pack-reused 649  
> Receiving objects: 100% (649/649), 335.08 KiB | 559.00 KiB/s, done.  
> Resolving deltas: 100% (385/385), done.  
> Kjell-Olovs-MacBook-Pro:GitHub kjell-olovhogdahl$ cd elm-architecture-tutorial/  
> Kjell-Olovs-MacBook-Pro:elm-architecture-tutorial kjell-olovhogdahl$ **pwd**  
> **/Users/kjell-olovhogdahl/Documents/GitHub/elm-architecture-tutorial**  
> Kjell-Olovs-MacBook-Pro:elm-architecture-tutorial kjell-olovhogdahl$ **ls**  
> LICENSE elm-package.json  
> README.md **examples**  
> Kjell-Olovs-MacBook-Pro:elm-architecture-tutorial kjell-olovhogdahl$

-2) It seems an easy way to compile and run elm-programs (files) is by “browsing” elm-files through a localhost web-server called elm-rector?

==&gt; The Elm-reactor seems to be explained here (<https://github.com/elm-lang/elm-reactor>)?

==&gt; It seems to be started with the installed command line elm-reactor?

> “  
> *In the root of your Elm project start the reactor with:

> **&gt;elm-reactor***

> *Now **open <http://localhost:8000> in your browser.** You should see a navigation page for your project.

> **Click on any file to see what it looks like**. For example, you can navigate to an Elm file like examples/1-button.elm and try it out. If you modify the file, you can just refresh that page and see the new version!*"

==&gt; It seems work just fine for the recommended elm examples?

> Kjell-Olovs-MacBook-Pro:elm-architecture-tutorial kjell-olovhogdahl$ pwd  
> /Users/kjell-olovhogdahl/Documents/GitHub/elm-architecture-tutorial  
> Kjell-Olovs-MacBook-Pro:elm-architecture-tutorial kjell-olovhogdahl$ ls  
> LICENSE elm-package.json  
> README.md examples  
> Kjell-Olovs-MacBook-Pro:elm-architecture-tutorial kjell-olovhogdahl$ cd examples  
> Kjell-Olovs-MacBook-Pro:examples kjell-olovhogdahl$ elm-reactor  
> elm-reactor 0.18.0  
> Listening on <http://localhost:8000>

==&gt; And opening the web-browser to localhost:8000 seems to show the content of the examples folder?

![](<elm-reactor view of elm-architecture-tutorial.tiff>)

==&gt; It seems, when an elm-file is opened by el-reacor, then elm-reactor automatically downloads and updates the build environment and then compiles and runs the elm-file and render it into the web window?

...

-1) Consider to install Elm on my Apple Macbook Pro 15” MAC OS?

==&gt; Elm for MAC OS seems to be available here (<https://guide.elm-lang.org/install.html>)?

==&gt; Elm for MAC OS seems to be distributed as installable package that installs to “/usr/local/bin/“?

![](<Elm MAC OS Install Greeting Window.tiff>)

![](<Elm Install Success Window.tiff>)

==&gt; Elm seems to be a small set of command line tools?

> “  
> *After installing through any of those routes, you will have the following command line tools:

> *  
> *• elm-repl — play with Elm expressions  
> *  
> *• elm-reactor — get a project going quickly  
> *  
> *• elm-make — compile Elm code directly  
> *  
> *• elm-package — download packages  
> *

> "

0) Elm seems to live here (<http://elm-lang.org>)?

{% endraw %}
