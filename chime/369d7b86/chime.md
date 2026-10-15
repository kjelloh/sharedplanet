# Todo: Consider to study the notion of having the Web-browser work as a local Notes App from code in the URL?

```#369d7b86``` *As of 2016-03-24 15:38*

[mail plain/text](mail.txt)

{% raw %}
It seems we can learn some cool ides from studying the idea presented in “DatworMagazin nr 4 2016” about writing code to run the web-browser into a local notes app?

1) Consider to check-out the links prpsopsed in the article?

==&gt; (<http://pastebin.com/YxyXZrkA>)

== Seems to be code to turn the browser into a notes app that stores the note into a (locally) stored URL?

“data:text/html,&lt;html&gt;&lt;script&gt;window.onload=function(){var a=document.body;a.addEventListener("keydown", function(b){if(b.ctrlKey&&83===b.which){document.location = 'data:text/html,' + document.childNodes&#91;0&#93;.outerHTML;b.preventDefault();}},!1);document.title= document.body.innerText.replace(/\\n&#91;\\s\\S&#93;+$/," - ")+new Date().toString();};&lt;/script&gt;&lt;body contenteditable style="font-size: 1.5em; width: 100%; height: 100%; border: none; outline: none; background: #111; color: #eee; padding: 10px;"&gt;&lt;/body&gt;&lt;/html&gt;”

==&gt; If one enters this code into the Web-browser adress window one gets a windows for entering text.

==&gt; If one prints Ctrl-Z an save-dialog i presented and one may save the note as a “Web Package”

==&gt; If one double-clicks the Web-package file the web-browser opens with the Note open in the editor :)

Actually pretty cool!

==&gt; (<https://github.com/jwaterfaucett/textpad>)

==&gt; Seems to be code to make an note-app extension to chrome web-brose?

“Textpad is a tiny extension for the chrome browser that acts as a todo list or general note taking app whenever you open a new tab in chrome.”

==&gt; (<https://chrome.google.com/webstore/detail/textpad/edopaieiodmddkbhpkfpjdlcjigacnkf>)

==&gt; According to the article this is a packaged plugin fro chrome based on the jwaterfaucett/textpad above?

2) Note how these application surely on the ability to have the browser store local data?

==&gt; This seem to be a good starting point to understand html 5 local storage (<http://www.w3schools.com/html/html5_webstorage.asp>)?

“With local storage, web applications can store data locally within the user's browser."

3) So, what more can we have the browser do locally just by entering code into the browser adress window?

...

...

Consider to study variants of this option to execute the browser to implement local client apps by having the browser execute code in URL:s?

...

{% endraw %}
