# Todo: Code Signing - Consider to document how ordering, receiving activating and applying Digicert Code Signing Certificate went?

```#580805de``` *As of 2016-11-22 12:16*

[mail plain/text](mail.txt)

{% raw %}
So, could it be a good idea to document for further references how to purchase and apply a Digicert Code Signing Certificate?

1) This seem to be the order confirmation 19/2 2016 (e-mail “DigiCert Order Confirmation for Order# 00877323 (your order is currently being processed)")?

Hello Kjell-Olov Högdal,

Thank you for your recent purchase! Our validation department is now reviewing your order. We may contact you if we need additional information to verify your organization.

To check on the status of your order, please visit: <https://www.digicert.com/custsupport/order-details.php?order_id=00877323>

Below you will find the details for Order# 00877323

**Thank you for choosing DigiCert!**

DigiCert Receipt Details for Order #00877323

DigiCert, Inc.  
2600 West Executive Parkway  
Suite 500  
Lehi, UT 84043  
USA  
Tel: 1-801-877-2100  
Fax: 1-801-705-0481  
Web: [www.digicert.com](http://www.digicert.com)  
Support: [support@digicert.com](mailto:support@digicert.com)

The ITfied AB

Aron Lindgrens Väg 6  
Järfälla, 17668  
Sweden

## Receipt Details

**Product Details**Product Purchased:EV Code SigningDate Purchased:19 Feb 2016 4:06 am MSTValidity Period:1 year(s)Common-Name (Domain):Account Number:135247Order Number:00877323

2) This seem to be the e-mail confirmation 19/2 2016 that I will be contacted to verify who I am (e-mail “Please approve DigiCert Order #00877323 for The ITfied AB”)

Dear Kjell-Olov Högdal,

DigiCert recently received a certificate request on behalf of The ITfied AB that requires your approval prior to the certificate's issuance.

Please go to the following address to review and approve this order:

<https://www.digicert.com/link/approve-order.php?t=d6z9tmd565tpxzjr&order_id=00877323>

If you have any questions, please contact DigiCert support at [support@digicert.com](mailto:support@digicert.com) or 1-801-701-9600.

Thanks!

The DigiCert Team

Phone: 1-801-701-9600  
Email: [support@digicert.com](mailto:support@digicert.com)  
Live Chat: [www.digicert.com](https://www.digicert.com/)

3) This seem to be the e-mail confirmation 22/2 2016 that the Certificate hardware token has been shipped (e-mail “Your DigiCert EV Code Signing Certificate has been shipped : Order #00877323”)

This is an email notification to let you know that we have just shipped your EV Code Signing Hardware Token.

You can track the package using the following link: <https://www.fedex.com/apps/fedextrack/?tracknumbers=775701361530>

Note that tracking for international orders may not be available after the package is passed off to the local postal service.

When you receive the token, login to your DigiCert Account to find the device password at:

<https://www.digicert.com/custsupport/order-details.php?order_id=00877323>

Change the password after logging into the token for the first time.

Please let us know if you have any questions. Thank you,  
DigiCert Support  
[support@digicert.com](mailto:support@digicert.com)

Thanks!

4) It seems I have to download a special USB token drover to access the USB?

==&gt; I logged in to my Digicert account

==&gt; I then acknowledged having received the token (was a little hard to find where to click )

==&gt; I then gained access to a download page

![](<Digicert Hardware Token Receipt Acknowledge Downloads.tiff>)

==&gt; I downloaded the driver on Windows 10 (it actually automatically started downloading when I logged in from Windows 10 having the above page open on my MAC)

==&gt; ...Download was really slow (19 MB in 5 minutes)

==&gt; I installed the driver to “C:\\Program Files\\SafeNet\\Authentication\\”

![](<Digicert Driver Install 1.tiff>)

![](<Digicert Driver Install 2.tiff>)

![](<Digicert Driver Install 3.tiff>)

![](<Digicert Driver Install 4.tiff>)

==&gt; I inserted the USB stick into my MAC and selected it to be mounted on Windows 10 Virtual Machine

\*\* Nothing happens \*\*

==&gt; I restart my Windows 10 Machine to see if this helps

==&gt; Aha - I must use the installed Client Software!

![](<SafeNet Authentication Client Tools.tiff>)

==&gt; I changed the password as instructed.

![](<Code Signing Token Password Changed Succesfully.tiff>)

5) It seems I have to export the certificate from the Token to the platform to be able to apply it for Code Signing?

==&gt; The Advanced View seem to enable view of the Tokens on the USB?

==&gt; There seem to be a Help button that opens up a help file?

==&gt; There seem to be a way to Export the Code Signing Certificate as a \*.cer-file?

...

{% endraw %}
