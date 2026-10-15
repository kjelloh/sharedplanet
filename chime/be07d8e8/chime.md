# Todo: Programming - Consider to delve into interesting C++ error handling idioms Expected&lt;T&gt; and CodeGuard11 proposed by Andrei Alexandrescu at "C++ Beyond 2012"

```#be07d8e8``` *As of 2016-01-12 13:06*

[mail plain/text](mail.txt)

{% raw %}
Stumbled on a talk (<https://channel9.msdn.com/Shows/Going+Deep/C-and-Beyond-2012-Andrei-Alexandrescu-Systematic-Error-Handling-in-C?ocid=player>) made by Andrei Alexandrescu at "C++ Beyond 2012”.

1) Consider to delve into his proposed (and widely appreciated) proposal of Expected&lt;T&gt; (A Type which is either a T or an exception)  
...  
2) Consider to delve into his Scopeguard11 idiom (classes and macros to neatly handle nested cleanups and rollback when exception occurrs)  
…

3) The code may ve extracted from the slides published here (<https://j5uukg.dm2301.livefilestore.com/y3m_dAYDCRVnJvht6ZdPsaXtL2-T17eF18VlWXHdG4W06I-E7nVjJTtz-sRMgPr8dE9eHqvx2KMOCIbAYdlqUk4FaeA03YYzaEwZq81l2nOIm7qGi7O6uHE4sDLXhHB1fYw/ErrorHandling-slides.pdf?psid=1>)?

==&gt; On Win8 machine, Tested in RAD Studio project “C:\\Users\\kjell-olov\\Documents\\Embarcadero\\Studio\\Projects\\MyCppPlayGround1”

==&gt; On Win8 machine, Tested in VS2015 “c:\\Users\\kjell-olov\\documents\\visual studio 2015\\Projects\\ExpectedTest1\\ExpectedTest1\\ExpectedTest1.cpp"

#if __cplusplus &lt; 201103L  
#error "C++11 or higher required"  
// A C++03 Excpected&lt;T&gt; seems to be proposed at (<https://github.com/martinmoene/spike-expected/blob/master/expected_lite.hpp>)?

#endif // __cplusplus &lt; 201103L  
// ---------------------------------------------------------------------------  
#include &lt;exception&gt; // std::exception_ptr,...  
//#include &lt;algorithm&gt; // std::swap C++98  
#include &lt;utility&gt; // std::swap C++11  
#include &lt;typeinfo&gt; // typeid&lt;&gt;...  
// ---------------------------------------------------------------------------

/\*\*  
\* This is basically Andrei Alexandrescu proposal for Expected&lt;T&gt; presented in his talk at C++ and Beyon 2013  
\* TALK == See (<https://channel9.msdn.com/Shows/Going+Deep/C-and-Beyond-2012-Andrei-Alexandrescu-Systematic-Error-Handling-in-C?ocid=player>)  
\* Below, TALK&lt;time&gt; refers to a time into the talk  
\*  
\* Slides seem to be published here SLIDES == See (<https://j5uukg.dm2301.livefilestore.com/y3m_dAYDCRVnJvht6ZdPsaXtL2-T17eF18VlWXHdG4W06I-E7nVjJTtz->sRMgPr8dE9eHqvx2KMOCIbAYdlqUk4FaeA03YYzaEwZq81l2nOIm7qGi7O6uHE4sDLXhHB1fYw/ErrorHandling-slides.pdf?psid=1)  
\* Below, SLIDES&lt;description&gt; refers to a location in the slides  
\*  
\*/

// TALK&lt;00::22:00&gt; and SLIDES&lt;"Expected&lt;T&gt; Characteristics"&gt;  
// \* Associates errors with computational goals  
// \* Naturally allows multiple exceptions in flight  
// \* Switch between “error handling” and “exception throwing” styles  
// \* Teleportation possible  
// \* Across thread boundaries  
// \* Across nothrow subsystem boundaries ? Across time: save now, throw later  
// \* Collect, group, combine exceptions

template&lt;class T&gt;  
class Expected {  
union {  
T ham;  
std::exception_ptr spam;  
};

bool gotHam;

Expected() {  
} // used internally

public:  
Expected(const T& rhs) : ham(rhs), gotHam(true) {  
}

Expected(T && rhs) : ham(std::move(rhs)), gotHam(true) {  
}

Expected(const Expected& rhs) : gotHam(rhs.gotHam) {  
if (gotHam)  
new(&ham) T(rhs.ham);  
else  
new(&spam) std::exception_ptr(rhs.spam);  
}

Expected(Expected && rhs) : gotHam(rhs.gotHam) {  
if (gotHam)  
new(&ham) T(std::move(rhs.ham));  
else  
new(&spam) std::exception_ptr(std::move(rhs.spam));  
}

void swap(Expected& rhs) {  
if (gotHam) {  
if (rhs.gotHam) {  
using std::swap;  
swap(ham, rhs.ham);  
}  
else {  
auto t = std::move(rhs.spam);  
new(&rhs.ham) T(std::move(ham));  
new(&spam) std::exception_ptr(t);  
std::swap(gotHam, rhs.gotHam);  
}  
}  
else {  
if (rhs.gotHam) {  
rhs.swap(\*this);  
}  
else {  
// Try to figure out why Alexandrescu uses exception_ptr::swap that is not part of C++ and how to fix this problem?  
// Note: Compiles OK in VS 2015 (void std::swap(exception_ptr & _Lhs, exception_ptr & _Rhs) throw() in "c:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\include\\exception")  
spam.swap(rhs.spam); // swap is not a member of C++11 expetion_ptr  
// std::swap(spam,rhs.spam); // just swapping the "pointers" will probably not work /referenced instances will not be cloned?  
// A C++03 Excpected&lt;T&gt; seems to be proposed at (<https://github.com/martinmoene/spike-expected/blob/master/expected_lite.hpp>)?  
std::swap(gotHam, rhs.gotHam);  
}  
}  
}

// Begin "Building from exception"

template&lt;class E&gt;  
static Expected&lt;T&gt;fromException(const E& exception) {  
if (typeid(exception) != typeid(E)) {  
throw std::invalid_argument("slicing detected");  
}  
return fromException(std::make_exception_ptr(exception));  
}

static Expected&lt;T&gt;fromException(std::exception_ptr p) {  
Expected&lt;T&gt;result;  
result.gotHam = false;  
new(&result.spam) std::exception_ptr(std::move(p));  
return result;  
}

static Expected&lt;T&gt;fromException() {  
return fromException(std::current_exception());  
}

// Begin “Access"

bool valid() const {  
return gotHam;  
}

T& get() {  
if (!gotHam)  
std::rethrow_exception(spam);  
return ham;  
}

const T& get() const {  
if (!gotHam)  
std::rethrow_exception(spam);  
return ham;  
}

// Begin “Probing fro type”  
template&lt;class E&gt;  
bool hasException() const {  
try {  
if (!gotHam)  
std::rethrow_exception(spam);  
}  
catch (const E& object) {  
return true;  
}  
catch (...) {  
}  
return false;  
}

// Begin “Icing on the cake”

template&lt;class F&gt;  
static Expected fromCode(F fun) {  
try {  
return Expected(fun());  
}  
catch (...) {  
return fromException();  
}  
}  
};

4) Consider to delve into Expected&lt;void&gt; as suggested by this thread (<http://stackoverflow.com/questions/14923346/how-would-you-use-alexandrescus-expectedt-with-void-functions>)?

5) Consider to delve into how this fits into the design-pattern I always has used for error and exception handing?  
a) I have not had so much code that deals with rollback, and only basic cleanup of allocated memory and closing files (but most is done with RAII destructor constructs)  
b) Consider the impact of changing existing code into using Expected&lt;T&gt;?  
c) What about any benefits from mixing Expected&lt;T&gt; and ScopeGuard approach?  
d) How does Alexandrescus proposal match existing code in my programs?  
...

6) Consider to follow up on his statement about ”exception code being 50 times slower than error-code based handling” (At 15m 15s into his talk)

==&gt; Consider to refactor Testbench Data-representation-framework to not use exceptions (use Expected&lt;T&gt; instead)?

7) As sidenote: Study the kind-of-neat way of using a macro to generate truly unique variable names (concatenates a variable prefix with a preprocessor generated integer/counter) (about 1:23::00 into the talk)  
…

Consider to elaborate on these ideas and at least understand and remember them for future usage?  
...

{% endraw %}
