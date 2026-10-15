# Todo: Cratchit - Consider to have Cratchit implement an internal world where Incomes are actual (+) and Costs are actually (-) to better interact with how a "normal" person would understand money?

```#a66cf09a``` *As of 2016-08-09 21:42*

[mail plain/text](mail.txt)

{% raw %}
Could it be possible to actually have Cratchit implement a monetary “world” where values actually have the sign we have come to understand them in daily life?

1) Consider in the Cracthit world income is actually plus (+) and costs are actually minus (-)

==&gt; Consider Cratchit then transforms to and from Swedish bookkeeping world where “Result” are negative for incomes to counterpart the Balance being positive for surplus of capital?

Cratchit Account Idiom

^

|

--------------------------&gt; |

| v

User &lt;--| The Swedish “standard” idiom (e.g. BAS xxx)

| ^

| |

--------------------------&gt; |

v

SIE —&gt; SRU

2) Consider the Cratchit user interface should actually use the Cratchit monetary world and take care of the signs behind the scene when creating SIE representation of financial events?

==&gt; Consider what financial events Cratchit and the user can communicate?

==&gt; Consider payment from other party (positive income, positive asset)

==&gt; Consider payment to other party (positive cost, negative asset)

==&gt; Consider invoice from other party (positive cost, positive debt)

==&gt; Consider sent invoice to other party (positive income, positive asset)

==&gt; Consider internal transactions for bookkeeping purposes as transfers between accounts (decrease one for increase of one other)

==&gt; Consider to opt for having the type of account take care of the “sign” so that in principle all accounts are positive (positive asset, positive debt, positive income, positive cost)

==&gt; Consider then it makes scene that balance is asset - debt?

==&gt; Consider then that result is income - costs?

==&gt; No problem keeping track of signs (it just falls out naturally)?

3) Consider The Cracthit world then has mechanisms to transform to and from the SIE world?

> Cratchit Accounting

> Assets &gt; 0 if we own capital  
> Debit = Increase assets  
> Credit = Decrease assets

> Debts &gt;0 if we have debts  
> Debit = Increase debts (we owe more)  
> Credit = Decrease debts (we owe less)

> Incomes &gt;0 if we made earnings  
> Debit = Increase incomes  
> Credit = Decrease incomes (erroneous registration or internal transfer?)

> Costs &gt;0 If we have had costs  
> Debit = Increase costs  
> Credit = Decrease costs (erroneous registration or internal transfer?)

> ------------------------------------------------------------------------------------------------  
> “Standard” Accounting (e.g. BAS or some proprietary scheme)

> > Asset &gt;0 if we own capital  
> > Debit = Increase Assets  
> > Credit = Decrease assets  
> > Debt &lt;0 If we owe someone  
> > Debit = Decrease Debts  
> > Credit = Increase debts  
> > Income &lt;0 if we gain earnings  
> > Debit = Decrease income  
> > Credit = Increase income  
> > Costs &gt;0 If we gain costs  
> > Debit = Increase costs  
> > Credit = Decrease costs

> ------------------------------------------------------------------------------------------------  
> SIE

> > Asset &gt;0 if we own capital  
> > Debt &lt;0 If we own someone  
> > Income &lt;0 if we gain earnings  
> > Costs &gt;0 IF we gain costs

4) Consider Cratchit to implement a more rigours account schema and also allows for future transactions?

==&gt; Consider Cratchit has Asset, Debt, Income and Cost accounts (but all positive for increase in each type)  
==&gt; Consider Cratchit to allow future statements to prepare planned end-of-year transactions?

==&gt; Consider in this way we may record each financial event including distributing the value over the correct period?

==&gt; E.g., A Cost may be booked with the amount that belongs to this period and the amount belonging to coming period at that very moment (no need to come back and process it at period end)?

…

5) Consider Cratchit to provide a “standard” view using the Cracthit account model?

==&gt; Consider that to enable existing tools to work (e.g. bindings to Tax declarations and end-of-year balance and result reports) we need to be able to provide such a view?

==&gt; Consider Cracthit shall be able to produce a view in any BAS account schema as well as an SIE defined listing of accounts and types?

…

6) Consider SIE is just an encoding of the “standard” account idiom using a standard (e.g., BAS) or some proprietary account scheme?

==&gt; Then Cratchit could implement a “standard idiom view” (+Asset, -Debt, -Income, +cost) and the encode it into SIE?

…

…

Consider to elaborate on this idea to have Cratchit implement a intuitive correct accounting idiom and then be able to transform to and from the “standard” idiom and the to/from SIE?

{% endraw %}
