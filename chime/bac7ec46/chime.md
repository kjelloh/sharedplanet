# Todo: Programming - Consider different Composite index and key based traversal C++ semantics?

```#bac7ec46``` *As of 2016-10-01 21:47*

[mail plain/text](mail.txt)

{% raw %}
So, what C++ semantics can we implement to allow easy to use and easy to read index traversal of composites (components)?

==&gt; Note: All components should support index (anonymous node) traversal?

==&gt; Note: Some components may support named (keyed) members?

-1) It seems we have three ways of matching a Path to a Component tree?

a) The Component uses Level&#91;i&#93;::member == Path&#91;i&#93; (i.e. operator== on Component and Key)

b) The Component uses a provided binary Predicate(member,Key)

c) The Path Key is a Predicate(member)

==&gt; Consider to try them out to see what design is the ”best”?

1) Consider array index using operator&#91;&#93; (index)?

Component& e = c&#91;1&#93;&#91;3&#93;&#91;2&#93;; // have operator&#91;&#93;(index) return a reference to selected child

2) Consider child select using operator()(index)

Component& e = c.n(1)-&gt;(3)-&gt;(2); // have operator()(index) return pointer to selected child and.

Component& e = c(1)(3)(2); //

3) Consider selection using index initializer list?

Component& e = c&#91;{1,3,2}&#93;;

==&gt; This seems to have the advantage that we can apply relative paths?

Component& e2 = c&#91;{1,3}&#93;;

Component& e3 = e2&#91;{2}&#93;;

Component& e3 = c&#91;{1,3}&#93;&#91;{2}&#93;;

...

4) Consider how to extend indexed traversal to keyed traversal?

==&gt; Consider to overload the operator&#91;&#93; with ones taking key types instead of index types?

==&gt; Q: How do we prevent ambiguity between index type and key types matching or implicitly cartable to index type (e.g. enum keys)?

Component& e = c&#91;”Student”&#93;&#91;”Adress”&#93;&#91;”Street"&#93;; // apply operator&#91;&#93;(t_key), t_key == std::string

Component& e = c&#91;{”Student”,”Adress”}&#91;”Street"&#93;; // apply operator&#91;&#93;(std__initializer_list&lt;t_key&gt;)

…

==&gt; Seems it works quite well to overload unsigned int index versions with enum key versions?

> enum e_Key {  
> key1  
> ,key2  
> ,key3  
> };

> class Component {  
> public:  
> using Index = unsigned int;  
> using Key = e_Key;

> Component& operator&#91;&#93;(Index i) { return \*this;}  
> Component& operator&#91;&#93;(std::initializer_list&lt;Index&gt; indexes ) { return \*this;}

> Component& operator&#91;&#93;(Key key) { return \*this;}  
> Component& operator&#91;&#93;(std::initializer_list&lt;Key&gt; keyes ) { return \*this;}

> };  
> }

> void test() {

> {  
> using namespace naive;  
> Component c;  
> Component& e1 = c&#91;1&#93;;  
> Component& e2 = c&#91;{1,3}&#93;;  
> Component& e3 = c&#91;key1&#93;;  
> Component& e4 = c&#91;{key2,key3}&#93;;  
> Component& e5 = c&#91;key1&#93;&#91;{key2,key3}&#93;;

> }  
> }

==&gt; Note: If we remove the Key overloads of operator&#91;&#93;, then the index versions are called (enum implicitly cast to unsigned int)

5) Consider what it would take to now handle XPath into xml Components using the Key traversal mechanism?

==&gt; See <http://www.w3schools.com/xsl/xpath_syntax.asp> for examples.

==&gt; Consider to provide an XPath —&gt; ibis::Path&lt;xml::element_t&gt;?

==&gt; We could then implement an XML document as a component with members having element_t of either Element or Attribute?

6) Consider to implement Predicate Key nodes (inspired by XPath Predicates)?

==&gt; Consider how we can implement XPath Predicates as Key of Predicate type?

"/title&#91;@lang='en’&#93;” means - select all title elements with the attribute lang equals the value ’en’.

==&gt; Consider an ibi::Path with element Predicate&lt;Attribute,Value&gt;?

Component& e1 = c&#91;Key&#93;; // Returns Component for which Predicate(component) return true?

...

7) Consider ibi::Path is always a vectors of Predicates (each key in the path implements bool operator()(Component) to compare a key match)?

==&gt; Q: What does this mean to the implementation of Compnent::operator&#91;&#93;(Key)?

> /bookstore/book&#91;1&#93; Selects the first book element that is the child of the bookstore element.

> **Note:** In IE 5,6,7,8,9 first node is&#91;0&#93;, but according to W3C, it is &#91;1&#93;. To solve this problem in IE, set the SelectionLanguage to XPath:

> *In JavaScript: xml*.setProperty("SelectionLanguage","XPath");/bookstore/book&#91;last()&#93;Selects the last book element that is the child of the bookstore element/bookstore/book&#91;last()-1&#93;Selects the last but one book element that is the child of the bookstore element/bookstore/book&#91;position()&lt;3&#93;Selects the first two book elements that are children of the bookstore element//title&#91;@lang&#93;Selects all the title elements that have an attribute named lang//title&#91;@lang='en'&#93;Selects all the title elements that have a "lang" attribute with a value of "en"/bookstore/book&#91;price&gt;35.00&#93;Selects all the book elements of the bookstore element that have a price element with a value greater than 35.00/bookstore/book&#91;price&gt;35.00&#93;/titleSelects all the title elements of the book elements of the bookstore element that have a price element with a value greater than 35.00

==&gt; Seems a predicate is actually a key,bool expression pair that compares to a value?

==&gt; Seems we could implement them with Lamdas passed to Predicate key node of Path?

...

…

Consider to elaborate on what index traversal semantics we may consider in C++?

...

{% endraw %}
