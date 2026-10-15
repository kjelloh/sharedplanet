# Todo: C++ preprocessor - Consider to understand the preprocessor code required to define valid identifier names from a prefix text and the __LINE__macro?

```#02b36adf``` *As of 2019-06-26 23:34*

[mail plain/text](mail.txt)

{% raw %}
I have never got my head around the strange way the preprocessor generates text from the __LINE__ macro so it is time I get to bottom with it!

1) Consider the preprocessor code that actually is bale to create identifier names from the __LINE__ macro?

==&gt; Consider wee need to expand __LINE__ in two steps?

> #define COMBINE1(X,Y) X##Y *// helper macro*  
> #define COMBINE(X,Y) COMBINE1(X,Y)

> **const** **int** COMBINE(value_,__LINE__) = 0;  
> **const** **int** COMBINE(value_,__LINE__) = 0;  
> **const** **int** COMBINE(value_,__LINE__) = 0;

==&gt; Consider the COMBINE macro is able to take two arguments where the first is plain source text and __LINE__ is not expanded UNTIL PASSED TO NESTED FUNCTION MACR=

![](<Screenshot 2019-06-26 at 23.14.42.png>)

*For reasons unknown to me macros passed to function macros are NOT expanded on passing (evaluation) so we need to nest macros to expand __LINE__ before doing ##.*

==&gt; But it still does not MAKE SENSE to me that __LINE__ gets expanded when passed to nested function macro but NOT to top level one?

Q: What triggers expansion of __LINE__ (if argument expansion is not a thing)??

==&gt; Consider this stackoverflow thread that seems to explain why we need two macros (<https://stackoverflow.com/questions/10379691/creating-macro-using-line-for-different-variable-names> )?

> You're using token pasting. This occurs before the recursive macro expansion (so that you can token paste to get the name of a macro you want to invoke). Thus:

> ```
> #define PASTE(a,b) a ## b
> ```

> will paste the exact arguments passed to `PASTE`, then try to expand the resulting new token. To get the effect you want, you need an additional level of indirection:

> ```
> #define PASTE_HELPER(a,b) a ## b
> #define PASTE(a,b) PASTE_HELPER(a,b)
> ```

> Here, the arguments to `PASTE` will be expanded before `PASTE_HELPER` is invoked.

  
==&gt; It seems the problem is that token-pasting takes place b e f o r e macro expansion (so value_ ## __LINE__ will become value___LINE__)?

> *Ok, so the important thing to know is that the macro operator ## for token-pasting takes place b e f o r e any macro expansion. And we need the __LINE__ macro to be e x p a n d e d before we concatenate the resulting character string with our other text.*

> *So the second thing we can take advantage of is that within a function macro the input arguments WILL be expanded IF we pass them to a new function macro. *

> *So In *#define PASTE(a,b) PASTE_HELPER(a,b)

> *the preprocessor will expand the arguments a and b before passing them to the second function macro.*

> *But how can we understand why the expansion DOES NOT occur when passing argument to the first function macro? *  
> *...*

==&gt; Consider C++ refernce of "replacing text macros" (<https://en.cppreference.com/w/cpp/preprocessor/replace> )?

> *"A ## operator between any two successive identifiers in the replacement-list runs parameter **replacement on the two identifiers** (which are **not macro-expanded first**) and **then concatenates** the result. This operation is called "concatenation" or "**token pasting**"."*

> *"**A **comment cannot be created** by pasting / and \* because **comments** are **removed** from text **before** macro **substitution** is considered.**"*

> *"**In function-like macros, a # operator before an identifier in the replacement-list runs the identifier through parameter replacement and encloses the result in quotes, effectively creating a string literal. In addition, the preprocessor adds backslashes to escape the quotes surrounding embedded string literals, if any, and doubles the backslashes within the string as necessary. All leading and trailing whitespace is removed, and any sequence of whitespace in the middle of the text (but not inside embedded string literals) is collapsed to a single space. This operation is called "stringification".**"*

==&gt; Consider to extract my own understanding of the pre-processor actual processing steps?

> *So, the documentation of the preprocessor behaviour is terse at best and nonexistent at worst. Such a simple and crucial thing as to specify when arguments to a function like macro is expanded is nowhere to be found?!!*

> *Anyhow, firstly it is good to know that comments are removed before anything else happens!*

> *Then it seems any ##, "token-pasting operator" is performed (thus normally taking place before expansion).*

> *Now, we are trying to understand why a function macro expansion within another function macro IS expanded before passed?C++ recursive macro expansion?*

==&gt; Consider this Issue "268. Macro name suppression in rescanned replacement text" discussed for C++ macro specification in the standard (<http://www.open-std.org/jtc1/sc22/wg21/docs/cwg_active.html#268> )?

> #### 268. Macro name suppression in rescanned replacement text

> **Section: **19.3.4 &#91;cpp.rescan&#93; **Status: **open **Submitter: **Bjarne Stroustrup **Date: **18 Jan 2001

> It is not clear from the Standard what the result of the following example should be:

> > ```
> > #define NIL(xxx) xxx
> > #define G_0(arg) NIL(G_1)(arg)
> > #define G_1(arg) NIL(arg)
> > G_0(42)

> > ```

> The relevant text from the Standard is found in 19.3.4 &#91;cpp.rescan&#93; paragraph 2:

> > If the name of the macro being replaced is found during this scan of the replacement list (not including the rest of the source file's preprocessing tokens), it is not replaced. Further, if any nested replacements encounter the name of the macro being replaced, it is not replaced. These nonreplaced macro name preprocessing tokens are no longer available for further replacement even if they are later (re)examined in contexts in which that macro name preprocessing token would otherwise have been replaced.

> The sequence of expansion of G0(42) is as follows:

> > ```
> > G0(42)
> > NIL(G_1)(42)
> > G_1(42)
> > NIL(42)
> > ```



==&gt; But it seems the intention (and the result in the real world) is 42 (The last NIL(42) IS expanded?

> The question is whether the use of NIL in the last line of this sequence qualifies for non-replacement under the cited text. If it does, the result will be NIL(42). If it does not, the result will be simply 42.

> Suggested resolution (Mike Miller): ...Once the scan reaches the preprocessing token following a macro's replacement list — including as part of the argument list for that or another macro — the macro's name is once again available for replacement. &#91;*Example:*

> ```
>     #define NIL(xxx) xxx
>     #define G_0(arg) NIL(G_1)(arg)
>     #define G_1(arg) NIL(arg)
>     G_0(42)                         // result is 42, not NIL(42)
> ```



==&gt; It seems I can confirm the expansions DOES take place as argued for in 268. Macro name suppression in rescanned replacement text?

![](<Screenshot 2019-06-26 at 22.47.39.png>)

==&gt; So what can we deduce from this series of expansions in this example?

> *So it seems we can make the expansion operations even more clear?*

> *G_0: G_0(42) ==&gt; NIL(G_1)(42) == NIL(G_1)(42)*  
> *NIL: NIL(G_1) ==&gt; G_1 == G_1(42)*  
> *G_1: G_1(42) ==&gt; NIL(42) == NIL(42)*  
> *NIL: NIL(42) ==&gt; 42*

==&gt; BUT WE STILL HAVE FOUND NO EXPLANATION TO WHY WE NEED NESTED FUNCTION MACROS TO EXPAND AND CONCATENATE __LINE__?

> *I mean, if __LINE__ is NOT expanded when passed as argument the first time, why is it expanded in the nested function expansion??*

...

{% endraw %}
