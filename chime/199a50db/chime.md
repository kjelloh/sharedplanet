# Todo: Programming - Consider to understand the Clang (LLVM) code parsing abilities?

```#199a50db``` *As of 2015-12-21 11:55*

[mail plain/text](mail.txt)

{% raw %}
To implement say code refactoring or a compiler for a new language it would be both interesting and of value to understand the design principles and abilities go the clang compiler?

1) Clang seem to generate an internal representation of the code called AST (Abstract syntax tree) (<http://stackoverflow.com/questions/7935008/clang-what-does-ast-abstract-syntax-tree-look-like>)

==&gt; clang++ -cc1 -ast-print ~/sum.cpp seem to generate a pretty-print of the AST generated for source code sum.cpp?

==&gt; “*If you want to hack on the compiler, you need -ast-dump, which will generate an output that maps directly the in-memory representation of the code that was parsed.*"

2) So what is the API to the Clang generated AST? (<http://clang.llvm.org/docs/IntroductionToTheClangAST.html>)

```
$ cat test.cc<http://test.cc>
int f(int x) {
  int result = (x / 42);
  return result;
}

# Clang by default is a frontend for many tools; -Xclang is used to pass
# options directly to the C++ frontend.
$ clang -Xclang -ast-dump -fsyntax-only test.cc<http://test.cc>
TranslationUnitDecl 0x5aea0d0 <<invalid sloc>>
... cutting out internal declarations of clang ...
`-FunctionDecl 0x5aeab50 <test.cc<http://test.cc>:1:1, line:4:1> f 'int (int)'
  |-ParmVarDecl 0x5aeaa90 <line:1:7, col:11> x 'int'
  `-CompoundStmt 0x5aead88 <col:14, line:4:1>
    |-DeclStmt 0x5aead10 <line:2:3, col:24>
    | `-VarDecl 0x5aeac10 <col:3, col:23> result 'int'
    |   `-ParenExpr 0x5aeacf0 <col:16, col:23> 'int'
    |     `-BinaryOperator 0x5aeacc8 <col:17, col:21> 'int' '/'
    |       |-ImplicitCastExpr 0x5aeacb0 <col:17> 'int' <LValueToRValue>
    |       | `-DeclRefExpr 0x5aeac68 <col:17> 'int' lvalue ParmVar 0x5aeaa90 'x' 'int'
    |       `-IntegerLiteral 0x5aeac90 <col:21> 'int' 42
    `-ReturnStmt 0x5aead68 <line:3:3, col:10>
      `-ImplicitCastExpr 0x5aead50 <col:10> 'int' <LValueToRValue>
        `-DeclRefExpr 0x5aead28 <col:10> 'int' lvalue Var 0x5aeac10 'result' 'int'
```

==&gt; Here seem to be a good Clang youtube about using AST for tool-builders (<https://youtu.be/VqCkCDFLSsc>)?

==&gt; Seem one is supposed to use the **-Xclang** option to pass plug-in parameters to the plug-in (not the -cc1 parameter in the example above)?

==&gt; Here Xclang option is defined fro the clang-cl front-end (visual studio cl.exe look-alike front-end) as “*-Xclang &lt;arg&gt; Pass &lt;arg&gt; to the clang compiler*” (<http://clang.llvm.org/docs/UsersManual.html#command-line-options>)

3) Clang LibTooling seem to be the recommended way to build tools based on Clang API (<http://clang.llvm.org/docs/LibTooling.html>)?

4) The Clang compiler exposes an API to define and engage plug-ins during the compilation front-end phase (<http://clang.llvm.org/docs/ClangPlugins.html>)

5) What clang-based refactoring tools are available?

==&gt; This seem to be a good youtube video about clang-based c++ refactoring (<https://www.youtube.com/watch?v=yuIOGfcOH0k>)

Plugins LibClang Standalone Tools

|  |  |

----------------------------------

|

----------------------------------------------------

| Tooling Refactoring AST Matchers |

| |

|  Clang |

----------------------------------------------------

…

Consider to study clang api abilities for building language tools (e.g. refactoring, cross-language, view-independent code editors)?

{% endraw %}
