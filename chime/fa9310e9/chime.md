# Todo: Consider to document the C++ traps i fell into while solving Advent of Code puzzles?

```#fa9310e9``` *As of 2023-01-06 13:30*

[mail plain/text](mail.txt)

{% raw %}
1) signed vs unsigned integers for operator&lt;

> day22

> This is NENEVR true!

> if (m_bottom_right.col &lt; row.size()-1) {

> This works as intended.

> if (m_bottom_right.col &lt; static_cast&lt;Result&gt;(row.size()-1)) {

2) signed vs unsigned for operator-

> day22

> This results in a very large unsigned integer!

> > auto diff = m_bottom_right.col - (row.size() - 1);

3) C++ operator% on negative lhs

> day??

> rhs % lhs is NEGATIVE if rhs is.

> -10 % 9 == -1 (NOT 8)

4) C++ operator% with unsigned rhs

> day??

4) std::accumulate using literal integer as start value

> year?? day??

> auto result = std::accumulate(begin,end,1)

> result will have the type UNSIGNED (not the type of \*begin)!

...

{% endraw %}
