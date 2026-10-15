# Todo: Programming - Understand RAD Studio "Import Component" behaviour and functionality

```#3ef0a0c8``` *As of 2015-12-05 18:27*

[mail plain/text](mail.txt)

{% raw %}
The RAD Studio “import component” wizard seems like a good tool to easily create VCL components to use COM and Active X interfaced objects. But I never got the hang of where the generated files go, what gets installed and how to keep everything at one place to have it under proper version control.

1) The generated bpd-file always gets built to the global folder "C:\\Users\\Public\\Documents\\Embarcadero\\Studio\\15.0\\BPL”

==&gt; And automatically installed packages refers to the bpd-file in this directory.

==&gt; This means these locally generated packages are NOT distributable to other machines and applications using components in such a package will fail (they are not available not installed on the other machine)

2) These steps seem to be one way of creating a project folder structure holding all files to build a package for one imported type library based component.

==&gt; Start by creating a project folder for the new project we are to create (the wizard we will use does not allow creation of new folders)

![](RAD_Import_Component_0.tiff)

==&gt; In this case the new folder “MyImportComponentTestPackage1”

==&gt; Open RAD Studio and Ensure no current project is open.

==&gt; Select &lt;Component&gt; / &lt;Import Component&gt;

![](RAD_Import_Component_1.tiff)

==&gt; In this case VCL for C++ and Next.

![](RAD_Import_Component_2.tiff)

==&gt; In this case Import a Type Library and Next

![](RAD_Import_Component_3.tiff)

==&gt; Search for the Type Library to import. In this Case UIAutomation. In this case select UIAutomationCoreRes and Next.

![](RAD_Import_Component_4.tiff)

==&gt; Select “Generate Component Wrappers” (To enable created component to work in design time of the IDE)

==&gt; Define “Unit Dir Name” to be in the folder of the Project we are in the work of creating (i.e. press ellipsis (…) button and create the proper project folder)

![](RAD_Import_Component_5.tiff)

==&gt; Select the Project folder we created above for the package project we are creating to build imported component - then OK and Next in the wizard.

![](RAD_Import_Component_6.tiff)

==&gt; Select “Install to New Package” (To have RAD Studio create a new project for the package holding the imported component)

![](RAD_Import_Component_7.tiff)

==&gt; Define the package name and folder by clicking the ellipsis (…) button and browse to our project folder created and used above

![](RAD_Import_Component_8.tiff)

==&gt; In this case we named the package as the project folder (my own standard). Click &lt;Save&gt; and then wizard &lt;Finish&gt;.

![](RAD_Import_Component_9.tiff)

==&gt; The wizard now detects the project we create needs VCL support. Click &lt;Yes&gt; to have it added.

![](RAD_Import_Component_10.tiff)

==&gt; The wizard now saves generated project files. Note that the wizard suggests the correct project folder. Then accept with &lt;Save&gt;

![](RAD_Import_Component_11.tiff)

==&gt; The wizard now builds and installs the package.

3) Seems that if we would like a version controlled project use installed VCL components produced by other version controlled package project we should put the bpl-file under version control and make the bpd-project part of the project group?

==&gt; Building the bpd-project will trigger RAD Studio to also install the build component?

…

Consider to delve into this RAD Studio “Import Component” more to understand the other variants to use the wizard?

a) What is “Install to Existing Package”? Will that add the imported component to an existing bpl-project?

b) What is “Crate Unit” (and how does it differ from “Install to Existing Package”?

...

{% endraw %}
