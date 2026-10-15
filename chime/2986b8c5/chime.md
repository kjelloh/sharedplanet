# Todo: Programming - Consider to list what Interaction-Design-Patterns we can identify in System Designs?

```#2986b8c5``` *As of 2016-05-09 19:37*

[mail plain/text](mail.txt)

{% raw %}
So, can we imagine to model normal function calls, client server interaction and beyond as different instantiations of Interaction-Design-Patterns?

1) Consider synchronous function calls as stack-defined interaction?

==&gt; Each call results in a new stack-layer and the return collapses the stack again.  
==&gt; Can we imagine this as a synchronous interaction with the interaction state defined by the stack-state?

2) Consider to find a model for Resumable Function Calls (Coroutines)?

==&gt; The interaction is asynchronous (it returns a future)  
==&gt; The state of the interaction is not defined by the stack (in fact the function no longer exists on the stack after first return)?  
==&gt; Consider the state of the interaction is defined by the future?

3) Consider the client server design pattern as incomplete to define all aspects of an interaction?

==&gt; The client is just the one who initiates the operation and the server is the one who carries it out.  
==&gt; The term does not say anything about the nature of the interaction (e.g., is the interaction synchronous or asynchronous)?  
…

4) Consider to name an interaction where the result of an operation is returned at a later time (asynchronous)?

==&gt; Synchronous or asynchronous return of result seem to be one dimension of an interaction?  
…

5) Consider the Request-Response interaction is one of the patterns we should have in the list?

==&gt; The Request-Response Interaction may be synchronous or asynchronous?

==&gt; Synchronous Request-Response may be stacked-defined (local) or Message based (request -response with remote node)?

==&gt; In the Request-Response pattern the request must carry the address to where to send the response?

==&gt; For stack-based interaction the return address is pushed on the stack.

==&gt; In message request-response interaction the return-adress (the caller) must be in the request.

==&gt; For session-based interactions the return-adress is implicit by the established session?

==&gt; This means that if the session is broken the callee will be unable to return the response (unless it can also repair the connection, i.e. actually stored the return adress)?

==&gt; As in a TCP-connection the callee knows the caller as the other side of the connection?

==&gt; This most TCP-based messaging protocols does not define the return-adress in the messages?

6) Consider interactions that relates to the same super-interaction but involves multiple participants?

==&gt; Consider a Card Payment Transaction where several unique ID:s are used to have all participants perserve the information about the original authorised financial transaction between the card-holder and a merchant?

==&gt; Consider a name for the Design Pattern that models this type of interaction(s)?

==&gt; Note it is always two participants that define the super-interaction (e.g. the Merchant and the card-holder)?

==&gt; And all sub-interactions just relates to this super-interaction (e.g. authorisation, presentment, clearing and settlement for a Card Payment)?

==&gt; Consider if ether are other multi-participant interactions that does not model the Card Payment Interaction?

==&gt; Can we imagine the Darwinet P2P state synchronisation as a multi-participant self-organising state-interaction Design Pattern?

…

7) Consider the “Saga Interaction Pattern” as defined by Roland Kuhn in this talk at 32:00 (<https://www.youtube.com/watch?v=r4bJqgqpsIQ>)?

“Divide long-lived distributed transactions into quick local ones with compensating actions for recovery”

==&gt; It seems to relate somewhat to the super-sub-interaction pattern discussed above?

==&gt; At 35:00 he actually refers to bank account transfers as an example of the Saga pattern?

==&gt; A transfer from source bank account to target bank account shall happen without locking both at once.

==&gt; So divide the transfer into two transactions.

==&gt; Transfer (T1) from the source account to a local account.

==&gt; Transfer (T2) money from local account to target account.

==&gt; Compensate failure by transferring money back again (aha, reversal)

5) Consider event interactions between two equal peers (no specified client or server)

==&gt; In this model both peers may be viewed as equally event driven?

==&gt; Consider that Peers may request operations or emits events (different interaction patterns)?

==&gt; Should we model a Peer that requests something from another Peer as a client-server interaction?  
==&gt; Should we focus on having pure event driven Peers as the special P2P case here?

==&gt; Consider the special about P2P interaction is the one where the nodes self-organise by emitting and processing events?

==&gt; If so, should we then have no explicit “requests”, just events of “need”?  
==&gt; Any Peer may decide to provide the “need” of another node (decide to “serve” the request)?  
…

6) Consider if asynchronous views of digital worlds are a design pattern of its own?

==&gt; Consider this model to be about having a digital world of “entities” (asynchronous operations) and “objects” (data models)?  
==&gt; Consider the world allows views to bind to different world states?  
==&gt; The view is asynchronously updated by the world when the viewed state changes?

==&gt; Consider object values and operation state and result to be viewable states?  
==&gt; Consider existence of entities and objects to be viewable states?  
==&gt; Consider the world-model to be a viewable state (as in what entities and objects that may be created)?

==&gt; Consider to relate this to the MIV model that seem to be very much about representing a “viewable digital world”?  
==&gt; In fact, viewing a “digital world” is to view its “evolution” (view how it changes)?  
…  
…

Consider to elaborate into this idea that we can imagine just a limited set of Interaction-Design-Patterns that all System Interactions fall into?  
...

{% endraw %}
