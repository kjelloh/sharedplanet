# Todo: Programming - Understand binary target files for different build platforms (VS, RAD Studio, Unix/gcc)

```#67e9d8f3``` *As of 2015-12-17 19:05*

[mail plain/text](mail.txt)

{% raw %}
Trying to use both Visual Studio and RAD Studio together on Windows poses some problems regarding the result of linking targets.

1) RAD Studio uses Clang for BCC64 which produces \*.o, \*.a (and other) files. What are they?

==&gt; (<http://stackoverflow.com/questions/9809213/what-are-a-and-so-files>)

“.a files are usually libraries which get statically linked (or more accurately archives), and .so are dynamically linked libraries.”

==&gt; Seems Clang produces targets in ELF-fromat (<http://jonathan2251.github.io/lbd/elf.html> )

“The ELF (Executable and Linkable Format) is a common standard file format for executables, object code, shared libraries and core dumps”

==&gt; This article states that BCC32 generates OMF files (<http://stackoverflow.com/questions/22413776/coff-vs-omf-library-format-on-windows?rq=1>)?

“I know that MS is COFF and Embarcadero is OMF”

==&gt; Embarcadero confirms this with the tool COFF2OMF to be used to link with Visual Studio COFF files (<http://docs.embarcadero.com/products/rad_studio/delphiAndcpp2009/HelpUpdate2/EN/html/devwin32/coff2omf_xml.html>)

“COFF2OMF enables C++Builder users to link to Microsoft and other third-party DLLs that use the COFF format”

==&gt; Hm, but his would not work for Visual Studio targets in PE Format?

==&gt; Found “Object File Converter” last updated Dec 2015 (<http://agner.org/optimize/>)

“Object file converter - This utility can be used for converting object files between COFF/PE, OMF, ELF and Mach-O formats for all 32-bit and 64-bit x86 platforms. Can modify symbol names in object files. Can build, modify and convert function libraries across platforms. Can dump object files and executable files. Also includes a very good disassembler supporting the SSE4, AVX, AVX2, AVX512, FMA3, FMA4, XOP and Knights Corner instruction sets. Source code included (GPL). Manual. File name: objconv.zip, size: 1010456, last modified: 2015-Dec-09.”

==&gt; Consider to look into the GPL source-code (could give insight to the different formats)?

2) RAD Studio BCC32 and Visual Studio produces \*.obj, \*.lib and \*.dll files. What are they?

==&gt; Windows uses PE format (supersedes COFF) (<http://stackoverflow.com/questions/2170818/clarification-on-binary-file-pe-coff-elf-formats-terminology>)

“Both ObjectFile & ImageFile are in PE Format in windows & ELF format in linux”

==&gt; The PE Format means “Portable Executable” and COFF "Common Object File Format" (<https://msdn.microsoft.com/en-us/windows/hardware/gg463119.aspx>)

3) This manual for objconv sports a table of a lot of different COFF/PE/ELF formats (<http://agner.org/optimize/objconv-instructions.pdf>)

4) Windows \*.lib files may be static libraries or import libraries (<http://stackoverflow.com/questions/3573475/how-does-the-import-library-work-details>

“Linking to a DLL file can occur implicitly compile at link time, or explicitly at run time.”

“If linked implicitly when the program is built, then stubs for each DLL export used byt the program get linked in to the program from an import library”

==&gt; This would mean that if linked with an import library the DLL:s will be loaded at runtime when needed (and thus must be provided with the exe to be there when needed).

…

Consider to study this subject more to get a broad understanding about the linker target file formats?

{% endraw %}
