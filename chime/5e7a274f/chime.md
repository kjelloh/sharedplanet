# Todo: Tha Meta Model - Consider to compare Tha meta modelling of type systems with the reflective language Black (implemented in Scheme)?

```#5e7a274f``` *As of 2019-06-11 18:22*

[mail plain/text](mail.txt)

{% raw %}
When I heard about the reflective language black I was curious to what degree the meta-semantic layering in Black compared to the Tha meta model layering and thought it should be valuable to follow up on this lead to see what we can learn?

1) Consider youtube video ""Programming Should Eat Itself" by Nada Amin" (<https://www.youtube.com/watch?v=SrKj4hYic5A&t=1684s> )?

![](<Screenshot 2019-06-11 at 16.57.40.png>)

==&gt; Consider the works of Kenichi Asay (<http://pllab.is.ocha.ac.jp/~asai/papers/> )?

==&gt; Consider Kenichi Asay on the reflective language Black (<http://pllab.is.ocha.ac.jp/~asai/Black/> )?

> *"Black is an extension of Scheme with a reflective construct exec-at-metalevel. It executes its argument at the metalevel where the interpreter that executes user programs is running. There, one can observe, access, and even modify the metalevel interpreter in any way. Because the metalevel interpreter determines the operational semantics of the language, Black effectively allows us to observe, access, and modify the language semantics from within the same language framework."*

==&gt; So it seems Black defines its meta levels in terms of the "levels of interpretation" (an expression on a meta level is always interpreted (evaluated) by the meta level above)?

==&gt; It seems the Kenichi Asay thesis "The Reflective Language Black" is available in postscript here (<http://pllab.is.ocha.ac.jp/~asai/papers/thesis.ps.gz> )?

> *"**Reflective programming languages provide high flexibility and extensibility by allowing user programs to access and change their language implementation (or semantics) from within themselves.**"*

> *"The thesis is divided into three parts. In the first part of the thesis, we investigate a general implementation framework for reflective languages which satisfy the following favorable properties: (1) user programs are allowed to access and change (parts of) the interpreter defining the language semantics from within the same language framework in an arbitrary way, (2) reflective facilities are available at every level (with minor approximation), hence there exists conceptually an infinite tower of interpreters, and (3) the interpreter runs as efficiently as the conventional (directly implemented) metacircular interpreter when reflection is not used. Based on this framework, we implement a reflective language called Black, a reflective extension of the functional language Scheme. "*

![](<Screenshot 2019-06-11 at 17.28.21.png>)

Figure 2.4 *from Kenichi Asay thesis "The Reflective Language Black" explaining the "tower structure" of evaluators*

![](<Screenshot 2019-06-11 at 17.29.25.png>)

A*n excerpt from Kenichi Asay thesis "The Reflective Language Black" explaining the meta-layering of evaluators*

==&gt; Consider the abstract of the 2014 paper "Compiling a Reflective Language using MetaOCaml" (<http://pllab.is.ocha.ac.jp/~asai/papers/gpce14abs.html> )?

> *"A reflective language makes the language semantics open to user programs and allows them to access, extend, and modify it from within the same language framework. "*

==&gt; Consider how Nada Amin seems to be in touch with this "Meta" approach to self reflective languages as well as in type systems?

> *"Nada Amin is a member of the Scala team at EPFL, where she studies type systems and hacks on programming languages. She has contributed to Clojure's core.logic and Google's Closure compiler. She's loved helping others learn to program ever since tutoring SICP as an undergraduate lab assistant at MIT."*

![](<Screenshot 2019-06-11 at 16.57.20.png>)

2) Consider the (related?) concept of "Type Theory Should Eat Itself" (<https://www.ioc.ee/~james/papers/lfmtp08_jmc.pdf> )?

TODO: Consider to delve into how "eat itself" here seems to mean that the tytpe theory should be defined self-reflectively (in terms of itself)?

3) Consider the (realted?) concept of "Homotopy Type Theory should eat itself (but so far, it’s too big to swallow)" (<https://homotopytypetheory.org/2014/03/03/hott-should-eat-itself/> )?

TODO: Consider to first understand what "Homotopy" means?

4) Consider the wikipedia article on "Homotopy type theory" (<https://en.wikipedia.org/wiki/Homotopy_type_theory> )?

> *"In mathematical logic and computer science, homotopy type theory (HoTT /hɒt/) refers to various lines of development of intuitionistic type theory, based on the interpretation of types as objects to which the intuition of (abstract) homotopy theoryapplies.*

> *This includes, among other lines of work, the construction of homotopical and higher-categorical models for such type theories; the use of type theory as a logic (or internal language) for abstract homotopy theory and higher category theory; the development of mathematics within a type-theoretic foundation (including both previously existing mathematics and new mathematics that homotopical types make possible); and the formalization of each of these in computer proof assistants."*

...

{% endraw %}
