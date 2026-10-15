# Todo: Programming - Överväg att beskriva och eventuellt bygga "drömapplikationen" för företagare för bokföring, bokslut och admin. av skatt och avgifter och göra den C++ open source?

```#de307f3c``` *As of 2016-05-02 12:29*

[mail plain/text](mail.txt)

{% raw %}
Vad kan vi säga om “drömapplikationen” för egna företagare för att enkelt kunna bokföra, göra bokslut, planera skatt, lön och utdelning/uttag?

==&gt; Se även “Todo: Deklarera Privat (KOH-Innovation) 2016"

==&gt; Se även “Todo: Eget AB - Dokumentera process för ekonomiska transaktioner och bokföring”

==&gt; Se även “Todo: Eget AB - Överväg att gå över till elektronisk bokföring?"

-7) Det verkar som om vi behöver kunna byta kontoplan (olika BAS-planer) enligt standard här (<http://www.bas.se/kontoplaner.htm>)

==&gt; Här verkar de lista skillnader mellan tidigare kontoplaner (<http://www.bas.se/arkiv.htm>)?

==&gt; Det verkar till exempel smart att kunna byta minimal kontoplan för enskilda näringsidkare som upprättar förenklat bokslut “K1” (<http://www.bas.se/documents/2016/Kontoplan_K1_Mini_2016_ver1.pdf>)?

==&gt; Överväg att låta programmet “veta” om den använder en BAS-kontoplan och i så fall vilken?

==&gt; På så sätt kan verifikationer “kodas” i rätt kontoplan.

==&gt; Och på så sätt kan en befintlig bokföring “kodas om” till en ny kontoplan?

==&gt; Överväg att ha en enkel funktion som transformerar (omför) en befintlig kontoplan till en ny (eller gammal)?

==&gt; Det verkar som en modell för bokföring visar löpande affärshändelser samt relation med skatteverket (deklaration + betalning in/ut av olika skatter och avgifter)?

Kunder —&gt; Verifikat —&gt; |

|

|&lt;—&gt; Bokföring&lt;konto-plan&gt; —&gt; Transform —&gt; Skatteverket API (SRU-Koder och blankett-rutor)

| |

| |  &lt;-- Verifikat —&gt; Skattekonto

Leverantörer &lt;— Verifikat —&gt; | |

| |

Ägare &lt;—&gt; Verifikat &lt;—&gt; Omföringar (e.g. bokslut, nytt år)

==&gt; Det som verkar “röra till det” är att både affärshändelser (transaktion eller åtagande om transaktion) samt interna omföringar mellan interna konton bokförs (och det är stor skillnad på de olika)?

==&gt; Resultatkonton skall hålla koll på kostnader och intäkter (både när de inträffat samt till vilken period och till vilket belopp de borde konteras)?

==&gt; Balanskonton skall både hålla koll på tillgångar och skulder (både när de inträffat samt till vilken period och till vilket belopp de borde konteras)?

...

-6) Överväg att definiera gränssnitt och transformera till externa “världar” som Kunder, Leverantörer, Skatteverket, anställda etc?

==&gt; Överväg att designa GUI efter olika “världsbilder”

==&gt; Relationen till skatteverket bör innehålla egna interna världen och skatteverkets värld (skattetransaktioner och skattedeklarationer)?

==&gt; I denna bild är SRU-kopplingar (koppling mellan kontoplan och “rutor” i skatteverkets blanketter) en transform mellan världar (redovisning = spegling)

==&gt; Överväg att hitta ett sätt att visa dessas kopplingar grafiskt (transformer = beräkningar) från konto i företagets värld till konto (ruta) i skatteverkets blanketter?

…

==&gt; Överväg att elaborera över möjligheten att med Darwinet gör transformer (spegling) som aktiva synkroniseringar (delta-synaningar i delade data)?

==&gt; I stället för mansull synkning (läsa av och fylla i) så synkas data aktivt som delta på delat data (mottagaren eller avsändaren gör transformen)

==&gt; Helst vill vi att skatteverket själv kan läsa och tolka delad huvudbok )direkt från bokföringen)?

==&gt; Helst skulle vi vilja att skatteverket själv genererar bokföringar i samband med in/ut-betalning till skattekontot (in/ut-betalning av beslutat, betald skatt)?

...

