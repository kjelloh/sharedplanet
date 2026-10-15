# Todo: Build a simple Graph Drawing Application based on Boost graph library

```#5a6d1259``` *As of 2015-10-05 17:30*

[mail plain/text](mail.txt)

{% raw %}
Consider to write an application that is able to show a graph defined using boost graph library.

1) Build it as a FireMonkey application (better graphics apis?)

==&gt; Created C:\\Users\\kjell-olov\\Documents\\Embarcadero\\Studio\\Projects\\MyGraphApplication\\build in Windows 8.

2) Find examples on how to create a FireMonkey component in which we can draw.

==&gt; Tried building a primitive one based on TShape (<http://docwiki.embarcadero.com/RADStudio/Seattle/en/Step_1_-_Create_a_New_Component_using_the_New_Component_Wizard>). But then the new component did not have any Align-properties?

==&gt; But TShape has an Align property? Why is it not visible in our custom control?

==&gt; One has to explicitly state inherited properties as published to make them surface in the extended control (<http://docwiki.embarcadero.com/RADStudio/XE8/en/Publishing_Inherited_Properties_(Graphic))>

==&gt; So, question is what kind of control a Graph is? Is it a TShape or a TGraphicsControl?

==&gt; Ok, so TGraphicsControl does not exist! Seems a graph may be considered a shape?

![](TShape_Inheritage.tiff)

3) Create a simple boost graph and have it drawn in the FireMonkey controller.

&lt;151005&gt;

\*) Note that when creating a component the “Palette Page” determines where in the IDE Tool-palette the component will be found.

\*) And the Package is the bpd-project that defines the name of the package into which the created controls are installed.

\*) A package is modeled by the IDE as a project of its own.

\*) NOTE: RAD Studio does not suggest by default that the new package should be stored into a project folder of its own! (confusing). One has to create a folder and explicitly state for each of the component project files that they shall be stored into that folder.

==&gt; Why does not RAD Studio propose the approach to store each project in a folder of its own?

\*) To make inherited properties of a control “surface” to the inheriting control one has only to add it to the “published:” section.

class PACKAGE TBoostGraphView : public TShape  
{  
private:  
protected:  
public:  
__fastcall TBoostGraphView(TComponent\* Owner);  
__published:  
__property Align;  
};

{% endraw %}
