# Todo: Let the Darwinet framework be message based MVC to map good to Cocoa, Swift and VCL mechanisms

```#151f3e90``` *As of 2015-08-13 15:02*

[mail plain/text](mail.txt)

{% raw %}
It seems the MVC Object oriented design of Apple OS:s and Embarcadero VCL maps very well to the same paradigm.

1) Messaging is asynchronous.  
2) The view commands the controller that updates the model. In VCL the view triggers and event that the controller acts on in an event handler that sets variables to new states.  
3) In Swift the Controller never accesses the view! This shows in the design paradigm that a controller class never imports UI classes (as emphasized in https://www.youtube.com/watch?v=OJUsghbtbF8 round 6-8 minutes in). Instead it shall be the view that gets told by the controller when to change the view (as shown in the same video round 60-62 minites in).

This would suggest that if we make the Darwinet API be MVC-based it will fit very well with the Swift and VCL frameworks.

a) Note that the View shall then actually be implemented by the client, not Darwinet! A Darwinet view exposes the data model! Consider to rename ”Darwinet View” to ”Aspect” or ”viewPoint”? I propose ViewPoint!  
b) Darwinet should expose a MIV controller for the client View to interact with. As stated above the MVC-design preferred by Swift lets the controller be the intermediator between the View and the Model (in our case the MIV). Thus, the client view should command the controller to change and the controller shall tell the view how to update in response to changes!

{% endraw %}
