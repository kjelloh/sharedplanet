# Todo: Programming - Consider to use this data for iPos BerTlv decoding tests?

```#e2faf6d3``` *As of 2016-09-12 13:28*

[mail plain/text](mail.txt)

{% raw %}
Consider the code below is good starting point to test out encoding of iPos messages in cross platform code (e.g., open_ipos project)?

> // TEST!  
> // static int callCounter = 0; // Enable test code  
> static int callCounter = 1; // disable test code

> if (callCounter++ == 0) {  
> // Do this only the first call!

> // Create a SR_STATUS_CHANGE for test  
> /\*  
> TS=20080128110123191 L=000002514 Fn=ipos_Read RC=0 ID=1 D=FFF10A2DDFF0020165DFF003023936DFF0050D54353330303036393635373336FFD3010DDFD3030131DFD302044F50454E  
> --- 11:01:23.191 2008-01-28 ---  
> iPOS &lt;== ipos_Read OK &lt;== SACI  
> ipos_Read OK  
> --- 11:01:23.191 2008-01-28 ---  
> T ==&gt; 96 SR_STATUS_CHANGE ==&gt; SACI  
> cdoiPOS_SA fff10a(45)  
> pdoType dff002(1) &#91;e&#93;  
> pdoSeqNbr dff003(2) &#91;96&#93;  
> pdoEcho dff005(13) &#91;T530006965736&#93;  
> cdoSR_STATUS_CHANGE ffd301(13)  
> pdoStateChangeIndicator dfd303(1) &#91;1&#93;  
> pdoStateChange dfd302(4) &#91;OPEN&#93;  
> \*/  
> // std::vector&lt;unsigned char&gt; sr_status_change_buf = c_DataRepresentationFramework::parseHexNibblePairString(_Asciisz("FFF10A2DDFF0020165DFF003023936DFF0050D54353330303036393635373336FFD3010DDFD3030131DFD302044F50454E"));  
> // const ipos::BerTlv\* p_sr_status_change = ipos::BerTlvParser::parseBerTlv(sr_status_change_buf);  
> // m_iPosReceivedMessagesQueue.putOneMessageIntoQueue(p_sr_status_change);

> // Assemble an SR_CARD_READ for test  
> /\*  
> TS=20080128110115285 L=000002483 Fn=ipos_Read RC=0 ID=1 D=FFF10A8185DFF0020165DFF003023935DFF0050D54353330303035383543363837FFD10165DFD1020131DFD103023031FFD10F56DFD10E084581091234567772DFD11001FEDFD11101A8DFD1120143DFD11301C0DFD1140100DFC31D03535745DFD10B034D3031DFD104031000FFDFD105030FFFFFDFD106031FFFFFDFD1070399999FDFD10D0399999F  
> --- 11:01:15.285 2008-01-28 ---  
> iPOS &lt;== ipos_Read OK &lt;== SACI  
> ipos_Read OK  
> --- 11:01:15.285 2008-01-28 ---  
> T ==&gt; 95 SR_CARD_READ ==&gt; SACI  
> cdoiPOS_SA fff10a(133)  
> pdoType dff002(1) &#91;e&#93;  
> pdoSeqNbr dff003(2) &#91;95&#93;  
> pdoEcho dff005(13) &#91;T53000585C687&#93;  
> cdoSR_CARD_READ ffd101(101)  
> pdoCardTypeIndikator dfd102(1) &#91;1&#93;  
> pdoCardType dfd103(2) &#91;01&#93;  
> cdoPayment ffd10f(86)  
> pdoPAN dfd10e(8) &#91;0x4581091234567772&#93;  
> pdoBitfields_1 dfd110(1) &#91;0xfe&#93;  
> pdoBitfields_2 dfd111(1) &#91;0xa8&#93;  
> pdoBitfields_3 dfd112(1) &#91;0x43&#93;  
> pdoBitfields_4 dfd113(1) &#91;0xc0&#93;  
> pdoBitfields_5 dfd114(1) &#91;0x00&#93;  
> pdoFinancialInstitution dfc31d(3) &#91;SWE&#93;  
> pdoCardHolderName dfd10b(3) &#91;M01&#93;  
> pdoMaxCashBackAmount dfd104(3) &#91;0x1000ff&#93;  
> pdoWithdrawalAmount dfd105(3) &#91;|0x0f||0xff||0xff|&#93;  
> pdoMinPurchaseAmount dfd106(3) &#91;0x1fffff&#93;  
> pdoMaxPurchaseAmount dfd107(3) &#91;0x99999f&#93;  
> pdoMaxRefundAmount dfd10d(3) &#91;0x99999f&#93;  
> \*/  
> // std::vector&lt;unsigned char&gt; sr_card_read_buf = c_DataRepresentationFramework::parseHexNibblePairString("FFF10A8185DFF0020165DFF003023935DFF0050D54353330303035383543363837FFD10165DFD1020131DFD103023031FFD10F56DFD10E084581091234567772DFD11001FEDFD11101A8DFD1120143DFD11301C0DFD1140100DFC31D03535745DFD10B034D3031DFD104031000FFDFD105030FFFFFDFD106031FFFFFDFD1070399999FDFD10D0399999F");  
> // const ipos::BerTlv\* p_sr_card_read_buf = ipos::BerTlvParser::parseBerTlv(sr_card_read_buf);  
> // m_iPosReceivedMessagesQueue.putOneMessageIntoQueue(p_sr_card_read_buf);

> // Create an SR_SEND_HOST PPL for test  
> /\*  
> TS=20080215100807140 L=000000014 Fn=ipos_Read RC=0 ID=1 D=FFF10A8186DFF0020163DFF0030132DFF0050D49353330303032383035343633FFC90167FF820220DF8203083035303030303031DF8204103139322E3136382E302E3139323A3231FFC90A3FDFC90B083035303030303031DFC90C00DFC90D083035303030303031DF811413633A5C7A6163695C74726D5F315C315C444C5CDFC90E083035303030303031  
> --- 10:08:07.140 2008-02-15 ---  
> iPOS &lt;== ipos_Read OK &lt;== SACI  
> ipos_Read OK  
> --- 10:08:07.140 2008-02-15 ---  
> T ==&gt; 2 SR_SEND_HOST ==&gt; SACI  
> cdoiPOS_SA fff10a(134)  
> pdoType dff002(1) &#91;c&#93;  
> pdoSeqNbr dff003(1) &#91;2&#93;  
> pdoEcho dff005(13) &#91;I530002805463&#93;  
> cdoSR_SEND_HOST ffc901(103)  
> cdoiPOSTsp ff8202(32)  
> pdoTSPId df8203(8) &#91;05000001&#93;  
> pdoTSPAddr df8204(16) &#91;192.168.0.192:21&#93;  
> cdoFileTSP ffc90a(63)  
> xxxN/A dfc90b(8) &#91;05000001&#93;  
> xxxN/A dfc90c(0) &#91;&#93;  
> xxxN/A dfc90d(8) &#91;05000001&#93;  
> pdoTermPath df8114(19) &#91;c:\\zaci\\trm_1\\1\\DL\\&#93;  
> xxxN/A dfc90e(8) &#91;05000001&#93;  
> \*/  
> // std::vector&lt;unsigned char&gt; sr_send_host_ppl_buf = c_DataRepresentationFramework::parseHexNibblePairString("FFF10A8186DFF0020163DFF0030132DFF0050D49353330303032383035343633FFC90167FF820220DF8203083035303030303031DF8204103139322E3136382E302E3139323A3231FFC90A3FDFC90B083035303030303031DFC90C00DFC90D083035303030303031DF811413633A5C7A6163695C74726D5F315C315C444C5CDFC90E083035303030303031");  
> // const ipos::BerTlv\* p_sr_send_host_ppl = ipos::BerTlvParser::parseBerTlv(sr_send_host_ppl_buf);  
> // m_iPosReceivedMessagesQueue.putOneMessageIntoQueue(p_sr_send_host_ppl);

> // Create a SR_SEND_HOST SPDH for test  
> /\*  
> TS=20070611153627593 L=000000365 Fn=ipos_Read RC=0 ID=1 D=FFF10A8201D3DFF0020163DFF003023130FFC9018201C2FFC70228DFC706103139322E3136382E302E373A38303035DFC707103139322E3136382E302E373A38303035DFC70801FFDFC90282018B392E303330323030303030332020202020202020202020202020303730363131313533343533464F30303035303030301C423030303030303030303030303030313130301C44311C50301C611E41303030301E422B30303030303030303030301E43303030301E442B30303030303030303030301E453237351E46301E48311E49311C6530301C68303031303031303235301C713B343538313039313233343536373737323D30383132313031313239353631313F1C361E453930311E493735321C391E4846464646373330393137303346453030303644441E4334351E443939393230303035303032341E49343731321E4E42494E5041525F5F30373034323031313236303744435041525F5F5F3037303631313131313035344D41535041525F5F30373032323231303337303944434150505F5F5F3037303630383135303433344750415F5F5F5F5F30373036303831353034333449504F53434F4E463037303532393137343332301C62373342304242344230374339413933371C6630341C473941453338333332  
> --- 15:36:27.593 2007-06-11 ---  
> iPOS &lt;== ipos_Read OK &lt;== SACI  
> ipos_Read OK  
> --- 15:36:27.593 2007-06-11 ---  
> T ==&gt; 10 SR_SEND_HOST ==&gt; SACI  
> cdoIPOS_SA fff10a(467)  
> pdoType dff002(1) &#91;c&#93;  
> pdoSeqNbr dff003(2) &#91;10&#93;  
> cdoSR_SEND_HOST ffc901(450)  
> cdoHostAddr ffc702(40)  
> pdoPrimIPAdr dfc706(16) &#91;192.168.0.7:8005&#93;  
> pdoSecondIPAdr dfc707(16) &#91;192.168.0.7:8005&#93;  
> pdoExpectResponse dfc708(1) &#91;|0xff|&#93;  
> pdoSPDH dfc902(395) &#91;9.0302000003 070611153453FO00050000|0x1c|B000000000000001100|0x1c|D1|0x1c|P0|0x1c|a|0x1e|A0000|0x1e|B+00000000000|0x1e|C0000|0x1e|D+00000000000|0x1e|E275|0x1e|F0|0x1e|H1|0x1e|I1|0x1c|e00|0x1c|h0010010250|0x1c|q;4581091234567772=08121011295611?|0x1c|6|0x1e|E901|0x1e|I752|0x1c|9|0x1e|HFFFF73091703FE0006DD|0x1e|C45|0x1e|D999200050024|0x1e|I4712|0x1e|NBINPAR__070420112607DCPAR___070611111054MASPAR__070222103709DCAPP___070608150434GPA_____070608150434IPOSCONF070529174320|0x1c|b73B0BB4B07C9A937|0x1c|f04|0x1c|G9AE38332&#93;

> === TestBench expanded SPDH message ===  
> SPDH  
> Header  
> Device Type: 9.  
> Transmission Number:03  
> Terminal Id: 02000003  
> Employee Id:  
> Current date: 070611  
> Current Time: 153453  
> Message Type: F  
> Message Subtype: O  
> Transaction Code: 00  
> Processing Flag 1: 0  
> Processing Flag 2: 5  
> Processing Flag 3: 0  
> Response Code: 000

> B Amount 1 &#91;000000000000001100&#93;  
> D Account Type &#91;1&#93;  
> P Draft Capture Flag &#91;0&#93;  
> a User Defined Data  
> aA &#91;0000&#93;  
> aB &#91;+00000000000&#93;  
> aC &#91;0000&#93;  
> aD &#91;+00000000000&#93;  
> aE &#91;275&#93;  
> aF &#91;0&#93;  
> aH &#91;1&#93;  
> aI &#91;1&#93;  
> e Pos condition code &#91;00&#93;  
> h Sequence Number &#91;0010010250&#93;  
> q Track2 &#91;;4581091234567772=08121011295611?&#93;  
> 6  
> 6E Point of Services Entry Mode &#91;901&#93;  
> 6I Transaction Currency Code &#91;752&#93;  
> 9  
> 9H Key Serial Number KSN (single length key) &#91;FFFF73091703FE0006DD&#93;  
> 9C POS Capability Code &#91;45&#93;  
> 9D Retrieval Reference Number &#91;999200050024&#93;  
> 9I Merchant Category Code &#91;4712&#93;  
> 9N Update Information &#91;BINPAR__070420112607DCPAR___070611111054MASPAR__070222103709DCAPP___070608150434GPA_____070608150434IPOSCONF070529174320&#93;  
> b PIN Block //Only for UKPT transactions &#91;73B0BB4B07C9A937&#93;  
> f PIN length //Only for UKPT transactions &#91;04&#93;  
> G MAC //Only if UKPT or Master Session &#91;9AE38332&#93;

> \*/  
> // std::vector&lt;unsigned char&gt; sr_send_host_spdh = c_DataRepresentationFramework::parseHexNibblePairString("FFF10A8201D3DFF0020163DFF003023130FFC9018201C2FFC70228DFC706103139322E3136382E302E373A38303035DFC707103139322E3136382E302E373A38303035DFC70801FFDFC90282018B392E303330323030303030332020202020202020202020202020303730363131313533343533464F30303035303030301C423030303030303030303030303030313130301C44311C50301C611E41303030301E422B30303030303030303030301E43303030301E442B30303030303030303030301E453237351E46301E48311E49311C6530301C68303031303031303235301C713B343538313039313233343536373737323D30383132313031313239353631313F1C361E453930311E493735321C391E4846464646373330393137303346453030303644441E4334351E443939393230303035303032341E49343731321E4E42494E5041525F5F30373034323031313236303744435041525F5F5F3037303631313131313035344D41535041525F5F30373032323231303337303944434150505F5F5F3037303630383135303433344750415F5F5F5F5F30373036303831353034333449504F53434F4E463037303532393137343332301C62373342304242344230374339413933371C6630341C473941453338333332");  
> // const ipos::BerTlv\* p_sr_send_host_spdh = ipos::BerTlvParser::parseBerTlv(sr_send_host_spdh);  
> // m_iPosReceivedMessagesQueue.putOneMessageIntoQueue(p_sr_send_host_spdh);

> // Create a DI_INFO from logged data  
> /\*  
> TS=20081024110723121 L=000000083 Fn=ipos_Read RC=0 ID=1 D=FFF10A81C6DFF0020167DFF003023133FFE10181B6FFE10258DFC10203323538DFE1030100FFB60222DFB6030131DFE10419506172616D657465726C6164646E696E672020202020202020FFB60222DFB6030132DFE1041970E567E5722E2E2E2020202020202020202020202020202020FFE10256DFC1020130DFE1030100FFB60222DFB6030133DFE1041920202020202020202020202020202020202020202020202020FFB60222DFB6030134DFE104195B5C5D20444350415220202020202020202020202020202020  
> --- 11:07:23.121 2008-10-24 ---  
> iPOS &lt;== ipos_Read OK &lt;== SACI  
> ipos_Read OK  
> --- 11:07:23.121 2008-10-24 ---  
> T ==&gt; 13 DI_INFO TextId=258 &#91;1&#93; "Parameterladdning" &#91;2&#93; "pågår..." TextId=0 &#91;3&#93; " " &#91;4&#93; "&#91;\\&#93; DCPAR" ==&gt; SACI  
> cdoiPOS_SA fff10a(198)  
> pdoType dff002(1) "g"  
> pdoSeqNbr dff003(2) "13"  
> cdoDI_INFO ffe101(182)  
> cdoDIMessage ffe102(88)  
> pdoTextId dfc102(3) "258"  
> pdoDIForce dfe103(1) "&lt;0x00&gt;"  
> cdoDsp ffb602(34)  
> pdoDspRow dfb603(1) "1"  
> pdoDIDspText dfe104(25) "Parameterladdning "  
> cdoDsp ffb602(34)  
> pdoDspRow dfb603(1) "2"  
> pdoDIDspText dfe104(25) "pågår... "  
> cdoDIMessage ffe102(86)  
> pdoTextId dfc102(1) "0"  
> pdoDIForce dfe103(1) "&lt;0x00&gt;"  
> cdoDsp ffb602(34)  
> pdoDspRow dfb603(1) "3"  
> pdoDIDspText dfe104(25) " "  
> cdoDsp ffb602(34)  
> pdoDspRow dfb603(1) "4"  
> pdoDIDspText dfe104(25) "&#91;\\&#93; DCPAR "  
> \*/  
> // std::vector&lt;unsigned char&gt; di_info_buf = c_DataRepresentationFramework::parseHexNibblePairString("FFF10A81C6DFF0020167DFF003023133FFE10181B6FFE10258DFC10203323538DFE1030100FFB60222DFB6030131DFE10419506172616D657465726C6164646E696E672020202020202020FFB60222DFB6030132DFE1041970E567E5722E2E2E2020202020202020202020202020202020FFE10256DFC1020130DFE1030100FFB60222DFB6030133DFE1041920202020202020202020202020202020202020202020202020FFB60222DFB6030134DFE104195B5C5D20444350415220202020202020202020202020202020");  
> // const ipos::BerTlv\* p_di_info_buf = ipos::BerTlvParser::parseBerTlv(di_info_buf);  
> // m_iPosReceivedMessagesQueue.putOneMessageIntoQueue(p_di_info_buf);

> /\*  
> TS=20070115144304104 L=000000223 Fn=ipos_Read RC=0 ID=1 D=FFF10A81EADFF0020167DFF003023430FFE10181DAFFE10232DFC10203323831DFE10301FFFFB60222DFB6030131DFE1041956E46E6C6967656E2076E46C6A3A2020202020202020202020FFE1027CDFC1020130DFE10301FFFFB60222DFB6030132DFE104193129204B6F6E746F2020202020202020202020202020202020FFB60222DFB6030133DFE104193229204B726564697420202020202020202020202020202020FFB60222DFB6030134DFE104193E202020202020202020202020202020202020202020202020FFB60D20DFB60803312C32DFB60A0133DFB6090134DFB60B023939DFB60C0545422C4E4F  
> T ==&gt; iPOS Msg ==&gt; SACI  
> cdoIPOS_SA fff10a(234)  
> pdoType dff002(1) &#91;g&#93;  
> pdoSeqNbr dff003(2) &#91;40&#93;  
> cdoDI_INFO ffe101(218)  
> cdoDIMessage ffe102(50)  
> pdoTextId dfc102(3) &#91;281&#93;  
> pdoDIForce dfe103(1) &#91;|0xff|&#93;  
> cdoDsp ffb602(34)  
> pdoDspRow dfb603(1) &#91;1&#93;  
> pdoDIDspText dfe104(25) &#91;Vänligen välj: &#93;  
> cdoDIMessage ffe102(124)  
> pdoTextId dfc102(1) &#91;0&#93;  
> pdoDIForce dfe103(1) &#91;|0xff|&#93;  
> cdoDsp ffb602(34)  
> pdoDspRow dfb603(1) &#91;2&#93;  
> pdoDIDspText dfe104(25) &#91;1) Konto &#93;  
> cdoDsp ffb602(34)  
> pdoDspRow dfb603(1) &#91;3&#93;  
> pdoDIDspText dfe104(25) &#91;2) Kredit &#93;  
> cdoDsp ffb602(34)  
> pdoDspRow dfb603(1) &#91;4&#93;  
> pdoDIDspText dfe104(25) &#91;&gt; &#93;  
> cdoKbd ffb60d(32)  
> pdoKbdKey dfb608(3) &#91;1,2&#93;  
> pdoKbdPos dfb60a(1) &#91;3&#93;  
> pdoKbdRow dfb609(1) &#91;4&#93;  
> pdoKbdInMax dfb60b(2) &#91;99&#93;  
> pdoKbdEndFnc dfb60c(5) &#91;EB,NO&#93;  
> \*/

> // std::vector&lt;unsigned char&gt; di_info_buf2 = c_DataRepresentationFramework::parseHexNibblePairString("FFF10A81EADFF0020167DFF003023430FFE10181DAFFE10232DFC10203323831DFE10301FFFFB60222DFB6030131DFE1041956E46E6C6967656E2076E46C6A3A2020202020202020202020FFE1027CDFC1020130DFE10301FFFFB60222DFB6030132DFE104193129204B6F6E746F2020202020202020202020202020202020FFB60222DFB6030133DFE104193229204B726564697420202020202020202020202020202020FFB60222DFB6030134DFE104193E202020202020202020202020202020202020202020202020FFB60D20DFB60803312C32DFB60A0133DFB6090134DFB60B023939DFB60C0545422C4E4F");  
> // const ipos::BerTlv\* p_di_info_buf2 = ipos::BerTlvParser::parseBerTlv(di_info_buf2);  
> // m_iPosReceivedMessagesQueue.putOneMessageIntoQueue(p_di_info_buf2);

> /\*  
> TS=20070115144313728 L=000000226 Fn=ipos_Read RC=0 ID=1 D=FFF10A81CEDFF0020167DFF003023431FFE10181BEFFE10256DFC1020132DFE1030100FFB60222DFB6030131DFE1041956E46E7461722070E520202020202020202020202020202020FFB60222DFB6030132DFE104196B6F72746B6F6E74726F6C6C20202020202020202020202020FFE10256DFC1020130DFE1030100FFB60222DFB6030133DFE1041920202020202020202020202020202020202020202020202020FFB60222DFB6030134DFE1041920202020202020202020202020202020202020202020202020FFB60D06DFB60C025042  
> T ==&gt; iPOS Msg ==&gt; SACI  
> cdoIPOS_SA fff10a(206)  
> pdoType dff002(1) &#91;g&#93;  
> pdoSeqNbr dff003(2) &#91;41&#93;  
> cdoDI_INFO ffe101(190)  
> cdoDIMessage ffe102(86)  
> pdoTextId dfc102(1) &#91;2&#93;  
> pdoDIForce dfe103(1) &#91;|0x00|&#93;  
> cdoDsp ffb602(34)  
> pdoDspRow dfb603(1) &#91;1&#93;  
> pdoDIDspText dfe104(25) &#91;Väntar på &#93;  
> cdoDsp ffb602(34)  
> pdoDspRow dfb603(1) &#91;2&#93;  
> pdoDIDspText dfe104(25) &#91;kortkontroll &#93;  
> cdoDIMessage ffe102(86)  
> pdoTextId dfc102(1) &#91;0&#93;  
> pdoDIForce dfe103(1) &#91;|0x00|&#93;  
> cdoDsp ffb602(34)  
> pdoDspRow dfb603(1) &#91;3&#93;  
> pdoDIDspText dfe104(25) &#91; &#93;  
> cdoDsp ffb602(34)  
> pdoDspRow dfb603(1) &#91;4&#93;  
> pdoDIDspText dfe104(25) &#91; &#93;  
> cdoKbd ffb60d(6)  
> pdoKbdEndFnc dfb60c(2) &#91;PB&#93;  
> \*/  
> // std::vector&lt;unsigned char&gt; di_info_buf3 = c_DataRepresentationFramework::parseHexNibblePairString("FFF10A81CEDFF0020167DFF003023431FFE10181BEFFE10256DFC1020132DFE1030100FFB60222DFB6030131DFE1041956E46E7461722070E520202020202020202020202020202020FFB60222DFB6030132DFE104196B6F72746B6F6E74726F6C6C20202020202020202020202020FFE10256DFC1020130DFE1030100FFB60222DFB6030133DFE1041920202020202020202020202020202020202020202020202020FFB60222DFB6030134DFE1041920202020202020202020202020202020202020202020202020FFB60D06DFB60C025042");  
> // const ipos::BerTlv\* p_di_info_buf3 = ipos::BerTlvParser::parseBerTlv(di_info_buf3);  
> // m_iPosReceivedMessagesQueue.putOneMessageIntoQueue(p_di_info_buf3);

> /\*  
> TS=20080319165901765 L=000000070 Fn=ipos_Read RC=0 ID=1 D=FFF10A8187DFF0020163DFF003023130DFF0050D49353330303130364345443836FFC90167FF820220DF8203083035303030303031DF8204103139322E3136382E302E3139323A3231FFC90A3FDFC90B083035303030303031DFC90C00DFC90D083035303030303031DF811413633A5C7A6163695C74726D5F315C315C444C5CDFC90E083035303030303031  
> --- 16:59:01.765 2008-03-19 ---  
> iPOS &lt;== ipos_Read OK &lt;== SACI  
> ipos_Read OK  
> --- 16:59:01.765 2008-03-19 ---  
> T ==&gt; 10 SR_SEND_HOST ==&gt; SACI  
> cdoiPOS_SA fff10a(135)  
> pdoType dff002(1) &#91;c&#93;  
> pdoSeqNbr dff003(2) &#91;10&#93;  
> pdoEcho dff005(13) &#91;I5300106CED86&#93;  
> cdoSR_SEND_HOST ffc901(103)  
> cdoiPOSTsp ff8202(32)  
> pdoTSPId df8203(8) &#91;05000001&#93;  
> pdoTSPAddr df8204(16) &#91;192.168.0.192:21&#93;  
> cdoFileTSP ffc90a(63)  
> pdoUserId dfc90b(8) &#91;05000001&#93;  
> pdoPassword dfc90c(0) &#91;&#93;  
> pdoFileNameTSP dfc90d(8) &#91;05000001&#93;  
> pdoTermPath df8114(19) &#91;c:\\zaci\\trm_1\\1\\DL\\&#93;  
> pdoFileNameLocal dfc90e(8) &#91;05000001&#93;

> \*/  
> // std::vector&lt;unsigned char&gt; sr_send_host_buf = c_DataRepresentationFramework::parseHexNibblePairString("FFF10A8187DFF0020163DFF003023130DFF0050D49353330303130364345443836FFC90167FF820220DF8203083035303030303031DF8204103139322E3136382E302E3139323A3231FFC90A3FDFC90B083035303030303031DFC90C00DFC90D083035303030303031DF811413633A5C7A6163695C74726D5F315C315C444C5CDFC90E083035303030303031");  
> // const ipos::BerTlv\* p_sr_send_host = ipos::BerTlvParser::parseBerTlv(sr_send_host_buf);  
> // m_iPosReceivedMessagesQueue.putOneMessageIntoQueue(p_sr_send_host);

> /\*  
> TS=20080430144402899 L=000000061 Fn=ipos_Read RC=0 ID=1 D=FFF10A82025BDFF0020163DFF0030135DFF0050D54353330303035363541363833FFC30182023AFFC30281FEDFC303023030DFC32106650572FFFFFFDFC31C0D5377656462616E6B2042414253DFC31E1056697361202020202020202020202020DFAF11083030303032333030DFC305083030303030303030DFC306083030303030303030DFC32206303830343330DFC32306313434333534DFC3280B3132333435362D37383930DFC309023030DFD10E084581091234567772DFC30A0430383038DFC30B0131DFC31803373532DFC30C0141DFC30D0144DFC3190C303034333938323330313838DFC30F0131DFC31003303030DFC329083536373737322020DFC31A1030353030303030312020202020202020DFC3200130DFC31D03535745DF940306303030303031FFC311820131DFC303023030DFC32106650572FFFFFFDFC309023030DFC3251A3B343538313039313233343536373737323D303830383130313FDFC30B0131DFC31003303030DFAF11083030303032333030DFC305083030303030303030DFC306083030303030303030DFC32206303830343330DFC32306313434333534DFC3150131DFC316023930DF92020435353432DFC31803373532DFC30C0141DFC3190C303034333938323330313838DFC329083536373737322020DFC31A1030353030303030312020202020202020DFC3200130DFC32A03E0F0D0DF8206023130DF92030131DFC31D03535745DF940306303030303031DFC31C0D5377656462616E6B2042414253DFC31E1056697361202020202020202020202020DFC30C0141DFC30D0144DFC30F01319FFF7F0A30303130303134383630  
> --- 14:44:02.899 2008-04-30 ---  
> iPOS &lt;== ipos_Read OK &lt;== SACI  
> ipos_Read OK  
> --- 14:44:02.899 2008-04-30 ---  
> T ==&gt; 5 SR_RECEIVE_DATA Solicited ==&gt; SACI  
> cdoiPOS_SA fff10a(603)  
> pdoType dff002(1) "c"  
> pdoSeqNbr dff003(1) "5"  
> pdoEcho dff005(13) "T53000565A683"  
> cdoSR_RECEIVE_DATA ffc301(570)  
> cdoReceiptData ffc302(254)  
> pdoDebitStatus dfc303(2) "00"  
> pdoAcqRefNbr dfc321(6) "0x650572FFFFFF"  
> pdoBankAgentName dfc31c(13) "Swedbank BABS"  
> pdoCardProductName dfc31e(16) "Visa "  
> pdoTransactionAmount dfaf11(8) "00002300"  
> pdoTransactionVAT dfc305(8) "00000000"  
> pdoCashBackAmount dfc306(8) "00000000"  
> pdoTransactionDate dfc322(6) "080430"  
> pdoTransactionTime dfc323(6) "144354"  
> pdoOrganisationNbr dfc328(11) "123456-7890"  
> pdoTransactionCode dfc309(2) "00"  
> pdoPAN dfd10e(8) "0x4581091234567772"  
> pdoExpirationDate dfc30a(4) "0808"  
> pdoAccountType dfc30b(1) "1"  
> pdoTransCurrencyCode dfc318(3) "752"  
> pdoIDMethod dfc30c(1) "A"  
> pdoPOSEntryMode dfc30d(1) "D"  
> pdoRetrievalReferenceNumber dfc319(12) "004398230188"  
> pdoAuthorisationMethod dfc30f(1) "1"  
> pdoAuthorisationResponseCode dfc310(3) "000"  
> pdoAuthorisationCode dfc329(8) "567772 "  
> pdoTerminalIdentifier dfc31a(16) "05000001 "  
> pdoAuthorisingEntity dfc320(1) "0"  
> pdoFinancialInstitution dfc31d(3) "SWE"  
> pdoOpenTransactionNumber df9403(6) "000001"  
> cdoLogData ffc311(305)  
> pdoDebitStatus dfc303(2) "00"  
> pdoAcqRefNbr dfc321(6) "0x650572FFFFFF"  
> pdoTransactionCode dfc309(2) "00"  
> pdoTrack2Part dfc325(26) ";4581091234567772=0808101?"  
> pdoAccountType dfc30b(1) "1"  
> pdoAuthorisationResponseCode dfc310(3) "000"  
> pdoTransactionAmount dfaf11(8) "00002300"  
> pdoTransactionVAT dfc305(8) "00000000"  
> pdoCashBackAmount dfc306(8) "00000000"  
> pdoTransactionDate dfc322(6) "080430"  
> pdoTransactionTime dfc323(6) "144354"  
> pdoTerminalCapability dfc315(1) "1"  
> pdoCardInput dfc316(2) "90"  
> pdoMerchantCategoryCode df9202(4) "5542"  
> pdoTransCurrencyCode dfc318(3) "752"  
> pdoIDMethod dfc30c(1) "A"  
> pdoRetrievalReferenceNumber dfc319(12) "004398230188"  
> pdoAuthorisationCode dfc329(8) "567772 "  
> pdoTerminalIdentifier dfc31a(16) "05000001 "  
> pdoAuthorisingEntity dfc320(1) "0"  
> pdoTermCapabilities dfc32a(3) "0xE0F0D0"  
> pdoSettId df8206(2) "10"  
> pdoCashierId df9203(1) "1"  
> pdoFinancialInstitution dfc31d(3) "SWE"  
> pdoOpenTransactionNumber df9403(6) "000001"  
> pdoBankAgentName dfc31c(13) "Swedbank BABS"  
> pdoCardProductName dfc31e(16) "Visa "  
> pdoIDMethod dfc30c(1) "A"  
> pdoPOSEntryMode dfc30d(1) "D"  
> pdoAuthorisationMethod dfc30f(1) "1"  
> xxxN/A 9fff7f(10) "0010014860"

> \*/  
> // std::vector&lt;unsigned char&gt; sr_receive_data_buf = c_DataRepresentationFramework::parseHexNibblePairString("FFF10A82025BDFF0020163DFF0030135DFF0050D54353330303035363541363833FFC30182023AFFC30281FEDFC303023030DFC32106650572FFFFFFDFC31C0D5377656462616E6B2042414253DFC31E1056697361202020202020202020202020DFAF11083030303032333030DFC305083030303030303030DFC306083030303030303030DFC32206303830343330DFC32306313434333534DFC3280B3132333435362D37383930DFC309023030DFD10E084581091234567772DFC30A0430383038DFC30B0131DFC31803373532DFC30C0141DFC30D0144DFC3190C303034333938323330313838DFC30F0131DFC31003303030DFC329083536373737322020DFC31A1030353030303030312020202020202020DFC3200130DFC31D03535745DF940306303030303031FFC311820131DFC303023030DFC32106650572FFFFFFDFC309023030DFC3251A3B343538313039313233343536373737323D303830383130313FDFC30B0131DFC31003303030DFAF11083030303032333030DFC305083030303030303030DFC306083030303030303030DFC32206303830343330DFC32306313434333534DFC3150131DFC316023930DF92020435353432DFC31803373532DFC30C0141DFC3190C303034333938323330313838DFC329083536373737322020DFC31A1030353030303030312020202020202020DFC3200130DFC32A03E0F0D0DF8206023130DF92030131DFC31D03535745DF940306303030303031DFC31C0D5377656462616E6B2042414253DFC31E1056697361202020202020202020202020DFC30C0141DFC30D0144DFC30F01319FFF7F0A30303130303134383630");  
> // const ipos::BerTlv\* p_sr_receive_data = ipos::BerTlvParser::parseBerTlv(sr_receive_data_buf);  
> // m_iPosReceivedMessagesQueue.putOneMessageIntoQueue(p_sr_receive_data);

> /\*  
> TS=20080415091534109 L=000000037 Fn=ipos_Read RC=0 ID=1 D=FFF10A22DFF0020162DFF0030135DFF004024F4BFFB6010EDFB2080431323334DFB202024542  
> --- 09:15:34.109 2008-04-15 ---  
> iPOS &lt;== ipos_Read OK &lt;== SACI  
> ipos_Read OK  
> --- 09:15:34.109 2008-04-15 ---  
> T ==&gt; 5 OP_TERMINAL_DIALOG OK ==&gt; SACI  
> cdoiPOS_SA fff10a(34)  
> pdoType dff002(1) "b"  
> pdoSeqNbr dff003(1) "5"  
> pdoResult dff004(2) "OK"  
> cdoOP_TERMINAL_DIALOG ffb601(14)  
> pdoKbdKeyVal dfb208(4) "1234"  
> pdoKbdEndFncSel dfb202(2) "EB"  
> \*/  
> // std::vector&lt;unsigned char&gt; op_terminal_dialog_buf = c_DataRepresentationFramework::parseHexNibblePairString("FFF10A22DFF0020162DFF0030135DFF004024F4BFFB6010EDFB2080431323334DFB202024542");  
> // const ipos::BerTlv\* p_op_terminal_dialog = ipos::BerTlvParser::parseBerTlv(op_terminal_dialog_buf);  
> // m_iPosReceivedMessagesQueue.putOneMessageIntoQueue(p_op_terminal_dialog);

> // Test test event report engine  
> // c_TestBenchRunTimeEnvironment::instance()-&gt;getDeviationReportEngineIfc()-&gt;reportTestEvent(new rdd::c_TestEvent("ipos.ReceivedSolicitedOutsideCommandSession"));  
> // c_TestBenchRunTimeEnvironment::instance()-&gt;getDeviationReportEngineIfc()-&gt;reportTestEvent(new rdd::c_TestEvent("ipos.ReceivedSolicitedOutsideCommandSession"));  
> // c_TestBenchRunTimeEnvironment::instance()-&gt;getDeviationReportEngineIfc()-&gt;reportTestEvent(new rdd::c_TestEvent("ipos.ReceivedSolicitedOutsideCommandSession"));  
> // c_TestBenchRunTimeEnvironment::instance()-&gt;getDeviationReportEngineIfc()-&gt;reportTestEvent(new rdd::c_TestEvent("ipos.ReceivedSolicitedOutsideCommandSession"));  
> // c_TestBenchRunTimeEnvironment::instance()-&gt;getDeviationReportEngineIfc()-&gt;reportTestEvent(new rdd::c_TestEvent("ipos.ReceivedSolicitedOutsideCommandSession"));  
> // c_TestBenchRunTimeEnvironment::instance()-&gt;getDeviationReportEngineIfc()-&gt;reportTestEvent(new rdd::c_TestEvent("ipos.ReceivedSolicitedOutsideCommandSession"));

> // if (this-&gt;getiPosApiHandler()-&gt;apiHasFunction("ipos_Read")) {  
> // LOG_DEVELOPMENT_TRACE(" \*\*\*\*\*\*\*\* API Has function ipos_Read \*\*\*\*\*\*\*\*\*\*\*");  
> // }  
> // else {  
> // LOG_DEVELOPMENT_TRACE(" ????????? API Has NOT function ipos_Read ?????????");  
> // }  
> //  
> // //  
> // if (this-&gt;getiPosApiHandler()-&gt;apiHasFunction("ipos_Conf")) {  
> // LOG_DEVELOPMENT_TRACE(" \*\*\*\*\*\*\*\* API Has function ipos_Conf \*\*\*\*\*\*\*\*\*\*\*");  
> // }  
> // else {  
> // LOG_DEVELOPMENT_TRACE(" ????????? API Has NOT function ipos_Conf ?????????");  
> // }

> }  
> // END OF TEST - REMOVE WHEN NOT NEEDED!! 080211/KoH

