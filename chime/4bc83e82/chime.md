# Todo: Consider to use this testdata to check MAC calculation refactoring?

```#4bc83e82``` *As of 2016-10-12 12:39*

[mail plain/text](mail.txt)

{% raw %}
-------------------- Header Log ----------------------------  
500 12:36:28 553 20161012 Proxy ----&gt; HOST 68 Purchase Online

------------------------------------------------------------

------------------- Expanded Log ---------------------------  
TS=20161012123628553 TXNODE=eIPosTBNode_SPDHProxy TXNODEINDEX=-1 RXNODE=eIPosTBNode_SPDH_HOST RXNODEINDEX=-1 InformationType=General Content=SPDHFrame D=023502392E363835393130303031362020202020202020333120202020313631303132313233363232464F30303035303030301C4230303030303130301C44301C4741333535383139351C50311C611E41303036331E422B30303030303132373039381E43303036331E442B30303030303132373039381E45303030303030301E46303030303030301E47311E48301E493030311C643139373732303620202020201C6530301C68303031303031313135301C361E453035311E4630301E493735321E4F3031383037353231363130313234354533463636463845454638333444333930303030324435413745454141363030303030303030303030303735323030303030303030303130303031313041373430303330323330303030303030353244413031323836413634303035371E503031303032323434303330323030303241303030303030303034333036301E5446464646373338393137303341363030303042321E583030303030321C391E4330351E443539313030303136303134301E49353632311E504530463043381E51373030303830423030311E5230303030381E53495446494544202020202020202020202020202020204B4953544120202020202020203132332034352020202053451F323637344343334532343039434144353330453545363444313443363543314146444442313731313930354642443442454441343333413142323044354132363143353334333835334238363145374134303543314239304344413037383133036C  
--- 12:36:28.553 2016-10-12 ---  
Proxy ==&gt; 68 Purchase Online ==&gt; HOST  
Raw :&lt;02&gt;5&lt;02&gt;9.6859100016 31 161012123622FO00050000&lt;1c&gt;B00000100&lt;1c&gt;D0&lt;1c&gt;GA3558195&lt;1c&gt;P1&lt;1c&gt;a&lt;1e&gt;A0063&lt;1e&gt;B+00000127098&lt;1e&gt;C0063&lt;1e&gt;D+00000127098&lt;1e&gt;E0000000&lt;1e&gt;F0000000&lt;1e&gt;G1&lt;1e&gt;H0&lt;1e&gt;I001&lt;1c&gt;d1977206 &lt;1c&gt;e00&lt;1c&gt;h0010011150&lt;1c&gt;6&lt;1e&gt;E051&lt;1e&gt;F00&lt;1e&gt;I752&lt;1e&gt;O018075216101245E3F66F8EEF834D3900002D5A7EEAA60000000000007520000000001000110A74003023000000052DA01286A640057&lt;1e&gt;P0100224403020002A0000000043060&lt;1e&gt;TFFFF73891703A60000B2&lt;1e&gt;X000002&lt;1c&gt;9&lt;1e&gt;C05&lt;1e&gt;D591000160140&lt;1e&gt;I5621&lt;1e&gt;PE0F0C8&lt;1e&gt;Q700080B001&lt;1e&gt;R00008&lt;1e&gt;SITFIED KISTA 123 45 SE&lt;1f&gt;2674CC3E2409CAD530E5E64D14C65C1AFDDB1711905FBD4BEDA433A1B20D5A261C5343853B861E7A405C1B90CDA07813&lt;03&gt;l  
No Parity:&lt;02&gt;5&lt;02&gt;9.6859100016 31 161012123622FO00050000&lt;1c&gt;B00000100&lt;1c&gt;D0&lt;1c&gt;GA3558195&lt;1c&gt;P1&lt;1c&gt;a&lt;1e&gt;A0063&lt;1e&gt;B+00000127098&lt;1e&gt;C0063&lt;1e&gt;D+00000127098&lt;1e&gt;E0000000&lt;1e&gt;F0000000&lt;1e&gt;G1&lt;1e&gt;H0&lt;1e&gt;I001&lt;1c&gt;d1977206 &lt;1c&gt;e00&lt;1c&gt;h0010011150&lt;1c&gt;6&lt;1e&gt;E051&lt;1e&gt;F00&lt;1e&gt;I752&lt;1e&gt;O018075216101245E3F66F8EEF834D3900002D5A7EEAA60000000000007520000000001000110A74003023000000052DA01286A640057&lt;1e&gt;P0100224403020002A0000000043060&lt;1e&gt;TFFFF73891703A60000B2&lt;1e&gt;X000002&lt;1c&gt;9&lt;1e&gt;C05&lt;1e&gt;D591000160140&lt;1e&gt;I5621&lt;1e&gt;PE0F0C8&lt;1e&gt;Q700080B001&lt;1e&gt;R00008&lt;1e&gt;SITFIED KISTA 123 45 SE&lt;1f&gt;2674CC3E2409CAD530E5E64D14C65C1AFDDB1711905FBD4BEDA433A1B20D5A261C5343853B861E7A405C1B90CDA07813&lt;03&gt;l  
SPDH  
Header  
Device Type = "9."  
Transmission Number = "68"  
Terminal Id = "59100016 "  
Employee Id = "31 "  
Current date = "161012"  
Current Time = "123622"  
Message Type = "F"  
Message Subtype = "O"  
Transaction Code = "00"  
Processing Flag 1 = "0"  
Processing Flag 2 = "5"  
Processing Flag 3 = "0"  
Response Code = "000"

