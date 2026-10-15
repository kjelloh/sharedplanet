# Todo: Programming - Consider the C++ Path library being able to construct compile-time Paths using actual C++ operator semantics?

```#f6b250b9``` *As of 2016-07-30 16:31*

[mail plain/text](mail.txt)

{% raw %}
Can we imagine that the C++ library may be implemented in such a way that a path may be constructed using actual C++ operator semantics?

1) Consider a Path must always have both a Text AND some C++ Semantic representation?

Path&lt;Node&gt; ==&gt; Text  // Shall always exist (user defined Node type)?  
Path&lt;Node&gt; &lt;== Text  // Shall Always exist (User defined Node type)?

Some-C++-Semantics ==&gt; Path&lt;Node&gt; // Shall Always exist?  
...

==&gt; Consider the Text representation is the one used in streaming and in Log entries for human reading?  
==&gt; Consider in this way the text representation may always be used in code (from string literals)?

==&gt; Consider constructors from Text must be constexpr to be used both compile time and run-time (same code)?

==&gt; Consider the text representation is the one to use for streaming (and thus always available also in code from string literals)?  
==&gt; Consider to implement Text—&gt;Path using user defined string literals (e.g., operator “”_path or “”_p)?  
==&gt; Consider NOT to implement Text—&gt;Node as this will create ambiguity in what to create from text (Node or Path)?

==&gt; Always decode to Path works as a node may always be represented as a single Node Path (and the opposite is not true)?  
…

==&gt; Consider the other option to be Path construction using C++ operator and member method syntax?

==&gt; Consider Path(“Node1”).(“Node2”).(“Node3”) (Implying “Node1” to path::Node construct exists)?  
==&gt; Consider Path(int1).(int2).(int3) (Implying Path::Node(integral type) is defined)?  
==&gt; Consider Path::Node::operator&#91;&#93; implies indexed Paths (and operator&#91;&#93; creates and appends an indexed node)?  
...

2) Consider Paths must always be encoded into the target environment (e.g. File Paths into FileSystem and registry Paths into Registry)?

==&gt; Consider Path::(“Users”).("kjell-olovhogdahl”).(“exercism”).("cpp”).(“bob”) becomes “Users/kjell-olovhogdahl/exercism/cpp/bob” on Linux/MacOS FileSystem?

==&gt; Consider semantics for Path encoding into target environment?

==&gt; Consider library add-on Path-gateways?

==&gt; ibi::gateway&lt;FileSystem&gt;::Path(path) creates a std::filesystem::path?  
==&gt; No, seems like a bad idea to have gateways members of the ibi namespace?

==&gt; Consider user-defined Path GateWays from Path library Paths?

==&gt; user_namespace::Path(ibi::Path p) creates a user environment Path from ibi Path?  
...

3) Consider to use all paths used in Testbench as a reference for what we would like to be bale to do?

&lt;File Paths&gt;

0D44:2015-09-24 11:20:12.771 BUSSINESS:Starting testbench=C:\\subversion\\babs_internal\\branches\\TestBench\\141001_RADStudioXE7_Code\\bin\\Debug\\Win32\\TestBench.exe

0D44:2015-09-24 11:20:12.942 DEVELOPMENT TRACE: 21CDD80 "runtime_environment.framework_path"=&gt;"C:\\subversion\\babs_internal\\branches\\TestBench\\141001_RADStudioXE7_Code\\bin\\Framework”

**==&gt; Path::Text “C:.subversion.babs_internal.branches.TestBench.141001_RADStudioXE7_Code.bin.Debug.Win32.TestBench.exe”?**

==&gt; NOTE: Separator ‘.’ will be confused with FilePath ‘.’ allowed in names and used as file-ending-separator!!

==&gt; Q: How do we represent a FileSystem Path as a Path::Text?

