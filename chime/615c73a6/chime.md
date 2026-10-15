# Todo: programming - Consider to design asynchronous "views" of some complete set of primitive and composite data models?

```#615c73a6``` *As of 2016-05-05 18:02*

[mail plain/text](mail.txt)

{% raw %}
Som what do we need to be able to asynchronously update views of some complete set of primitive and composite data models?

-1) Consider to implement the found interfaces as a C++ template library (compile time generated interface)?

==&gt; Can we imagine to model the found interfaces as C++ templates for easy creation of these kinds of interfaces?  
==&gt; Consider to have the library also enable compile time specialization using Reactor and Proactor design patterns?  
==&gt; Both Reacor and Proactor are, as defined, asynchronous processors of received events?  
==&gt; For the Reactor Design Pattern the EventHandler is called synchronously (e.g., using normal function call)?  
==&gt; For the Proactor Design Pattern the Event handler is called asynchronously (e.g. called using std::async)?

==&gt; Consider to have the interface define consumable events using a type list that translates to std::variant events of types of that list?  
==&gt; This would make it easy to define the interface (one may call it only with events defined by the variant)?  
==&gt; What mechanism can we imagine to give good compiler warnings if one tries to call the interface with invalid event?  
...

==&gt; Can we imagine to allow also synchronous interfaces to be defined (no Reactor nor Proactor behavior)?

==&gt; The callable interface still uses the same front-end (act-on-variant)?  
==&gt; But the event is processed directly using calling thread (i.e. call the dispatcher directly)?

==&gt; Can we even imagine having the front-end synchronous but allow a Proactor back-end?

==&gt; if so the call would result in the calling thread calls the dispatcher directly?  
==&gt; But the Dispatcher is a Proactor one (e.g., calling the Event Handler using std::async)  
==&gt; What options should we then provide to return the future Completion Result?

==&gt; Consider returning a future to the caller?  
==&gt; Consider having the caller provide a call-back?  
==&gt; Consider having the caller provide the dispatcher for the completion?  
==&gt; if the provided Dispatcher is a synchronous one, then the callers code will be called by the Proactors Event Handler Thread?  
==&gt; If the caller is itself a Reactor the Completion Dispatcher provided will just post the Completion to the caller?  
…  
...  
...

1) Consider an asynchronous interface to view unstructured data (PODs)?

==&gt; Such data requires no update of structure changes?

2) Consider an asynchronous interface to view composites?

==&gt; Such data requires update of the data structure (e.g. sequence insert)?

3) Consider to optimize view updates to only visible data?

==&gt; Consider that the view should be able to tell the interface what bindings that are at any time active (bound t a visible view)?  
==&gt; Consider if the information about visibility should be at the front-end sink as a filter or at the core source as a update-disabler?  
==&gt; Consider the extreme design that the view regieters and unregisters as a listener in synchronization with being visible or not?

4) Consider the signal design of asynchronous view update interface?

==&gt; Should the model register view-Ids to know where too post updates?  
==&gt; Should the front-end provide a single-sink and dispatch messages to adressed views?  
==&gt; In what ways can we imagine to short-cut update messages from each data model member to its corresponding view?  
==&gt; Consider to what degree we should aggregate larger ”chunks” of model members to reduce update messaging to the cost of sending larger chunks of data?  
==&gt; E.g., is it more efficient to send update of the whole visible part of a list rather than only the member that changed value?

==&gt; Should we consider data structure changes to be more expensive to update than unstructured value changes?  
==&gt; E.g., it seems updating the view to show adding a child to a tree node affects the view more than just changing a tree node value?  
==&gt; On the other hand, we can’t know if the added child node results in a visible change?  
==&gt; And the change of an unstructured data value may also result in a structural change in the view (if the value represents visible or structural information)?

5) Consider to what degree the data model may use memory bindings with the view?

==&gt; To what degree can we allow the data model to store pointers directly to view objects?  
==&gt; How do we handle asynchronous deletion of view objects if data model has pointers to them?  
==&gt; Do we in fact require double-references so that each side when deleted can tell the other side to unbind?  
...

6) Consider to model data using ”type” and ”Representation”?

==&gt; Is this even meaningful to design the view interface (does not a view implicitly apply a notion of ”representation”)?  
==&gt; Is it not even so that the ”view” defines a ”representation” of the value?

==&gt; Would this suggest that if the view interface would carry information about what a value represent we would be able to build self-created views (e.g. knows how to view text)?

7) So, what unstructured data can we imagine?

==&gt; Consider Integer?  
==&gt; Consider Character?  
==&gt; Consider Boolean?

==&gt; Consider the view interface of unstructured data to share common traits?

==&gt; Consider interface to handle existence of model value?

value view model value  
”Remove view” &lt;== deleted == ”Value instance deleted”  
?? &lt;== created == ”value created”  
When a value is created it can’t have a pre-existing view (no bound view)  
This message should be sent to the parent view (the view of the parent value)?  
In fact, both deleted and created should be sent to the parent value view?

==&gt; Consider interface to handle existence and visibility aspects of the view?

value view model value

”Created view" ==&gt; bind ==&gt; ”The view&#91;id&#93; is registered as listener to this value”  
”Value is visible” ==&gt; is_visible ==&gt; ”Register the view&#91;id&#93; as visible"  
”Value is invisible” ==&gt; is_hidden ==&gt; ”Register the view&#91;id&#93; as hidden"  
”deleted view” ==&gt; unbind ==&gt; ”The view&#91;id&#93; is unbound from value”

==&gt; Consider interface to handle value updates?

value view model value

”Update value" &lt;== value_update == ”The value in the view differs from the one in model”

7) So, what data structures can we imagine?

==&gt; Consider a vector (all members the same ”type")?  
==&gt; Consider a structure (different member ”types possible)?  
==&gt; Consider a Composite (members are of composite or unstructured ”type”)?

==&gt; Consider the view interface of structured data to share common traits?

value view model value

”View new structure” &lt;== structure_update == ”member added”ales?

This message should in fact be sent to the parent view (the view of the parent structured value)?  
It is the view of a structured value that knows how to change the view for structure member changes?

”Created view” ==&gt; bind ==&gt; ”The view&#91;id&#93; is registered as listener to this added value”

This message is actually sent by the new view created fro the added member value?

… In fact, all messaging for the added member value and view of that value is handled exactly as for all other v  
… If the added member is itself a structured value this pattern repeats for each new level of the composite?

8) Consider the interfaces we define to be exactly what a Darwinet Client would need and use?

==&gt; Also consider that the view interface may more-or-less mimic corresponding MIV Delta Interface between nodes?

==&gt; The only differences is that the MIV also handles model changes whilst the view only processes existence and value changes?  
...

…

Consider to elaborate more in this idea to identify common patters to asynchronously synchronize a view and a data model for primitive and composite views and values?  
...

{% endraw %}
