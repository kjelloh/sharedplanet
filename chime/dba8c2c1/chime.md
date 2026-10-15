# Todo: C++ - Consider to process current C++17 draft through Doc-to-help project to generate different output formats of the specification?

```#dba8c2c1``` *As of 2017-02-06 22:03*

[mail plain/text](mail.txt)

{% raw %}
Would it be possible to access the current C++17 draft documentation and parse it in some way that enables a Doc-to-help project to generate its output formats based on the source?

1) Consider to use the (TeX?) source on github (<https://github.com/cplusplus/draft>)?

==&gt; The output seems to be pdf?

> ”  
> *To typeset the draft document, from the source directory:

> *  
> *• run **latexmk -pdf std**  
> *

> *That's it! You should now have an std.pdf containing the typeset draft.*  
> "

==&gt; On MAC they recommend MAC version of Tex (<http://tug.org/mactex/>)?

==&gt; The latexmk command line manual seems to live here (<http://man.cx/latexmk>)?

==&gt; latexmk seems to be able to generate dvi, ps, pdf or ”hardcopy” formats?

> > ”*latexmk issues the appropriate sequence of commands to generate a .dvi, .ps, .pdf and/or hardcopy version of the document*"

==&gt; The dvi-format seems to refer to the ”Device Independent Format” (<https://en.wikipedia.org/wiki/Device_independent_file_format>)?

==&gt; The ps-format seems to refer to the ”Postscript” language (<https://en.wikipedia.org/wiki/PostScript>)?

==&gt; The pdf-format of course refers to Adobe pdf (<https://en.wikipedia.org/wiki/Portable_Document_Format>)

==&gt; LaTeX seems to be the name of an open source (GNU LPPL) for Tex tools (<https://www.latex-project.org/get/>)?

==&gt; This seems to be a good approved list of TeX distributions and tools (<http://www.tug.org/interest.html#free>)?

2) Consider ways to translate the github source to Word or HTML format?

==&gt; Consider this page has many good leads to optional transform chains of formats /<https://en.wikibooks.org/wiki/LaTeX/Export_To_Other_Formats>)?

==&gt; It seems to suggest that TeX actually generates dvi or pdf (and that PostScript is a post-process using either of these formats as the source)?

==&gt; Consider this tool to convert LaTex to Word (<http://www.grindeq.com/index.php?p=latex2word>)?

==&gt; NOTE: It does not seem to support dvi or pdf inputs (And C++ source on github needs to be built to produce correct document)

==&gt; Also, it recommends to process only max 60 pages at a time (and the C++ standard in round 800 pages)!

==&gt; Consider what transforms we can imagine to get Word or html5 format for Doc-To-Help?

Tex output Doc-To-Help input

dvi doc

docx

html5

ps doc

docx

html5

pdf doc

docx

html5

{% endraw %}
