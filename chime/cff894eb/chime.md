# Todo: Programming - Consider book-keeping-tool (e.g., Cratchit) to anticipate financial statements to register based on the financial statement history?

```#cff894eb``` *As of 2016-08-05 16:25*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to have a mechanism of a book-keeping-tool (e.g. Cratchit) to propose (anticipate) financial statements due at current date by comparing with this that where entered at roughly the same time of previous years?

1) Consider to implement the mechanism in Cratchit as a proof-of-concept?

==&gt; Created Github project (https://github.com/kjelloh/cratchit)

2) Consider how Cratchit shall behave?

==&gt; Consider “2016-05-17 Telia 1330,00” should generate an SIE statement for invoice from Telia?

==&gt; Consider the general form “&lt;date&gt; &lt;keyword&gt; &lt;amount&gt;” shall generate an SISE statement for the template defined by keyword?

==&gt; Consider an invoice number should be created for a created SIE statement representing a received invoice?

==&gt; Consider the keyword defines a payment is there is already an unpaid invoice statement registered matching the same keyword?

2016-05-17 Telia 1330,00 ==&gt; Creates an SIE statement for invoice from Telia?  
2016-06-16 TELIASONERA SPERRIGE AB -1.330,00 ==&gt; Creates an SIE statement for payment from Telia?

==&gt; Consider the keyword “VAT” creates an SIE-statement that closes the current VAT period?

==&gt; Consider if Cratchit should be able to auto-generate VAT close statements (ITfied currently declares VAT each 3-month period )?

…

3) Consider the mechanism to use SIE-file input to register date and time of entered verifications?

4) Consider the mechanism to anticipate (and propose) verifications that occurs at roughly the same time each year (timed verifications)?

==&gt; Consider end-of-year and beginning-of-year as such ”specific time” verifications (always xx0430 and xx0501)?  
...

5) Consider the mechanism to try and identify recurring (periodic) verifications?

==&gt; Consider Mobile-phone invoices and payments to be such periodic ones?  
==&gt; Consider to use a time-window of different sizes to identify periodic verifications?

==&gt; E.g., One month, three month, yearly)?

6) Consider the mechanism to try and identify accrual financial statements (Swedish ”periodiseringar”)?

==&gt; Consider how we may identify financial statements solely to place part of the transaction in the correct period?  
…

…

Consider to delve into this idea of having a book-keeping-tool base its expectations of financial statements to make at a given time on what has happened in the past?  
...

{% endraw %}
