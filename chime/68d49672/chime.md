# Todo: Consider the relevance and importance the the C++ Github project Immer (Immutable data structures) is still alive and well?

```#68d49672``` *As of 2024-02-20 12:16*

[mail plain/text](mail.txt)

{% raw %}
I want to use immutable data structures in my code development and it gives me a good feeling that the Immer project is still alive and being maintained!

==&gt; Also see "[Todo: Darwinet - Consider to implement the Typescript CRTD-library "Collab" in C++ based on C++ immutable library "Immer"?](../12aef88f/chime.md)"

==&gt; Also see "[Todo: Cratchit Book Keeping - Consider to implement a C++ book keeping application using Tha modelling, Elm Idion and Immer Immutable data Struictures asynchronously synchronising with REST Web service (FortKnox) and IPFS file system?](../7c6907a4/chime.md)"

==&gt; Also see "[Todo: C++ Tha - Consider to implement Tha meta-tier.model in the immutable data structure library Immer?](../8cbd727b/chime.md)"

1) The Immer C++ project seems to live here on Github (<https://github.com/arximboldi/immer> )?

> ## Dependencies

> This library is written in C++14 and a compliant compiler is necessary. It is [continuously tested](https://travis-ci.org/arximboldi/immer) with Clang 3.8 and GCC 6, but it might work with other compilers and versions.

> No external library is necessary and there are no other requirements.

> ## <https://github.com/arximboldi/immer#usage>Usage

> This is a header only library. You can just copy the `immer` subfolder somewhere in your *include path*.

> If you are using the [Nix package manager](https://nixos.org/nix) (we strongly recommend it) you can just:

> ```
> nix-env -if https://github.com/arximboldi/immer/archive/master.tar.gz<https://github.com/arximboldi/immer/archive/master.tar.gz>

> ```

> Alternatively, you can use [CMake](https://cmake.org/) to install the library in your system once you have manually cloned the repository:

> ```
> mkdir -p build && cd build
> cmake .. && sudo make install
> ```



2) Consider if, how and when I may consider to base my Cratchit book keeping application on Immer?

==&gt; Consider to implement the Cratchit Model as an Immer immutable data structure and push each new model into a vector of model history?

> *The initial idea here is that we may begin to introduce Immer into Cratchit by implementing the Model using Immer immutable data structures and then push each new model onto a vector of models. In this way we would get a history of model mutations with the benefit of "knowing" what has changed during execution of the application.*

> *I have a hunch that there are some benefits in doing this that I have not completely made bare yet. But I can imgane the following.*

> *We would be able to "undo" with ease and provide this feature to the user.*

> *We may be able to streamline the persistent storage by only saving the deltas?*

> *I may also be able to experiment with the Tha idea to always keep the latest state stored in full and then add the back propagation deltas (in effect reversing the history of changes from old to new and store them as new to old).*

> *Maybe if I implement the model in Cratchit as Immer immutable data structures I can get a seed to how I can come up with a framework and model for storing deltas in the Tha immutable data model?*

> *...*

...

{% endraw %}
