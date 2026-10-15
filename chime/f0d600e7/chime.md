# Todo: Mörkö - Överväg att bygga en enkel Ah-mätare för att mäta ström från solpanel, ström till batteri och ström från batteri?

```#f0d600e7``` *As of 2017-01-24 19:35*

[mail plain/text](mail.txt)

{% raw %}
Överväg att det vore ett kul projekt att bygga en enkel Ah-mätare för att mäta energi-mängd som transporterats i solpanelsannläggning?

1) Överväg att använda den här IC-kretsen från ELfa ([https://www.elfa.se/sv/kretskort-lem-fhs-40-kit/p/17374880?q=\*&filter_Category3=Linjära+kretsar&filter_Category5=Strömsensorer&filter_Category4=Sensorer&filter_Buyable=1&filter_Avkänt+strömområde%7E%7EA=%26plusmn%3B+29.76&page=1&origPageSize=50&simi=97.5](https://www.elfa.se/sv/kretskort-lem-fhs-40-kit/p/17374880?q=*&filter_Category3=Linjära+kretsar&filter_Category5=Strömsensorer&filter_Category4=Sensorer&filter_Buyable=1&filter_Avkänt+strömområde%7E%7EA=%26plusmn%3B+29.76&page=1&origPageSize=50&simi=97.5))?

**==&gt; Enligt ELFA har detta kort en känslighet på 67 mV/A**

==&gt; Den verkar vara baserad på det här chippet (<http://www.lem.com/docs/products/fhs%2040-p%20sp600.pdf>)?

![](<Current Sensor LEM Minisens PCB mount options.tiff>)

==&gt; ELFA-modellen (KIT 4) verkar vara den till vänster med ström-banan direkt under chippet?

==&gt; Enligt LEM produktblad verkar Kit 4 ge känslighet 65 - 90 mV/A (Stämmer med ELFAS angivelse på 67 mV/A)

![](<Current Sensor LEM Minisens sensitivity.tiff>)

==&gt; Med matningsspänning Jord, +/- 5 V så kan vi integrera en utsignal -5…+5 V

==&gt; För att kunna integrera flöde i båda riktningarna behöver vi få +5V == 100 Ah (positivt flöde) och -5V == -100 Ah (negativt flöde)

==&gt; We want the mapping 100 Ah ==&gt; 5 V

==&gt; 20 Ah / V of integrated output

==&gt; I.e., Integrated 500 mV == 10 Ah

==&gt; But we may design the sensor to measure Max 10 A (for our purposes)

==&gt; 10 A ==&gt; 670 mV sensor output.

==&gt; The integrator must be designed to integrate 670 mV in one hour to 500 mV integrated output (i.e. 10 Ah)

...

==&gt; Thus the AD-converter should map -5V … +5V to the range -100 … + 100 (decimal output and we disregard to use all bits for maximal precision)?

**==&gt; The digital precision is thus 100 Ah in steps of 1 Ah (the resolution is only 1 Ah)!**

*==&gt; Consider to use a 16 bit AD-converter?!!*

…

2) Överväg att bygga ihop den till en ekel integrator för att skapa ett mått på totalt genomfluten energi (proportionellt mot genomfluten Ah)?

==&gt; Koppla den till en OP-stärkare som integrerar ut-spänningen från sensorn?

==&gt; Sensorn ger en utspänning som är V/A.

==&gt; Integrerad spänning borde alltså ge V/Ah.

==&gt; Koppla på en AD-omvandlare och gör så att integratorn nollställs då det digitala värdet läses av?

==&gt; Med fiffig koppling borde en Rasperry-Pi kunna läsa av och resetta sensorn varje gång den bootas upp (sensorn lever sitt eget liv = alltid aktivmed låg förbruklning)?

…

…

Consider to elaborate on this idea to build a small AH-meeter with digital output for Mörkö solar panel equipment?

...

{% endraw %}
