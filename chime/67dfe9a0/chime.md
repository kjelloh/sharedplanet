# Todo: Tha model - Consider that namespaces and "scopes" in Tha is actually environments for identifier name look-up totally orthogonal to the value model itself?

```#67dfe9a0``` *As of 2017-08-05 18:32*

[mail plain/text](mail.txt)

{% raw %}
It seems we should create namespaces and “scope” as related to organisation and visibility of identifier names only. It seems it is totally orthogonal to the value model itself?

1) Consider identifiers “lives” in an environment?

==&gt; An identifier for any meta-value (any level) lives in the environment defined by the current “location" of the declaration?

int main() { // “main” is a member of global namespace (environment)  
int x; // “x” is a member of the namespace main within the global environment  
}

2) Consider namespaces (environments) are nested within and can “see” (specialise) its parent namespace (environment)?

==&gt; Consider nested namespaces?

namespace a {  
int x;  
namespace b {  
int y; // name “x” is visible here  
}  
// name “y” in “b” is NOT visible here  
}

3) Consider current environment is in fact a Tagged Set of visible namespaces?

==&gt; Consider the C++ using statement?

namespace a {  
using namespace std;  
// Here both identifiers in a, in parent namespaces of a AND the namespace std is accessible  
}

==&gt; Thus, to look-up an identifier the environment needs to search in all namespaces defined by the current namespace set AND the nested parent namespaces?

4) Consider that identifiers on meta-levels all exist in the same current namespace Set?

==&gt; Thus, it makes no sense to define meta-identifiers in some meta-namespace (just as C++ puts variable, type and template identifiers in the same namespace)?  
…

…

Consider to elaborate on this idea of namespaces organising identifiers regardless of meta-level?  
...

{% endraw %}
