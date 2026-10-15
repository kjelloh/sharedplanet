# Todo: Consider to document the C++ short comings I was hurt by while solving Advent of Code puzzles?

```#c3e94e8e``` *As of 2023-01-11 15:31*

[mail plain/text](mail.txt)

{% raw %}
1) Hidden semantics for signed vs unsigned integers for operator&lt;

> day22

> This is NENEVR true!

> if (m_bottom_right.col &lt; row.size()-1) {

> This works as intended.

> if (m_bottom_right.col &lt; static_cast&lt;Result&gt;(row.size()-1)) {

==&gt; Should I implement a "safe compare" to be used for my puzzle solving needs to avoid this trap?

2) Hidden semantics for signed vs unsigned for operator-

> day22

> This results in a very large unsigned integer!

> > auto diff = m_bottom_right.col - (row.size() - 1);

==&gt; Should I implement a "safe subtraction" to be used for my puzzle solving needs to avoid this trap?

3) C++ operator% on negative lhs

> day??

> rhs % lhs is NEGATIVE if rhs is.

> -10 % 9 == -1 (NOT 8)

4) C++ operator% with unsigned rhs

> day??

==&gt; Should I implement a "nomalised modulo function" to be used for my puzzle solving needs to avoid this trap?

5) Hidden semantics for std::accumulate using literal integer as start value

> year?? day??

> auto result = std::accumulate(begin,end,1)

> result will have the type UNSIGNED (not the type of \*begin)!

==&gt; Should I implement my own accumulate that uses the type of the iterated data to be used for my puzzle solving needs to avoid this trap?

6) std::array arguments length and "value" are in the opposite order of the STL container constructors

> // std::array&lt;3,std::array&lt;3,int&gt;&gt; unfolded{};  
> std::array&lt;std::array&lt;int,3&gt;,3&gt; unfolded{};

> auto v = std::vector&lt;std::string&gt;(3,"");

7) st::array requires an extra level of {} in construction

> std::array&lt;std::array&lt;int,3&gt;,3&gt; face_id_grid{{{{-1,-1,-1}},{{-1,-1,-1}},{{-1,-1,-1}}}}; // 3x3 unfolded faces id

==&gt; This seems to be because std::array is a struct with the array as a member?

==&gt; Also, in some cases the extra nesting may be eluded which actually adds to the confusion when this can't be done...

7) No standard graphical library to visualise 2D nor 3D objects

> A lot of the puzzles involve traveling a 2D space.

> This can sufficiently be simulated and rendered to the screen using std::cout;

> But it is a lot of pain to write all operator&lt;&lt; for the objects to be rendered.

> And 3D rendering is simply out of the question...

==&gt; What support functionality can I implement to help me visualise these things?

...

{% endraw %}
