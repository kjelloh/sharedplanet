# Todo: Meta Value Model - Consider a model instance may specialize (inherit from) some standard values and scripting language identifiers?

```#78e8349e``` *As of 2017-06-11 16:50*

[mail plain/text](mail.txt)

{% raw %}
Consider we may implement the standard value identifiers and scripting language identifiers by allowing an actual model instantiation to extend (specialize) a basic-model and some language-model?

1) Consider how we may implement Meta Value Model ”inherit” or ”specialization”?

==&gt; Consider the meta-value ”specialized”?

(declaration int (specialized number)) // would mean identifier ”int” inherits from (is a specialized) number)?

==&gt; Consider we need a way to specify what may be specialized in the source meta-value?

==&gt; Compare C++ ”virtual” that states that a functions may be specialized?

…

2) Consider we may always allow Cloning of another model (by simply defining it to be the same value as another model)?

==&gt; Consider cloning still means the custom model still shares the cloned model (it is a persistent data structure)?

==&gt; But cloning allows mutation of the cloned model (new immutable state affects only custom model, not the cloned one)?

==&gt; Thus, cloning say a Darwinet MIV will have mutations to be synchronized only in the domain of the clone (not in the domain of the source model)?

...

3) Consider to define the basic value compositions as a Meta Value Model to inherit from?

BasicMetaValueModel // Basic value compositions

^

| *Specialize*

|

CustomMetaValueModel // Custom value compositions

==&gt; Consider it is this basic model defines ”array”, ”record”, ”number”, ”text” etc…?

...

4) Consider to add scripting language identifiers as a Meta Value Model from which to inherit to add scripting language processing abilities?

BasicMetaValueModel // Basic value compositions

^

| *Specialize*

|

ScriptingLanguageMetaValueModel

^

| *Specialize*

|

CustomMetaValueModel // Custom value compositions with scrip function abilities

==&gt; It seems we need to inherit from a Scripting Language Model to be able to store scripts as executable code in the model (otherwise we would not know how to execute this code)?

==&gt; But extending a custom model with scripting engine model enable external client to evaluate scripts on the model?

BasicMetaValueModel // Basic value compositions

^

| *Specialize*

|

CustomMetaValueModel // Custom value compositions (can’t execute function as scripts - **script language values not known**)?

^

| *Specialize*

|

ScriptingLanguageMetaValueModel // External client may process the Custom model with these scripts - **script language values are known**?

==&gt; Consider Meta Value Model identifiers for our **Meta Lisp** language?

==&gt; Consider ”**append**” is a Meta Lisp Model function?

==&gt; Consider C++ language scripting model?

C++: int count = 5;

Value&lt;1&gt; **(declare int (specialized number))** // C++ model ”int” type

Value&lt;0&gt; ((declare count int) 5)

C++:  class A {

int x;

int b;

}

A a{2,3}; // auto a=A{2,3}, A a = {2,3}

Meta&lt;2&gt; (declare class (specialized record)) // C++ model ”class”

Meta&lt;1&gt; ((declare class A) (declare int x) (declare int b)) // A is record with named members ”x”, ”b” both of Value&lt;1&gt; int

Meta&lt;0&gt; ((declare a A) (x 2) (b 3)) // a is instance of A and member values are instance of value 2 and 3.

==&gt; Consider Clojure language scripting model (<https://clojure.org/index>)?

See ”Todo: Meta Value Model - Consider to compare idioms in our Meta Lisp language with the Clojure language?”

…

…

Consider to delve into this idea to enable Meta Values to be composed using inheritance (specialization)?

...

{% endraw %}
