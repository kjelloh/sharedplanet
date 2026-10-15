#include "TestBenchReused.h"
#include <cmath> // pow
#include <boost/format.hpp> /* 160919 - Requies Boost installed and configured for this project
BOOST_LIBRARYDIR (e.g., C:\local\boost_1_60_0\lib32-msvc-14.0 for win32 build)
BOOST_ROOT (e.g., C:\local\boost_1_60_0)

*/

#include <iomanip> // std::setfill,...
//#include <fstream>
//#include "SysUtils.hpp"

namespace testbench {

#define LOG_DESIGN_INSUFFICIENCY_I(S,I1)
#define LOG_DESIGN_INSUFFICIENCY_II(S,I1,I2)

	namespace c_DataRepresentationFramework  {


		/**
		* Returns provided integer as a decimal string
		*/
		c_AsciiString intToDecimalString(int val, int minNoOfDigits) {
			c_DataRepresentationFramework::c_AsciiString result;
			anonymous(result) += (boost::format("%d") % boost::io::group(std::setfill('0'), std::setw(minNoOfDigits), val)).str();
			return result;
		}

		/**
		* Cretaes a string of hex nibble pairs from provided data buffer.
		* Each byte in the buffer is transalted into a two digit hexadecimal output.
		* data[0x23, 0x34 ...] is output in string as "2334..."
		*/
		c_AsciiString createHexNibbleString(const t_raw_vector& buf) {
			c_AsciiString result;

			t_raw_vector::const_iterator iter = buf.begin();
			while (iter != buf.end()) {
				result += _Asciis((boost::format("%02X") % static_cast<int>(*iter)).str());
				++iter;
			}
			return result;
		}

		/**
		* Creates a string from provided vector of unsigned chars
		*/
		c_AsciiString createString(const t_raw_vector& buf) {
			c_AsciiString result;
			t_raw_vector::const_iterator iter = buf.begin();
			for (iter = buf.begin(); iter != buf.end(); iter++) {
				anonymous(result) += static_cast<char>(*iter);
			}
			return result;
		}

	}

	//---------------------------------------------------------------------------
	namespace bertlv {

		// ============================ class BerTlvHelperMethods =================================
		bool BerTlvHelperMethods::isSet(t_byte byte, const int bitindex) {
			bool result = false;
			if ((bitindex >= 1) && (bitindex <= 8)) {
				// OK
				//			VALIDATE(((bitindex >= 1) && (bitindex <= 8)));
				// bitindex in range 1-8
				// e.g. bitindex = 8, b = 10110001
				// mask -> 2^8 = 10000000
				// b & mask = 10000000
				// -> b = mask
				int mask = (int)std::pow((double)2, (double)(bitindex - 1));
				int res = byte & mask;
				if (res == mask) {
					result = true;
				}
				else {
					result = false;
				}
			}
			else {
				LOG_DESIGN_INSUFFICIENCY_I(_UTF8sz("BerTlvHelperMethods::isSet failed. Called with invalid bitindex=%d"), bitindex);
			}
			return result;
		}

		//	void BerTlvHelperMethods::safe_sprintf(c_DataRepresentationFramework::c_ISO_8859_1_String& buf, const c_DataRepresentationFramework::c_ISO_8859_1_String& format, int val, int maxchars) {
		// maxchars not used after refactoring below 101118/KoH
		void BerTlvHelperMethods::safe_sprintf(c_DataRepresentationFramework::c_ISO_8859_1_String& buf, const c_DataRepresentationFramework::c_ISO_8859_1_String& format, int val) {
			buf = (boost::format(format) % val).str();
			//		int ret = sprintf(buf, format, val);
			//		if ((ret < 0) || (ret > maxchars)) {
			//			throw std::runtime_error("error writing to buffer");
			//		}
		}

		// ============================ (END) class BerTlvHelperMethods =================================
		// ============================ BerTlvPrimitiveContent =================================
		BerTlvPrimitiveContent::BerTlvPrimitiveContent(c_BertlvByteVector bytes) : bytes(bytes) {
		}

		BerTlvPrimitiveContent::~BerTlvPrimitiveContent() {
		}

		bool BerTlvPrimitiveContent::isComposite() const {
			return false;
		}

		c_BertlvByteVector BerTlvPrimitiveContent::byteVector() const {
			return bytes;
		}

		// ============================ (END) BerTlvPrimitiveContent =================================
	} // namespace bertlv


	  //---------------------------------------------------------------------------

	namespace ipos {
		//// ============================ class iPosMessageHelper =================================

		//const BerTlv * iPosMessageHelper::readMessage(iPosHandle * handle, const int maxlen, int deviceNo) {
		//	const BerTlv * result = NULL;
		//	int len = 0;
		//	t_byte * data = new t_byte[maxlen];
		//	try {
		//		int rc = handle->read(data, maxlen, &len, deviceNo);
		//		if (rc == 0) {
		//			if (len > 0) {
		//				c_BertlvByteVector ret_data;
		//				for (int i = 0; i < len; i++) {
		//					ret_data.push_back(data[i]);
		//				}
		//				result = BerTlvParser::parseBerTlv(ret_data);
		//			}
		//			else {
		//			}
		//		}
		//	}
		//	catch (...) {
		//		delete[] data;
		//		throw;
		//	}
		//	delete[] data;
		//	return result;
		//}

		//int iPosMessageHelper::writeMessage(iPosHandle * handle, const BerTlv * message, int deviceNo) {
		//	int result = -0xffff;
		//	t_byte * arr = NULL;
		//	try {
		//		c_BertlvByteVector v = message->byteVector();
		//		arr = new t_byte[v.size()];
		//		c_BertlvByteVector::iterator iter;
		//		int index = 0;
		//		for (iter = v.begin(); iter != v.end(); iter++) {
		//			arr[index++] = *iter;
		//		}
		//		result = handle->write(arr, (int)v.size(), deviceNo);
		//	}
		//	catch (...) {
		//		if (arr != NULL) {
		//			delete[] arr;
		//			arr = NULL;
		//		}
		//		throw;
		//	}
		//	if (arr != NULL) {
		//		delete[] arr;
		//		arr = NULL;
		//	}
		//	return result;
		//}

		//// ============================ (END) iPosMessageHelper =================================

		//// ============================ class iPosHandle =================================
		//iPosHandle * iPosHandle::instance = NULL;

		//iPosHandle * iPosHandle::getInstance(const c_FilePath& dllfile_path) {
		//	c_LogString sMessage("Will load iPOS API = \"");
		//	sMessage += toLogString(dllfile_path.toString());
		//	sMessage += _UTF8sz("\"");
		//	LOG_BUSINESS(sMessage);
		//	const HINSTANCE hDLL = LoadLibrary(dllfile_path.toString().c_str());
		//	if (hDLL != NULL) {
		//		if (instance == NULL) {
		//			instance = new iPosHandle(hDLL);
		//		}
		//		return instance;
		//	}
		//	else {
		//		// We failed.
		//		//		c_DataRepresentationFramework::c_ISO_8859_1_String msg(METHOD_PREFIXED_LOG_STRING(", Failed to load dll file: " + c_DataRepresentationFramework::toUTF8String(dllfile_path.toString())));
		//		//		msg.anonymous() += "\nCheck that other SA-CI is not running. (For example ZipIf service)";
		//		//		throw std::runtime_error(msg);
		//		c_LogString sMessage(METHOD_PREFIXED_LOG_STRING(" failed to load DLL file "));
		//		sMessage += toLogString(dllfile_path.toString());
		//		sMessage += _UTF8sz(". Windows Error = ");
		//		//			DWORD win_last_error = GetLastError();
		//		//			sMessage += toLogString(SysErrorMessage(win_last_error));
		//		sMessage += logStringOfWinApiErrorCode(GetLastError());
		//		LOG_BUSINESS(sMessage);
		//		throw std::runtime_error(sMessage.c_str());
		//	}
		//}