==&gt; C++ Semantics: Path(“C:”).(“subversion”).("babs_internal”).("branches”).("TestBench”).("141001_RADStudioXE7_Code”).("bin”).("Debug”).("Win32”).(“TestBench.exe”);

==&gt; NOTE: Using this C++ semantics the ‘.’ in names is not a problem?

…

&lt;Property Paths&gt;

0D44:2015-09-24 11:20:12.981 DEVELOPMENT TRACE: 21CE1A8 "workspace.current_testbench_sub_folder"=&gt;"VX820"

0D44:2015-09-24 11:20:12.983 DEVELOPMENT TRACE: 21CE408 "iPOS.Enabled"=&gt;”true"

0D44:2015-09-24 11:20:12.993 DEVELOPMENT TRACE: 21CE408 "Testbench.iPOSTerminal.ConnectionType"=&gt;"TCP/IP"

0D44:2015-09-24 11:20:12.993 DEVELOPMENT TRACE: 21CE408 "Testbench.iPOSTerminal.ConnectionAddress"=&gt;"192.168.0.100:9988"

0D44:2015-09-24 11:20:12.993 DEVELOPMENT TRACE: 21CE408 "Testbench.iPOSTerminal.ConnectionAddress"=&gt;"192.168.0.100:9988"

0D44:2015-09-24 11:20:12.993 DEVELOPMENT TRACE: 21CE408 "Testbench.TspId"=&gt;"59100016"

0D44:2015-09-24 11:20:12.993 DEVELOPMENT TRACE: 21CE408 "Testbench.TspIpAndPort"=&gt;”164.10.25.253”

**==&gt; Path::Text: “workspace.current_testbench_sub_folder”;**

==&gt; NOTE: This Text representation is already used?

==&gt; C++ Semantics: Path(“workspace”).(“current_testbench_sub_folder”);

…

&lt;XML File elements&gt;

0D44:2015-09-24 11:20:12.989 BUSSINESS:Imported file C:\\Users\\Public\\Documents\\Swedbank Testbench Workspace\\VX820\\defaultTerminaliPosInterface.xml from C:\\subversion\\babs_internal\\branches\\TestBench\\141001_RADStudioXE7_Code\\bin\\Framework\\defaultTerminaliPosInterface.xml

0D44:2015-09-24 11:20:12.995 DEVELOPMENT TRACE: 21CE408 "iPOS.Terminal.InterfaceFile"=&gt;"editedTerminaliPosInterface.xml"

==&gt; Although current mechanism does not use Path-based access - but could be made to do (See “Todo: Programming - Consider to implement the tag-path based encode and decode idiom as a C++ library?”)

> > &lt;?xml version="1.0"?&gt;

> > -&lt;composite_specification last_changed_date_and_time="2014-12-31 17:36:38.201" caption="iPos Interface" uuid="ad1a5709-21fa-423a-a1bc-9a1a533acfd2"&gt;

> > -&lt;types&gt;  
> > -&lt;container_type caption="root" path="0"&gt;

> > &lt;type_reference path="FFF001" description="Command sent from the SA-CI to the iPOS. The complete content is a constructed data object including all tags, length and data that is part of the command. The length is set to the length from the pdoType to end of the message" precense_requirement="X"/&gt;

> > &lt;type_reference path="FFF10A" description="Command sent from the iPOS to the SA-CI. The complete content is a constructed data object including all the tags, length and data that is part of the command. Length is set to the length from the pdoType to end of the message" precense_requirement="X"/&gt;

> > &lt;type_reference path="FFF201" description="Background command sent from the SA-CI to the iPOS. The complete content is a constructed data object including all tags, length and data that is part of the command. The length is set to the length from the pdoType to end of the message" precense_requirement="X"/&gt;

> > &lt;type_reference path="FFF30A" description="Background message sent from the iPOS to the SA-CI. The complete content is a constructed data object including all the tags, length and data that is part of the command. Length is set to the length from the pdoType to end of the message" precense_requirement="X"/&gt;

> > &lt;/container_type&gt;  
> > &lt;primitive_type caption="pdoPayTermSer" path="DF810B" format="AN" maxlength="5"/&gt;

> > &lt;primitive_type caption="pdoPayTermIp" path="DF810C" format="ANS" maxlength="40"/&gt;

> > &lt;primitive_type caption="pdoPayTermUsb" path="DF810D" format="ANS" maxlength="8"/&gt;

> > &lt;primitive_type caption="pdoMaxDspLength" path="DF810E" format="N" maxlength="2"/&gt;

> > &lt;primitive_type caption="pdoDspTimer" path="DF810F" format="N" maxlength="2"/&gt;

> > &lt;primitive_type caption="pdoLocalIp" path="DF8111" format="ANS" maxlength="40"/&gt;

> > &lt;primitive_type caption="pdoSubnetMask" path="DF8112" format="ANS" maxlength="F"/&gt;

> > &lt;primitive_type caption="pdoGateway" path="DF8113" format="ANS" maxlength="F"/&gt;

> > &lt;primitive_type caption="pdoiPOSRestart" path="DF8115" format="AN" maxlength="2"/&gt;

> > &lt;primitive_type caption="pdoDate " path="DF820A" format="AN" maxlength="8"/&gt;

> > &lt;primitive_type caption="pdoTime " path="DF820B" format="AN" maxlength="6"/&gt;

> > &lt;primitive_type caption="pdoCardReader" path="DF8C03" format="AN" maxlength="1"/&gt;

> > &lt;primitive_type caption="pdoOpenFuncKey" path="DF8C04" format="BOOLEAN" maxlength="1"/&gt;

> > &lt;primitive_type caption="pdoTransactionType" path="DF8C06" format="AN" maxlength="1"/&gt;

> > -&lt;container_type caption="cdoSA_iPOS" path="FFF001"&gt;

> > ...

==&gt; Consider using Path-of-Paths with the first path being the FilePath to the XML-file?

**==&gt; Path::Text: “{C:.Users.Public\\Documents.Swedbank Testbench Workspace.VX820.defaultTerminaliPosInterface.xml} , {composite_specification.types.container_type.type_reference}”…**

==&gt; Q: Is it a good solution to use initialer-list-syntax with braced-parenthesis?

==&gt; Q: Or should we not allow text representation of path-of-paths at allt?

**==&gt; Q: But then, how do we stream (encode into text) a path-of-paths?**

==&gt; NOTE: Current XML-file uses key,value properties (e.g. “path=“ and “description=“)?

==&gt; Q: Should we thus imply a “properties” member that returns a list of key, value pairs?

==&gt; Q: I.e., “composite_specification.types.container_type.type_reference.**properties**” returns value (?)

> > > > path="FFF001”

> > > > description="Command sent from the SA-CI to the iPOS. The complete content is a constructed data object including all tags, length and data that is part of the command. The length is set to the length from the pdoType to end of the message”

> > > > precense_requirement="X"

==&gt; C++ Semantics: auto p =  **{**Path(“C:”).("Users”).("Public\\Documents”).("Swedbank Testbench Workspace”).("VX820”).("defaultTerminaliPosInterface.xml”)

**, **Path(“composite_specification”),("types.container_type”),("type_reference”)**}**

==&gt; NOTE: Uses initialiser list of two paths thus creating a path-of-paths?

==&gt; Q: Would it not be nice if we had a Path constructor taking a Filesystem::Path?

==&gt; C++ Semantics: auto p =  **{**FileSystem::Path(“C:\\Users\\Public\\Documents\\Swedbank Testbench Workspace\\VX820\\defaultTerminaliPosInterface.xml ”)

**, **Path(“composite_specification”),("types.container_type”),("type_reference”)**}**

...

…

&lt;Windows Registry Paths&gt;

0D44:2015-09-24 11:23:28.566 DEVELOPMENT TRACE: Registry:"SOFTWARE\\SCC\\iPosLog\\RealDll"&lt;="C:\\Users\\Public\\Documents\\Swedbank Testbench Workspace\\VX820\\iPosAPI\\FG197128d.dll

0D44:2015-09-24 11:23:28.566 DEVELOPMENT TRACE: Registry:"SOFTWARE\\SCC\\iPosLog\\LogFile"&lt;="C:\\Users\\Public\\Documents\\Swedbank Testbench Workspace\\VX820\\iposlog.txt

0D44:2015-09-24 11:23:28.566 DEVELOPMENT TRACE: Registry:"SOFTWARE\\SCC\\iPosLog\\TempLog"&lt;="C:\\Users\\Public\\Documents\\Swedbank Testbench Workspace\\VX820\\TempLog.txt

0D44:2015-09-24 11:23:28.566 DEVELOPMENT TRACE: Registry:"SOFTWARE\\SCC\\iPosLog\\MaxOldMsg"&lt;=“19

**==&gt; Path::Text: “SOFTWARE.SCC.iPosLog.RealDll”**

==&gt; C++ Semantics: Path(“SOFTWARE”).("SCC”).("iPosLog”).(“RealDll);

…

&lt;TestBench State Nodes&gt;

0D44:2015-09-24 11:23:30.365 BUSSINESS: Node&#91;&lt;root&gt;.&lt;manual_test_mode&gt;&#93; Handled event SaleApplicationStartedEvent created action(s) EnsureAPIConfIsCalledIfThereIsOne

0D44:2015-09-24 11:23:30.366 BUSSINESS: Node&#91;&lt;root&gt;.&lt;ContentsHolder&gt;&#93; &#91;CMDBeg&#93;cdoSA_iPOS:0.pdoSeqNbr:0 &lt;— 1

**==&gt; Path::Text: “root.manual_test_mode”**

==&gt; C++ Semantics: Path(“root”).("manual_test_mode”);

...

0D44:2015-09-24 11:23:32.347 BUSSINESS: Node&#91;&lt;root&gt;.&lt;manual_test_mode&gt;.&lt;ContentsHolder&gt;&#93; &#91;Undefined Message Type&#93;cdoiPOS_SA:0.cdoSR_SEND_HOST:0.cdoiPOSTsp:0.pdoTSPAddr:0 --&gt; 164.10.25.253

0D44:2015-09-24 11:23:32.347 BUSSINESS: Node&#91;&lt;root&gt;.&lt;manual_test_mode&gt;.&lt;ContentsHolder&gt;&#93; &#91;Undefined Message Type&#93;cdoiPOS_SA:0.cdoSR_SEND_HOST:0.cdoFileTSP:0.pdoUserId:0 --&gt; 59100016

&lt;Actions&gt;

0D44:2015-09-24 11:23:30.366 BUSSINESS:Performing action SendiPosMessage.&#91;Undefined Message Type&#93;cdoSA_iPOS:0.cdoOP_INIT:0

==&gt; Note: Actions seems to actually be an example of composed Paths (i.e. Path1 followed by Path2)?

==&gt; Consider to try refactor Actions into Path-of-Paths (First Path being Action Path and second Path being optional iPOS Path or whatever the action references to)?

==&gt; Note: Actions seem to mimic the design of Events (See below)

0D44:2015-09-24 11:23:32.346 BUSSINESS:Performing action FetchPPLFile

0D44:2015-09-24 11:23:39.774 BUSSINESS:Performing action SendSPDHToHost_A

**==&gt; Path::Text: “{SendiPosMessage}, {{Undefined Message Type}, cdoSA_iPOS:0.cdoOP_INIT:0”**

==&gt; Q: Is this nesting of path-of-pats the way to go?

==&gt; C++ Semantics:  auto p = {

Path(“SendiPosMessage”)

,  {

Path("Undefined Message Type”)

,Path(“cdoSA_iPOS”)&#91;0&#93;.(“cdoOP_INIT")&#91;0&#93;

}

}

==&gt; Q: Is this using of implicit intilizer-list constructors a good idea?

&lt;Events&gt;

0D44:2015-09-24 11:23:29.337 BUSSINESS:Queued event = Foreign_iPosStateIDLEBusyDetected

0D44:2015-09-24 11:23:30.608 BUSSINESS:Queued event = ReceivediPosCommandOKResponse.cdoiPOS_SA.cdoOP_INIT

0D44:2015-09-24 11:23:30.330 BUSSINESS:Queued event = SaleApplicationStartedEvent

0D44:2015-09-24 11:23:30.608 BUSSINESS:Queued event = ReceivediPosCommandOKResponse.cdoiPOS_SA.cdoOP_INIT

==&gt; Note: Events seem to mimic the design of Actions (See above)

...

&lt;IP Address&gt;

0D44:2015-09-24 11:23:30.367 DEVELOPMENT TRACE:21CE408 "Testbench.iPOSTerminal.ConnectionAddress"=&gt;"192.168.0.101:9988"

==&gt; Consider an IP-address is actually a Key-path (with optional second path of one node defining a port)?

…

…

Consider to delve deeper into this idea of expressing compile-time Paths using some clever C++ semantics?  
...

{% endraw %}
