// zepos_api.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#define ZEPOS_API_EXPORTS
	#include "zepos_api.h"
#undef ZEPOS_API_EXPORTS
#include "iPosLogReused.h"
#include <string>
#include <vector>
#include "iPosMessage.h"

// BEGIN iPOS API
ZEPOS_API_API int  ipos_Init(HWND Handle, unsigned int Message, TOnEvent Callback, int Id) { 

	// Re-use handleMsg from iPosLog code
#define  FUNCTION "ipos_Init"	
	int            iRet=0;                   /* Return code from function     */

	/*
	Save info to be used to notify SACI of new messages.
	----------------------------------------------------
	*/
	iPosLog::gs_pgi->hwnd = Handle;                 /* HWND                          */
	iPosLog::gs_pgi->uiMsg = Message;              /* msg                           */
	iPosLog::gs_pgi->pcb = Callback;                  /* Callback function             */

	iPosLog::handleMsg                              /* Handle message                */
	(
		LL_ALWAYS,                          /* Log level                     */
		FMT_INIT,                           /* Format string                 */
		iPosLog::collectTimestamp(),                 /* Time stamp                    */
		iPosLog::gs_pgi->uiLineNumber++,               /* Line number                   */
		FUNCTION,                           /* Function                      */
		iRet,                               /* Return value                  */
		Id,                                 /* Access ID                     */
		Handle,                               /* HWND                          */
		Message,                            /* Msg                           */
		Callback                                 /* Callback                      */
	);
#undef   FUNCTION

	return 0; 
}
ZEPOS_API_API int  ipos_Conf(char* szConfigString, int Id) { 

	// Re-use handleMsg from iPosLog code
#define  FUNCTION "ipos_Conf"
	int            iRet = 0;                   /* Return code from function     */
	iPosLog::handleMsg                              /* Handle message                */
	(
		LL_ALWAYS,                          /* Log level                     */
		FMT_CONF,                           /* Format string                 */
		iPosLog::collectTimestamp(),                 /* Time stamp                    */
		iPosLog::gs_pgi->uiLineNumber++,               /* Line number                   */
		FUNCTION,                           /* Function                      */
		iRet,                               /* Return value                  */
		Id,                                 /* Access ID                     */
		iPosLog::hex2Ascii(szConfigString, (int)strlen(szConfigString))
		/* Configuration info            */
	);
#undef   FUNCTION

	return 0; 
}

