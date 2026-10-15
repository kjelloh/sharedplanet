# Todo: Meta Value Model - Consider what we can learn from the Elm language for Meta Value Model design, REPL application and scripting abilities?

```#308aee14``` *As of 2017-06-12 17:36*

[mail plain/text](mail.txt)

{% raw %}
So, what can we learn about the Meta Value Model implementation and scripting abilities from studying and comparing with the Elm language (<https://www.gitbook.com/book/evancz/an-introduction-to-elm/details>)?

1) Elm seems to come with a REPL and this seem to be an online one to try out (<http://elmrepl.cuberoot.in>)?

==&gt; The Repl seem to only evaluate expressions and show values?

==&gt; I fail to have it show types (Elm does not treat types as values, i.e., meta-values)?

==&gt; The Repl does not seem to be able to evaluate type annotations (declarations)?

==&gt; Again, because Elm repl evaluates only value expressions (not meta-expressions)?

==&gt; But it does evaluate ”type Msg = …"

==&gt; Also see ”REPL does not support typing in type annotations #113” (<https://github.com/elm-lang/elm-repl/issues/113>)

2) An Elm application seems to implement a very clean and good separation view, update and model?

> " • Model — the state of your application  
> • Update — a way to update your state  
> • View — a way to view your state as HTML"

==&gt; It seems this is how the Elm run-time ties it all together?

==&gt; Also see ”Todo: Meta Value Model - Consider what we can learn from the Elm language for Meta Value Model design, REPL application and scripting abilities?"

init_value

|

| (0)

v

subscriptions update view

^| 0.1 ^| ^|

(4.2) || (5.2) { model 6.1 || (1){ model || (2.2) Html&lt;Msg&gt;

|v ,Sub&lt;Msg&gt;} 6.2 || ,Cmd&lt;Msg&gt;} ||

|v  2.1 |V |v

---------------------------------------------------------------------------------

| Elm run-time |

---------------------------------------------------------------------------------

^ | (3)

| -----&gt; Html&lt;Msg&gt; ----&gt; | Client (4.1) | (Elm application web-browser window)

| | v

| | \* Client mutates Html - It generates Msg

| (5.1) | |

|----------- Msg &lt;------- | &lt;--------------------------------------

==&gt; Model seems to be a type alias (i.e., a type)?

type alias Model = {…}

==&gt; Update seems to be a function that accepts a Msg and a Model and create a new Model?

Update : Msg -&gt; Model -&gt; Model

==&gt; And View transforms a Model to Html (that produces Msg and pass to update)?

View : Model -&gt; Html Msg

==&gt; The syntax Html Msg is strange (but seems to mean a Html value that is able to produce Msg values?

> ””

==&gt; The binding between the Html value and the a Msg value seems to be made in the view method (that generates the Html value)?

> ”One thing to notice is that our view function is producing a **Html Msg** value. This means that it is a chunk of **HTML that can produce Msg values**. And when you look at the definition, you see the onClick attributes are set to give out Increment and Decrement values. These will get fed directly into our update function, driving our whole app forward."

==&gt; Consider an example of a view implementation

> ```
> view : Model -> Html Msg
> view model =
>   div []
>     [ button [ onClick Decrement ] [ text "-" ]
>     , div [] [ text (toString model) ]
>     , button [ onClick Increment ] [ text "+" ]
>     ]
> ```

  
==&gt; It seems to generate html code using Elm functions like ”**div**” and ”**button**”?

> > ”Another thing to notice is that div and button are just normal Elm functions. These functions take (1) a **list of attributes** and (2) a **list of child nodes**"

3) Elm seems to use separate function declaration and definition?

==&gt; Also see ”[Todo: Meta Value Model - Consider ways to implement function meta-value hierarchy (meta-2...meta-0 declaration, definition operations)?](../130c6d9a/chime.md)"

==&gt; The function declaration defines function name and mapping?

Elm&gt; **Update : Msg -&gt; Model -&gt; Model** // Reads: Identifier ”update” is of meta-value Msg -&gt; Model -&gt; Model

==&gt; Which would mean our Meta Value Lisp declaration could be:

meta-0&gt; **(declare Update (function Msg Model Model))**

==&gt; The function definition seems to declare arguments and define the function body?

Elm&gt; **Update msg model = … function body …**

==&gt; Which would mean our Meta List definition would be:

meta-0&gt; **(define Update msg model (… function body…))**

==&gt; Note: It seems we can’t apply the function identifier as value constructor as this would would be confused with function application (how would evaluator know when to execute constructor and when to execute actual function)?

==&gt; Or, Can we define that an undefined Identifier will act as value constructor bit a defined Identifier will apply the as_function on the value?

as_function(undefined_identifier) = define undefined_identifier as_fucntion(meta-value)

as_function(defined_identifier) = as_function(value)

...

…

Consider to delve into the Elm language to see what we can learn for design of Meta Value Model and its scripting abilities?

...

{% endraw %}
