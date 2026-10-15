# Todo: Consider to understand the Nordea "EBOKSsignatur.XML" file format and content (what is it and how is it used to verify a signature)?

```#877d773e``` *As of 2020-08-27 12:15*

[mail plain/text](mail.txt)

{% raw %}
-1) It seems the XML file I downloaded as a "proof" of me having signed a Nordea document with Mobile BankID is part of Nets SDO framework (<https://www.nets.eu/developer/E-Signing/overview/Pages/Signeddocumentformat.aspx> )?

> *"The SDO (**Signed Data Object)** and PAdES (PDF Advanced Electronic Signatures) document format is described on this page. "*

> *"**The SEID SDO is a XML based data package designed to act as a self-contained validation of one or more digital signatures on one or more documents. The reason for this format is to be able to confirm non-repudiation and integrity of the signed document independent of time. Thus the result of a digital signing process can be packaged into a SEID SDO format to simplify validation, traceability and visualization of the signed document.*

> *The SEID SDO is based upon ETSI TS 101 733 (CAdES) and ETSI 101 903 (XAdES). The SEID SDO format is described here: Kva er SEID-prosjektet​ (in Norwegian only)

> A comparable format is PAdES which uses Acrobat reader to visualize the digital signature embedded in a .pdf document. The Nets E-Signing service produces both a SDO and a PAdES file (if requested) as the result of a digital signing process.**"*

## Attachments

- [EBOKSsignatur.XML](EBOKSsignatur.XML)

{% endraw %}