		///**
		//* Returns true if loaded api has provided function name
		//* in its interface.
		//*/
		//bool iPosHandle::apiHasFunction(const char* szMemberFunctionName) {
		//	bool result = false;

		//	// Is loaded DLL a wrapper or the reall DLL?
		//	iPosAPI::ipos_GetOriginalHandle* pGetOriginalHandle = reinterpret_cast<iPosAPI::ipos_GetOriginalHandle*>(GetProcAddress(hDLL, "ipos_GetOriginalHandle"));
		//	if (pGetOriginalHandle != NULL) {
		//		// Query the wrapped DLL
		//		FARPROC pMember = GetProcAddress(pGetOriginalHandle(), szMemberFunctionName);
		//		result = (pMember != NULL);
		//	}
		//	else {
		//		// Query this DLL
		//		FARPROC pMember = GetProcAddress(hDLL, szMemberFunctionName);
		//		result = (pMember != NULL);
		//	}

		//	return result;
		//}

		////    typedef int e_iPOSAPIFunctionId;
		//enum e_iPOSAPIFunctionId {
		//	e_iPOSAPIFunctionId_Undefined
		//	, e_iPOSAPIFunctionId_ipos_Init
		//	, e_iPOSAPIFunctionId_ipos_Write
		//	, e_iPOSAPIFunctionId_ipos_Read
		//	, e_iPOSAPIFunctionId_ipos_GetVersion
		//	, e_iPOSAPIFunctionId_ipos_Close
		//	, e_iPOSAPIFunctionId_ipos_Conf
		//	, e_iPOSAPIFunctionId_Unknown
		//};

		//struct t_iPOSAPIDefinitionEntry {
		//	e_iPOSAPIFunctionId id;
		//	char* szName;
		//};

		//const t_iPOSAPIDefinitionEntry iPOSAPIDefinition[6] = {
		//	{ e_iPOSAPIFunctionId_ipos_Init,"ipos_Init" }
		//	,{ e_iPOSAPIFunctionId_ipos_Write,"ipos_Write" }
		//	,{ e_iPOSAPIFunctionId_ipos_Read,"ipos_Read" }
		//	,{ e_iPOSAPIFunctionId_ipos_GetVersion,"ipos_GetVersion" }
		//	,{ e_iPOSAPIFunctionId_ipos_Close,"ipos_Close" }
		//	,{ e_iPOSAPIFunctionId_ipos_Conf,"ipos_Conf" }
		//};

		///**
		//* Template specialization for an array T with S elements.
		//* The compiler will instanziate an arraysize function that returns the number of elememnts
		//* of provided array T.
		//*/
		//template <typename T, unsigned S>
		//inline unsigned arraysize(const T(&v)[S]) { return S; }

		//iPosHandle::iPosHandle(const HINSTANCE hDLL)
		//	: hDLL(hDLL)
		//	, m_fn_ipos_Init(NULL)
		//	, m_fn_ipos_Write(NULL)
		//	, m_fn_ipos_Read(NULL)
		//	, m_fn_ipos_GetVersion(NULL)
		//	, m_fn_ipos_Close(NULL)
		//	, m_fn_ipos_Conf(NULL)
		//{
		//	// 160206, Changed to perform binding based on iPOSAPIDefinition mechanism/KoH
		//	//		try {
		//	//			m_fn_ipos_Init = reinterpret_cast<iPosAPI::ipos_Init*>(GetProcAddress(hDLL, "ipos_Init"));
		//	//			m_fn_ipos_Write = reinterpret_cast<iPosAPI::ipos_Write*>(GetProcAddress(hDLL, "ipos_Write"));
		//	//			m_fn_ipos_Read = reinterpret_cast<iPosAPI::ipos_Read*>(GetProcAddress(hDLL, "ipos_Read"));
		//	//			m_fn_ipos_GetVersion = reinterpret_cast<iPosAPI::ipos_GetVersion*>(GetProcAddress(hDLL, "ipos_GetVersion"));
		//	//			m_fn_ipos_Close = reinterpret_cast<iPosAPI::ipos_Close*>(GetProcAddress(hDLL, "ipos_Close"));
		//	//			m_fn_ipos_Conf = reinterpret_cast<iPosAPI::ipos_Conf*>(GetProcAddress(hDLL, "ipos_Conf"));
		//	//		} catch (...) {
		//	//		}

		//	// Loop through iPOSAPIDefinition and bind interface members to "us"
		//	bool api_bind_failed = false;
		//	for (unsigned int i = 0; i < arraysize(iPOSAPIDefinition); ++i) {
		//		api_bind_failed = false;
		//		try {
		//			switch (iPOSAPIDefinition[i].id) {
		//			case e_iPOSAPIFunctionId_ipos_Init:
		//				api_bind_failed = (NULL == (m_fn_ipos_Init = reinterpret_cast<iPosAPI::ipos_Init*>(GetProcAddress(hDLL, iPOSAPIDefinition[i].szName))));
		//				break;
		//			case e_iPOSAPIFunctionId_ipos_Write:
		//				api_bind_failed = (NULL == (m_fn_ipos_Write = reinterpret_cast<iPosAPI::ipos_Write*>(GetProcAddress(hDLL, iPOSAPIDefinition[i].szName))));
		//				break;
		//			case e_iPOSAPIFunctionId_ipos_Read:
		//				api_bind_failed = (NULL == (m_fn_ipos_Read = reinterpret_cast<iPosAPI::ipos_Read*>(GetProcAddress(hDLL, iPOSAPIDefinition[i].szName))));
		//				break;
		//			case e_iPOSAPIFunctionId_ipos_GetVersion:
		//				api_bind_failed = (NULL == (m_fn_ipos_GetVersion = reinterpret_cast<iPosAPI::ipos_GetVersion*>(GetProcAddress(hDLL, iPOSAPIDefinition[i].szName))));
		//				break;
		//			case e_iPOSAPIFunctionId_ipos_Close:
		//				api_bind_failed = (NULL == (m_fn_ipos_Close = reinterpret_cast<iPosAPI::ipos_Close*>(GetProcAddress(hDLL, iPOSAPIDefinition[i].szName))));
		//				break;
		//			case e_iPOSAPIFunctionId_ipos_Conf:
		//				api_bind_failed = (NULL == (m_fn_ipos_Conf = reinterpret_cast<iPosAPI::ipos_Conf*>(GetProcAddress(hDLL, iPOSAPIDefinition[i].szName))));
		//				break;
		//			default: {
		//				c_LogString sMessage("iPOS API Bind failed - Unknown iPOSAPIDefinition member ignored. Member = ");
		//				sMessage += _Asciisz(iPOSAPIDefinition[i].szName);
		//				LOG_DESIGN_INSUFFICIENCY(sMessage);
		//			};
		//			}
		//			if (api_bind_failed) {
		//				c_LogString sMessage("Failed to bind to iPOS API Member = ");
		//				sMessage += _Asciisz(iPOSAPIDefinition[i].szName);
		//				sMessage += _UTF8sz(". Error = ");
		//				sMessage += logStringOfWinApiErrorCode(GetLastError());
		//				LOG_BUSINESS(sMessage);
		//			}
		//		}
		//		catch (...) {
		//			c_LogString sMessage("iPOS API Bind failed when attending to Member = ");
		//			sMessage += _Asciisz(iPOSAPIDefinition[i].szName);
		//			sMessage += _UTF8sz(". General Exception cought.");
		//			LOG_DESIGN_INSUFFICIENCY(sMessage);
		//		}
		//	}

		//}

		//iPosHandle::~iPosHandle() {
		//	FreeLibrary(hDLL);
		//	instance = NULL;
		//}

