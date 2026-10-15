# Todo: Consider to understand and use 'git clean' to get rid of untracked files in a git repo folder?

```#fa532a04``` *As of 2026-10-01 12:17*

[mail plain/text](mail.txt)

{% raw %}
I quite often need to 'un-litter' my git repo from files that ends up in the repo but should not be there.

1) It seems 'git clean' is the command to use?

==&gt; It seems I can 'dry run' git clean with the -n flag?

> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/chime % git clean -nf

> Would remove eml_to_chime.py

> Would remove eml_to_html.py

> Would remove emls_to_chimes.py

> Would remove html_to_markdown.py

> Would remove pytest.ini

> Would remove test_eml_to_chime.py

> Would remove test_html_to_markdown.py

> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/chime %

==&gt; It seems 'git clean -f' removes files that are untracked and NOT in '.gitignore'?

> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/chime % git clean -f

> Removing eml_to_chime.py

> Removing eml_to_html.py

> Removing emls_to_chimes.py

> Removing html_to_markdown.py

> Removing pytest.ini

> Removing test_eml_to_chime.py

> Removing test_html_to_markdown.py

> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/chime %



...

{% endraw %}
