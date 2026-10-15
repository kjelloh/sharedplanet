# Todo: Consider to try out Neovim with the Tree-sitter playground and syntax highlighting?

```#9ab7f675``` *As of 2022-01-21 13:50*

[mail plain/text](mail.txt)

{% raw %}
I want a good code editor with syntax highlighting and good language support and navigation.

==&gt; Also see "Todo: Consider to check out the Tree-Sitter incremental language parser for IDE syntax highlighting support?"

1) Neovim seems to live here (<https://neovim.io> )?

2) The Neovim plugin for Tree-Sitter seems to live here (<https://github.com/nvim-treesitter/nvim-treesitter> )?

3) Consider to document how to install and activate Tree-sitter for C++ in Neovim om MAcOS?

==&gt; It seems the things to do is hidden in this instruction (<https://github.com/nvim-treesitter/nvim-treesitter#readme> )?

==&gt; It seems I need git, a C-compiler and libstdc++ instaleld (which I have on my macOS machine)

> ## Requirements

- Neovim latest stable version or [nightly](https://github.com/neovim/neovim#install-from-source)
- `tar` and `curl` in your path (or alternatively `git`)
- A C compiler in your path and libstdc++ installed ([Windows users please read this!](https://github.com/nvim-treesitter/nvim-treesitter/wiki/Windows-support)).



==&gt; It seems Tree-sitter is available for install on Brew (<https://formulae.brew.sh/formula/tree-sitter> )?

==&gt; Or I can install vim-plug and then config (<https://github.com/junegunn/vim-plug> )?

> E.g., if you are using [vim-plug](https://github.com/junegunn/vim-plug), put this in your `init.vim` file:

  
> ```
> Plug 'nvim-treesitter/nvim-treesitter', {'do': ':TSUpdate'}  " We recommend updating the parsers on update
> ```

  
==&gt; It seems I need a compiled .so file for the parser I want to Tree-sitter to use but can use neovim helper to get this done?

> Treesitter uses a different *parser* for every language, which needs to be generated via `tree-sitter-cli` from a `grammar.js` file, then compiled to a `.so` library that needs to be placed in neovim's `runtimepath` (typically under `parser/{language}.so`). To simplify this, `nvim-treesitter` provides commands to automate this process. If the language is already ``[supported by nvim-treesitter](https://github.com/nvim-treesitter/nvim-treesitter#supported-languages), you can install it with

  
> ```
> :TSInstall <language_to_install>
> ```

  
Q: What do I need to write as the name of C++ (cpp? c++? other caption?)

==&gt; It seems instrcutions on the commands in Neovim to interact with Tree-sitter plugin lives here (<https://github.com/nvim-treesitter/nvim-treesitter/blob/master/doc/nvim-treesitter.txt> )?

> *Install the parser for your language

> &gt;  
> :TSInstall {language}  
> &lt;

> To get a list of supported languages

> &gt;  
> :TSInstallInfo*

> *...*

> *By default, everything is disabled.  
> To enable supported features, put this in your \`init.vim\` file:

> &gt;  
> lua &lt;&lt;EOF  
> require'nvim-treesitter.configs'.setup {  
> -- One of "all", "maintained" (parsers with maintainers), or a list of languages  
> ensure_installed = "maintained",  
> -- Install languages synchronously (only applied to \`ensure_installed\`)  
> sync_install = false,  
> -- List of parsers to ignore installing  
> ignore_install = { "javascript" },  
> highlight = {  
> -- \`false\` will disable the whole extension  
> enable = true,  
> -- list of language that will be disabled  
> disable = { "c", "rust" },  
> -- Setting this to true will run \`:h syntax\` and tree-sitter at the same time.  
> -- Set this to \`true\` if you depend on 'syntax' being enabled (like for indentation).  
> -- Using this option may slow down your editor, and you may see some duplicate highlights.  
> -- Instead of true it can also be a list of languages  
> additional_vim_regex_highlighting = false,  
> },  
> }  
> EOF*

...

{% endraw %}
