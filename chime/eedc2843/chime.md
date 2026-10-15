# Todo: Consider the package managers available on Debian and where they install packages on the system?

```#eedc2843``` *As of 2021-12-21 05:58*

[mail plain/text](mail.txt)

{% raw %}
1) Consider the package managers mentioned in this article "How to install packages on Debian 11" (<https://linuxhint.com/installing_packages_debian/> )?

> Some commands have been obsoleted in the newer version of Debian 11 like apt-get, but there are many other commands which can be used as an alternative to apt-get to install the packages in Debian 11.

> Installing a package using apt  
> &gt;sudo apt install  
> &gt;sudo apt remove  
> &gt;sudo apt autoremove &#91;package-name&#93;

> Installing a package using dpkg  
> &gt;sudo dpkg -i &#91;package&#93;  
> &gt;sudo dpkg -r &#91;package&#93;

> Installing a package using aptitude  
> &gt;sudo apt install aptitude  
> &gt;sudo aptitude install &#91;package name&#93;  
> &gt;sudo aptitude remove &#91;package name&#93;

> Installing a package using gdebi  
> &gt;sudo apt install gdebi  
> &gt;sudo gdebi &#91;package name&#93;

...

{% endraw %}