> int maxNoOfMessagesToProcess = 0;  
> // while (m_iPosReceivedMessagesQueue.thereIsAtLeastOneMessageInQueue()) {  
> while (c_iPosReceivedMessagesQueueSingleton::instance()-&gt;thereIsAtLeastOneMessageInQueue()) {  
> // const ipos::BerTlv\* pBerTlv = m_iPosReceivedMessagesQueue.getOneMessageFromQueue();  
> const ipos::BerTlv\* pBerTlv = c_iPosReceivedMessagesQueueSingleton::instance()-&gt;getOneMessageFromQueue();  
> if (pBerTlv != NULL) {

> c_DataRepresentationFramework::c_ISO_8859_1_String spdoResult;  
> c_DataRepresentationFramework::c_ISO_8859_1_String spdoType;

> oipos::c_DefinitionTagPath message_definition_tag_path(pBerTlv-&gt;getTagValue());  
> ipos::BerTlv\* cdoMessage = NULL; // WIll be set below

> // Determine the message = the tag name of first cdo in message  
> // and assemble a tag path that identifies the message to produce an  
> // internal event about the message  
> const ipos::BerTlvContentItemIfc\* const contents = pBerTlv-&gt;getContent();  
> if (contents-&gt;isComposite()) {  
> // Cast to composite and iterate to first sub-container  
> // which should be the ipos message container  
> const ipos::BerTlvCompositeContent\* composite = dynamic_cast&lt;const ipos::BerTlvCompositeContent\*&gt;(contents);  
> std::vector&lt; const ipos::BerTlv\* &gt;::const_iterator iter = composite-&gt;iterator_begin();  
> while (iter != composite-&gt;iterator_end()) {  
> // Get the result value  
> if ((\*iter)-&gt;getTagValue() == ipos::pdoResult) {  
> spdoResult = ipos::iPosHelperMethods::anToString((\*iter)-&gt;getContent()-&gt;byteVector());  
> }  
> // Get the message type value  
> else if ((\*iter)-&gt;getTagValue() == ipos::pdoType) {  
> spdoType = ipos::iPosHelperMethods::anToString((\*iter)-&gt;getContent()-&gt;byteVector());  
> }  
> else if ((\*iter)-&gt;getContent()-&gt;isComposite()) {  
> // Add message container tag value to message container path  
> message_definition_tag_path.push_back((\*iter)-&gt;getTagValue());  
> cdoMessage = const_cast&lt;ipos::BerTlv\*&gt;(\*iter); // Get hold of message part  
> }

> iter++;  
> }

> // TEST 120109/KoH. Put an SR_MESSAGE on the input queue if we have received an SR_SEND_HOST  
> // This will test that we are able to disregard the received SR_MESSAGE when later sending the SR_SEND_HOST response!  
> /\*  
> TS=20120109204524984 L=000000010 Fn=ipos_Read RC=0 ID=1 D=FFF10A41DFF0020163DFF0030132DFF0050D58333033303330333041394236FFC10122DFC10203313130DFC10317554E41424C4520544F204F50454E20434F4D20504F5254  
> --- 20:45:24.984 2012-01-09 ---  
> iPOS &lt;== ipos_Read OK &lt;== SACI  
> ipos_Read OK  
> --- 20:45:24.984 2012-01-09 ---  
> T ==&gt; 2 SR_MESSAGE Solicited TextId=110 "UNABLE TO OPEN COM PORT " ==&gt; SACI  
> cdoiPOS_SA fff10a(65)  
> pdoType dff002(1) "c"  
> pdoSeqNbr dff003(1) "2"  
> pdoEcho dff005(13) "X30303030A9B6"  
> cdoSR_MESSAGE ffc101(34)  
> pdoTextId dfc102(3) "110"  
> pdoIposErrorText dfc103(23) "UNABLE TO OPEN COM PORT"  
> \*/  
> //if (message_definition_tag_path.back() == ipos::cdoSR_SEND_HOST) {  
> // std::vector&lt;unsigned char&gt; op_terminal_dialog_buf = c_DataRepresentationFramework::parseHexNibblePairString(_Asciisz("FFF10A41DFF0020163DFF0030132DFF0050D58333033303330333041394236FFC10122DFC10203313130DFC10317554E41424C4520544F204F50454E20434F4D20504F5254"));  
> // const ipos::BerTlv\* p_sr_message = ipos::BerTlvParser::parseBerTlv(op_terminal_dialog_buf);  
> // m_iPosReceivedMessagesQueue.putOneMessageIntoQueue(p_sr_message);  
> //}

> // TEST 150523, Fake OP_NEW_CUSTOMER response carrying contactless support tag  
> // TODO: 150523, Remove test code when no longer needed!  
> #ifdef IPOS_AMOUNT_BEFORE_CARD  
> /\*  
> //T ==&gt; 4 OP_NEW_CUSTOMER OK ==&gt; SACI  
> //  cdoiPOS_SA fff10a(20)  
> // pdoType dff002(1) = "b"  
> // pdoSeqNbr dff003(1) = "4"  
> // pdoResult dff004(2) = "OK"  
> // cdoOP_NEW_CUSTOMER ff8c01(0)  
> {  
> if (message_definition_tag_path.back() == ipos::cdoOP_NEW_CUSTOMER) {  
> LOG_SCOPE_S(c_LogString("if (message_definition_tag_path.back() == ipos::cdoOP_NEW_CUSTOMER)"));  
> // It is an OP_NEW_CUSTOMER response.  
> // Get a non-const access to const cdoMessage. We are to modify it.  
> ipos::BerTlvContentItemIfc\* contents = const_cast&lt;ipos::BerTlvContentItemIfc\*&gt;(cdoMessage-&gt;getContent());  
> if (contents-&gt;isComposite()) {  
> // It is a container OK (cdoOP_NEW_CUSTOMER must be a conactiner)  
> // Cast to composite for conveniance  
> ipos::BerTlvCompositeContent\* composite = dynamic_cast&lt;ipos::BerTlvCompositeContent\*&gt;(contents);  
> ipos::c_BertlvByteVector yes_vector(1,1); // One byte with value 1 = true  
> const ipos::BerTlv\* pdoAmountBeforeCardSupported = ipos::BerTlv::createPrimitiveBerTlv(ipos::pdoAmountBeforeCardSupported,yes_vector);  
> composite-&gt;insert(composite-&gt;iterator_end(),pdoAmountBeforeCardSupported);  
> LOG_BUSINESS(c_LogString("Test Code #ifdef IPOS_AMOUNT_BEFORE_CARD added pdoAmountBeforeCardSupported(true) to OP_NEW_CUSTOMER response"));  
> }  
> }  
> }  
> \*/  
> #endif // IPOS_AMOUNT_BEFORE_CARD

{% endraw %}
