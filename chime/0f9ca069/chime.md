# Todo: Convert .key file to windows pvk-file

```#0f9ca069``` *As of 2015-09-29 20:52*

[mail plain/text](mail.txt)

{% raw %}
1) Donload the pvk-tool from http://www.drh-consultancy.demon.co.uk/pvktool.zip  
2) Use the tool as describe at http://wiki.cacert.org/Authenticode  
# Convert the private key file from PEM to the Microsoft  
# proprietary PVK format (use pvktool utility mentioned on webpage).  
&gt; pvk -in userkey.pem -topvk -nocrypt -out userkey.pvk

{% endraw %}
