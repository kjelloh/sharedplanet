# Todo: Programming - Consider to write about how "Wining Code" kind of relates to C++ "Contracts"?

```#0fc6f593``` *As of 2016-01-14 11:52*

[mail plain/text](mail.txt)

{% raw %}
Studying the latest proposal for C++ “Contracts” it seems the “Wining Code” idiom is in fact a way to implement “Contract Violation”?

1) Consider Gabriel dos Reis Contract Proposal at 33:50 into talk (<https://channel9.msdn.com/events/CPP/CppCon-2015/CPPConD03V025>)?

==&gt; The C++ Contract pre-condition &#91;&#91;expects: &lt;predicate&gt;&#93;&#93; corresponds to LOG_DEISGN_INSUFFICIENCY for false predicate?

==&gt; Wining Code does not have any post-condition part (post-condition violation are caught by pre-condition Wining Code later on)?

==&gt; The C++ Proposal for Contracts is to use C++11 attribute-syntax &#91;&#91;&lt;attribute&gt;&#93;&#93; (<http://en.cppreference.com/w/cpp/language/attributes>)

2) Consider if there is a way to have Wining Code (LOG_DESIGN_INSUFFICIENCY) to close up to proposed C++ contracts?

==&gt; C++ Contracts may be disabled invisible to the ABI (Application Binary Interface) of the code.

==&gt; Wining Code can only disable LOG_DESIGN_INSUFFICIENCY (define macro empty) but the predicate is still active in the code.

==&gt; Could we make Wining Code removable by macros?

if (&lt;predicate&gt;) WINE({

})

else {

…

==&gt; If WINE macro is defined empty, then compiler will optimise away the if-clause?

3) Consider where Wining Code differs from C++ Contracts?

==&gt; LOG_DESIGN_INSUFFICIENCY focuses on detection of events (situations) that the code is not designed to handle.

==&gt; This is not always a Contract Violation (it may also be a valid event that just is not yet handled in code)?

==&gt; Thus, a Design Insufficiency sometimes lead to Contract Violation, but not always (sometimes the code just not yet fulfils the Contract)?

The Code Wines either for Contract Violation or Failure to comply with the Contract?(!)

…

Consider to elaborate more on this idea to have Wining Code close up to C++ proposal for contracts?

...

{% endraw %}
