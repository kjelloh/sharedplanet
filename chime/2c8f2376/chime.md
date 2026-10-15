# Todo: Darwinet - Consider to implement Darwinet in Clojure or Scala with an Electron user interface?

```#2c8f2376``` *As of 2017-02-01 14:45*

[mail plain/text](mail.txt)

{% raw %}
Studying different functional programming languages and cross platform user interfaces it seems to me it may be a good idea to elaborate on the possibility to implement Darwinet in a language where the Persistent Data Structures, Reactive Functional Programming and ”React” like user interfaces are available out-of-the-box?

1) Consider this talk by ”Planet OS: Efficient Immutable Data Structures ('Okasaki for Dummies') by Tom Faulhaber” (<https://www.youtube.com/watch?v=XODjKeumO_s>)

==&gt; Consider to follow up on the leads in the above image of the History of Persistent Data Structures?

> ![](<Persistent Data Structures History.tiff>)

==&gt; Consider to follow up on the references to Functional Data Structures?

> ![](<Functional Data Structures References by Faulhaber.tiff>)

==&gt; The Rich Hickey ”Are we There Yet” talk seems to live here (<https://www.infoq.com/presentations/Are-We-There-Yet-Rich-Hickey>)?

==&gt; He seems to make a compelling and interesting refernce to the thinking about time by the philosopher **Alfred North Whitehead** :)

==&gt; He seesm to argue we need a way to represent time in programs without trying to pretend we control time (time flows and the world changes and the program must embrace that as concurrent as possible)?

==&gt; He seesm to introduce the concept of ”Time Constructs” to be able to reason about how time must or should relate with the running program and its operations?

==&gt; He seem to talk about CAS, Copy-and-Swap, as a way to hide mutation so that the ”new” value leaves the old one intact (immutable)?

==&gt; He seems to SMS, Software Transaction Memory (<https://en.wikipedia.org/wiki/Software_transactional_memory>) as a mechanism to atomically (unobservable shared) synchronize two time-lines?

...

==&gt; The Gerard Huet ”Functional Pearl: The Zipper” paper seems to live here (<https://www.st.cs.uni-saarland.de/edu/seminare/2005/advanced-fp/docs/huet-zipper.pdf>)?

==&gt; The Jean Niklas L’orange ”Understanding Clojure's Persistent Vectors, pt. 1” seems to live here (<http://hypirion.com/musings/understanding-persistent-vector-pt-1>)?

2) Consider to implement the Darwinet Node in Functional JacaScript, Elm, Elexir, Clojure or Scala?

==&gt; What pieces of framework can we imagine to implement a proof-of-concept Darwinet Node in a quick and easy way?

==&gt; Consider we like Persistent Data Structures neatly available?

==&gt; Clojure and Scala have them in the core of the language.

==&gt; Javascript has the well known immutable.js (enabling using Javascipt world design)?

Electron GUI —&gt; Node.js Darwinet

==&gt; We may use Emscriptem to transpile C++ to JavaScript?

…

==&gt; We may use ClojureScript to apply Clojure code in Javascript world?

…

3) Consider a C++ Darwinet proof of concept uses immgui to render snapshots of current MIV at desirable frame rate?

==&gt; Consider this for now solves the problem of how the GUI should mutate according to new MIV states?

==&gt; We can begin by simply having an immgui that samples current MIV state and renders it?

==&gt; We then also totally isolates user input from rendering (we render ONLY MIV state and user input ONLY creates new MIV states)?

...

…

Consider to test out these tool chains, frameworks and target environments to get some understanding if they could serve as the first implementation to prove the Darwinet Design Goals?

...

{% endraw %}
