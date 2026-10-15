# Todo: Programming Elm Idiom C++ - Consider how we may use the Elm Idiom run-time with an immutable application state (model) to provide different user front-ends to the same core (run-time) and back-end (update)?

```#87b55061``` *As of 2017-07-25 21:25*

[mail plain/text](mail.txt)

{% raw %}
Consider it would be possible to apply the Elm run-time idiom with an immutable application state to implement an application architecture where we may hook different user front-ends (views) to the same core (run-time) and back-end (update)?

-1) It seems the view function should actually change with the actual Client View (Different Model -&gt; View and different View object depending on Client View)?

==&gt; It seems from the Elm run-time we learn that the View is actually a representation of the actual GUI (both output and input)?

==&gt; This follows from Elm using an HTML DOM as the view object (thus specialised for the Web UI it uses)?

==&gt; Thus, a Console UI would use a View object with display texts and a prompt while a Windows user interface would use a VCL-like representation?

…

==&gt; Note: Don’t forget all data is immutable and thus the view function can be free (it has no use of an object state)

==&gt; The same goes for the update function of course.

...

==&gt; Consider a Console Client View (and thus view function) should differ from the ones for a Windows user interface?

==&gt; In the Console Client View we have Text inout and output (and a prompt) and thus the View object should carry such information?

==&gt; While in a Windows User Interface we have a hierarchy of buttons, edit boxes and panes (and thus the View object is this very structure)?

…

==&gt; Although, then the application state (the Model) should not carry Console prompt or text in/out information?

==&gt; Instead the View object for the console should be able to generate such information from the Model?

==&gt; E.g., a Chord Chart application updates a beat in the model and the view generates a text representation of the beats in the Console View object?

...

==&gt; Consider making the view function call the actual user interface code itself (run-time gets no return from view call)?

Elm run-time idiom for different User Interface Views

---------------------------------------------------------------------------------

| |

| Asynchronous IO Declares: Model, Msg {msg_1…msg_n} and View |

| | Defines: subscriptions, update and view |

| v |

| subscriptions update |

| ^| ^| Business |

---------||-------------------------||-------------------------------------------

|| ||

|| ||

|| (5.2) 0.1 || (1)

(4.2) || { Model { Model 6.1 || { Mod Model

{ Model || ,Sub Msg} ,Msg} 6.2 || ,Cmd Msg}

,Msg} |v 1.1 |V

---------------------------------------------------------------------------------

| run-time |

| Declares decorators: Mod, Sub, Cmd, Op |

| run defines: run |

| ^ n registered UIs |

--------|------------------------------------------------------------------------

(0) |  (5.1) ^ | (1.2)

{Model |  {Op Msg} | | {Mod Model}

,Msg} |  | |

---------------------------------------|----------------|-------

| User Interface n | v |

| view

Each UI has | | (2) .

its own | | { View | Direct =

view: Model -&gt; View | | ,Op Msg} | not through

And makes asynchronous | | | run-time...

call-backs to run-time | | (3) .

| | {View, Op Msg}

| v

-------------------------- 0..\* Clients (all sharing Model state)

| |

| Some Model Client |

| |

| Asynchronous Event

| | (4.1) : Relation between Client Events

| v : and Op Msg is defined by View

| View ------&gt; Op Msg object (created by view function)

|

| |

--------------------------

...

==&gt; Consider making the view function part of the attached user interface (still piping view call and return through run-time)?

Elm run-time idiom for different User Interface Views

---------------------------------------------------------------------------------

| |

| Asynchronous IO Declares: Model, Msg {msg_1…msg_n} and View |

| | Defines: subscriptions, update and view |

| v |

| subscriptions update |

| ^| ^| Business |

---------||-------------------------||-------------------------------------------

|| ||

|| ||

|| (5.2) 0.1 || (1)

(4.2) || { Model { Model 6.1 || { Mod Model

{ Model || ,Sub Msg} ,Msg} 6.2 || ,Cmd Msg}

,Msg} |v 1.1 |V

---------------------------------------------------------------------------------

| run-time |

| Declares decorators: Mod, Sub, Cmd, Op |

| run defines: run |

| ^ |

--------|------------------------------------------------------------------------

(0) | (1.2) ^| (2) (5.1) ^ | (3)

{Model |  {Mod Model} || { View {Op Msg} | | {View, Op Msg}

,Msg} |  || ,Op Msg} | |

|| | |

----------------------------------------------------------------

| || User Interface X | | |

|v | |

view | |

| v

-------------------------- 0..\* Clients (all sharing Model state)

| |

| Some Model Client |

| |

| Asynchronous Event

| | (4.1) : Relation between Client Events

| v : and Op Msg is defined by View

| View ------&gt; Op Msg object (created by view function)

