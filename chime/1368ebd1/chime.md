# Todo: Consider to write about how Card Payment Networks work?

```#1368ebd1``` *As of 2017-01-10 09:05*

[mail plain/text](mail.txt)

{% raw %}
When you pay with a card you initiate a two step process.

1. The first happens when you use the card and results in an I Owe You (IOY) from your Card Issuer (and your Card Account) to the Merchant.
2. The second happens when the Merchant sends the IOY to the acquire and gets reimbursed.

Now, what complicates these two processes are all the sub steps involved and not to mention all the different parties chipping in to make this global machinery work. Lets delve a little deeper to get a feel of the next level of granularity.

Lets start with the IOY, there are many ways the Card Issuer allows the Merchant to acquire a valid one. At the very least the Cardholder must provide a valid card number to the Merchant. This number is called Personal Account Number, or PAN, and it uniquely identifies the cardholders account with the Card Issuer.

...

{% endraw %}
