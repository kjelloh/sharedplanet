# Todo: Meta Model - Consider to define a language to define meta-value computation (i.e., arrows alias functions)?

```#5afafbd8``` *As of 2017-06-05 21:00*

[mail plain/text](mail.txt)

{% raw %}
Could it be fun and valuable to be able to define defacto functions using meta-value processing expressions and statements?

1) Consider a purely functional language using a basic set of functions and function composition?

==&gt; Consider ’:’ to bind (declare) name to/as meta-value (name declared-as meta-value)?

Declaration: x:number

==&gt; The declaration would read x declared-as number

==&gt; Consider ’=’ to bind (define) name as/to a value?

Definition: x = 4

==&gt; The definition would read: x defined as 4.

==&gt; Consider Definition may be written as declaration = value?

definition: x:number = 4

==&gt; The Definition would read x declared as number defined as 4?

==&gt; Consider to use &#91;&#93; to denote lists?

Declaration: numbers : &#91;number&#93;

Definition: numbers = &#91;2,5,17&#93;

Definition: numbers: &#91;number&#93; = &#91;2,5,17&#93;

==&gt; Consider {} to denote records of declarations?

Declaration: entry : {name:text, value:number}

Definition: entry = {name=”value1”, value=5}

Definition: entry:{name:text, value:number} = {name=”value1”, value=5}

Hm… Record member order is not perserved (thus we need to repeat record member names in the definition)?

==&gt; Consider ”-&gt;” means function computation left side to right side meta-value?

Declaration: f : number -&gt; number

Definition: f = x -&gt; {x\*x}

Definition: f : number -&gt; number = x -&gt; x\*x

==&gt; The declaration would read: ”f” declared as compute number to number

==&gt; The definition would read: ”f” equals x computed to expression x\*x.

==&gt; Note: The declaration already stated x to be number and expression to evaluate to number?

==&gt; short-hand definition would read: f declared as number to number, defined as x computed as x\*x?

==&gt; Compare JavaScript (<https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/Arrow_functions>)

==&gt; Compare Haskell (<https://www.haskell.org/arrows/>)?

Hm… ”number -&gt; number” defines meta-value {function,{number, number}}?

==&gt; Consider to use &#91;&#93; to denote lists also in expressions?

Declaration: f: number -&gt; &#91;number&#93;

Definition: f = x -&gt; &#91;x&#93;

Definition: f : number -&gt; &#91;number&#93; = x -&gt; &#91;x&#93;

==&gt; The declaration would read: ”f” such that number computes to list-of-number

==&gt; The definition would read: ”f” equals x computes as expression - list with member x.

==&gt; Consider {} to denote records also in expressions?

Declaration: f: text -&gt; number -&gt; {name:text,value:number}

Definition: f = name -&gt; value -&gt; {name=name, value=value}

Definition: f : text -&gt; number -&gt; {name:text, value:number} = name -&gt; value -&gt; {name=name, value=value}

Hm… This is strange?

==&gt; But it could make sense as in the definition ’=’ means named-value = value (so name=name means record member ”name” defined as argument value ”name”?

==&gt; Compare this to C++ that allows constructor(int x) : x(x) {} to mean member x = argument x?

==&gt; Consider "f argument” means f applied to argument?

Declaration: entry : {name:text,value:number}

Definition: entry = f ”value1” 5

Defiinition: entry : {name:text,value:number} = f ”value1” 5

==&gt; The declaration would read: ”entry” declared as record {name:text,value:number}

==&gt; The definition would read: entry defined as f applied to ”value1” - applied to 5 (which will invoke f expression {name = ”value1”, value = 5})

…

2) Consider meta-values are initialization functions anonymously defined when they occur to the right of ’=’?

definition: x = number 4

==&gt; Would read: x is defined as the number meta-value applied to 4 (x is this bound to meta-value named ”number")

==&gt; Note: meta-values are always functions that computes initialization values?

Definition: numbers = &#91;number&#93; &#91;2,5,17&#93;

==&gt; Would mean &#91;number&#93; is the anonymous list-of-numbers meta-value applied to the list &#91;2,5,17&#93; (numbers thus bound to anonymous list-of-numbers meta-value)?

Definition: entry = {name:text, value:number} {name=”value1”, value=5}

==&gt; {name:text, value:number} declaration defines an anonymous record-meta-value then applied to defacto record value {name=”value1”, value=5} (entry is thus bound to the anonymous record-meta-value)

Definition: f = number -&gt; number x -&gt; x\*x

Definition: f = number -&gt; &#91;number&#93; x -&gt; &#91;x&#93;

==&gt; Would mean number -&gt; number is the anonymous meta-arrow-value (computation) defined as x -&gt; x\*x (f is thus bound to the anonymous meta-arrow number-&gt;arrow and defined )?

==&gt; Note: We do not need any framing ( meta-value -&gt; meta-value defines anonymous meta-arrow and the ”space x” indicates end of meta-value declaration)?

==&gt; Or, require parenthesis to aid parsing?

Definition: f = (number -&gt; number) (x -&gt; x\*x)

Definition: f = (number -&gt; &#91;number&#93;) (x -&gt; &#91;x&#93;)

??

Definition: f = text -&gt; number -&gt; {name:text, value:number} name -&gt; value -&gt; {name=name, value=value}

**==&gt; WE ARE HERE... **

3) Consider to define also imperative statements?

==&gt; Consider to use {} to compose statements in arrow computations (functions)?

Declaration: f: number -&gt; &#91;number&#93;

Definition: f = x -&gt; {

if (&gt;5) x {

{return &#91;x&#93;}

,{return &#91;&#93;}

}

}

…

Consider to elaborate on this ida of defining some language to allow the model to contain meta-value computation (arrows alias functions)?

...

{% endraw %}
