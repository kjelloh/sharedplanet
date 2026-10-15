# Todo: Book keeping - Consider I should do accounting in the actual format I am required to report it to the Swedish tax Agency "Skatteverket" and "Bolagsverket"?

```#94d5fe3e``` *As of 2019-08-10 13:44*

[mail plain/text](mail.txt)

{% raw %}
So, if the "ultimate" reason I keep books is top be able to do the required reporting to Swedish Authorises I should in fact keep the books in the format they require to get the reporting in?

1) Consider what I am required according to Swedish Law to report to Swedish Authorises and keep track of in may day-to-day business?

2) Consider how to help with the hurdles I experienced when doing my latest Tax Agency yearly declaration and Annual Report to "bolagsverket"?

> *One hurdle was to map the accounts in my book keeping to the Annual Report as defined by Swedish law to report it in a text dokument to "Bolagsverket".*

> *1) I had a hard time to understand what BAS accounts to use for different financial events so that the amounts end up at the right location in the Annual Report*  
> *2) I had a hard time to understand how to summarise BAS accounts (with correct signs mind you) into the correct entries in the Annual Report*

> *It seems, I I just kept the books in the format of the entries in the Annual Report I would NOT have had these problems?*

> *One hurdle was to map the accounts in my book keeping to the Annual Tax Declaration to send to the Swedish Tax Agency*

> *1) I had a hard time to understand what BAS accounts to use for different financial events so that the amounts end up at the right location in the tax Agency Declaration*  
> *2) I had a hard time to understand how to summarise BAS accounts (with correct signs mind you) into the correct entries in the Annual Tax Agency Declaration*

> *It seems, I I just kept the books in the format of the entries in the Tax Agency declaration I would NOT have had these problems?*

> *Now, it seems the entries in the Annual Financial Report and the entries in the Tax Agency Annual declaration maps up very well. There where as far as I could understand just one entry where the Tax Agency required an amount to be reported as two parts while the Annual Report to "Bolagsverket" accepted the amounts reported as one summed together.*

3) Consider what I can do to enhance book keeping using the standard BAS accounts but still be able to effortlessly extract information in reports to Swedish Authorises?

==&gt; It seems I need to report VAT every quarter, Salary Tax and fees every month and two almost equal Annual Financial Statements to Swedish Tax Agency and to "Bolagsverket"?

> *Now there exists a mapping in the form of SRU codes to map values in BAS accounts to Swedish Tax Agency reports. But to map BAS accounts to the Annual Financial Report to "Bolagsverket" I need a "hard coded" approach. As far as I have seen there are no "codes" to identify entries in the Annual Financial report as defined by the Swedish law. So maybe we can define one just to simplify things?*

> *There is still a problem with the VAT report in that it is not so clear what the amounts in this report actually is expected to mean! I have reason to suspect some of the amounts are reported just for survey purposes so that Swedish Authorises can create reports and follow trends in the financial sector. The values of goods and services I have imported or bought within EU are two amounts I strongly suspect are just for statistical purposes. And so is the "virtual VAT" I have to add and subtract on stuff I buy from outside of EU. All which gets very complicated to correctly enter into the BAS accounts (as they do not actually exist in the real world)! For these amounts a book keeping system that actually uses the entries in the VAT report as the record keeping format would be a bliss!*

> *Som should I get rid of the BAS accounts all together? And design a book keeping application that uses the Swedish Tax Agency SRU codes as accounts instead? At least in that way I am sure I will have an easier time to do the actual accounting as required by the Swedish Tax Agency. And I am pretty sure I can map the SRU codes to the amounts required for the entries in the Annual Financial Report I am required to produce according to Swedish law?*

> *And I could still tag the SRU accounts with BAS accounts to be able to produce reports based on these. Ok, so I would loose the ability to split amounts in SRU accounts into sub-BAS-accounts. But then, would that be such a great loss? I suppose if I would like to be able to use my accounting to track separate streams of financial activities (e.g., different sell revenues or department costs) or values of separate assets I would not be able to do so. The SRU codes are coarser and does not allow for such dub division of amounts.*

> *One way would have my accounting application use nested name spaces identified with account path names. So we could sub-divide any SRU account by adding a sub-account that is the BAS account? Now this would work as along as each BAS account is mapped to only ONE UNIQUE SRU code. And I am not sure this is the case.*

> *So maybe a problem we need to address is to be able to have many-to-may relationship between accounts in the company books and the entries in the reports I am required to send to Swedish Authorises?*

4) Consider we should define an accounting scheme that allows for many-to-may mappings from internal financial events and amounts to entries in several different report formats?

==&gt; Consider we need to keep an incarnation of the Italian double book keeping to have each financial statement be accounted for in a way that the entries "zeroes out"?

> *It seems we can't get rid of the mechanism to keep books that requires each financial event to be accounted for so that the account entries "zeroes out". This is so basic and probably powerful that we should keep it. Now, this way of account financial events is based on the model of reality that each amount represents a flow of currency and an accumulation of currency. So we account both what the flow was and where it ended up.*

> *But maybe we can do a better job of modelling currency flow vs currency accumulation to make the accounting more intuitive? For example, I get taxed for the flow of currency into my company where the net inflow minus the net outflow is the "result". On the other hand, some of that flow may be some interest on assets I have borrowed or loaned out. And the value of these assets measured in currency are also kept in my books. But there is some subtle differens between flow of currency and assets measured in currency.*

> *Now, accounting is only about flow of currency! A financial event is always about currency being transacted. If I pay for something I transact currency from my bank account to the seller. So it is natural to understand I have to account for the reduction of currency on my bank account. But I am also required to account for where the money went! And I do this by accounting the same amount, but with opposite sign (!), to a cost account. And this latter account thus is an account of the flow of currency to that "type" of cost. So while the first account reflects the actual amount I have on my account (it is actually there), the cost account only accumulates all the "flow" of currency for the purpose represented by the account! There seems to be a crucial difference here that maybe the accouning application should expose to the user?*

> *It is as if a cost account is more like the gauge on a petrol dispenser pump while the bank account is more like a level gauge on the tank itself?*

> ***Aha - the accounting application could show the Equity, Capital and Liability accounts as "containers" with "level gauges" and Revenue/Income and Expense/Losses accounts as "pumps" with flow meters? ***

5) Consider the wikipedia article on Double-entry bookkeeping system (<https://en.wikipedia.org/wiki/Double-entry_bookkeeping_system> )?

...

{% endraw %}