|

| |

--------------------------

==&gt; It seems the run.time decorators Mod, Sub, Cmd and Op should remain View and Model independent?

1) Consider what needs to change to hook different types of Views (front-ends) to the same application state and run-time?

==&gt; Consider the run-time used in project ”/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyDataModelPlayground/MyDataModelPlayground”?

> Generic Elm run-time System Model

> ---------------------------------------------------------------------------------  
> | |  
> | Asynchronous IO Declares: Model, Msg {msg_1…msg_n} and View |  
> | | Defines: subscriptions, update and view |  
> | v |  
> | subscriptions update view |  
> | ^| ^| ^| Application |  
> ---------||-------------------------||--------------------------||---------------  
> || || ||  
> || || ||  
> || (5.2) 0.1 || (1) (1.2) || (2)  
> (4.2) || { Model { Model 6.1 || { Mod Model {Mod Model} || { View  
> { Model || ,Sub Msg} ,Msg} 6.2 || ,Cmd Msg} || ,Op Msg}  
> ,Msg} |v 1.1 |V |v  
> ---------------------------------------------------------------------------------  
> | run-time |  
> | Declares decorators: Mod, Sub, Cmd, Op |  
> | run defines: run |  
> | ^ |  
> --------|------------------------------------------------------------------------  
> (0) | (5.1) ^ | (3)  
> {Model | {Op Msg} | | {View, Op Msg}  
> ,Msg} | | v  
> -------------------------- 0..\* Clients (all sharing Model state)  
> | |  
> | Some Model Client |  
> | |  
> | Asynchronous Event  
> | | (4.1) : Relation between Client Events  
> | v : and Op Msg is defined by View  
> | View ------&gt; Op Msg object (created by view function)  
> |  
> | |  
> --------------------------

> ==&gt; (0) The run-time is called with the initial Model and Msg (to get things started)

> ==&gt; (0.1) After 0 - initial update with init value {Model, Msg} (defined Model and Msg = msg_1…msg_n}

> ==&gt; (1) update returns new model state (persistent data structure = new instance) according to Msg  
> ==&gt; (1.1) After 1 if Cmd Msg - recurse update with Msg (enables update to iterate with itself with internal Cmd Msg)  
> ==&gt; (1.2) After 1 if No Cmd Msg - calls view function (To create a View of current Model)  
> ==&gt; (2) view returns new View Op (a Client representation of current model state update)

> ==&gt; (3) run-time sends View Op to Client

> ==&gt; (4.1) Asynchronous - Client acts on some event and calls View to create appropriate Op Msg response.  
> ==&gt; (4.2) Asynchronous - run-time calls subscriptions is to get any external pending events as Sub Msg.

> ==&gt; (5.2) After 5.1, The Client returns Op Msg generated by View object in response to Client Event.  
> ==&gt; (5.2) After 4.2, subscriptions returns any received external event as Sub Msg.

> ==&gt; (6.1) After 5.1 - updates model according to Msg received from Client  
> (6.2) After 5.2 - updates model according to any Msg in Sub Msg from subscription (external event receiver)

2) Consider an Elm Idiom run-time to display and edit sheet music imported from iREalPro?

==&gt; See ”/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyIRealProURLReader/MyIRealProURLReader” (Now using Elm run.time idiom)

