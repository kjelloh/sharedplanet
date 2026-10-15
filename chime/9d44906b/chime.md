# Todo: Programming - Consider to study and try out Windows GUI automation frameworks?

```#9d44906b``` *As of 2015-12-05 19:06*

[mail plain/text](mail.txt)

{% raw %}
Would it not be nice to be able to automate any windows application by simply driving the application thought its existing GUI interface (e.g. to automate creation of Visual Studio Console projects from c++ boost examples ).

1) This is one tool I found in just a first search on the web (<https://www.autoitscript.com/site/autoit/> )

2) Here is one that had the same thought back in 2008 (<http://www.codeproject.com/Articles/22559/Driving-or-Automating-GUI-Applications> )

3) Automata (389 Euro) seem a more mother tool (<http://www.getautoma.com> )?

==&gt; Here seem to be the python scrip-interface of Automata (<http://www.getautoma.com/docs> )?

==&gt; Here is a pdf of the Automata Python interface (<http://www.getautoma.com/files/docs/AutomaAPIDocumentation.pdf> )

4) What Windows API:s are available to operate the GUI of an application?

==&gt; Here is a thread asking this question with seemingly good answers (<https://social.msdn.microsoft.com/Forums/windowsdesktop/en-US/5cb52362-f470-489d-8898-7d3375dbeb1b/windowsguiautomation?forum=windowsaccessibilityandautomation>)?

==&gt; This seem to be msn article for “Windows API Automation” (<https://msdn.microsoft.com/en-us/library/ff486375(v=VS.85).aspx> )

> The Windows Automation API is designed for experienced C/C++ developers. In general, developers need a moderate level of understanding about Component Object Model (COM) objects and interfaces, Unicode, and Windows API programming.

==&gt; Here is msdn “UI AUtomation Specification” (<https://msdn.microsoft.com/en-us/windows/bb892135.aspx> )

> The UI Automation Specification provides information about Microsoft's accessibility frameworks, including Active Accessibility, UI Automation, and UI Automation Express

==&gt; The Windows Automation API is only available up to Windows 7?

> The Windows Automation API is supported on the following operating systems: Windows XP, Windows Server 2003 R2, Windows Vista, Windows 7, and Windows Server 2008 R2

==&gt; No - It seems to be in Windows 8 to (<https://msdn.microsoft.com/en-us/library/windows/desktop/hh437316(v=vs.85).aspx> )

==&gt; Seems the application needs to be and all standard windows controllers already are “UI Automation Providers” (<https://msdn.microsoft.com/en-us/library/windows/desktop/ee671597(v=vs.85).aspx> )

> Microsoft includes a provider for each of the standard controls that are supplied with Microsoft Win32, Windows Forms, and Windows Presentation Foundation (WPF). This means that the standard controls are automatically exposed to UI Automation clients; you do not need to implement any accessibility interfaces for the standard controls.

==&gt; Seem WPF is the lastest framework for Windows Application GUI (<https://msdn.microsoft.com/en-us/library/aa970268(v=vs.100).aspx> )

> Windows Presentation Foundation (WPF) is a next-generation presentation system for building Windows client applications with visually stunning user experiences. With WPF, you can create a wide range of both standalone and browser-hosted applications.

==&gt; Sidenote: Writing C++ applications with WPF GUI is not a good idea (<http://stackoverflow.com/questions/4776355/does-wpf-work-with-c> )

==&gt; But having a C++ application automate the GUI of another one as an UI Automation Provider should be ok?

==&gt; Seem Windows Automation API is win32 only which means win64 interoperability issues (<https://msdn.microsoft.com/en-us/library/windows/desktop/ee872017(v=vs.85).aspx> )

5) This seem like a good starting point to learn about how to Automate a Windows GUI application (UI Automation Provider) (<https://msdn.microsoft.com/en-us/library/windows/desktop/dd561882(v=vs.85).aspx> )?

==&gt; Don’t confuse with older “Microsoft Active Accessibility Architecture” (<https://msdn.microsoft.com/en-us/library/windows/desktop/dd561918(v=vs.85).aspx> )

> The Windows Automation API consists of two technologies—Microsoft Active Accessibility and Microsoft UI Automation. Microsoft Active Accessibility is the legacy accessibility technology that was introduced as a platform add-in for Windows 95, while UI Automation is a newer, more capable technology that overcomes the limitations inherent in Microsoft Active Accessibility.

==&gt; Here is the UI Automation Specification (<https://msdn.microsoft.com/en-us/library/windows/desktop/dd561923(v=vs.85).aspx> ).

==&gt; Here seem to be a good page for writing UI Automation C# clients (<https://msdn.microsoft.com/en-us/library/aa348551(v=vs.110).aspx> )?

6) This seem to be thread with good leads based on trying to automate a delphi application (<https://social.msdn.microsoft.com/Forums/windowsdesktop/en-US/009b814c-0755-40b4-a035-a4fa1fd74cb3/ui-automation-for-delphi-application?forum=windowsaccessibilityandautomation> )?

==&gt; Seem the deplhi application needs some tweaking to have its controls exposed properly as “UI Automation Providers”?

> For future references. You can achieve that by implementing custom, overridden UIAutomation providers. The easiest solution is to create descendant classes based on the controls you use, e.g. TEdit -&gt; TAutoEdit. You need to catch WM_GETOBJECT in your new controls and return your custom provider. In the custom provider you simply implement the properties, you need.

7) So, key thing is to find out how to build a “UI Automation Client”?

==&gt; This page (UI Automation Client Programmer Guide) seem to be a good starting point (<https://msdn.microsoft.com/en-us/library/ee684021(v=vs.85).aspx> )?

1. Obtain an instance of the CUIAutomation object.

#include &lt;uiautomation.h&gt;

// CoInitialize must be called before calling this function, and the  
// caller must release the returned pointer when finished with it.  
//

HRESULT InitializeUIAutomation(IUIAutomation \*\*ppAutomation)

{

return CoCreateInstance(

CLSID_CUIAutomation

,NULL

,CLSCTX_INPROC_SERVER

,IID_IUIAutomation

,reinterpret_cast&lt;void\*\*&gt;(ppAutomation));

}

1. Retrieve IUIAutomationElement interfaces for UI elements from the UI Automation tree.

See (<https://msdn.microsoft.com/en-us/library/ee671590(v=vs.85).aspx> )

1. Retrieve UI element properties and invoke UI element functionality.

See (<https://msdn.microsoft.com/en-us/library/ee671593(v=vs.85).aspx> )

1. Respond to UI Automation events.

See (<https://msdn.microsoft.com/en-us/library/ee671220(v=vs.85).aspx> )

8) Consider to study Embarcadero COM wrapper functionality to auto-generate client interface to a UI Automation Provider application (e.g. the TestBench)?

a) See "Todo: Programming - Understand RAD Studio "Import Component" behaviour and functionality”

...

{% endraw %}