B Amount 1 = "00000100"  
D Account Type = "0"  
G MAC //Only if UKPT or Master Session = "A3558195"  
P Draft Capture Flag = "1"  
a User Defined Data  
aA = "0063"  
aB = "+00000127098"  
aC = "0063"  
aD = "+00000127098"  
aE = "0000000"  
aF = "0000000"  
aG = "1"  
aH = "0"  
aI = "001"  
d Retailer ID = "1977206 "  
e Pos condition code = "00"  
h Sequence Number = "0010011150"  
6  
6E Point of Services Entry Mode = "051"  
6F Electronic Commerce Flag = "00"  
6I Transaction Currency Code = "752"  
6O Smart Card Request Data = "018075216101245E3F66F8EEF834D3900002D5A7EEAA60000000000007520000000001000110A74003023000000052DA01286A640057"  
6P Smart Card Additional Request Data = "0100224403020002A0000000043060"  
6T Key serial number (double length key) = "FFFF73891703A60000B2"  
6X Point of Service Data = "000002"  
9  
9C POS Capability Code = "05"  
9D Retrieval Reference Number = "591000160140"  
9I Merchant Category Code = "5621"  
9P EMV Terminal Capability = "E0F0C8"  
9Q = "700080B001"  
9R = "00008"  
9S = "ITFIED KISTA 123 45 SE"  
\* = "2674CC3E2409CAD530E5E64D14C65C1AFDDB1711905FBD4BEDA433A1B20D5A261C5343853B861E7A405C1B90CDA07813"

------------------------------------------------------------

-------------------- Header Log ----------------------------  
501 12:36:29 386 20161012 Proxy &lt;---- HOST 68 Purchase Online 001 = A:Approved Transactions&#91;Approved no balances available&#93;

------------------------------------------------------------

