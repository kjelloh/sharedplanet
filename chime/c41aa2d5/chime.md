# Todo: Consider to enable invoice receivers to authenticate the sender by encrypting some sender ID with public private key pair?

```#c41aa2d5``` *As of 2018-05-13 12:57*

[mail plain/text](mail.txt)

{% raw %}
Consider we can imagine a procedure where the sender of an invoice encrypts its name with its private key so that the receiver can check this using the senders public key?

1) Consider how the sender and receiver can cooperate to enable the receiver to authenticate received invoices (or other communication)?

==&gt; Consider the sender encrypts its name using its private key?

==&gt; Consider it then puts the encrypted data as BASE-64 on the sent invoice?

==&gt; Consider the sender publish its public key?

==&gt; Consider the receiver may now decrypt the BASE-64 encoded data with the public key?

==&gt; Not the receiver should get the correct sender name (if not, the sent invoice is a fraud)?

…

2) Consider to enhance the process so that only a Hash is exchanged?

==&gt; We need a way so that the sender can generate a hash that the receiver can authenticate ONLY using the public key?

==&gt; It seems the sender can first hash its name using a defined hash algorithm?

==&gt; The sender can even publish this hash?

==&gt; The sender then encrypts this hash with its private key?

==&gt; The result is data of the same length as the hash?

==&gt; The sender now sends this encrypted hash on the invoice to the receiver?

==&gt; The receiver now uses the public key of the sender to decrypt the received hash.

==&gt; The result should now be the hash of the sender?

…

3) Consider we may encode the encrypted hash on the invoice as an QR-code?

==&gt; It seems we can store 2953 binary bytes into a QR-code (<https://en.wikipedia.org/wiki/QR_code#Storage>)?

==&gt; It seems RSA and NIST recommends 2048 bit (256 bytes) RSA keys for security up to 2030 (<https://en.wikipedia.org/wiki/Key_size>)?

> “*RSA claims that 1024-bit keys are likely to become crackable some time between 2006 and 2010 and that **2048-bit keys are sufficient until 2030**.&#91;14&#93; The **NIST recommends 2048-bit keys for RSA**. &#91;15&#93; An RSA key length of 3072 bits should be used if security is required beyond 2030.&#91;16&#93; NIST key management guidelines further suggest that 15360-bit RSA keys are equivalent in strength to 256-bit symmetric keys.&#91;17&#93;*"

==&gt; It seems the QR-code storage capacity of 2953 bytes vastly exceeds the RSA key length requirement of 256 bytes (we can store some additional info)?

...

4) Consider with Darwinet the shared data is already secured by domain and node-2-node encryption and authentication?

==&gt; Thus, Using Darwinet the access to trusted public key of the sender can be secured by the Darwinet network?

==&gt; Consider Darwinet may also incorporate some form of blockchain-consensus as further basis of trust between messaging parties?

...

…

Consider to delve deeper into this idea of designing (proposing) a process where senders and receivers of invoices may cooperate to ensure invoice authentication?

{% endraw %}