-5) Överväg att kunna se olika interna “världar” som “relationer” (skulder/fodringar till externåk aktörer som skatteverket, kunder, leverantörer, anställda), “egendom” (värde och avskrivningar), “försäljning” etc.

==&gt; Vid val av “värld” ser man bara information som “bor” i den världen?

==&gt; Vid val av “relation till skatteverket” ser man bara interna verifikatdelar (sammanställningar) som berör skatt och avgifter till skatteverket?

==&gt; Vid val av “Relation till leverantörer” ser man bara interna verifikatdelar (t.ex. ej moms) som berör skuld/fodringar i relation till en/flera leverantörer.

==&gt; Överväg att få detta att fungera helt i IRL-värdlen (hela tiden är underliggande bokföring dold)?

...

-4) Överväg att basera GUI på en översta nivå som är faktiska bilder på IRL-verifikat (räkning, faktura, kvitto)?

---- Räkning Telia Faktura Swedbank Kvitto  Kontoutdrag Skattekonto

|  |  |  |  | *Användarens “värld”*

|  |  |  |  |

OCR ---------------------------------------------------------------------------------------------------------------------------

|  |  |  |    |

----&gt; Verifikation Verifikation Verifikation Verifikation *Bokföring-kunnigs “värld"*

Varje verifikation är “klassisk” montering i kontoplan.

|

|

“Värld” av konton och kontoföringar

==&gt; Överväg att som option använda OCR för att skapa Verifikation från scannat verifikat?

==&gt; Överväg att skapa extra IRL-lager där varje verifikat är uppdelat i IRL-delar som moms, kostnad, intäkt etc.

==&gt; Detta extra lager kan erbjuda hjälp där applikationen förklarar vad delarna är (vad är moms, vad är intäkt, vad är kostnad)

…

-3) Överväg att göra det enkelt att ange period som ett verifierat avser (eventuellt flera)?

==&gt; En elräkning kan avse framtida kostnader för tjänst samt faktisk förbrukad el?

==&gt; En telefonräkning fungerar ungefär som en elärgning (faktisk debiterad förbrukning + förbetalt tjänst e.g., turfmängd)?

==&gt; Genom att lätt kunna ange period för del-verifikat (upplupen förbrukning, framtida förbetalt tjänst) kan perforering ske automatiskt?

==&gt; Överväg att lätt kunna låta bli att ange period (då period garanterat) inte kommer att ligga inom räkenskapsperiod (år)?

...

-2) Överväg att elaborera kring det faktum att IRL-verifikat kan resultera (relatera till) affärhändleser i tid skilt från verifikatets tid?

==&gt; Ett IRL-kontoutdrag är i själva verket en lista av del-verifikat av enstaka transaktioner med egna datum (tidigare än tidpunkt för kontoutdraget)

==&gt; Överväg att ha en funktion som automatiskt (från digitalt-data eller OCR-genereta data) skapa del-verifikat som boföre separat (återskapar sann historia av affärshändelser)

==&gt; En faktura är i själva verket ett krav på en framtida betalning till oss (skapar alltså en framtida fodran = påminnelse att betalning inväntas)

==&gt; En räkning är i själva verket ett krav på en framtida betalning till en leverantör (alltså en framtida skuld = påminnelse att betalning avkrävts)

-1) Överväg att i GUI alltid visa faktiska transaktioner (in/ut från företag eller mellan bankkonton i företag)?

==&gt; De flesta affärshändelser är transaktioner av pengar till (intäkt) eller från (utgift) företaget.

==&gt; Vissa transaktioner är mellan egna bankkonton (som alltså blir mellan konton i bokföringen)

==&gt; Övriga är till/från externa aktörer (företag, anställda, kunder) och alltså kontoförs som dubbel kontoföring (ett balans och ett resultat-konto)

==&gt; I denna vy behöver bara de IRL-konton (kassa, bank etc) som tar emot, betalar ut pengar visas (bokföringskonton är ointressant)?

==&gt; Överväg att se på kontoföring i bokföring som ett sätt att hålla koll på olika saker men på ett “språk” som en vanlig dödlig behöver förstå?

==&gt; Viss kontoföring är för att hålla koll på företagets relation med skatteverket?

==&gt; Viss kontoföing är för att hålla koll på försäljning?

==&gt; Viss kontoföing är för att hålla koll på soliditet?

==&gt; Viss kontoöring är för att hålla koll på värdeminskning av egendom?

