# Todo: Programming - Consider a PIN replacement input with four steps of image selections?

```#b59fd1d1``` *As of 2016-07-29 21:29*

[mail plain/text](mail.txt)

{% raw %}
Could we imagine to try out a PIN replacement input scheme where the user selects images in four steps and one or four hasch values are returned?

1) Consider the Authentication server sends four sets of images to the PIN input client?

==&gt; The user has configured the server with images he/she recognizes mixed with similar but unrecognized ones?  
==&gt; On PIN input the server assembles four sets of i10 mages?  
==&gt; The server knows what the hasch-value that is expected of the correct selected images in each set.  
...

2) Consider a scheme where in each set the user selects the image he/she recognizes?

==&gt; Consider the scheme is about showing one recognized image mixed with nine unknowns?  
==&gt; The location of the recognized image changes on each Authorization session?  
...

3) Consider a scheme where the user selects several images from each set?

==&gt; Consider two images from 10 means there are one of 90 combination that is correct?  
==&gt; Consider this means the user may actually enter a combination 1...89 (in the right order) from each such set?  
==&gt; Consider in this scheme all images are recognized by the client but he/she has to enter the stated combination?  
==&gt; Consider this means entering of four PIN digits (two images from each set) means a middle man would have to guess 1...89 combinations for each entry?  
...

4) Consider to implement a GitHub project to try out a graphical user interface of entering PIN in this manner?

==&gt; Consider to test how fast entering PIN in this way can be?  
==&gt; Consider to test how secure this way of PIN entering can be?  
==&gt; Consider that PIN entry shall still be over an encrypted link (meaning the resulting hash values are in fact encrypted)?  
...

...

Consider to delve into trying out image-selecting-authentication-scheme?  
...

{% endraw %}