ZEPOS_API_API int  ipos_Write(unsigned char *Data, int DataLen, int Id) {
	// Note:	It is the caller that owns (and will delete) the provided data buffer.
	//			We need to take the copies we need before returhing.

	// Re-use handleMsg from iPosLog code
#define  FUNCTION "ipos_Write"
	int            iRet = 0;                   /* Return code from function     */
	//iPosLog::handleMsg                              /* Handle message                */
	//(
	//	LL_ALWAYS,                          /* Log level                     */
	//	FMT_WRITE,                          /* Format string                 */
	//	iPosLog::collectTimestamp(),                 /* Time stamp                    */
	//	iPosLog::gs_pgi->uiLineNumber++,               /* Line number                   */
	//	FUNCTION,                           /* Function                      */
	//	iRet,                               /* Return value                  */
	//	Id,                                 /* Access ID                     */
	//	iPosLog::hex2Ascii(Data, DataLen)             /* Hex-Ascii                     */
	//);
	{
		try {
			{
				// Test creating iPos Message
				ipos::Message msg(ipos::ipos_span{ Data,DataLen });
				ipos::BertlvByteVector v = msg.make_vector();
				iPosLog::handleMsg                              /* Handle message                */
				(
					LL_ALWAYS,                          /* Log level                     */
					FMT_WRITE,                          /* Format string                 */
					iPosLog::collectTimestamp(),                 /* Time stamp                    */
					iPosLog::gs_pgi->uiLineNumber++,               /* Line number                   */
					FUNCTION,                           /* Function                      */
					iRet,                               /* Return value                  */
					Id,                                 /* Access ID                     */
					iPosLog::hex2Ascii(v.data(), v.size())             /* Hex-Ascii                     */
				);

			}
			{
				// Test of logging xml message for Testbench to sniff

				std::string sXml(R"(<?xml version="1.0" encoding="UTF-8"?>
<SaleToPOIRequest xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:noNamespaceSchemaLocation="EpasSaleToPOIMessages.xsd">
   <MessageHeader ProtocolVersion="1.0" MessageClass="Service" MessageCategory="Login" MessageType="Request" ServiceID="285" WorkstationID="" POIID="52400053" />
   <LoginRequest OperatorLanguage="sv" OperatorID="Cashier16" ShiftNumber="2" POISerialNumber="78910AA46010005">
      <DateTime>2016-08-31T13:09:12.4251848+02:00</DateTime>
      <SaleSoftware ManufacturerID="PointOfSaleCo" ApplicationName="SaleSys" SoftwareVersion="01.98.01" CertificationCode="ECTS2PS001" />
      <ConfigData>
         <TxnHostAddress>164.10.203.25:6054</TxnHostAddress>
         <ConfigHostAddress>164.10.25.253:21</ConfigHostAddress>
         <ConfigFile />
      </ConfigData>
   </LoginRequest>
</SaleToPOIRequest>)");
				/*
				TS=20160920183618683 TXNODE=eIPosTBNode_EpasSale RXNODE=eIPosTBNode_EpasSale InformationType=General D=3C3F786D6C2076657273696F6E3D22312E302220656E636F64696E673D225554462D38223F3E0A3C53616C65546F504F495265717565737420786D6C6E733A7873693D22687474703A2F2F7777772E77332E6F72672F323030312F584D4C536368656D612D696E7374616E636522207873693A6E6F4E616D657370616365536368656D614C6F636174696F6E3D224570617353616C65546F504F494D657373616765732E787364223E0A2020203C4D6573736167654865616465722050726F746F636F6C56657273696F6E3D22312E3022204D657373616765436C6173733D225365727669636522204D65737361676543617465676F72793D224C6F67696E22204D657373616765547970653D225265717565737422205365727669636549443D223238352220576F726B73746174696F6E49443D222220504F4949443D22353234303030353322202F3E0A2020203C4C6F67696E52657175657374204F70657261746F724C616E67756167653D22737622204F70657261746F7249443D22436173686965723136222053686966744E756D6265723D22322220504F4953657269616C4E756D6265723D22373839313041413436303130303035223E0A2020202020203C4461746554696D653E323031362D30382D33315431333A30393A31322E343235313834382B30323A30303C2F4461746554696D653E0A2020202020203C53616C65536F667477617265204D616E75666163747572657249443D22506F696E744F6653616C65436F22204170706C69636174696F6E4E616D653D2253616C655379732220536F66747761726556657273696F6E3D2230312E39382E3031222043657274696669636174696F6E436F64653D224543545332505330303122202F3E0A2020202020203C436F6E666967446174613E0A2020202020202020203C54786E486F7374416464726573733E3136342E31302E3230332E32353A363035343C2F54786E486F7374416464726573733E0A2020202020202020203C436F6E666967486F7374416464726573733E3136342E31302E32352E3235333A32313C2F436F6E666967486F7374416464726573733E0A2020202020202020203C436F6E66696746696C65202F3E0A2020202020203C2F436F6E666967446174613E0A2020203C2F4C6F67696E526571756573743E0A3C2F53616C65546F504F49526571756573743E				*/
				iPosLog::handleMsg												// Handle message 
				(
					LL_ALWAYS													// Log level       
					, "TS=%s TXNODE=%s RXNODE=%s InformationType=%s D=%s"
					, iPosLog::collectTimestamp()								// TS=             
					, "eIPosTBNode_EpasSale"									// TXNODE=
					, "eIPosTBNode_EpasPOI"										// RXNODE=
					, "General"													// InformationType=
					, iPosLog::hex2Ascii((void*)sXml.c_str(), sXml.size())      // Hex nibble string
				);
			}
		}
		catch (...) {
			iRet = -1; // Failed
		}
	}
#undef   FUNCTION

	// TODO: REMOVE TEST WHEN DONE
	{
		unsigned int terminalid = 0;
		unsigned int msglen = 512; // NOT: Simulate size that can hold simulated response in ipos_Read below
		iPosLog::cb(terminalid, msglen); // Test to call the callback (to trigger Client to call Read on us)
	}

	return 0;
}
ZEPOS_API_API int  ipos_Read(unsigned char *Data, int MaxLen, int *DataLen, int Id) {

	{
		// Dummy code for TEST
		// NOT: Ensure we do not provide more than we indocate in simlatde callback in ipos_write above!
		// TS=20160830185738282 L=000000005 Fn=ipos_Read RC=0 ID=1 D=FFF10A30DFF0020162DFF0030131DFF004024F4BFF81011CFFB1110CDFB112084647313937313238FFB11308DFB11404494E4954
		//std::string sOP_INITRsp(R"(FFF10A30DFF0020162DFF0030131DFF004024F4BFF81011CFFB1110CDFB112084647313937313238FFB11308DFB11404494E4954)");
		//for (unsigned int i = 0; i < sOP_INITRsp.size(); i += 2) {
		//	char left = sOP_INITRsp[i];
		//	char right = sOP_INITRsp[i + 1];
		//	Data[i/2] = (left>'9'?(left-'A'):(left-'0')) * 0x10 + (right>'9'?(right-'A'):(right-'0'));
		//}
		//*DataLen = sOP_INITRsp.size()/2;
	}
	{
		// FF F1 0A 00
		Data[0] = 0xFF;
		Data[1] = 0xF1;
		Data[2] = 0x0A;
		Data[3] = 0x00;

		*DataLen = 4;
	}

	// Re-use handleMsg from iPosLog code
#define  FUNCTION "ipos_Read"
	int            iRet = 0;                   /* Return code from function     */
	iPosLog::handleMsg                              /* Handle message                */
	(
		LL_ALWAYS,                          /* Log level                     */
		FMT_READ,                           /* Format string                 */
		iPosLog::collectTimestamp(),                 /* Time stamp                    */
		iPosLog::gs_pgi->uiLineNumber++,               /* Line number                   */
		FUNCTION,                           /* Function                      */
		iRet,                               /* Return value                  */
		Id,                                 /* Access ID                     */
		iPosLog::hex2Ascii(Data, *DataLen)            /* Data                          */
	);
#undef   FUNCTION
	return 0;
}
ZEPOS_API_API int  ipos_Close(int Id) { 
	// Re-use handleMsg from iPosLog code
#define  FUNCTION "ipos_Close"
	int            iRet = 0;                   /* Return code from function     */
	iPosLog::handleMsg                              /* Handle message                */
	(
		LL_ALWAYS,                          /* Log level                     */
		FMT_CLOSE,                          /* Format string                 */
		iPosLog::collectTimestamp(),                 /* Time stamp                    */
		iPosLog::gs_pgi->uiLineNumber++,               /* Line number                   */
		FUNCTION,                           /* Function                      */
		iRet,                               /* Return value                  */
		Id                                  /* Access ID                     */
	);

#undef   FUNCTION
	return 0;
}
ZEPOS_API_API int  ipos_GetVersion(IPOS_VERSIONINFO* versionInfo) {

	static IPOS_VERSIONINFO versioninfo{
		 0	//int            DLLVersionMajor;
		,1	//int            DLLVersionMinor;
		,1//int            IsDebugVersion;
		// 1234567890123456789012345678901234567890123456789012345678901234
		, "zepos_api\0                                                     "//char           Name[64];
		, "Swedbank AB\0                                                   "//char           Manufacturer[64];
		, "Swedbank AB\0                                                   "//char           Copyright[64];
	};

	// Re-use handleMsg from iPosLog code
#define  FUNCTION "ipos_GetVersion"
	int            iRet = 0;                   /* Return code from function     */
	iPosLog::handleMsg                              /* Handle message                */
	(
		LL_ALWAYS,                          /* Log level                     */
		FMT_GETVER,                         /* Format string                 */
		iPosLog::collectTimestamp(),                 /* Time stamp                    */
		iPosLog::gs_pgi->uiLineNumber++,               /* Line number                   */
		FUNCTION,                           /* Function                      */
		iRet,                               /* Return value                  */
		iPosLog::hex2Ascii(&versioninfo, sizeof(versioninfo))
		/* Data (version info)           */
	);

#undef   FUNCTION
	return 0;
}
// END iPOS API
