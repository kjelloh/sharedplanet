# Todo: Mörkö - Överväg att göra Rasperry Pi manöverpanel för övervakning av solcellsanläggning?

```#0d89665b``` *As of 2017-01-25 23:19*

[mail plain/text](mail.txt)

{% raw %}
Fundera på om det kunde vara kul att göra en Rasperry Pi manöverpanel för solcellsanläggningen på Mörkö som gör användningen lättare?

==&gt; Se även ”Todo: Mörkö - Solpaneler, överväg att hitta bra information på nätet för att välja utrustning?”

1) Försök räkna på hur mycket ström en Rasperry Pi drar eller om det finns sätt att den inte är på annars än när den behövs?

…

2) Överväg att göra ett Web-gränssnitt och WiFi-koppling så man kan koppla in sig med mobiltelefon?

==&gt; Nej, Använd en Mobil Dongel och låt Pi skicka info över Webben.

3) Överväg sätt att få Pi att koppla upp sig med mobilt internet?

==&gt; Det verkar som man kan använda en mobilt internet dongel (<https://www.emnify.com/2015/06/18/how-to-fit-a-raspberry-pi-with-mobile-connectivity/>)?  
==&gt; Med denna konfiguration kopplar Pi upp sig mot internet över dongel (ppp-protokoll) vid boot?  
…

4) Överväg att ladda Pi med ett bra OS?

==&gt; Överväg att använda Raspbian (<https://www.raspberrypi.org/downloads/raspbian/>)?

==&gt; Eller inte (verkar komma med tillbehör jag inte vill ha)?

> > ”*Raspbian comes pre-installed with plenty of software for education, programming *"  
> > ”*Mathematica and the Wolfram Language are included in this release under license and with permission of Wolfram Research, Inc. and may be used for non-commercial purposes only*"

==&gt; Jag behöver ett IoT anpassat OS?

==&gt; It seems Raspberry normally comes with NOOBS (<https://www.raspberrypi.org/downloads/noobs/>)?

==&gt; And NOOBS seems to contain Raspbian (With stuff like Mathematica and Wolfram Lamnguage I do not care for - See above)?

==&gt; Never the less, it seems NOOBS the includes a service to download another OS?

> ”*NOOBS is an easy operating system installer which contains Raspbian. It also provides a selection of alternative operating systems which are then downloaded from the internet and installed.*"

==&gt; This seems like a good post about available OS for Raspberry PI (<http://lifehacker.com/the-best-operating-systems-for-your-raspberry-pi-projec-1774669829>)?

> ”...*we’ll stick to the most common OSesoperating systems available on the newest models of the Raspberry Pi. Right now, that’s Raspbian, OSMC, OpenELEC, Windows IoT Core, and RISC OS.*"

…

5) Överväg att slå på Pi periodiskt med timer (spara ström) samt konfigurera Pi att starta applikationen automatiskt vid Boot?

==&gt; Det här verkar vara ett sätt att boota direkt till Desktop (<http://www.opentechguides.com/how-to/article/raspberry-pi/5/raspberry-pi-auto-start.html>)?  
==&gt; Det här verkar vara en liknande artikel om auto-book till desktop (<http://www.instructables.com/id/Raspberry-PI-auto-boot/>)?  
…

6) Överväg att skriva en applikation som synkar information i en Darwinet domän?

==&gt; Överväg att ha två heltal i domänen - Aktuell laddning i batteribanken, aktuell daglig förbrukning samt aktuell daglig laddning från solpaneler?  
==&gt; Överväg att historiken då automatiskt kommer att erbjuda möjlighet att visa en graf på laddning, bank-nivå samt förbrukning över tid (dag för dag)?  
...

7) Överväg att ha funktion där laddningshastighet och aktuell tillgång i batterier visas i mått av förbrukare (e.g., antal fulla mobiltelefoner, antal timmar lampor, antal fulla iPad, antal fulla skruvdragare etc…)

==&gt; Överväg att använda antal Ah för en fulladdad enhet som en måttenhet.  
==&gt; Då kan tillgänglig laddning i batteribank visas i denna måttenhet.

Säg att en mobiltelefon behöver 2 Ah för full laddning.  
Och Batteribanken för närvarande innehåller 50 Ah.

==&gt; Då är Batterbibankens laddning för stunden 25 Mobiltelefoner.

==&gt; Och då kan aktuell daglig laddning också anges i denna enhet.

Säg att en mobiltelefon behöver 2 Ah för full laddning.  
Och aktuell daglig uppgångad energi från solcell är 40 Ah per dygn.

==&gt; Då är nytillverkad laddning per dygn 20 Mobiltelefoner.

==&gt; NOT: Applikationen måste ta hänsyn till förluster för att visa riktiga värden?

8) Överväg att ansluta D/A-givare för att kunna läsa av AH-meter (och annat)?

==&gt; Överväg denna A/D-omvandlare för Raspberry Pi (<https://learn.adafruit.com/raspberry-pi-analog-to-digital-converters/overview>)?

...

…

{% endraw %}
