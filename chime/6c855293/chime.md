# Todo: Programming - Consider to implement and publish an open source C++ SIE-file reader/writer library?

```#6c855293``` *As of 2016-05-07 20:19*

[mail plain/text](mail.txt)

{% raw %}
Imagine to implement and publish as open source a C++ library for SIE-file read and write?

1) Consider to study what existing open source libraries there is for SIE-file decoding and encoding?

==&gt; On github there seem to be a couple of SIE-file processing libraries in different languages?

==&gt; This seem to be a ruby project with latest commit jan 2016 (<https://github.com/barsoom/sie>)?

==&gt; This seem to a node.js Express Framework web application component with latest commit aug 2012 (<https://github.com/holar2b/node-sie-reader>)?

==&gt; This seem to be a C# application (Visual Studio 2013 project file included) with lates commit May 2015 (<https://github.com/idstam/jsisie>)?

==&gt; It seem to be available as installable nuget package?

2) Consider to enable conversion between SIE-data-model in alternative composite encodings (not only the actual SIE-encoding)?

==&gt; SIE-files are encoded as defined by the SIE standard (<http://www.sie.se/?page_id=250>)?

==&gt; But we can imagine the same data-model to be encoded in say JSON or XML (same element names and meaning)?

==&gt; Consider to imagine the C++ SIE-library being able to encode an SIE-data-model in some common internal Key-path-based Composite?

|&lt;==&gt; JSON File Encoder ==&gt; JSON file

|

SIE-File &lt;==&gt; SIE File Decoder &lt;==&gt; SIE-key-path-tagged Composite &lt;==&gt; |

|

|&lt;==&gt; JSON File Encoder ==&gt; JSON file

==&gt; Consider to propose an SIE-structure-key-paths for an SIE-file Composite (<http://www.sie.se/?page_id=250>)?

> // Note: Keys spelled in capital letters corresponds to SIE-encoding of #-element (e.g., sie.ADRESS corresponds to file member #ADRESS)  
> // Note: In key-path the key name is the SIE Element name with spaces replaced with ‘_’ (e.g., SIE Element “distribution address” becomes key “distribution_address”  
> // Note: Elements that implicitly form a list is assigned a list key &#91;&#93;  
> // Note: member with sub-elements {dimension_no object_no} has been assigned the key “object”  
> // Note: Specified #RES member “year’s” has bee assigned the key “year_no”  
> // Note: Specified TRANS member element “object list” has been assigned the list key “objects&#91;&#93;” each conforming to key object (see specification 8.21)  
> sie.ADRESS.contact  
> sie.ADRESS.distribution_address  
> sie.ADRESS.postal_address  
> sie.ADRESS.tel

> sie.BKOD.SNI_code

> sie.DIM&#91;\*&#93;.dimension_no  
> sie.DIM&#91;\*&#93;.name

> sie.ENHET&#91;\*&#93;.account_no  
> sie.ENHET&#91;\*&#93;.unit

> sie.FLAGGA.x

> sie.FNAMN.company_name

> sie.FNR.company_id

> sie.FORMAT  
> sie.FTYP

> sie.GEN.date  
> sie.GEN.sign

> sie.IB.year_no  
> sie.IB.account  
> sie.IB.balance  
> sie.IB.quantity // optional

> sie.KONTO&#91;\*&#93;.account_no  
> sie.KONTO&#91;\*&#93;.account_name

> sie.KPTYP

> sie.KTYP.account_no  
> sie.KTYP.account_type

> sie.OBJEKT&#91;\*&#93;.dimension_no  
> sie.OBJEKT&#91;\*&#93;.object_no  
> sie.OBJEKT&#91;\*&#93;.object_name

> sie.OIB&#91;\*&#93;.year_no  
> sie.OIB&#91;\*&#93;.account  
> sie.OIB&#91;\*&#93;.object.dimension_no  
> sie.OIB&#91;\*&#93;.object.object_no  
> sie.OIB&#91;\*&#93;.balance  
> sie.OIB&#91;\*&#93;.quantity // optional

> sie.OMFATTN

> sie.ORGNR.CIN  
> sie.ORGNR.acq_no  
> sie.ORGNR.act_no

> sie.OUB&#91;\*&#93;.year_no  
> sie.OUB&#91;\*&#93;.account  
> sie.OUB&#91;\*&#93;.object.dimension_no  
> sie.OUB&#91;\*&#93;.object.object_no  
> sie.OUB&#91;\*&#93;.balance  
> sie.OUB&#91;\*&#93;.quantity // optional

> sie.PBUDGET&#91;\*&#93;.year_no  
> sie.PBUDGET&#91;\*&#93;.period  
> sie.PBUDGET&#91;\*&#93;.account  
> sie.PBUDGET&#91;\*&#93;.object.dimension_no  
> sie.PBUDGET&#91;\*&#93;.object.object_no  
> sie.PBUDGET&#91;\*&#93;.balance  
> sie.PBUDGET&#91;\*&#93;.quantity

> sie.PROGRAM.program_name  
> sie.PROGRAM.version

> sie.PROSA

> sie.PSALDO&#91;\*&#93;.year_no  
> sie.PSALDO&#91;\*&#93;.period  
> sie.PSALDO&#91;\*&#93;.account  
> sie.PSALDO&#91;\*&#93;.object.dimension_no  
> sie.PSALDO&#91;\*&#93;.object.object_no  
> sie.PSALDO&#91;\*&#93;.balance

> sie.RAR&#91;\*&#93;.year_no  
> sie.RAR&#91;\*&#93;.start  
> sie.RAR&#91;\*&#93;.end

> sie.RES&#91;\*&#93;.year_no  
> sie.RES&#91;\*&#93;.account  
> sie.RES&#91;\*&#93;.balance  
> sie.RES&#91;\*&#93;.quantity

> sie.SIETYP

> sie.SRU&#91;\*&#93;.account  
> sie.SRU&#91;\*&#93;.SRU_code

> sie.TAXAR

> sie.UB&#91;\*&#93;.year_no  
> sie.UB&#91;\*&#93;.account  
> sie.UB&#91;\*&#93;.balance  
> sie.UB&#91;\*&#93;.quantity

> sie.UNDERDIM&#91;\*&#93;.dimension_no  
> sie.UNDERDIM&#91;\*&#93;.name  
> sie.UNDERDIM&#91;\*&#93;.superdimension

> sie.VALUTA

> sie.VER&#91;\*&#93;.series  
> sie.VER&#91;\*&#93;.verno  
> sie.VER&#91;\*&#93;.verdate  
> sie.VER&#91;\*&#93;.vertext // optional presence  
> sie.VER&#91;\*&#93;.regdate  
> sie.VER&#91;\*&#93;.sign

> sie.VER&#91;\*&#93;.RTRANS&#91;\*&#93;.account_no  
> sie.VER&#91;\*&#93;.RTRANS&#91;\*&#93;.objects&#91;\*&#93;.dimension_no  
> sie.VER&#91;\*&#93;.RTRANS&#91;\*&#93;.objects&#91;\*&#93;.object_no  
> sie.VER&#91;\*&#93;.RTRANS&#91;\*&#93;.amount  
> sie.VER&#91;\*&#93;.RTRANS&#91;\*&#93;.transdate // optional  
> sie.VER&#91;\*&#93;.RTRANS&#91;\*&#93;.transtext // optional  
> sie.VER&#91;\*&#93;.RTRANS&#91;\*&#93;.quantity // optional presence  
> sie.VER&#91;\*&#93;.RTRANS&#91;\*&#93;.sign

> sie.VER&#91;\*&#93;.TRANS&#91;\*&#93;.account_no  
> sie.VER&#91;\*&#93;.TRANS&#91;\*&#93;.objects&#91;\*&#93;.dimension_no  
> sie.VER&#91;\*&#93;.TRANS&#91;\*&#93;.objects&#91;\*&#93;.object_no  
> sie.VER&#91;\*&#93;.TRANS&#91;\*&#93;.amount  
> sie.VER&#91;\*&#93;.TRANS&#91;\*&#93;.transdate // optional  
> sie.VER&#91;\*&#93;.TRANS&#91;\*&#93;.transtext // optional  
> sie.VER&#91;\*&#93;.TRANS&#91;\*&#93;.quantity // optional presence  
> sie.VER&#91;\*&#93;.TRANS&#91;\*&#93;.sign

> sie.VER&#91;\*&#93;.BTRANS&#91;\*&#93;.account_no  
> sie.VER&#91;\*&#93;.BTRANS&#91;\*&#93;.objects&#91;\*&#93;.dimension_no  
> sie.VER&#91;\*&#93;.BTRANS&#91;\*&#93;.objects&#91;\*&#93;.object_no  
> sie.VER&#91;\*&#93;.BTRANS&#91;\*&#93;.amount  
> sie.VER&#91;\*&#93;.BTRANS&#91;\*&#93;.transdate // optional  
> sie.VER&#91;\*&#93;.BTRANS&#91;\*&#93;.transtext // optional  
> sie.VER&#91;\*&#93;.BTRANS&#91;\*&#93;.quantity // optional presence  
> sie.VER&#91;\*&#93;.BTRANS&#91;\*&#93;.sign

3) Consider to define a C++ DSL to define the whole file encoder and/or decoder?

==&gt; Consider a decoder to call an element-sink with each element key-path and value?

==&gt; Consider an encoder to call an element-source with each required element key-path and expect a value in return?

==&gt; Consider to pass element values around as std::optional to communicate if the element value presence?

==&gt; In decoding a not present value indicates a not present element.

==&gt; In encoding a not present value may or may not be encoded as defined by encoding rules (not present element or present element with non-present value)?

…

4) Consider to provide the library with test code?

==&gt; Consider to use Google test Framework (popular)?

==&gt; Or consider to use Boost Tes Framework (well established standard)?

...

Consider to iterate until a working SIE-file encoder/decoder library is implemented?

...

{% endraw %}
