# Todo: Consider to understand and build my own cryptocurrency coin (e-coin) hardware wallet?

```#9ef41d95``` *As of 2017-12-23 18:50*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good and interesting adventure to try and understand and build my own hardware e-coin wallet (to secure blockchain ledger wallet keys)?

1) Consider this EEVLog 1048 episode testing the “EEVblog #1048 - Ledger Nano S Crypto Hardware Wallet” hardware wallet (<https://www.youtube.com/watch?v=SKWYO3Qh79A>)?

==&gt; The “Ledger Nano S” crypto currency wallet seems to live here (<https://www.ledgerwallet.com/products/ledger-nano-s>)?

==&gt; The Trezor bitcoin wallet seems to live here (<https://trezor.io>)?

==&gt; At 6:03 he seems to show that Ledger Nano S supports BIP 39 Wordlist, BIP 32 key derivation and BIP 44 key recovery standards (<https://youtu.be/SKWYO3Qh79A?t=363>)

![](<Screen Shot 2017-12-23 at 16.05.39.png>)

==&gt; At 31:08 he seem to state that the Ledger Nano S is based on the SMT32F042 micro controller (<https://youtu.be/SKWYO3Qh79A?t=1868>)?

![](<Screen Shot 2017-12-23 at 16.41.27.png>)

==&gt; The SMT32F042 micro controller seems to live here (<http://www.st.com/en/microcontrollers/stm32f042f6.html>)?

![](<Screen Shot 2017-12-23 at 16.41.40.png>)

==&gt; At 31:44 he seems to state that the wallet uses the ST31H320 security chip also from STMicroElectronics (<https://youtu.be/SKWYO3Qh79A?t=1904>)?

![](<Screen Shot 2017-12-23 at 17.44.34.png>)

==&gt; The chip seems to live here (<http://www.st.com/en/secure-mcus/st31h320.html>)?

==&gt; It seems to be defined as an “SecurCore® SC000™ 32-bit RISC core”

==&gt; Which seem to be defined by the ARM group here (<https://developer.arm.com/products/processors/cortex-m/sc000-processor>)?

==&gt; It seems to be a chip also used on Smart Cards?

> > > “*The SC000 is currently the most widely licensed 32-bit processor for smartcards worldwide*”

==&gt; It surely seems stable for hardware security processing supporting a wide range of well proven algorithms?

> > “*The AES accelerator provides a high-performance implementation of **AES-128, AES-192, AES-256** algorithms. The 3-key **Triple DES** accelerator (EDES+) peripheral enables Cipher Block Chaining (**CBC**) mode, fast DES and triple DES computation based on three key registers and one data register, while the NESCRYPT cryptoprocessor efficiently supports the **public key algorithm** with native operations up to 4096 bits long.*"

==&gt; It seems ST31 and ST33 chip series aims at contactless and contact PKI based cards (<http://www.st.com/en/secure-mcus/secure-hardware-platforms.html>)?

![](<Screen Shot 2017-12-23 at 18.06.37.png>)

==&gt; Consider this video that seems to really stress the application of ST31 MCU series for contactless cards (<https://st-videos.s3.amazonaws.com/Secure_Offer.mp4>)?

![](<Screen Shot 2017-12-23 at 18.25.26.png>)

…

2) Consider to investigate and understand hardware security and standards related to ST31 hight security micro controllers?

==&gt; Consider the wikipedia article on ISO 7816 (<https://en.wikipedia.org/wiki/ISO/IEC_7816>)?

> “***ISO/IEC 7816** is an international standard related to electronic identification cards with contacts, especially smart cards, managed jointly by the International Organization for Standardization (ISO) and the International Electrotechnical Commission (IEC).*"

==&gt; Consider the wikipedia article on ISO 14443 (<https://en.wikipedia.org/wiki/ISO/IEC_14443>)?

> “***ISO/IEC 14443 Identification cards** -- Contactless integrated circuit cards -- Proximity cards is an international standard that defines proximity cards used for identification, and the transmission protocols for communicating with it*"

==&gt; This seem to be the ST31 architecture (<http://www.st.com/en/secure-mcus/st31-arm-sc000.html?querycriteria=productId=SC1617>)?

![](<Screen Shot 2017-12-23 at 18.14.06.png>)

==&gt; While this is the ST23 architecture (<http://www.st.com/content/st_com/en/products/secure-mcus/secure-hardware-platforms/st23.html?querycriteria=productId=SC1126>)?

![](<Screen Shot 2017-12-23 at 18.15.26.png>)

3) Consider support for tinkering and developing using the SMT32 chip and the ST31 chip?

==&gt; It seems ARM group prdoived development environments should work with ST31 (SecureCore) chips (<http://www.st.com/content/ccc/resource/technical/document/data_brief/ac/ed/36/cb/1c/04/43/a8/DM00240763.pdf/files/DM00240763.pdf/jcr:content/translations/en.DM00240763.pdf>)?

> “Software development tools description

> Dedicated SecurCore® SC000TM software development tools are provided by ARM® and Keil®. This includes the **Instruction Set Simulator** (ISS) and C compiler. The documentation is available on the ARM and Keil web sites.

> Moreover, STMicroelectronics provides:

> A time-accurate hardware **emulator** controlled by the Keil debugger and the **ST development environment**.

> A complete product **simulator** based on **Keil’s ISS simulator** for the SecurCore® SC000TM CPU."

==&gt; Digikey seems to sell STMicroElectronics SMT32F042 boards for 100 SEK (<https://www.digikey.se/product-detail/en/stmicroelectronics/NUCLEO-F042K6/497-15980-ND/5428804>)?

==&gt; It seems all SMT32 boards come with Arduino connections as well as their own (<https://www.digikey.se/en/product-highlight/s/stmicroelectronics/stm32-kits>)

> “*STM32 Nucleo boards help design engineers try out new ideas and to quickly create prototypes with any STM32 MCU. All Nucleo boards come with **Arduino™ connectors** and the STMicroelectronics **Morpho connectors** allowing for easy hardware add-ons. STM32 Nucleo users have free access to the **mbed online compiler**, the mbed online C/C++ SDK and the developer community at [mbed.org](http://mbed.org). Build a complete application in only a few minutes.*"

==&gt; Consider this Github based project to use Arduino IDE to develop for SMT32 boards (<https://github.com/rogerclarkmelbourne/Arduino_STM32>)?

==&gt; It does not mention support for SMT32F0xx boards (only F1xx, F3xx and F4xx)?

==&gt; It seems the F0 series are 8 bit controllers while the F1 series are 32 bit controllers (<http://www.st.com/en/microcontrollers/stm32f0-series.html?querycriteria=productId=SS1574>)?

> > “ *• The STM32F0x0 Value line is highly competitive in traditional 8-bit and 16-bit markets and eliminates the need to manage different architectures and the associated development overhead. If your device needs a USB peripheral, it’s now possible to order an STM32F070 Value line MCU.*  
> > *• The STM32F0x1 line provides a high integration of functions and covers a wide range of memory sizes and packages, bringing flexibility to cost-sensitive applications.  
> > *  
> > *• The STM32F0x2 line provides rich connectivity with crystal-less USB 2.0 and a CAN bus interface, making it the ideal choice for communication gateways, smart-energy devices or game terminals.  
> > *  
> > *• The STM32F0x8-line operating at 1.8V ±8% is well suited for use in portable consumer applications such as smartphones, accessories and media devices.*"

![](<Screen Shot 2017-12-23 at 17.07.26.png>)

==&gt; There seem to a an Arduino IDE group that lives here (<http://www.stm32duino.com>)?

4) It seems ARM supports the [mbed.org](http://mbed.org) framework for IoT using Arm products (<https://www.mbed.com/en/>)?

==&gt; NOTE: mbed seem to be more than ARM (Arm products are only part of the mbed framework)?

==&gt; There seem to be a crazy amount of mbed platform enabled development boards out there (<https://os.mbed.com/platforms/>)?

==&gt; This seems to be all STMicroElectronics boards listed on the mbed site (<https://os.mbed.com/platforms/?tvend=10>)?

==&gt; It lists the MT32F042 board here (<https://os.mbed.com/platforms/ST-Nucleo-F042K6/>)?

==&gt; It seems to be listed as an “ARM®32-bit **Cortex®-M0** CPU” ?

==&gt; Consider the wikipedia page on ARM Cortex M (<https://en.wikipedia.org/wiki/ARM_Cortex-M>)?

> “The **Arm Cortex-M** is a group of 32-bit RISC Arm processor cores licensed by **Arm Holdings** for microcontroller use"

![](<Screen Shot 2017-12-23 at 17.41.27.png>)

...

5) Consider to study and understand the BIP 39 Wordlist, BIP 32 key derivation and BIP 44 key recovery standards?

==&gt; BIP seems to refer to “Bitcoin Improvement Proposal” and live here on Github (<https://github.com/bitcoin/bips>)?

==&gt; BIP 39 seem to be a way to represent encryption keys using words, i.e. a word list (<https://github.com/bitcoin/bips/blob/master/bip-0039.mediawiki>)?

==&gt; BIP 32 seem to be a way to create and access wallet tree hierarchies (<https://github.com/bitcoin/bips/blob/master/bip-0032.mediawiki>)?

> “*The specification consists of two parts. In a first part, a system for **deriving a tree** of keypairs from a single seed is presented. The second part demonstrates how to build a **wallet structure** on top of such a tree.*"

==&gt; BIP 44 seem to be an actual wallet tree hierarchy using BIP 32 (and BIP 43) mechanisms (<https://github.com/bitcoin/bips/blob/master/bip-0044.mediawiki>)?

> “*This BIP **defines** a logical **hierarchy** for deterministic wallets based on an algorithm described in **BIP-0032** (BIP32 from now on) and purpose scheme described in **BIP-0043** (BIP43 from now on).*"

...

6) Consider to study and compare the “Ledger Nano S” crypto currency wallet (<https://www.ledgerwallet.com/products/ledger-nano-s>)?

...

7) Consider to study and compare the Trezor bitcoin wallet (<https://trezor.io>)?

8) Consider to investigate what Yubico is up to and how it relates to crypto currency hardware wallets (<https://www.yubico.com/products/yubikey-hardware/>)?

==&gt; They do not seem to advertise any crypto currency wallet products?

==&gt; It seems Yubico focus on user authentication using hardware digital encryption technologies?

> “*With a simple touch, the YubiKey protects access to computers, networks, and online services. Touch to trigger **FIDO U2F**, smart card (**PIV**), Yubico OTP, **Code Signing**, **OpenPGP**, **OATH**-TOTP, OATH-HOTP, and **Challenge-Response***"

==&gt; It seems Yubico interfaces with user authentication interfaces for a range of well known large services (<https://www.yubico.com/solutions/>)?

> “Designed to work off-the-shelf, the YubiKey works with Facebook, Gmail, GitHub, Dropbox, Dashlane, LastPass, Salesforce, Duo, Docker, Centrify..."

==&gt; Consider this 2015 open source initiative implementing a javacard bitcoin wallet on a Yubikey Neo (<https://github.com/Toporin/SatoChipApplet>)?

> “*SatoChip stands for Secure Anonymous Trustless and Open Chip. It is a **javacard applet** that can be used as a secure hardware wallet running for example on a **Yubikey Neo**.*"

…

…

Consider top delve into this idea of developing my own hardware cryptocurrency hardware wallet and in the process connect my knowledge about card payments, contactless cards, EMV regulations and what have you?

{% endraw %}