		//int iPosHandle::init(iPosAPI::TOnRecvEvent ptr, const int id) {
		//	//	iPosAPI::ipos_Init* iposInit = reinterpret_cast<iPosAPI::ipos_Init*>(GetProcAddress(hDLL, "ipos_Init"));
		//	//	return iposInit(NULL, 0, ptr, id);
		//	int result = -1;
		//	if (m_fn_ipos_Init != NULL) {
		//		result = m_fn_ipos_Init(NULL, 0, ptr, id);
		//	}
		//	else {
		//		throw std::runtime_error(METHOD_PREFIXED_LOG_STRING(" failed. Not supported by loaded iPos API"));
		//	}
		//	return result;
		//}

		//int iPosHandle::write(unsigned char * data, const int dataLen, const int id) {
		//	//	iPosAPI::ipos_Write* iposWrite = reinterpret_cast<iPosAPI::ipos_Write*>(GetProcAddress(hDLL, "ipos_Write"));
		//	//	return iposWrite(data, dataLen, id);
		//	int result = -1;
		//	if (m_fn_ipos_Write != NULL) {
		//		result = m_fn_ipos_Write(data, dataLen, id);
		//	}
		//	else {
		//		throw std::runtime_error(METHOD_PREFIXED_LOG_STRING(" failed. Not supported by loaded iPos API"));
		//	}
		//	return result;
		//}

		//int iPosHandle::read(unsigned char * data, const int maxLen, int * dataLen, int id) {
		//	//	iPosAPI::ipos_Read* iposRead = reinterpret_cast<iPosAPI::ipos_Read*>(GetProcAddress(hDLL, "ipos_Read"));
		//	//	return iposRead(data, maxLen, dataLen, id);
		//	int result = -1;
		//	if (m_fn_ipos_Read != NULL) {
		//		result = m_fn_ipos_Read(data, maxLen, dataLen, id);
		//	}
		//	else {
		//		throw std::runtime_error(METHOD_PREFIXED_LOG_STRING(" failed. Not supported by loaded iPos API"));
		//	}
		//	return result;
		//}
		//int iPosHandle::getVersion(iPosAPI::IPOS_VERSIONINFO * versionInfo) {
		//	//	iPosAPI::ipos_GetVersion* iposGetVersion = reinterpret_cast<iPosAPI::ipos_GetVersion*>(GetProcAddress(hDLL, "ipos_GetVersion"));
		//	//	return iposGetVersion(versionInfo);
		//	int result = -1;
		//	if (m_fn_ipos_GetVersion != NULL) {
		//		result = m_fn_ipos_GetVersion(versionInfo);
		//	}
		//	else {
		//		throw std::runtime_error(METHOD_PREFIXED_LOG_STRING(" failed. Not supported by loaded iPos API"));
		//	}
		//	return result;
		//}

		//int iPosHandle::close(const int id) {
		//	//	iPosAPI::ipos_Close* iposClose = reinterpret_cast<iPosAPI::ipos_Close*>(GetProcAddress(hDLL, "ipos_Close"));
		//	//	return iposClose(id);
		//	int result = -1;
		//	if (m_fn_ipos_Close != NULL) {
		//		result = m_fn_ipos_Close(id);
		//	}
		//	else {
		//		throw std::runtime_error(METHOD_PREFIXED_LOG_STRING(" failed. Not supported by loaded iPos API"));
		//	}
		//	return result;
		//}

		///**
		//* Calls ipos API ipos_Conf
		//*/
		//int iPosHandle::conf(const char* szConfigString, int Id) {
		//	int result = -1;
		//	if (m_fn_ipos_Conf != NULL) {
		//		result = m_fn_ipos_Conf(szConfigString, Id);
		//	}
		//	else {
		//		throw std::runtime_error("iPosHandle::conf failed. Not supported by loaded iPos API");
		//	}
		//	return result;
		//}

		//// ============================ (END) iPosHandle =================================

		// ============================ class TagConst =================================

		//TagConst * TagConst::instance = NULL;
		//
		//TagConst * TagConst::getInstance() {
		//	// synchronizing should not be necessary since
		//	// worst case is two created instances.
		//	if (instance == NULL) {
		//		std::vector < std::pair < c_DataRepresentationFramework::c_ISO_8859_1_String, int > > v;
		//		v = createVector();
		//		instance = new TagConst(v);
		//	}
		//	return instance;
		//}

		TagConst::TagConst(const c_TagLabelPairVector& v)
		{
			c_TagLabelPairVector::const_iterator iter;
			for (iter = v.begin(); iter != v.end(); iter++) {
				//			c_TagLabelPair p = * iter;
				//			m1.insert(std::pair < int, c_DataRepresentationFramework::c_ISO_8859_1_String > (p.second, p.first));
				//			m2.insert(std::pair < c_DataRepresentationFramework::c_ISO_8859_1_String, int > (p.first, p.second));

				m1.insert(std::make_pair(iter->second, iter->first));
				m2.insert(std::make_pair(iter->first, iter->second));
			}
		}

		TagConst::~TagConst() {
			//		delete instance;
		}

		/**
		* returns true and sets sResult to the label of provided tag value
		* if it is found.
		*/
		bool TagConst::lookup(const t_TagValue tagvalue, c_DataRepresentationFramework::c_ISO_8859_1_String& sResult) const {
			bool result = false;
			sResult.clear();
			std::map < int, c_DataRepresentationFramework::c_ISO_8859_1_String >::const_iterator iter;
			iter = m1.find(tagvalue);
			if (iter != m1.end()) {
				sResult = iter->second;
				result = true;
			}
			return result;
		}

		c_DataRepresentationFramework::c_ISO_8859_1_String TagConst::getNoLabelAvailable() const {
			//		return _Literalsz("xxxN/A");
			return _Literalsz("?Name?");
		}

		//	int TagConst::lookup(const c_DataRepresentationFramework::c_ISO_8859_1_String & taglabel) const {
		//		std::map < c_DataRepresentationFramework::c_ISO_8859_1_String, int >::const_iterator iter;
		//		iter = m2.find(taglabel);
		//		if (iter == m2.end()) {
		//			c_DataRepresentationFramework::c_ISO_8859_1_String str("");
		//			str.append("No tag value found for label: ");
		//			str.append(taglabel);
		//			throw std::range_error(str);
		//		}
		//		return iter->second;
		//	}
		//
		//	c_DataRepresentationFramework::c_ISO_8859_1_String TagConst::lookup(const t_TagValue tagvalue) const {
		//		c_DataRepresentationFramework::c_ISO_8859_1_String result("?Name?");
		//		std::map < int, c_DataRepresentationFramework::c_ISO_8859_1_String >::const_iterator iter;
		//		iter = m1.find(tagvalue);
		//		if (iter != m1.end()) {
		//			result = iter->second;
		//		}
		//		return result;
		//	}