Elm Idiom run-time for a chord chart app (e.g., ”/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyIRealProURLReader/MyIRealProURLReader"

---------------------------------------------------------------------------------

| |

| Asynchronous IO Declares: Model, Msg {msg_1…msg_n} and View |

| | Defines: subscriptions, update and view |

| v |

| subscriptions update view |

| ^| ^| ^| Application |

---------||-------------------------||--------------------------||---------------

|| || ||

|| || ||

|| (5.2) 0.1 || (1) (1.2) || (2)

(4.2) || { Model { Model 6.1 || { Mod Model {Mod Model} || { View

{ Model || ,Sub Msg} ,Msg} 6.2 || ,Cmd Msg} || ,Op Msg}

,Msg} |v 1.1 |V |v

---------------------------------------------------------------------------------

| run-time |

| Declares decorators: Mod, Sub, Cmd, Op |

| run defines: run |

| ^ |

--------|------------------------------------------------------------------------

(0) | (5.1) ^ | (3)

{Model | {Op Msg} | | {View, Op Msg}

,Msg} | | v

-------------------------- 0..\* Clients (all sharing Model state)

| |

| Some Model Client |

| |

| Asynchronous Event

| | (4.1) : Relation between Client Events

| v : and Op Msg is defined by View

| View ------&gt; Op Msg object (created by view function)

|

| |

--------------------------

==&gt; Consider what the Application State (The Model) should be?

Model

SongList

Name

Songs

Song

e1 := Song Name

e2 := Author

e3 := ??

e4 := Style Variant (Combines with Song Style)

e5 := Key Signature

e6 := ??

e7 := Chord Chart

Slots

Slot

&#91;Chord&#93;

Symbols = N.C | % | %% | … (See <https://sv.wikipedia.org/wiki/Symboler_i_notskrift>)

&#91;Text&#93;

e8 := Song Style

e9 := Tempo

e10 = Repeats

e11 := song_list_separator_1 (null)

e12 := song_list_separator_2 (null)

Song

...

Song

...

Song

...

==&gt; Consider to implement a Windows view that provides the user with the same actions and feed-back?

![](<iRealPro Main Window.jpeg>)

==&gt; The left pane are songs organized into list based on different criteria (All songs, last viewed, last edited, last imported, play lists…)

==&gt; The middle pane lists songs in the grouping selected in the left pane.

==&gt; The right pane shows the chord chart of song selected in the middle pane

==&gt; Consider the iRealPro chord chart pane?

==&gt; Consider this pane defines 12 rows times 16 Slot chord chart (192 possible slots = maximum 192 chord song)

==&gt; This thread seem to confirm this (<http://www.irealb.com/forums/showthread.php?2157-BEGINNERS-start-here&p=25854#post25854>)?

![](<iRealPro Chord Chart Pane Example.jpeg>)

![](<iRealPro Command Bar.jpeg>)

![](<iRealPro Slot Edit Floating Window.jpeg>)

==&gt; It seems the application state (the model) must carry also View state (what is editable, what is enabled/disabled…)

==&gt; Or, the view function must be able to create a View State from data in the model?

==&gt; Note: The view function maps the Model (state) to a View (it can’t store state itself)!

**==&gt; Thus -&gt; Anything the user see must come from the Application state!**

==&gt; Consider the user actions must be totally defined in a set of Messages (from user to model update)?

User Action -&gt; Msg -&gt; **update** -&gt; New Model

==&gt; Consider the user View must be totally defined from the View object created from the application model?

New Model -&gt; **view** -&gt; View -&gt; User ViewPort

==&gt; Thus, we may design all required Messages as well as the Model and View contents from the Model, View update loop?

Front End Run-Time

-------------------- ------------------------

| |

| | Model

| | Msg State

------------+--+---&gt;---&gt; **update** -------&gt; **view**

| | | |

User Action  -&gt; View.**process** | | |

| | | |

User Sensation &lt;- **show(View)** | | |

^ | | View |

| | | State |

------------+--+--&lt;---------------------

| |

-------------------- ------------------------

3) Consider a Console View and a Windows View may use the same Messaging and View Model?

==&gt; Consider a Console View

User Actions

Enter Add empty Slot + move to next slot

Chord + Enter Set Chord + move to next slot

Select Slot  Show Slot, Row, System

Symbol + Enter  Show Slot, Row, System

Text + Enter  Show Slot, Row, System

|

| **Console**

| Front End Run-Time

| -------------------- ------------------------

| | |

| | | Model

| | | Msg State

| ------------+--+---&gt;---&gt; **update** -------&gt; **view**

| | | | |

User Action  -&gt; View.**process** | | |

| | | |

User Sensation &lt;- **show(View)** | | |

| ^ | | View |

| | | | State |

| ------------+--+--&lt;---------------------

| | |

| -------------------- ------------------------

|

v

Show Current Bar

Show Current Row

Show Whole Chord Chart (16 x 12, ...)

==&gt; Consider a Window View

User Actions

![](<iRealPro Slot Edit Floating Window.jpeg>) —&gt; Each Entry = One **Msg**

|

| **Window**

| Front End Run-Time

| -------------------- ------------------------

| | |

| | | Model

| | | Msg State

| ------------+--+---&gt;---&gt; **update** -------&gt; **view**

v | | | |

User Action  -&gt; View.**process** | | |

| | | |

User Sensation &lt;- **show(View)** | | |

| ^ | | View |

| | | | State |

| ------------+--+--&lt;---------------------

| | |

| -------------------- ------------------------

|

v

![](<iRealPro Main Window.jpeg>)

4) Consider to try and implement a Microsoft Windows VCL Front-end based on existing View and set of User Action Messages?

==&gt; Consider what we need to do to implement the actual window user interface in VCL in RAD Studio?

…

5) Consider What we need to do to implement the windows user interface using Electron Javascript Web-browser framework (<https://electron.atom.io>)?

==&gt; Consider Visual Studio Code and Atom Editor are implemented using Electron fro cross platform UI?

…

…

Consider to try out and delve deeper into this idea of separating the User interface from the business logic using the Elm Idiom run-trime and view of immutable State (Model)?

...

{% endraw %}
