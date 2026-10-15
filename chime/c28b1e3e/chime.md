# Todo: Consider ways to use Linux command line commands to create directory listing sorted on date, size, file type etc. ?

```#c28b1e3e``` *As of 2021-10-26 23:54*

[mail plain/text](mail.txt)

{% raw %}
I need to clean up a directory structure from old files, unused files, files to be moved to an archive etc.

1) It seems I can sort files by size using command line:

**ls -lR | awk '/^-/ {print $5 " " $8 " " $6 " " $7 " " substr($0,index($0,$9))}' | awk '!/:/ {print}' | sort -n**

2) It seems I can sort files by "date" using command line:

**ls -lR | awk '/^-/ {print $8 " " $6 " " $7 " " substr($0,index($0,$9))}' | awk '!/:/ {print}' | sort**

3) It seems I can get a tree-formatted directory listing by installing and use the "tree" command?

**tree -RN**

4) Consider to identify files already at another location by sorting the two directory listings and identify pair of equal entries?

kjell-olovhogdal@Kjell-Olovs-Mac-Pro Dropbox % **ls -lR . &gt; ../brf_ekbladet_files.txt**

{% endraw %}
