# Todo: Consider a stand-by killer we can wake up over a Lora network to activate say a WiFi printer?

```#2f5b0b63``` *As of 2018-05-17 15:53*

[mail plain/text](mail.txt)

{% raw %}
Could we imagine to have a laser printer stand-by-killed but woken up by a print task over a Lora Network?

1) Consider a stand-by killer that wakes up from deep-sleep to check any incoming request to wake up?

==&gt; Consider a micro controller that regularly wakes up and sends a query to a print service over Lora?  
==&gt; Consider the print service responds with a “wake-up and print” response?  
==&gt; Consider the stand-by killer then turn on the printer?  
==&gt; Consider the print-queue then takes care of actually printing tasks on the queue when the printer comes online over Wifi?

==&gt; Consider the stand-by killer then shuts down the printer after the pre-programmed time of inactivity?  
…

…

Consider to delve into this idea of having a stand-by killer that regularly wakes up from deep sleep to query if there is a request to wake-up?  
...

{% endraw %}
