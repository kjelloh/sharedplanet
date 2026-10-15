# Todo: Consider to discuss the idea that User+Password may actually be replaced with a single "password" where the first part identifies who and the second allows authorization?

```#4dd4a67d``` *As of 2017-01-17 13:04*

[mail plain/text](mail.txt)

{% raw %}
Consider we may view a user+password login as actually a single password login (where the first part of the password identifies the user)?

1) Consider the simple case User+Password = ”&lt;User&gt;””&lt;Password&gt;”?

==&gt; If the User is Bob and the password is Nigella, then the password BobNigella would be enough to login Bob?  
…

2) Consider the idea that each letter in the password is actually a choice in a sequence of steps in an ”access maze”?

==&gt; Consider the password ”bob123”  
==&gt; It may actually be seen as a travel in a maze where each junction has &#91;a…z&#93;&#91;A…Z&#93;&#91;0..9&#93; paths.

==&gt; Consider a PIN code of four digits like ”1234"  
==&gt; It may actually be seen as a travel in a maze where each junction has 10 paths (and we take four steps)

…

3) Consider what alternative user interfaces we may provide as a view of ”maze travel” model of entering a password?

==&gt; Consider Image Selections for PIN inputs?

==&gt; Instead of entering a digit the user selects an image (one out of ten images)  
==&gt; Consider the user is instructed what image to select (like ”select Pete”)?  
==&gt; Consider only the user knows what Pete looks like?  
==&gt; We then need a new set of images for each digit (a bystander may otherwise be able to learn what Pete looks like)  
…

==&gt; Consider what alternative ”maze” we can imagine to replace character passwords?

==&gt; Consider an n-character password - It will at each step define k junctions (where k is the number of valid characters to enter at each step)?  
==&gt; If we replace this with fewer steps of fewer junctions at each step we will weaken the original password?  
…

…

Consider to delve into this idea of viewing a password as a step-by-step travel in a maze combined with the idea to put the user name into the password?  
...

{% endraw %}