------------------- Expanded Log ---------------------------  
TS=20161012123629386 TXNODE=eIPosTBNode_SPDH_HOST TXNODEINDEX=-1 RXNODE=eIPosTBNode_SPDHProxy RXNODEINDEX=-1 InformationType=General Content=SPDHFrame D=009882392E36B83539B1303030B136A0A0A0A0A0A0A0A033B1A0A0A0A0B136B130B1B2B1B233363330C6CF30303030303030B19CC633B136B739B8A0429C47C6C5C3C5B2B133B19CD19C361EC53035B11EC9B735B21ED130B1303030B4B7B742B1C5B4B1304230C34144393030B1B29C391E41331E443539B1303030B13630B1B4301E6FB2B2B1A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0032B  
--- 12:36:29.386 2016-10-12 ---  
Proxy &lt;== 68 Purchase Online 001 = A:Approved Transactions&#91;Approved no balances available&#93; &lt;== HOST  
Raw :&lt;00&gt;&lt;98&gt;&lt;82&gt;9.6&lt;b8&gt;59&lt;b1&gt;000&lt;b1&gt;6&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;3&lt;b1&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;b1&gt;6&lt;b1&gt;0&lt;b1&gt;&lt;b2&gt;&lt;b1&gt;&lt;b2&gt;3630&lt;c6&gt;&lt;cf&gt;0000000&lt;b1&gt;&lt;9c&gt;&lt;c6&gt;3&lt;b1&gt;6&lt;b7&gt;9&lt;b8&gt;&lt;a0&gt;B&lt;9c&gt;G&lt;c6&gt;&lt;c5&gt;&lt;c3&gt;&lt;c5&gt;&lt;b2&gt;&lt;b1&gt;3&lt;b1&gt;&lt;9c&gt;&lt;d1&gt;&lt;9c&gt;6&lt;1e&gt;&lt;c5&gt;05&lt;b1&gt;&lt;1e&gt;&lt;c9&gt;&lt;b7&gt;5&lt;b2&gt;&lt;1e&gt;&lt;d1&gt;0&lt;b1&gt;000&lt;b4&gt;&lt;b7&gt;&lt;b7&gt;B&lt;b1&gt;&lt;c5&gt;&lt;b4&gt;&lt;b1&gt;0B0&lt;c3&gt;AD900&lt;b1&gt;&lt;b2&gt;&lt;9c&gt;9&lt;1e&gt;A3&lt;1e&gt;D59&lt;b1&gt;000&lt;b1&gt;60&lt;b1&gt;&lt;b4&gt;0&lt;1e&gt;o&lt;b2&gt;&lt;b2&gt;&lt;b1&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;a0&gt;&lt;03&gt;+  
No Parity:&lt;00&gt;&lt;98&gt;&lt;02&gt;9.6859100016 31 161012123630FO00000001&lt;1c&gt;F316798 B&lt;1c&gt;GFECE2131&lt;1c&gt;Q&lt;1c&gt;6&lt;1e&gt;E051&lt;1e&gt;I752&lt;1e&gt;Q01000477B1E410B0CAD90012&lt;1c&gt;9&lt;1e&gt;A3&lt;1e&gt;D591000160140&lt;1e&gt;o221 &lt;03&gt;+  
SPDH  
Header  
Device Type = "9."  
Transmission Number = "68"  
Terminal Id = "59100016 "  
Employee Id = "31 "  
Current date = "161012"  
Current Time = "123630"  
Message Type = "F"  
Message Subtype = "O"  
Transaction Code = "00"  
Processing Flag 1 = "0"  
Processing Flag 2 = "0"  
Processing Flag 3 = "0"  
Response Code = "001"

F Approval Code = "316798 B"  
G MAC //Only if UKPT or Master Session = "FECE2131"  
Q Echo Data = ""  
6  
6E Point of Services Entry Mode = "051"  
6I Transaction Currency Code = "752"  
6Q Smart Card Response Data = "01000477B1E410B0CAD90012"  
9  
9A Authorising Entity = "3"  
9D Retrieval Reference Number = "591000160140"  
9o Download Indicator = "221 "

——————————————————————————————

-------------------- Header Log ----------------------------  
503 12:36:29 487 20161012 Proxy + New MAC = FECE2131

------------------------------------------------------------

------------------- Expanded Log ---------------------------  
TS=20161012123629487 TXNODE=eIPosTBNode_SPDHProxy TXNODEINDEX=-1 InformationType=Warning D=4E6577204D4143203D204645434532313331  
--- 12:36:29.487 2016-10-12 ---  
Proxy New MAC = FECE2131  
New MAC = FECE2131

------------------------------------------------------------

MAC form Host = FECE2131  
Calculated MAC to terminal = FECE2131

{% endraw %}