==&gt; osv...

1) Överväg att designa programmet så alla delar känns som “ett” (inte en massa obskyra delar för bokföring, bokslut, årsredovisning, moms och skottredovisning etc.)?

2) Överväg att kunna definiera godtyckligt intervall för rapport och fiffa mellan rapporter genererade på olika intervall?

==&gt; På detta sätt kan användaren “spåra” vad som påverkar vad?

==&gt; Till exempel göra en balansrapport för helår inklusive och exklusive bokslutsomföringar (som jag har så svårt att förstå var siffrorna kommer ifrån)?

==&gt; Överväg ett GUI där man markerar ett intervall på tidslinjen, kopplar eventuellt filter och sedan koppar en rapportgenerator på resultatet.

----&gt; &lt;filter 1&gt; --&gt; &lt;transform&gt; --&gt; GUI Rapport 1

|---&gt; &lt;filter 2&gt; --&gt; &lt;transform&gt; --&gt; GUI Rapport 2

|

/--------------------/

&lt;intervall&gt;

-------------------&gt; &lt;transform&gt; --&gt; GUI Rapport 1

| ---&gt; &lt;transform&gt; --&gt; GUI Rapport 2

| |

/----------------/ |

&lt;intervall 1&gt;  |

/-------------------------/

&lt;intervall 2&gt;

3) Överväg att ha ett GUI som klart visar när en affärshändelse sker, hur den bokförs och vilken period den avser?

==&gt; Som lekman är det svårt att få en överblick och förstå vad alla transaktioner avser, när dom sker och varför.

==&gt; Med en tydlig tidslinje och grafik som visar hur värden “flödar” in och ut ur företaget (eller bara internt mellan konton) så blir det lättare?

4) Överväg att programmet skall ha ett GUI så man kan interagera med faktiska verifikationer (dölj kontoplaner, SRU-koder och annat tjafs)?

==&gt; När man får en räkning bokför man räkningen (programmet vet hur)

==&gt; När man skickar en faktura bokför man en faktura (programmet vet hur)

5) Överväg att ha en “under huven”-vy där man jobbar med konton och verifikationer (för interaktion med revisorer och bokföringshjälp)?

==&gt; Här kan de som vet skruva på kopplingar till baskonto-plan, SRU-koder för genrering till deklaration etc.?

6) Överväg att se alla händelser på en tidslinje vänster till höger?

==&gt; Till vänster, ovan tidsaxeln, har man företagets interna “konton” = ett träd där översta nivån är Tillgångar/Skulder (Balans) och Utgifter/Inkomster (Resultat)

==&gt; Till vänster, Under tidsaxeln, har man externa “konton” = ett träd där översta nivån är Kunder, Leverantörer och “Staten” (skatt och moms)

==&gt; Transaktioner med externa “konton” blir en pil upp (inbetalning) eller ner (utbetalning) ansluten till pil mellan interna konton (balans och resultat)

==&gt; Det är endast om man öppnar upp trädet som man ser underkonton och mer detaljerat om flera konton är inblandade i en transaktion.

7) Överväg att låta tidslinjen fortsätta in i framtiden och där markera kända leverantörsskulder, kundfordringar samt skatt/moms som beräknas komma in/ut?

==&gt; Då kan man lätt se framtida utbetalningar (när de borde ske och hur mycket som skall betalas)

==&gt; Där kan man se framtida inbetalningar (när de borde betalas in och vilket belopp som skall komma in)

==&gt; Det borde också gå att se periodiseringar (belopp in/ut som tillfaller nästa period/räkenskapsår)?

...

8) Överväg att ha ett “steg-för-steg” fönster till höger för att se ordning på moment för genomförande av vanliga operationer?

==&gt; Operationen bokslut innehåller stegen fullfölja löpande bokföring, göra omföringar (rätt balans, peridosera resultat, redovisa moms, redovisa årets resultat).

==&gt; Först när man bockar av ett moment öppnas nästa (stängda moment bokför transaktioner i momentet).

==&gt; På detta sätt blir man ledd från bokföring, till bokslut, årsredovisning, deklaration, genrering av underlag till skatteverket.

…

…

Överväg att göra fler anteckningar över hur mitt drömverktyg skulle se ut och fundera på hur jag skulle kunna börja koda på ett sådant i open source och C++?

{% endraw %}