		TagConst::c_TagLabelPairVector& TagConst::createVector() {
			static TagConst::c_TagLabelPairVector v;
			// header
			v.push_back(c_TagLabelPair(_Literalsz("cdoSA_iPOS"), cdoSA_iPOS));
			v.push_back(c_TagLabelPair(_Literalsz("cdoiPOS_SA"), cdoiPOS_SA));
			v.push_back(c_TagLabelPair(_Literalsz("pdoType"), pdoType));
			v.push_back(c_TagLabelPair(_Literalsz("pdoSeqNbr"), pdoSeqNbr));
			v.push_back(c_TagLabelPair(_Literalsz("pdoResult"), pdoResult));
			v.push_back(c_TagLabelPair(_Literalsz("pdoEcho"), pdoEcho));
			// OP_INIT
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_INIT"), cdoOP_INIT));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTermPath"), pdoTermPath));
			v.push_back(c_TagLabelPair(_Literalsz("cdoPayTerm"), cdoPayTerm));
			v.push_back(c_TagLabelPair(_Literalsz("pdoPayTermSer"), pdoPayTermSer));
			v.push_back(c_TagLabelPair(_Literalsz("pdoPayTermIp"), pdoPayTermIp));
			v.push_back(c_TagLabelPair(_Literalsz("pdoPayTermUsb"), pdoPayTermUsb));
			v.push_back(c_TagLabelPair(_Literalsz("pdoMaxDspLength"), pdoMaxDspLength));
			v.push_back(c_TagLabelPair(_Literalsz("pdoNbrRow"), pdoNbrRow));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDspTimer"), pdoDspTimer));
			v.push_back(c_TagLabelPair(_Literalsz("cdoLocalNetworkConfig"), cdoLocalNetworkConfig));
			v.push_back(c_TagLabelPair(_Literalsz("pdoLocalIp"), pdoLocalIp));
			v.push_back(c_TagLabelPair(_Literalsz("pdoSubnetMask"), pdoSubnetMask));
			v.push_back(c_TagLabelPair(_Literalsz("pdoGateway"), pdoGateway));
			v.push_back(c_TagLabelPair(_Literalsz("pdoiPOSRestart"), pdoiPOSRestart));
			v.push_back(c_TagLabelPair(_Literalsz("cdoPayTermInfo"), cdoPayTermInfo));
			v.push_back(c_TagLabelPair(_Literalsz("pdoPedType"), pdoPedType));
			v.push_back(c_TagLabelPair(_Literalsz("pdoPedId"), pdoPedId));
			// DI_INFO
			v.push_back(c_TagLabelPair(_Literalsz("cdoDI_INFO"), cdoDI_INFO));
			v.push_back(c_TagLabelPair(_Literalsz("cdoDIMessage"), cdoDIMessage));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTextId"), pdoTextId));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDIForce"), pdoDIForce));
			v.push_back(c_TagLabelPair(_Literalsz("cdoDsp"), cdoDsp));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDspRow"), pdoDspRow));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDspJustified"), pdoDspJustified));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDIDspText"), pdoDIDspText));
			v.push_back(c_TagLabelPair(_Literalsz("cdoKbd"), cdoKbd));
			v.push_back(c_TagLabelPair(_Literalsz("pdoKbdKey"), pdoKbdKey));
			v.push_back(c_TagLabelPair(_Literalsz("pdoKbdKeyVal"), pdoKbdKeyVal));
			v.push_back(c_TagLabelPair(_Literalsz("pdoKbdRow"), pdoKbdRow));
			v.push_back(c_TagLabelPair(_Literalsz("pdoKbdPos"), pdoKbdPos));
			v.push_back(c_TagLabelPair(_Literalsz("pdoKbdInMax"), pdoKbdInMax));
			v.push_back(c_TagLabelPair(_Literalsz("pdoKbdEndFnc"), pdoKbdEndFnc));
			v.push_back(c_TagLabelPair(_Literalsz("pdoKbdEndFncSel"), pdoKbdEndFncSel));
			v.push_back(c_TagLabelPair(_Literalsz("cdoDIChar"), cdoDIChar));
			v.push_back(c_TagLabelPair(_Literalsz("pdoChar"), pdoChar));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDspPos"), pdoDspPos));
			v.push_back(c_TagLabelPair(_Literalsz("cdoDIEvent"), cdoDIEvent));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDIEventType"), pdoDIEventType));
			// SR_MESSAGE
			v.push_back(c_TagLabelPair(_Literalsz("cdoSR_MESSAGE"), cdoSR_MESSAGE));
			v.push_back(c_TagLabelPair(_Literalsz("pdoIposErrorText"), pdoIposErrorText));
			// OP_CONNECT
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_CONNECT"), cdoOP_CONNECT));
			v.push_back(c_TagLabelPair(_Literalsz("cdoiPOSTsp"), cdoiPOSTsp));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTSPId"), pdoTSPId));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTSPAddr"), pdoTSPAddr));
			v.push_back(c_TagLabelPair(_Literalsz("cdoSA"), cdoSA));
			v.push_back(c_TagLabelPair(_Literalsz("pdoSettId"), pdoSettId));
			v.push_back(c_TagLabelPair(_Literalsz("cdoPPId"), cdoPPId));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDate"), pdoDate));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTime"), pdoTime));
			v.push_back(c_TagLabelPair(_Literalsz("cdoLastTrans"), cdoLastTrans));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTypeLastTrans"), pdoTypeLastTrans));
			v.push_back(c_TagLabelPair(_Literalsz("pdoSASensitiveDataProtectionLevel"), pdoSASensitiveDataProtectionLevel)); // 100208 KoH

																															 // OP_OPEN
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_OPEN"), cdoOP_OPEN));
			// NEW_CUSTOMER
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_NEW_CUSTOMER"), cdoOP_NEW_CUSTOMER));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTransactionType"), pdoTransactionType));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCardContinue"), pdoCardContinue));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCardReader"), pdoCardReader));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDspRow"), pdoDspRow));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDspJustified"), pdoDspJustified));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDspText"), pdoDspText));
			v.push_back(c_TagLabelPair(_Literalsz("pdoOpenFuncKey"), pdoOpenFuncKey));
			// OP_END
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_END"), cdoOP_END));
			// SR_CARD_READ
			v.push_back(c_TagLabelPair(_Literalsz("cdoSR_CARD_READ"), cdoSR_CARD_READ));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCardTypeIndikator"), pdoCardTypeIndikator));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCardType"), pdoCardType));
			v.push_back(c_TagLabelPair(_Literalsz("pdoPAN"), pdoPAN));
			v.push_back(c_TagLabelPair(_Literalsz("pdoMaskedPAN"), pdoMaskedPAN));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCardUserID"), pdoCardUserID));
			v.push_back(c_TagLabelPair(_Literalsz("cdoLoyaltyList"), cdoLoyaltyList));
			v.push_back(c_TagLabelPair(_Literalsz("pdoAID"), pdoAID));
			v.push_back(c_TagLabelPair(_Literalsz("pdoMaxCashBackAmount"), pdoMaxCashBackAmount));
			v.push_back(c_TagLabelPair(_Literalsz("pdoWithdrawalAmount"), pdoWithdrawalAmount));
			v.push_back(c_TagLabelPair(_Literalsz("pdoMinPurchaseAmount"), pdoMinPurchaseAmount));
			v.push_back(c_TagLabelPair(_Literalsz("pdoMaxPurchaseAmount"), pdoMaxPurchaseAmount));
			v.push_back(c_TagLabelPair(_Literalsz("pdoMaxRefundAmount"), pdoMaxRefundAmount));
			v.push_back(c_TagLabelPair(_Literalsz("pdoBonusApplication"), pdoBonusApplication));
			v.push_back(c_TagLabelPair(_Literalsz("pdoBitfields_1"), pdoBitfields_1));
			v.push_back(c_TagLabelPair(_Literalsz("pdoBitfields_2"), pdoBitfields_2));
			v.push_back(c_TagLabelPair(_Literalsz("pdoBitfields_3"), pdoBitfields_3));
			v.push_back(c_TagLabelPair(_Literalsz("pdoBitfields_4"), pdoBitfields_4));
			v.push_back(c_TagLabelPair(_Literalsz("pdoBitfields_5"), pdoBitfields_5));
			v.push_back(c_TagLabelPair(_Literalsz("pdoFinancialInstitution"), pdoFinancialInstitution));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCardHolderName"), pdoCardHolderName));
			v.push_back(c_TagLabelPair(_Literalsz("cdoUnknownCard"), cdoUnKnownCard));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTrack1Data"), pdoTrack1Data));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTrack2Data"), pdoTrack2Data));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTrack3Data"), pdoTrack3Data));
			v.push_back(c_TagLabelPair(_Literalsz("cdoPayment"), cdoPayment));
			// OP_PAY
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_PAY"), cdoOP_PAY));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTransactionAmount"), pdoTransactionAmount));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTransactionVAT"), pdoTransactionVAT));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTransCurrencyCode"), pdoTransCurrencyCode));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCashBackAmount"), pdoCashBackAmount));
			v.push_back(c_TagLabelPair(_Literalsz("pdoMerchantCategoryCode"), pdoMerchantCategoryCode));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCashierId"), pdoCashierId));
			v.push_back(c_TagLabelPair(_Literalsz("pdoSettId"), pdoSettId));
			v.push_back(c_TagLabelPair(_Literalsz("cdoSR_STATUS_CHANGE"), cdoSR_STATUS_CHANGE));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTermNbrChar"), pdoTermNbrChar));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTrack1"), pdoTrack1));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTrack2"), pdoTrack2));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTrack3"), pdoTrack3));
			v.push_back(c_TagLabelPair(_Literalsz("pdoChip"), pdoChip));
			v.push_back(c_TagLabelPair(_Literalsz("pdoName"), pdoName));
			v.push_back(c_TagLabelPair(_Literalsz("pdoHWVer"), pdoHWVer));
			v.push_back(c_TagLabelPair(_Literalsz("pdoSWVer"), pdoSWVer));
			v.push_back(c_TagLabelPair(_Literalsz("pdoHWSecurityVer"), pdoHWSecurityVer));
			v.push_back(c_TagLabelPair(_Literalsz("pdoSWSecurityVer"), pdoSWSecurityVer));
			v.push_back(c_TagLabelPair(_Literalsz("pdoLoyaltyDone"), pdoLoyaltyDone));
			v.push_back(c_TagLabelPair(_Literalsz("pdoOpenLowLevel"), pdoOpenLowLevel));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCardContinue"), pdoCardContinue));
			v.push_back(c_TagLabelPair(_Literalsz("cdoiPOS"), cdoiPOS));
			v.push_back(c_TagLabelPair(_Literalsz("pdoiPOSVer"), pdoiPOSVer));
			v.push_back(c_TagLabelPair(_Literalsz("cdoStatus"), cdoStatus));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCurrState"), pdoCurrState));
			v.push_back(c_TagLabelPair(_Literalsz("pdoStateChange"), pdoStateChange));
			v.push_back(c_TagLabelPair(_Literalsz("pdoStateChangeIndicator"), pdoStateChangeIndicator));
			// OP CANCEL
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_CANCEL"), cdoOP_CANCEL));
			// OP CLOSE
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_CLOSE"), cdoOP_CLOSE));
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_AUTHORIZE"), cdoOP_AUTHORIZE));
			v.push_back(c_TagLabelPair(_Literalsz("pdoOpenTransactionHandling"), pdoOpenTransactionHandling));
			// OP_DEBIT
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_DEBIT"), cdoOP_DEBIT));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCreateAdvice"), pdoCreateAdvice));
			// SR REQUEST DATA
			v.push_back(c_TagLabelPair(_Literalsz("cdoSR_REQUEST_DATA"), cdoSR_REQUEST_DATA));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTagList"), pdoTagList));
			v.push_back(c_TagLabelPair(_Literalsz("cdoTagListData"), cdoTagListData));
			// SR SEND HOST
			v.push_back(c_TagLabelPair(_Literalsz("cdoSR_SEND_HOST"), cdoSR_SEND_HOST));
			v.push_back(c_TagLabelPair(_Literalsz("cdoHostAddr"), cdoHostAddr));
			v.push_back(c_TagLabelPair(_Literalsz("pdoPrimPhonNbr"), pdoPrimPhonNbr));
			v.push_back(c_TagLabelPair(_Literalsz("pdoSecondPhonNbr"), pdoSecondPhonNbr));
			v.push_back(c_TagLabelPair(_Literalsz("pdoPrimIPAdr"), pdoPrimIPAdr));
			v.push_back(c_TagLabelPair(_Literalsz("pdoSecondIPAdr"), pdoSecondIPAdr));
			v.push_back(c_TagLabelPair(_Literalsz("pdoExpectResponse"), pdoExpectResponse));
			v.push_back(c_TagLabelPair(_Literalsz("pdoSPDH"), pdoSPDH));
			v.push_back(c_TagLabelPair(_Literalsz("cdoFileTSP"), cdoFileTSP));

			v.push_back(c_TagLabelPair(_Literalsz("pdoUserId"), pdoUserId));
			v.push_back(c_TagLabelPair(_Literalsz("pdoPassword"), pdoPassword));
			v.push_back(c_TagLabelPair(_Literalsz("pdoFileNameTSP"), pdoFileNameTSP));
			v.push_back(c_TagLabelPair(_Literalsz("pdoFileNameLocal"), pdoFileNameLocal));
			v.push_back(c_TagLabelPair(_Literalsz("pdoFileSendOrReceive"), pdoFileSendOrReceive));

			// SR SEND HOST RESP
			v.push_back(c_TagLabelPair(_Literalsz("pdoResponseCodeFTP"), pdoResponseCodeFTP));
			// SR RECEIVE DATA
			v.push_back(c_TagLabelPair(_Literalsz("cdoSR_RECEIVE_DATA"), cdoSR_RECEIVE_DATA));
			v.push_back(c_TagLabelPair(_Literalsz("cdoReceiptData"), cdoReceiptData));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDebitStatus"), pdoDebitStatus));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTextId"), pdoTextId));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDebitStatusText"), pdoDebitStatusText));
			v.push_back(c_TagLabelPair(_Literalsz("pdoAcqRefNbr"), pdoAcqRefNbr));
			v.push_back(c_TagLabelPair(_Literalsz("pdoAcqRefNbr_HC"), pdoAcqRefNbr_HC));
			v.push_back(c_TagLabelPair(_Literalsz("pdoBankAgentName"), pdoBankAgentName));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCardProductName"), pdoCardProductName));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTransactionDate"), pdoTransactionDate));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTransactionTime"), pdoTransactionTime));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTransactionTime_HC"), pdoTransactionTime_HC));
			v.push_back(c_TagLabelPair(_Literalsz("pdoOrganisationNbr"), pdoOrganisationNbr));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTransactionCode"), pdoTransactionCode));
			v.push_back(c_TagLabelPair(_Literalsz("pdoPAN"), pdoPAN));
			v.push_back(c_TagLabelPair(_Literalsz("pdoExpirationDate"), pdoExpirationDate));
			v.push_back(c_TagLabelPair(_Literalsz("pdoAccountType"), pdoAccountType));
			v.push_back(c_TagLabelPair(_Literalsz("pdoIDMethod"), pdoIDMethod));
			v.push_back(c_TagLabelPair(_Literalsz("pdoPOSEntryMode"), pdoPOSEntryMode));
			v.push_back(c_TagLabelPair(_Literalsz("pdoRetrievalReferenceNumber"), pdoRetrievalReferenceNumber));
			v.push_back(c_TagLabelPair(_Literalsz("pdoAuthorisationMethod"), pdoAuthorisationMethod));
			v.push_back(c_TagLabelPair(_Literalsz("pdoAuthorisationResponseCode"), pdoAuthorisationResponseCode));
			v.push_back(c_TagLabelPair(_Literalsz("pdoAuthorisationCode"), pdoAuthorisationCode));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTerminalIdentifier"), pdoTerminalIdentifier));
			v.push_back(c_TagLabelPair(_Literalsz("pdoOpenTransactionNumber"), pdoOpenTransactionNumber));
			v.push_back(c_TagLabelPair(_Literalsz("cdoEMVData"), cdoEMVData));
			v.push_back(c_TagLabelPair(_Literalsz("pdoAID"), pdoAID));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTVR"), pdoTVR));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTSI"), pdoTSI));
			v.push_back(c_TagLabelPair(_Literalsz("cdoLogData"), cdoLogData));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDebitStatus"), pdoDebitStatus));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTerminalCapability"), pdoTerminalCapability));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCardInput"), pdoCardInput));
			v.push_back(c_TagLabelPair(_Literalsz("pdoMerchantCategoryCode"), pdoMerchantCategoryCode));
			v.push_back(c_TagLabelPair(_Literalsz("pdoAuthorisingEntity"), pdoAuthorisingEntity));
			v.push_back(c_TagLabelPair(_Literalsz("pdoAC"), pdoAC));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCryptoAmount"), pdoCryptoAmount));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCryptoInfoData"), pdoCryptoInfoData));
			v.push_back(c_TagLabelPair(_Literalsz("pdoIAD"), pdoIAD));
			v.push_back(c_TagLabelPair(_Literalsz("pdoUnpredicNumber"), pdoUnpredicNumber));
			v.push_back(c_TagLabelPair(_Literalsz("pdoATC"), pdoATC));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTVR"), pdoTVR));
			v.push_back(c_TagLabelPair(_Literalsz("pdoAIP"), pdoAIP));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCryptoTransactionDate"), pdoCryptoTransactionDate));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCryptoTransType"), pdoCryptoTransType));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCryptoCurrency"), pdoCryptoCurrency));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTermCountryCode"), pdoTermCountryCode));
			v.push_back(c_TagLabelPair(_Literalsz("pdoEMVTerminalType"), pdoEMVTerminalType));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDFName"), pdoDFName));
			v.push_back(c_TagLabelPair(_Literalsz("pdoAppVersNumber"), pdoAppVersNumber));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTermAppVersNumber"), pdoTermAppVersNumber));
			v.push_back(c_TagLabelPair(_Literalsz("pdoOtherAmount"), pdoOtherAmount));
			v.push_back(c_TagLabelPair(_Literalsz("pdoPANSeqNumber"), pdoPANSeqNumber));
			v.push_back(c_TagLabelPair(_Literalsz("pdoEMVResponseCode"), pdoEMVResponseCode));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCVMResult"), pdoCVMResult));
			v.push_back(c_TagLabelPair(_Literalsz("pdoScriptResult"), pdoScriptResult));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTermCapabilities"), pdoTermCapabilities));
			v.push_back(c_TagLabelPair(_Literalsz("pdoAdditionalRID"), pdoAdditionalRID));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCashierId"), pdoCashierId));
			v.push_back(c_TagLabelPair(_Literalsz("pdoFinancialInstitution"), pdoFinancialInstitution));
			v.push_back(c_TagLabelPair(_Literalsz("pdoMaxAllowedAmount"), pdoMaxAllowedAmount));
			v.push_back(c_TagLabelPair(_Literalsz("pdoOpenTransactionNumber"), pdoOpenTransactionNumber));
			v.push_back(c_TagLabelPair(_Literalsz("pdoLogReason"), pdoLogReason));
			v.push_back(c_TagLabelPair(_Literalsz("cdoiPOSLogData"), cdoiPOSLogData));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTypeOfLog"), pdoTypeOfLog));
			v.push_back(c_TagLabelPair(_Literalsz("pdoLogBlock"), pdoLogBlock));
			v.push_back(c_TagLabelPair(_Literalsz("pdoiPOSData"), pdoiPOSData));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTrack2Part"), pdoTrack2Part));
			v.push_back(c_TagLabelPair(_Literalsz("pdoPaymentCode"), pdoPaymentCode));
			// OP_TRACE
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_TRACE"), cdoOP_TRACE));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTraceLevel"), pdoTraceLevel));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTraceInfo"), pdoTraceInfo));
			// OP_PROPRIETARY
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_PROPRIETARY"), cdoOP_PROPRIETARY));
			v.push_back(c_TagLabelPair(_Literalsz("cdoSR_HANDLE_PROPRIETARY_DATA"), cdoSR_HANDLE_PROPRIETARY_DATA));
			v.push_back(c_TagLabelPair(_Literalsz("pdoProprietaryApplicationID"), pdoProprietaryApplicationID));
			v.push_back(c_TagLabelPair(_Literalsz("pdoProprietaryCommandData"), pdoProprietaryCommandData));
			// OP_LOG
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_LOG"), cdoOP_LOG));
			v.push_back(c_TagLabelPair(_Literalsz("pdoRequestType"), pdoRequestType));
			v.push_back(c_TagLabelPair(_Literalsz("pdoSearchData"), pdoSearchData));
			v.push_back(c_TagLabelPair(_Literalsz("pdoLogFileName"), pdoLogFileName));
			// OP_PUT_CARD_DATA
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_PUT_CARD_DATA"), cdoOP_PUT_CARD_DATA));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCardInputIndicator"), pdoCardInputIndicator));
			v.push_back(c_TagLabelPair(_Literalsz("pdoPAN"), pdoPAN));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTrack1Data"), pdoTrack1Data));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTrack2Data"), pdoTrack2Data));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTrack3Data"), pdoTrack3Data));
			// OP_REFUND
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_REFUND"), cdoOP_REFUND));
			v.push_back(c_TagLabelPair(_Literalsz("cdoChangeAcqBank"), cdoChangeAcqBank));
			// OP_STATUS
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_STATUS"), cdoOP_STATUS));
			// OP_CORR
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_CORR"), cdoOP_CORR));
			// OP_TERMINAL_DIALOG
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_TERMINAL_DIALOG"), cdoOP_TERMINAL_DIALOG));
			v.push_back(c_TagLabelPair(_Literalsz("cdoOPMessage"), cdoOPMessage));
			v.push_back(c_TagLabelPair(_Literalsz("pdoBeep"), pdoBeep));
			v.push_back(c_TagLabelPair(_Literalsz("cdoDspIdle"), cdoDspIdle));

			// cdoOP_NEW_PARAMETERS
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_NEW_PARAMETERS"), cdoOP_NEW_PARAMETERS));
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_MAINTENANCE"), cdoOP_MAINTENANCE));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTypeOfFunction"), pdoTypeOfFunction));
			v.push_back(c_TagLabelPair(_Literalsz("pdoUserPW"), pdoUserPW));
			v.push_back(c_TagLabelPair(_Literalsz("pdoDumpData"), pdoDumpData));
			v.push_back(c_TagLabelPair(_Literalsz("pdoLSPDHDate"), pdoLSPDHDate));
			v.push_back(c_TagLabelPair(_Literalsz("pdoLSPDHTime"), pdoLSPDHTime));
			v.push_back(c_TagLabelPair(_Literalsz("pdoLSPDHRspCode"), pdoLSPDHRspCode));
			v.push_back(c_TagLabelPair(_Literalsz("cdoParameterInfo"), cdoParameterInfo));
			v.push_back(c_TagLabelPair(_Literalsz("pdoFileNamePPL"), pdoFileNamePPL));
			v.push_back(c_TagLabelPair(_Literalsz("pdoTransactionCategoryCode"), pdoTransactionCategoryCode));
			v.push_back(c_TagLabelPair(_Literalsz("cdoCloseBatch"), cdoCloseBatch));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCBTerm"), pdoCBTerm));
			v.push_back(c_TagLabelPair(_Literalsz("pdoCBHost"), pdoCBHost));
			// Language select expansion designed by Sagem
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_SET_LANGUAGE"), cdoOP_SET_LANGUAGE));
			v.push_back(c_TagLabelPair(_Literalsz("pdoIso639Code"), pdoIso639Code));
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_GET_LANGUAGES"), cdoOP_GET_LANGUAGES));
			v.push_back(c_TagLabelPair(_Literalsz("pdoLanguageCount"), pdoLanguageCount));
			v.push_back(c_TagLabelPair(_Literalsz("cdoSR_LANGUAGE_CHANGE"), cdoSR_LANGUAGE_CHANGE));
			v.push_back(c_TagLabelPair(_Literalsz("cdoSR_LANGUAGE_MISMATCH"), cdoSR_LANGUAGE_MISMATCH));
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_READ_WRITE_CARD"), cdoOP_READ_WRITE_CARD));
			// Background commands extension
			v.push_back(c_TagLabelPair(_Literalsz("cdoSA_iPOS_B"), cdoSA_iPOS_B));
			v.push_back(c_TagLabelPair(_Literalsz("cdoiPOS_SA_B"), cdoiPOS_SA_B));
			v.push_back(c_TagLabelPair(_Literalsz("cdoOP_CASH_ADVANCE"), cdoOP_CASH_ADVANCE));
			// TODO 070529 - Define message type 'a' = Command ack
			return v;
		}

		// ============================ (END) TagConst =================================
		// ============================ class iPosHelperMethods =================================

		int iPosHelperMethods::getSevenBitValue(const t_byte byte) {
			return byte & 0x7F;
		}

		int iPosHelperMethods::toInt(const t_byte mostSignificant, const t_byte middle, const t_byte leastSignificant) {
			int intval = mostSignificant << 16;
			intval += middle << 8;
			intval += leastSignificant;
			return intval;
		}

		c_BertlvByteVector iPosHelperMethods::stringToBytes(const c_DataRepresentationFramework::c_ISO_8859_1_String & value) {
			c_BertlvByteVector ret;
			c_DataRepresentationFramework::c_ISO_8859_1_String::const_iterator i;
			for (i = value.begin(); i != value.end(); i++) {
				ret.push_back(*i);
			}
			return ret;
		}

		c_DataRepresentationFramework::c_ISO_8859_1_String iPosHelperMethods::bytesToString(const c_BertlvByteVector & value) {
			//    c_DataRepresentationFramework::c_ISO_8859_1_String ret("");
			//    c_BertlvByteVector::const_iterator i;
			//    for (i = value.begin(); i != value.end(); i++) {
			//        ret += * i;
			//    }
			//    return ret;
			return c_DataRepresentationFramework::createString(value);
		}

		c_BertlvByteVector iPosHelperMethods::toA(const t_byte value) {
			c_BertlvByteVector ret;
			ret.push_back(value);
			return ret;
		}

		c_BertlvByteVector iPosHelperMethods::toAN(const c_DataRepresentationFramework::c_ISO_8859_1_String & value) {
			return iPosHelperMethods::stringToBytes(value);
		}

		c_BertlvByteVector iPosHelperMethods::toAN(const int value) {
			//	char data[50];
			//	itoa(value, data, 10);
			//	return iPosHelperMethods::stringToBytes(data);
			c_DataRepresentationFramework::c_ISO_8859_1_String sValue(c_DataRepresentationFramework::intToDecimalString(value));
			return iPosHelperMethods::stringToBytes(sValue);
		}

		c_BertlvByteVector iPosHelperMethods::toANS(const c_DataRepresentationFramework::c_ISO_8859_1_String & value) {
			return iPosHelperMethods::stringToBytes(value);
		}

		c_BertlvByteVector iPosHelperMethods::toBool(const bool value) {
			c_BertlvByteVector ret;
			if (value) {
				ret.push_back(0xFF);
			}
			else {
				ret.push_back(0x00);
			}
			return ret;
		}

		c_BertlvByteVector iPosHelperMethods::toCN(const c_DataRepresentationFramework::c_ISO_8859_1_String & value, const int nbrOfBytes) {
			c_BertlvByteVector ret;
			bool done = false;
			unsigned int i = 0;
			while (!done) {
				if (i >= value.length()) {
					done = true;
				}
				else if ((int)ret.size() >= nbrOfBytes) {
					LOG_DESIGN_INSUFFICIENCY_II(_Asciisz("iPosHelperMethods::toCN failed. ret.size()=%d Exceeds nbrOfBytes=%d"), ret.size(), nbrOfBytes);
					done = true;
				}
				else {
					int byte;
					int highbyte = atoi(value.substr(i, 1).c_str()) * 0x10;
					int lowbyte = 0x0f;
					if ((i + 1) < value.length()) {
						lowbyte = atoi(value.substr(i + 1, 1).c_str());
					}
					byte = (int)(highbyte + lowbyte);
					ret.push_back(byte);
					i += 2;
				}
			}
			int rest = nbrOfBytes - (int)ret.size();
			for (int i = 0; i < rest; i++) {
				ret.push_back(0xFF);
			}
			return ret;
		}

		c_BertlvByteVector iPosHelperMethods::toN(const c_DataRepresentationFramework::c_ISO_8859_1_String & value) {
			return iPosHelperMethods::stringToBytes(value);
		}

		char iPosHelperMethods::aToChar(const t_byte value) {
			return (char)value;
		}

		c_DataRepresentationFramework::c_ISO_8859_1_String iPosHelperMethods::anToString(const c_BertlvByteVector & value) {
			return iPosHelperMethods::bytesToString(value);
		}

		long iPosHelperMethods::anToLong(const c_BertlvByteVector & value) {
			long ret = 0;
			c_BertlvByteVector::const_iterator i;
			for (i = value.begin(); i != value.end() && isdigit(*i); i++) {
				ret *= 10;
				ret += (*i - '0');
			}
			return ret;
			// return iPosHelperMethods::bytesToString(value);
		}

		c_DataRepresentationFramework::c_AsciiString iPosHelperMethods::nToString(const c_BertlvByteVector & value) {
			return c_DataRepresentationFramework::c_AsciiString(c_DataRepresentationFramework::anonymous(iPosHelperMethods::bytesToString(value)));
		}

		c_DataRepresentationFramework::c_ISO_8859_1_String iPosHelperMethods::ansToString(const c_BertlvByteVector & value) {
			return iPosHelperMethods::bytesToString(value);
		}

		bool iPosHelperMethods::toBool(const t_byte value) {
			bool ret;
			if (value == 0xFF) {
				ret = true;
			}
			else if (value == 0x00) {
				ret = false;
			}
			else {
				// todo
				// throw exception("fel indata: " + value);
			}
			return ret;
		}

		c_DataRepresentationFramework::c_AsciiString iPosHelperMethods::compressed_bToString(const c_BertlvByteVector & value) {
			return c_DataRepresentationFramework::createHexNibbleString(value);
		}

		long iPosHelperMethods::cnToLong(const c_BertlvByteVector & value) {
			long retval = 0;
			bool done = false;
			for (unsigned int i = 0; i < value.size() && !done; i++) {
				int highval = (value[i] & 0xF0) / 0x10;
				int lowval = value[i] & 0x0F;
				if (highval == 0xF) {
					done = true;
				}
				else {
					retval *= 10;
					retval += highval;
				}
				if (lowval == 0xF) {
					done = true;
				}
				else {
					retval *= 10;
					retval += lowval;
				}
			}
			return retval;
		}

		c_DataRepresentationFramework::c_AsciiString iPosHelperMethods::cnToString(const c_BertlvByteVector & value) {
			c_DataRepresentationFramework::c_AsciiString ret;
			bool done = false;
			for (unsigned int i = 0; i < value.size() && !done; i++) {
				int highval = (value[i] & 0xF0) / 0x10;
				int lowval = value[i] & 0x0F;
				char data[2];
				if (highval == 0xF) {
					done = true;
				}
				else {
					itoa(highval, data, 10);
					ret.push_back(data[0]);
				}
				if (lowval == 0xF) {
					done = true;
				}
				else {
					itoa(lowval, data, 10);
					ret.push_back(data[0]);
				}
			}
			return ret;
		}

		c_DataRepresentationFramework::c_AsciiString iPosHelperMethods::toN(const c_BertlvByteVector & value) {
			return c_DataRepresentationFramework::c_AsciiString(c_DataRepresentationFramework::anonymous(iPosHelperMethods::bytesToString(value)));
		}

		c_BertlvByteVector iPosHelperMethods::toNb(const c_DataRepresentationFramework::c_ISO_8859_1_String & value, int len) {
			c_BertlvByteVector ret;
			int nbrofleadingZeroes = len - (int)value.length();
			for (int i = 0; i < nbrofleadingZeroes; i++) {
				ret.push_back('0');
			}
			for (int i = 0; i < (int)value.length(); i++) {
				ret.push_back(value[i]);
			}
			return ret;
		}

		c_BertlvByteVector iPosHelperMethods::toBinaryZeroNb(const int len) {
			c_BertlvByteVector ret;
			for (int i = 0; i < len; i++) {
				ret.push_back(0x00);
			}
			return ret;
		}

		c_DataRepresentationFramework::c_AsciiString iPosHelperMethods::toNb(const c_BertlvByteVector & value) {
			return c_DataRepresentationFramework::c_AsciiString(c_DataRepresentationFramework::anonymous(iPosHelperMethods::bytesToString(value)));
		}

		c_BertlvByteVector iPosHelperMethods::toByteVector(const int value) {
			c_BertlvByteVector ret;
			bool done = false;
			int bval = value;
			while (!done) {
				// e.g.
				// bval = 0xDDFF -> div = DD, mod = FF
				// put mod first in the std::vector
				int div = bval / 0x100;
				int mod = bval % 0x100;
				ret.insert(ret.begin(), mod);
				if (div > 0) {
					// if more bytes -> divide further on by 0x100
					bval = bval / 0x100;
				}
				else {
					// no more bytes
					done = true;
				}
			}
			return ret;
		}

		std::vector < t_TagValue > iPosHelperMethods::extractTagList(const c_BertlvByteVector & tagList) {
			std::vector < t_TagValue > tagValues;
			unsigned int offset = 0;
			while (offset < tagList.size()) {
				int bytesRead;
				t_TagValue tot = static_cast<t_TagValue>(0);
				int first = tagList[offset + 0];
				bytesRead = 1;
				int bit5to1 = first & 0x1F;
				// Check if bit 5 -> bit 1 is in <= 30 or > 30
				if (bit5to1 <= 30) {
					// it's a tag included in a single octet
					tot = static_cast<t_TagValue>(first);
				}
				else {
					// it's a tag included in more than one octet
					bool done = false;
					// initialize tot to the value of the first byte,
					// start the loop at the second byte
					tot = static_cast<t_TagValue>(first);
					int index = 1;
					// Read until bit 8 is 0
					while (!done) {
						t_TagValue val = static_cast<t_TagValue>(tagList[offset + index]);
						tot = static_cast<t_TagValue>(tot * 0x100 + val);
						if (bertlv::BerTlvHelperMethods::isSet(val, 8)) {
							// continue with next byte
							index++;
						}
						else {
							// the last byte
							done = true;
						}
					}
					bytesRead += index;
				}
				tagValues.push_back(tot);
				offset += bytesRead;
			}
			return tagValues;
		}

		// ============================ (END) iPosHelperMethods =================================

		/**
		* Returns a formatted c_DataRepresentationFramework::c_ISO_8859_1_String of provided primitive content
		*/
		c_DataRepresentationFramework::c_ISO_8859_1_String ContentMaskedFormatter::toString(const BerTlvPrimitiveContent * const content, const c_DataRepresentationFramework::c_ISO_8859_1_String& sIndent) {
			c_DataRepresentationFramework::c_ISO_8859_1_String result("#discretionary data. intentionally not shown#");
			return result;
		}

		/**
		* Returns a formatted c_DataRepresentationFramework::c_ISO_8859_1_String of provided primitive content
		*/
		c_DataRepresentationFramework::c_ISO_8859_1_String HexNibblePairContentsFormatter::toString(const BerTlvPrimitiveContent * const pContent, const c_DataRepresentationFramework::c_ISO_8859_1_String& sIndent) {
			c_DataRepresentationFramework::c_ISO_8859_1_String result("0x");
			result += c_DataRepresentationFramework::createHexNibbleString(pContent->byteVector());
			return result;
		}

		//---------------------------------------------------------------------------
		/**
		* Constructor
		*/
		c_StructContentsFieldDefinition::c_StructContentsFieldDefinition(c_DataRepresentationFramework::c_ISO_8859_1_String sCaption, int fieldSizeInBytes)
			: m_sCaption(sCaption)
			, m_FieldSizeInBytes(fieldSizeInBytes)
		{
		}

		/**
		* Copy constructor
		*/
		c_StructContentsFieldDefinition::c_StructContentsFieldDefinition(const c_StructContentsFieldDefinition& other_instance)
		{
			// Use assignment perator
			*this = other_instance;
		}

		/**
		* Assignment operator
		*/
		c_StructContentsFieldDefinition& c_StructContentsFieldDefinition::operator=(const c_StructContentsFieldDefinition& other_instance) {
			this->m_sCaption = other_instance.m_sCaption;
			this->m_FieldSizeInBytes = other_instance.m_FieldSizeInBytes;
			return *this;
		}

		/**
		* Returns this field caption
		*/
		c_DataRepresentationFramework::c_ISO_8859_1_String c_StructContentsFieldDefinition::Caption() {
			return this->m_sCaption;
		}

		/**
		* Returns the size in bytes of this field
		*/
		int c_StructContentsFieldDefinition::getFieldSizeInBytes() {
			return this->m_FieldSizeInBytes;
		}

		//---------------------------------------------------------------------------

		/**
		* Creates a structure contents formatter using the provided
		* structure definition.
		*/
		StructContentsFormatter::StructContentsFormatter(const c_StructContentsDefinition& structContentsDefinition)
			: m_StructContentsDefinition(structContentsDefinition)
		{
		}

		/**
		* Assignment operator
		*/
		StructContentsFormatter& StructContentsFormatter::operator=(const StructContentsFormatter& other_instance) {
			this->m_StructContentsDefinition = other_instance.m_StructContentsDefinition;
			return *this;
		}

		/**
		* Returns a formatted c_DataRepresentationFramework::c_ISO_8859_1_String of provided primitive content
		*/
		c_DataRepresentationFramework::c_ISO_8859_1_String StructContentsFormatter::toString(const BerTlvPrimitiveContent * const content, const c_DataRepresentationFramework::c_ISO_8859_1_String& sIndent) {
			c_DataRepresentationFramework::c_ISO_8859_1_String sRaw_Content = iPosHelperMethods::bytesToString(content->byteVector());

			c_DataRepresentationFramework::c_ISO_8859_1_String result = sRaw_Content;
			c_DataRepresentationFramework::c_ISO_8859_1_String sOurIndent = sIndent;
			c_DataRepresentationFramework::anonymous(sOurIndent) += "\t";

			c_DataRepresentationFramework::anonymous(result) += "\n";
			result += sOurIndent;

			// Loop through fields of struct and format data from content accordingly
			std::vector<c_StructContentsFieldDefinition>::iterator iter = this->m_StructContentsDefinition.begin();
			c_DataRepresentationFramework::c_ISO_8859_1_String::iterator content_iter = sRaw_Content.begin();
			bool structDidNotFitInInputData = false;
			while (iter != this->m_StructContentsDefinition.end()) {
				result += iter->Caption();
				c_DataRepresentationFramework::anonymous(result) += ":\t";
				for (int i = 0; i < iter->getFieldSizeInBytes(); i++) {
					if (content_iter != sRaw_Content.end()) {
						c_DataRepresentationFramework::anonymous(result) += *content_iter;
						content_iter++;
					}
					else {
						// Error. The contents does not contain the complete field!
						structDidNotFitInInputData = true;
						c_DataRepresentationFramework::anonymous(result) += "...#end of input error!#";
						break;
					}
				}
				iter++;
				if (iter != this->m_StructContentsDefinition.end()) {
					c_DataRepresentationFramework::anonymous(result) += "\n"; // separate with new line
					result += sOurIndent;
				}
			}
			if (structDidNotFitInInputData) {
				c_DataRepresentationFramework::anonymous(result) += "\nError=Input data to small to contain expected structure!";
				c_DataRepresentationFramework::anonymous(result) += "\nCheck data provider or test tool design for errors";
			}
			return result;
		};

		//---------------------------------------------------------------------------

	} // namespace ipos
}