# Todo: Consider to delve into ISO 20022 that seems to be the result of previous SEPA EPAS proposal that was OSCAR for a while?

```#02219e99``` *As of 2020-04-28 12:26*

[mail plain/text](mail.txt)

{% raw %}
Lennart Helleberg told me about NEXO organisation that now seems to be responsible for the now manifested EPAS standard

1) It seems NEXO is an organisation that maintains the ISO 20022 electronic payment messaging standard (<https://www.nexo-standards.org/about-us> )?

==&gt; It seems NEXO suggests ISO 20022 is about "**standardising** the **exchange** of **payment** acceptance **data** between merchants, acquirers, payment service providers and other payment stakeholders"

> "*nexo standards enables fast, interoperable and borderless payments acceptance by standardising the exchange of payment acceptance data between merchants, acquirers, payment service providers and other payment stakeholders. nexo’s messaging protocols and specifications adhere to ISO20022 standards, are universally applicable and are freely available globally.*"

2) This seems to be the home site for ISO 20022 (<https://www.iso20022.org/about-iso-20022> )?

==&gt; It seems ISO 20022 is a messaging model as well as a dictionary definition and a set of conversion to and from XML and ASN.1 formats?

> *"ISO 20022 is a multi part International Standard prepared by ISO Technical Committee TC68 Financial Services.*

> *It describes a common platform for the development of **messages** using:

> *  
> *• a **modelling** methodology to capture in a syntax-independent way financial business areas, business transactions and associated message flows  
> *  
> *• a central **dictionary** of business items used in financial communications  
> *  
> *• a set of **XML and ASN.1 design rules** to convert the message models into XML or ASN.1 schemas, whenever the use of the ISO 20022 XML or ASN.1-based syntax is preferred"*

==&gt; It seems all the available documentation on ISO 20022 messages are downloadable as documents (<https://www.iso20022.org/iso-20022-message-definitions> )?

> *Hm... It seems to only prodive download of XML schemas for sets of messages (the download seesm to be zip-files with xsd-file contens)?*

3) It seems Swedish Handelsbanken accepts file upload from financial systems to the bank using an ISO 20022 file format (<https://www.handelsbanken.se/sv/foretag/konton-betalningar/tjanster-som-forenklar/filtjanster> )?

> "*När man kommunicerar med banken via fil finns det flera lokala format och standardiserade format att välja på, som till exempel ISO 20022 XML och SWIFT. *"

==&gt; It seems Swedish Handelsbanken provides a brochure about the ISO 20022 XML file format they accept as input (<https://www.handelsbanken.se/shb/inet/icentsv.nsf/vlookuppics/a_betalningar_iso_20022_xml_produktblad/$file/iso_20022_xml_sv.pdf> )?

> *"**ISO 20022 och SEPA*

> *SEPA är en EU-förordning där syftet är en gemensam standard för eurobetalningar inom Europa. För avgående eurobetalningar via fil är ISO 20022 ett krav.**"*

> *"Meddelandetyper*

> *Handelsbanken stödjer följande meddelandetyper inom ISO 20022 (baserat på CGI:s rekommendationer):*

> *• Pain.001, version 2 och 3 – Betalningsuppdrag*

> *Betalningsuppdrag som inkluderar alla typer av betalningar och valutor i de länder där Handelsbanken är verksam. Pain001-meddelanden kan valideras på [handelsbanken.se/testafil](http://handelsbanken.se/testafil).*

> *...*

> *• Camt.054, version 2 – Debetavisering*

> *Debetavisering för avgående betalningar. Innehåller all information från betalningsuppdraget."*

...

{% endraw %}
