# Todo: Create an encrypted pfx-file from bought spc-certificate code-signing file

```#1af72d71``` *As of 2015-10-07 13:19*

[mail plain/text](mail.txt)

{% raw %}
So, finally, I know how to buy and use a code signing certificate? (Also see mail “Todo: Create a pfx-file from spc- and key-files”)

1) I bought one from GoDaddy by creating a request using openssl and defined by GoDaddy (Documented at [\\\\psf\\Dropbox\\The](smb://psf/Dropbox/The) ITfied\\Interna Projekt\\26. Use Code Signing certificate)  
==&gt; First time 141031 in Windows 8 (request files at C:\\Users\\kjell-olov\\Desktop\\The ITfied Code Signing Certificate)  
==&gt; Second time 150925 in windows 8 (files at C:\\Users\\kjell-olov\\Desktop\\The ITfied Code Signing Certificate 150925)  
2) After they authenticated me over the phone I could download the certificate as an spc-file.  
==&gt; First time 141031 I got 76180a87894c.spc ([\\\\psf\\Dropbox\\The](smb://psf/Dropbox/The) ITfied\\Köpta Digitala Media\\GoDaddy)  
==&gt; Second time 150925 I got d8775b727123848b.spc ([\\\\psf\\Dropbox\\The](smb://psf/Dropbox/The) ITfied\\Köpta Digitala Media\\GoDaddy)  
3) After trial-and-error I figured out a series of steps to create the files I needed to use them for Code Signing in InstallShield 2015 (InstallShield 2012 had become incompatible with Windows security updates for Code Signing)

a) I used Windows to create a cer-file (i.e. PEM-formatted file) from my spc-file.

1) I opened the spc-file and saved the ITfied certificate as “Base-64 encoded”, i.e. PEM-format.  
2) I named the file TheITfiedCert.cer

I now used openssl to convert PEM to PFX  
&gt; openssl pkcs12 -export -out certificate.pfx -inkey privateKey.key -in TheITfiedCert.cer

\*) Note no -certfile parameter (I trusted openssl to get it from windows CA storage, or not need it, and it worked).

\*) Note that openssl asks for a passphrase but I entered nothing (this means no password value is required in InstallShield)

==&gt; The command created a pfx-file (although it reported “Unable to write ‘random state'”). What does that mean?  
==&gt; But the file worked in InstallShield 2015 (No password required)

So ==&gt; How do we create a pfx-file that is password protected?

4) Tried the "openssl pkcs12 -export” command using a password

Tried OpenSSL with option for output password

&gt; openssl pkcs12 -export -out certificate.pfx -inkey privateKey.key -in TheITfiedCert.cer -passout stdin

\*) The “-passout stdin” should tell openssl to ask the user to enter the passphrase to use for the output?

\*) The command passed without a prompt so I tried entrained a password and hit enter.

\*) A pfx-file was created.

==&gt; NO, the cerated pfd-file was not accepted by InstallShield 2015 (with out without the password entered for the openssl command)

Tried openssl default behaviour for output passphrase.

&gt; openssl pkcs12 -export -out certificate.pfx -inkey privateKey.key -in TheITfiedCert.cer

\*) Note this is the same command as the one that worked above.

\*) Openssl now prompts “Enter Export Password” and “Verifying - Enter Export Password”. I entered a password.

==&gt; YES, the created pfx-file now works with InstallShield (provided the password in InstallShield “Certificate Password” field!

5) So, here is what should work.

a) Create a Certificate request in the form of privateKey.key and CSR.csr using openssl (as defined by the CA we by the certificate from)

b) Install the received certificate (spc-file) in windows 8 using (right click the file and select &lt;Install Certificate&gt;

c) Use windows certificate viewer to export the installed certificate (the leaf certificate i.e. in out the case “The ITfied AB” certificate) to “Base-64 encoded”, i.e. PEM-format (cer-file)

d) Use openssl to create a password protected pfx-file

6) Store the CSR, private key and pfx-password at a secure location (NOT Online)!

==&gt; Consider to use an encrypted USB-stick?

7) At the production environment, place the certificate pfx-file in a local folder and have InstallShield use that one.

a) Consider to create a sub-folder of the project Install build directory called “Code_Signing_Certificate”.

b) Place the password-protected pfx-file in that folder and make InstallShield use it.

c) To the folder, add a README.TXT that explains how to administrate the pfx-file (describe that the pfx-file is not online but must be provided into the build environment and also installed there!)

&lt;Visited information sources&gt;

a) OpenSSL Cookbook published by FeastyDuck ([https://www.feistyduck.com/library/openssl%2dcookbook/online/](https://www.feistyduck.com/library/openssl-cookbook/online/)). I also downloaded it as EPUB book to Downloads “OpenSSLCookBook”

{% endraw %}
