# Todo: Ibi - Consider to elaborate on possible mechanisms to enable clients to apply ibi paths to select members of existing (and new) composites?

```#f67ac300``` *As of 2016-08-21 12:46*

[mail plain/text](mail.txt)

{% raw %}
So, how can we make an ini path usable to select a member of a composite structure?

1) Consider mechanisms on each “level” (composite member) to find the one that matches current key node?

==&gt; Consider the path p = n1.n2.n3 (n being a value of some key type N of an ini path).

==&gt; Consider a composite c where each member is either a leaf l or a composite c.

==&gt; Q: How can we apply the path p to select the member in c that matches the key path?

==&gt; If each C members are iteratable (provides being/end interface) we may try std::find using operator== on composite member c and path key n?

==&gt; This works if the namespace of C provides an operator== that can compare a member value c with a key value n.

==&gt; The path p = n1.n2.n3 would then select:

first: std::find(c.begin(), c.end(),&#91;&#93;(const C& c){return c == n1} ==&gt; finds c1

then:  std::find(c1.begin(), c1.end(),&#91;&#93;(const C& c){return c == n2} ==&gt; finds c2

then:  std::find(c2.begin(), c2.end(),&#91;&#93;(const C& c){return c == n3} ==&gt; find c3.

==&gt; If each C provides an operator&#91;&#93; using a key value type N we may try calling it with the current path node n?

==&gt; The path p = n1.n2.n3 would then select c&#91;n1&#93;.&#91;n2&#93;.&#91;n3&#93;?

==&gt; Consider the client may provide a std::optional&lt;C&&gt; select(C& c, ini::Path p)?

==&gt; Such a select function could then apply each node of path p to each selected member of composite c and return an optional reference to member in the structure that matches p?

…

2) Consider mechanisms that allows the ini::path to be any of the compassable types (i.e. “zipped” types like indexed path and “stacked” types like {path1, path2})?

==&gt; Consider how we may use meta programming to have a single path, a zipped path and a stacked path to be applied using a uniform semantics?

==&gt; Consider that the example of std::optional&lt;C&&gt; select(C& c, P p) should work regardless of the type of P?

==&gt; Consider what would be required for all path types P to be iteratable?

==&gt; Consider a single path p = n1.n2.n3 is always trivially iteratable (it is a range of nodes of the same type)?

==&gt; Consider a single path of variant node p = v1.v2.v3 to be iteratable but then \*iter would be a variant and should be processed using variant visitor mechanism?

==&gt; Consider a “zipped” path would require client to understand that each node will be an std::tuple (p = z1.z2.z3 where each z is a “zip” into an std::tuple)?

{n1.n2.n3}

p =  ==&gt; p.begin() == std::tuple(n1,i1)

{i1.i2.i3}

==&gt; Consider a “stacked” path would require the client to be able to handle key nodes of p1 and then key nodes of p2?

p = {{n1,n2.n3} , {i1,i2,i3}} ==&gt; p.front() == n1. p.back() == i3.

==&gt; Consider what it would take to make all path types to act as “generators” (e.g., implement the visitable idiom)?

==&gt; Could we imagine the Visitable idiom to be able to handle the different path types “better” than the Iteratable idiom?

==&gt; Consider the client may provide a “select” functor that an ibi::select method may apply to search a composite?

std::optional&lt;C&&gt; ibi::select(C& c, P p, Selector s) {

// For each key in path p

// Call selector s to select member m in c that matches the key.

// If m exists repeat with next key in path p to get member in m.

}

==&gt; Consider this would work well as the Composite design pattern requires all members to share a common Composite API and thus may provide a uniform way of selecting a member with a key?

struct IteratableComposite {

iterator begin();

iterator end();

bool operator==(Key key);

}

struct VisitableComposite {

bool accept(Visitor v);

}

struct SelectableComposite {

SelectableComposite& operator&#91;&#93;(Key key);

}

…

…

Consider to elaborate on the mechanisms we can imagine to enable a client to easily make existing composite structures apply the different ibi path types to select members?

...

{% endraw %}
