# Todo: C++ Elm Idiom - Consider this is actually better described as a Single Atom Architecture (Clojure and React terminology)?

```#164356bc``` *As of 2017-07-29 15:58*

[mail plain/text](mail.txt)

{% raw %}
It seems what I have been called the Elm idiom (Model update view) is perhaps better known as the Single Atom Architecture?

==&gt; Also see “Todo: Tha, Elm and Immer - Consider the C++ Immer immutable data structures based text editor "ewig" is in fact implementing the Elm model, view, update?

1) Consider the talk “C++Now 2017: Juanpe Bolivar “Postmodern Immutable Data Structures"” at 32:45 (<https://youtu.be/ZsryQp0UAC8?t=1966>)?

==&gt; He shows his text editor example that uses an immutable application state and refers to it as implemented what Clojure folks call “Single Atom Architecture)?

2) Consider to relate Elm Idiom and Single Atom Architecture terminology to Juanpe Bolivar example project “ewig” (<https://github.com/arximboldi/ewig>)?

==&gt; Note: The project seems to atomaticly download the immer project (and the —recursive flag a number of other submodules are also downloaded)?

> Kjell-Olovs-MacBook-Pro:GitHub kjell-olovhogdahl$ **git clone <https://github.com/arximboldi/ewig.git> --recursive**  
> Cloning into '**ewig**'...  
> remote: Counting objects: 482, done.  
> remote: Total 482 (delta 0), reused 0 (delta 0), pack-reused 482  
> Receiving objects: 100% (482/482), 1.84 MiB | 977.00 KiB/s, done.  
> Resolving deltas: 100% (262/262), done.  
> Submodule 'deps/immer' (<https://github.com/arximboldi/immer.git>) registered for path 'deps/immer'  
> Cloning into '/Users/kjell-olovhogdahl/Documents/GitHub/ewig/deps/immer'...  
> Submodule path 'deps/immer': checked out 'b1f458ca460f060440547dfd1e5a283620e31789'  
> **Submodule 'extra/python/lib/pybind11'** (<https://github.com/pybind/pybind11.git>) registered for path 'deps/immer/extra/python/lib/pybind11'  
> **Submodule 'tools/sinusoidal-sphinx-theme'** (<https://github.com/arximboldi/sinusoidal-sphinx-theme.git>) registered for path 'deps/immer/tools/sinusoidal-sphinx-theme'  
> Cloning into '/Users/kjell-olovhogdahl/Documents/GitHub/ewig/deps/immer/extra/python/lib/pybind11'...  
> Cloning into '/Users/kjell-olovhogdahl/Documents/GitHub/ewig/deps/immer/tools/sinusoidal-sphinx-theme'...  
> Submodule path 'deps/immer/extra/python/lib/pybind11': checked out '1eaacd19f6de9a053570c21de6d173efc2304bc2'  
> **Submodule 'tools/clang'** (<https://github.com/wjakob/clang-cindex-python3>) registered for path 'deps/immer/extra/python/lib/pybind11/tools/clang'  
> Cloning into '/Users/kjell-olovhogdahl/Documents/GitHub/ewig/deps/immer/extra/python/lib/pybind11/tools/clang'...  
> Submodule path 'deps/immer/extra/python/lib/pybind11/tools/clang': checked out '254c7a91e3c6aa254e113197604dafb443f4d429'  
> Submodule path 'deps/immer/tools/sinusoidal-sphinx-theme': checked out 'c00ae5d7a707b4381a3e100e988594ef73fa5888'  
> Kjell-Olovs-MacBook-Pro:GitHub kjell-olovhogdahl$

==&gt; Yes, if a do not provide the —recursive flag I do not get the dependencies!

> Kjell-Olovs-MacBook-Pro:GitHub kjell-olovhogdahl$ git clone <https://github.com/arximboldi/ewig.git>  
> Cloning into 'ewig'...  
> remote: Counting objects: 482, done.  
> remote: Total 482 (delta 0), reused 0 (delta 0), pack-reused 482  
> Receiving objects: 100% (482/482), 1.84 MiB | 1.17 MiB/s, done.  
> Resolving deltas: 100% (262/262), done.  
> Kjell-Olovs-MacBook-Pro:GitHub kjell-olovhogdahl$

==&gt; The ewig project seems to be a good example of how we know by the nature of the entry-point what platform and GUI we are to initiate?

> int main(int argc, char\* argv&#91;&#93;)  
> {  
> std::locale::global(std::locale(""));

> if (argc != 2) {  
> std::cerr &lt;&lt; "give me a file name" &lt;&lt; std::endl;  
> return 1;  
> }

> return **ewig::run(argv&#91;1****&#93;)**;  
> }

==&gt; Consider we should not forget that the entry-point is the one for the Application (not the User Interface)?

==&gt; Thus, ewig::run(argv&#91;1&#93;) is for execution of the whole application (including the user interface)?

==&gt; For the Single Atom Architecture this means we may define a run() to enter the run-time that is specialised for the platform and user interface we are to execute?

…

==&gt; It seems the ewig application can serve as a good clean example of the Single Atom Architecture (Elm Idiom and React design pattern)?

> int run(const char\* fname)  
> {  
> auto state = application{load_buffer(fname), key_map_emacs};  
> auto ui = tui{};  
> draw(state, ui.size());

> while (auto new_state = update(state, ui.next())) {  
> state = \*new_state;  
> draw(state, ui.size());  
> }

> return 0;  
> }

==&gt; The update() method maps exactly to the Elm idiom update: Msg -&gt; Model -&gt; Model (Here update(state, ui.next())

==&gt; Note hos the ui object here is polled for user action messages (instead of being asychronous events on a message queue)?

==&gt; What in ewig application is called draw is in fact exactly what in Elm is called update: Model -&gt; View (Here the draw method wraps the whole view_port so no View object per-se is created)?

==&gt; Consider what the code would look like if we separate an actual update method from the draw method?

> while (auto new_state = update(state, ui.next())) {  
> state = \*new_state;  
> **auto new_view = view(state);**  
> **draw(new_view);**  
> }

==&gt; Consider what the code could look like if we made the project cross platform supporting platform specific draw methods?

> namespace detail {

> template &lt;typename **View**, typename **DrawFn**&gt;  
> int run(const char\* fname, DrawFn&& draw)  
> {  
> auto state = application{load_buffer(fname), key_map_emacs};  
> auto ui = tui{};  
> draw(state, ui.size());

> while (auto new_state = update(state, ui.next())) {  
> state = \*new_state;  
> draw(state, ui.size());  
> }

> return 0;  
> }  
> }

> int run(const char\* fname)  
> {  
> return detail::**run&lt;tui&gt;(fname,draw****)**;  
> }

==&gt; In this way we can specialise the View object type and the draw function for the run-time?

…

3) Consider to understand Facebooks React idiom as a Single Atom Architecture (<https://facebook.github.io/react/>)?

==&gt; Hm…it seems evident that Elm has more or less copied the design of React (<https://facebook.github.io/react/tutorial/tutorial.html>)?

==&gt; React uses a render method to generate HTML code from a state (Elm uses an update method to generate an HTML object from model)?

…

==&gt; It seems Redux is one of many Html render frameworks that works well with React-like javascript frameworks (<http://redux.js.org/docs/basics/UsageWithReact.html>)?

> “*That said, Redux works especially well with libraries like React and Deku because they let you describe UI as a function of state, and Redux emits state updates in response to actions.*"

4) Consider to study Clojure OM library (clojure Facebook react wrapper) to get insights into the Single Atom Arhictecture and UI design (<https://github.com/omcljs/om>)?

…

5) Consider A Single Atom Architecture is related to what is called an Immutable User Interface?

==&gt; Consider this talk “Immutable User Interfaces (Lee Byron) - Full Stack Fest 2016” has having good leads into JavaScript immutable (Elm, React) user interfaces (<https://www.youtube.com/watch?v=pLvrZPSzHxo>)?

==&gt; Lee Byron seems to be the developer of immutable.js (<https://facebook.github.io/immutable-js/>)?

==&gt; Also see “Todo: Darwinet - Consider Javascript React with immutable.js or Mori actually kind-of already implemented Darwinet immutable MIV and delta history mechanisms?"

==&gt; Also see “Todo: ibi library key path - Consider to enable easy construction of Tries (Index and hash) with corresponding key-path support for member reference? “

==&gt; He seems to stress the point of designing UIs on immutable state instead of MVC and REST idioms at about 10:45 (<https://youtu.be/pLvrZPSzHxo?t=647>)?

==&gt; He seems to call the idiom “Immutable App Architecture”?

**==&gt; He actually (at 11:30) state that it was Elm that inspired React!!**

==&gt;

6) Consider that Elm actually proceeded React, Redux and other Immutable Application frameworks?

==&gt; Consider 11:30 into “Immutable User Interfaces (Lee Byron) - Full Stack Fest 2016” has having good leads into JavaScript immutable (Elm, React) user interfaces (<https://www.youtube.com/watch?v=pLvrZPSzHxo>)?

==&gt; Consider this blog-post that seems to state this (<https://medium.com/javascript-inside/what-if-react-was-really-only-the-v-in-mvc-5854fd6f601c>)?

==&gt; This talk seems to be on youtube here (<https://www.youtube.com/watch?v=e56pm2xN00k>)?

==&gt; This talk seems to present some quotes from earlier developers that inspired the immutable application and view of its state?

...

==&gt; Consider the javascript elmar.js that seems to mimic Elm view part (<https://github.com/steos/elmar.js/tree/master>)?

==&gt; And a corresponding blog-post abut elmar and Elm idiom in Javascript (<https://medium.com/javascript-inside/elm-architecture-for-react-951b383fcd65>)?

...

…

Consider to delve deeper into comparing Single Atom Architecture, the Elm idiom and what Clojure and React are doing to get a base on a good C++ implementation using some C++ immutable data structure library as application state (e.g., the immer library)?

...

{% endraw %}
