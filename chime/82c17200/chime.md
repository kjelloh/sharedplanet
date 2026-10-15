# Todo: clang-bcc - Consider to understand how to make object files from bcc (bcc32, bcc32c and bcc64) "survive" the MinGW make ar-command tool output link correctly?

```#82c17200``` *As of 2016-08-11 20:30*

[mail plain/text](mail.txt)

{% raw %}
It seems cmake for MinGW generates a make environment that calls the Linux ar (archive) command line tool to put compiled obj.files into an archive that is then called to link?

Visual Studio  ==&gt; COFF

bcc32 ==&gt; OMF

bcc32c ==&gt; OMF

bcc64 ==&gt; ELF

1) It seems bcc32c compiles to formats specified here (<http://docwiki.embarcadero.com/RADStudio/Seattle/en/BCC32C>)?

> **Output Files**

> **File Type **

> **File Extension **

> **File Format **

> Executable

> .exe

> [PE32](http://en.wikipedia.org/wiki/Portable_Executable)

> Shared Library

> .dll

> [PE32](http://en.wikipedia.org/wiki/Portable_Executable)

> Static Library

> .lib

> [OMF](http://en.wikipedia.org/wiki/Relocatable_Object_Module_Format)

> Compiled Object

> .obj

> [OMF](http://en.wikipedia.org/wiki/Relocatable_Object_Module_Format)

==&gt; It seems the OMF file format is old and originates from 16-bit DOS/Windows (See OMF below)?

2) It seems bcc64 compiles to formats specified here (<http://docwiki.embarcadero.com/RADStudio/Seattle/en/BCC64>)?

> **Output Files**

> **File Type **

> **File Extension **

> **File Format **

> Executable

> .exe

> [PE32+](http://en.wikipedia.org/wiki/Portable_Executable)

> Shared Library

> .dll

> [PE32+](http://en.wikipedia.org/wiki/Portable_Executable)

> Static Library

> .a

> [ar](<http://en.wikipedia.org/wiki/ar_(Unix)>)

> Compiled Object

> .o

> [ELF](http://en.wikipedia.org/wiki/Executable_and_Linkable_Format)

3) It seems bcc32 (original borland c++ compiler) compiles to formats defined here (<http://docwiki.embarcadero.com/RADStudio/Seattle/en/BCC32>)?

> **Output Files**

> **File Type **

> **File Extension **

> **File Format **

> Executable

> .exe

> [PE32](http://en.wikipedia.org/wiki/Portable_Executable)

> Shared Library

> .dll

> [PE32](http://en.wikipedia.org/wiki/Portable_Executable)

> Static Library

> .lib

> [OMF](http://en.wikipedia.org/wiki/Relocatable_Object_Module_Format)

> Compiled Object

> .obj

> [OMF](http://en.wikipedia.org/wiki/Relocatable_Object_Module_Format)

4) It seems Visual Studio C++ produces COFF object files (<https://msdn.microsoft.com/en-us/library/9s7c9wdw.aspx>)?

> *“The compilers produce Common Object File Format (COFF) object (.obj) files.”*

...

5) Consider what sources we can use to understand the different object file formats?

==&gt; Consider wikipedia on PE32 “Portable Executable 32-bit” (<https://en.wikipedia.org/wiki/Portable_Executable>)?

==&gt; Consider wikipedia on PE32+ (extension for 64-bit) (<https://en.wikipedia.org/wiki/Portable_Executable>)?

==&gt; Consider wikipedia on OMF “Relocatable Object Module Format" (<https://en.wikipedia.org/wiki/Relocatable_Object_Module_Format>)?

==&gt; Consider Wikipedia on the ELF “Executable Link Format” (<https://en.wikipedia.org/wiki/Executable_and_Linkable_Format>)?

6) But when clang-bcc impersonates a bcc compiler the output obj.file format is not what MinGW make environment expects?

==&gt; This thread suggests Embarcadero mkexp command line tool may be used to create an archive (<https://forums.embarcadero.com/message.jspa?messageID=753179&tstart=630>)?

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\clang-bcc\\build\\test\\clang-bcc-bin&gt;mkexp  
> mkexp.exe: Copyright (c) 2013 Embarcadero Technologies, Inc.  
> All rights reserved.

> usage: mkexp &#91;-n&#93; &#91;-d&#93; &#91;-o&#93; &#91;-p&#93; outputfile inputfile  
> Creates an import archive from an input file.  
> Valid input files are OMF object files that contain only  
> EXPDEF COMENT records, PE files, and DEF files.

> -f: prefer to link by ordinal (dangerous)  
> -d: assume input is a DEF file  
> -o: assume input is an OMF object file  
> -p: assume input is a PE file

> File type is by default based on extension:  
> OMF: .obj  
> DEF: .def  
> PE: .dll, .exe

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\clang-bcc\\build\\test\\clang-bcc-bin&gt;

==&gt; It seems to accept both DEF, OMF and PE input formats?

==&gt; The output from bcc64 is COFF and bcc32c may link with both COFF and OMF (<http://www.codeproject.com/Articles/264103/Using-COFF-C-object-files-with-Delphi-X2>)?

> *“Delphi XE2 can also link with COFF object files when compiling for 32-bit (in addition to OMF). “*

==&gt; It seems Visual Studio compiles to COFF but older Borland compilers compiled to OMF?

> *“How can we use "C" code compiled with Visual Studio inside Delphi? Till now, it was nearly impossible because Visual Studio compiles to COFF, Delphi understood only OMF, and converters from COFF to OMF were not reliable because the OMF used by Delphi has many proprietary undocumented portions. “*

…

7) MinGW64 seem to provide the Linux objdump to examine the content of objects files

> kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 ~  
> $ **objdump**  
> Usage: C:\\msys64\\mingw64\\bin\\objdump.exe &lt;option(s)&gt; &lt;file(s)&gt;  
> Display information from object &lt;file(s)&gt;.  
> At least one of the following switches must be given:  
> -a, --archive-headers Display archive header information  
> -f, --file-headers Display the contents of the overall file header  
> -p, --private-headers Display object format specific file header contents  
> -P, --private=OPT,OPT... Display object format specific contents  
> -h, --&#91;section-&#93;headers Display the contents of the section headers  
> -x, --all-headers Display the contents of all headers  
> -d, --disassemble Display assembler contents of executable sections  
> -D, --disassemble-all Display assembler contents of all sections  
> -S, --source Intermix source code with disassembly  
> -s, --full-contents Display the full contents of all sections requested  
> -g, --debugging Display debug information in object file  
> -e, --debugging-tags Display debug information using ctags style  
> -G, --stabs Display (in raw form) any STABS info in the file  
> -W&#91;lLiaprmfFsoRt&#93; or  
> --dwarf&#91;=rawline,=decodedline,=info,=abbrev,=pubnames,=aranges,=macro,=frames,  
> =frames-interp,=str,=loc,=Ranges,=pubtypes,  
> =gdb_index,=trace_info,=trace_abbrev,=trace_aranges,  
> =addr,=cu_index&#93;  
> Display DWARF info in the file  
> -t, --syms Display the contents of the symbol table(s)  
> -T, --dynamic-syms Display the contents of the dynamic symbol table  
> -r, --reloc Display the relocation entries in the file  
> -R, --dynamic-reloc Display the dynamic relocation entries in the file  
> @&lt;file&gt; Read options from &lt;file&gt;  
> -v, --version Display this program's version number  
> -i, --info List object formats and architectures supported  
> -H, --help Display this information

> kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 ~  
> $

8) Embarcadero provides the TDump tool to inspect its compiler object files

> C:\\Users\\kjell-olovhogdahl&gt;**tdump**  
> Turbo Dump Version 6.5.2.0 Copyright (c) 1988-2014 Embarcadero Technologies, Inc.  
> Syntax: TDUMP &#91;options&#93; &#91;InputFile&#93; &#91;ListFile&#93; &#91;options&#93;  
> -a Display file in 8-bit ASCII -a7 Display file in 7-Bit ASCII  
> -b# Start at offset # -C Dump OBJ, LIB COFF info  
> -d Dump OBJ, LIB debug info -e Dump as EXE  
> -ed No EXE debug info -ee&#91;=x&#93; PE exports only (x=srch)  
> -eiID EXE tbls:HDR,OBJ,FIX,NAM,ENT -el No EXE line numbers  
> -em&#91;=x&#93; PE imports only (x=srch) -em.&#91;x&#93; PE imp. modules (x=srch)  
> -ep No EXE PE header display -er No EXE relocation records  
> -eh No EXE headers display -et No EXE symbols  
> -es Hex dump of program sections -es=x Hex dump of section 'x'  
> -ea&#91;:v&#93; Dump Exports(:v sort on RVA) -ex No New Executable dump  
> -h Output in hex -iID Incl dbg tbl:&#91;?/abc...rst&#93;  
> -l Dump as OMF LIB -le&#91;=x&#93; Dump EXPDEF recs (x=srch)  
> -li&#91;=x&#93; Dump IMPDEF recs (x=srch) -m No C++ de-mangling  
> -M Dump as MACH file -o Dump as OMF OBJ  
> -oc Do OMF CRC check -oiID Include OMF rec (? for list)  
> -oxID Exclude OMF rec (? for list) -q Suppress copyright message  
> -r Raw dump of records -R Dump PE relocation table  
> -s&#91;=x&#93; Dump strings (x=srch) -su&#91;=x&#93; Dump unix style strings  
> -ua Un-assemble objs, exes, dlls -um Unmangle file list of names  
> -v Verbose dump of records -xID Excl dbg tbl:&#91;?/abc...rst&#93;  
> -? Display a better help screen

> C:\\Users\\kjell-olovhogdahl&gt;dumpbin  
> 'dumpbin' is not recognized as an internal or external command,  
> operable program or batch file.

> C:\\Users\\kjell-olovhogdahl&gt;

9) Visual Studio provides its dumpbin tool to examine object file content

> C:\\Program Files (x86)\\Microsoft Visual Studio 14.0&gt;**dumpbin**  
> Microsoft (R) COFF/PE Dumper Version 14.00.24210.0  
> Copyright (C) Microsoft Corporation. All rights reserved.

> usage: DUMPBIN &#91;options&#93; &#91;files&#93;

> options:

> /ALL  
> /ARCHIVEMEMBERS  
> /CLRHEADER  
> /DEPENDENTS  
> /DIRECTIVES  
> /DISASM&#91;:{BYTES|NOBYTES}&#93;  
> /ERRORREPORT:{NONE|PROMPT|QUEUE|SEND}  
> /EXPORTS  
> /FPO  
> /HEADERS  
> /IMPORTS&#91;:filename&#93;  
> /LINENUMBERS  
> /LINKERMEMBER&#91;:{1|2}&#93;  
> /LOADCONFIG  
> /NOLOGO  
> /OUT:filename  
> /PDATA  
> /PDBPATH&#91;:VERBOSE&#93;  
> /RANGE:vaMin&#91;,vaMax&#93;  
> /RAWDATA&#91;:{NONE|1|2|4|8}&#91;,#&#93;&#93;  
> /RELOCATIONS  
> /SECTION:name  
> /SUMMARY  
> /SYMBOLS  
> /TLS  
> (press &lt;return&gt; to continue)  
> /UNWINDINFO

> C:\\Program Files (x86)\\Microsoft Visual Studio 14.0&gt;

…

Consider to delve into this “world” of object file formats to see if we can figure out how to make clang-bcc be able to impersonate as a clang compiler without breaking the object file format the tool chain expects?

...

{% endraw %}
