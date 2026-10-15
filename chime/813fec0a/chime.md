# Todo: Programming - Consider to try out the LLVM tool-chain för Visual Studio?

```#813fec0a``` *As of 2016-09-29 15:25*

[mail plain/text](mail.txt)

{% raw %}
Consider to try out and understand the LLVM tool chain for Visual studio?

1) The Windows LLVM tool chain for visual studio seems to be available here (<http://llvm.org/builds/>)?

==&gt; Q: Is this a front-end (Clang) with Visual Studio backend (link)?

==&gt; It seems to be both a Clang front-end and a backend linker and debugger?

> *” Currently, the package only includes clang, clang-format, lld, lldb, and the AddressSanitizer runtime from compiler-rt, but eventually it should grow to encompass other Clang tools, and possibly other LLVM projects such as libc++."*

==&gt; Would this imply we will be able to compile Clang compatible C++ code in Visual Studio?

==&gt; What does that even mean (will Visual Studio Clang simulate all MSVC macros and tool-chain attributes)?

...

2) How does this LLVM for windows Visual Studio differ from the clang-cl (Visual Studio C/C++ compiler cl) (<http://clang.llvm.org/docs/UsersManual.html#clang-cl>)?

…

3) In what way does this LLVM for Visual Studio relate to the Visual Studio C2 backend option (<https://blogs.msdn.microsoft.com/vcblog/2016/01/20/clang-with-microsoft-codegen-january-2016-released/>)

==&gt; It seems we may install Visual Studio CodeGen from Windows Programs and Features?

> ”  
> How to get this update  
> • Control Panel -&gt; Programs -&gt; Programs and Features  
> • Right click on “Microsoft Visual Studio Enterprise 2015”  
> • Click “Change”  
> • Click “Modify”  
> • Select “Clang with Microsoft CodeGen (January 2016)”. The previous release would be marked as “Deprecated”."

==&gt; It seems the Visual Studio C2 backend initiative is for mixing Clang cross platform C++ with Platform UI C++ code?

> On our end, the primary motivation for doing this work is to enable the cross-platform scenario where a significant portion of your app is cross-platform C++ code.

> <https://msdnshared.blob.core.windows.net/media/MSDNBlogsFS/prod.evol.blogs.msdn.com/CommunityServer.Blogs.Components.WeblogFiles/00/00/00/65/69/7510.crossplat_code_structure.png>

  
## Attachments

- [7510.crossplat_code_structure.png](7510.crossplat_code_structure.png)

{% endraw %}
