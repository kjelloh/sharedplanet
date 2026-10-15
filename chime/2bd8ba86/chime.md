# Todo: C++ - Study Herb Stutter proposals for asynchronous (Active) worker objects

```#2bd8ba86``` *As of 2015-12-01 15:46*

[mail plain/text](mail.txt)

{% raw %}
When searching for information about function and class template specialisation I stumbled cross Herb Stutter and liked his way of explaining c++ implementation of asynchronous computing.

1) Herb Sutter seems like a guy to turn to for explanation about c++ stuff (<http://www.gotw.ca>)?

2) He also blogs (<http://herbsutter.com>)

3) Here seems to be good input on asynchronous state-based worker (Active) objects: “Got state? Hide it! And if it's shared and either popular or slow, make it asynchronous...it's just good encapsulation" (<http://www.drdobbs.com/architecture-and-design/know-when-to-use-an-active-object-instea/227500074?pgno=1>)?

1

2

3

4

5

6

7

8

9

10

11

12

13

14

15

16

17

`// Example 3: Private -- expressed as active object (see &lt;a href="<http://www.drdobbs.com/go-parallel/article/showArticle.jhtml;jsessionid=VOJHXWYJKEAAZQE1GHPSKHWATMY32JVN?articleID=225700095>"&gt;&#91;3&#93;&lt;/a&gt; for details)`

`//`

`class` `AsyncLogFile {`

`public``:`

` ``void` `write( string str )`

` ``{ a.Send( &#91;=&#93; { ``log``.write( str ); } ); }`

`private``:`

` ``File ``log``; ``// private file`

` ``Active a; ``// private helper (queue+thread)`

`};`

`AsyncLogFile logFile;`

`// Each caller just uses the active object directly`

`string temp = …;`

`temp.append( … );`

`temp.append( … );`

`logFile.write( temp );`

==&gt; Active is a class hiding a thread and its thread-protected queue

==&gt; The Active instance is called using a lambda

4) It turns out the Active Pattern according to Stutter is hiding the asynchronous execution totally private behind an object interface (<http://www.drdobbs.com/parallel/prefer-using-active-objects-instead-of-n/225700095>)

“ \*) Keep data isolated, private to a thread where possible…

\*) Communicate among threads via asynchronous messages.

\*) Organize each thread's work around a message pump.”

5) Stutter outlines the Active object in C++ “classic style” here (<http://www.drdobbs.com/parallel/prefer-using-active-objects-instead-of-n/225700095?pgno=3>)

// Example 2: Active helper, in idiomatic C++(0x)  
//  
class Active {  
public:  
typedef function&lt;void()&gt; Message;

private:

Active( const Active& ); // no copying  
void operator=( const Active& ); // no copying

bool done; // le flag  
message_queue&lt;Message&gt; mq; // le queue  
unique_ptr&lt;thread&gt; thd; // le thread

void Run() {  
while( !done ) {  
Message msg = mq.receive();  
msg(); // execute message  
} // note: last message sets done to true  
}

public:

Active() : done(false) {  
thd = unique_ptr&lt;thread&gt;(  
new thread( &#91;=&#93;{ this-&gt;Run(); } ) );  
}

~Active() {  
Send( &#91;&&#93;{ done = true; } ); ;  
thd-&gt;join();  
}

void Send( Message m ) {  
mq.send( m );  
}  
};

class Backgrounder {  
public:  
void Save( string filename ) { a.Send( &#91;=&#93; {  
…  
} ); }

void Print( Data& data ) { a.Send( &#91;=, &data&#93; {  
…  
} ); }

private:  
PrivateData somePrivateStateAcrossCalls;  
Active a;  
};

==&gt; The “Backgrounder” simply implements the Active Object interface and defers interface calls to the aggregated Active object using “send”

==&gt; Calls are passed as functors (i.e. messages are functors). Thus the Active object manage a queue of functors to execute.

4) Result are returned as different types of Callbacks (<http://www.drdobbs.com/cpp/prefer-using-futures-or-callbacks-to-com/226700179?queryText=%2522Active%2BObject%2522>)

==&gt; “Option 1: Return a Future (Caller Naturally "Pulls”)"

future&lt;bool&gt; result = backgrounder.Save( filename );  
…  
… this code can run concurrently with Save()  
…  
Use( result.get() ); // block if necessary until result is available

==&gt; “Option 2: Return a Future (Caller Converts "Pull" Into "Push”)”

shared_future&lt;bool&gt; result;  
result = backgrounder.Save( filename );  
// queue up a continuation to notify ourselves of the  
// result once it's available  
result.ContinueWith(&#91;=&#93; { SendSaveComplete( result-&gt;get()); });

==&gt; “Option 3: Accept an Event or Callback (to "Push" to Caller)”

“just firing off an asynchronous method call and immediately returning is a good practice for callbacks”

class Backgrounder {  
public:  
void Save(

string filename,  
,function&lt;void(bool)&gt; returnCallback) {  
a.Send( &#91;=&#93; {  
// … do the saving work …  
returnCallback( didItSucceed() ? true : false );  
}

);

}

…

// pass a continuation to be called to give  
// us the result once it's available  
shared_future&lt;bool&gt; result = backgrounder.Save(

filename  
,&#91;=&#93; { SendSaveComplete( result-&gt;get() ); }

);

==&gt; “Getting Multiple or Interim Results”

“ • Provide an explicit message queue or channel back to the caller, which can enqueue multiple results.

• Accept a callback to invoke repeatedly to pass multiple results back to the caller."

...

5) This seem to be an “in depth” discussion about the Active, Concurrent Object and Actor, pattern (<http://www.cs.wustl.edu/~schmidt/PDF/Act-Obj.pdf>)

“The Active Object design pattern decouples method execution from method invocation to enhance concurrency and simplify synchronized access to an object that resides in its own thread of control"

6) There seem to be also the Proactor design pattern (<http://www.cs.wustl.edu/~schmidt/PDF/proactor.pdf>)

“The Proactor pattern supports the demultiplexing and dispatching of multiple event handlers, which are triggered by the completion of asynchronous events”

7) And the Reactor design pattern (<http://www.cs.wustl.edu/~schmidt/PDF/reactor-siemens.pdf>)

“The Reactor design pattern handles service requests that are delivered concurrently to an application by one or more clients"

…

Consider to try this out on the Testbench application?

{% endraw %}
