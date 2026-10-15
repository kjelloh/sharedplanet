//---------------------------------------------------------------------------


#pragma hdrstop

#include "UKPTFramework.h"
#include "BusinessLogUnit.h"
//#include "t8_pin.h" // ukpt_curr_key_d(struct UKPT *u)

//---------------------------------------------------------------------------

#pragma package(smart_init)

/**
  * Namespace containing the UKPT framework
  */
namespace ukpt_fw {

	/**
	  * Creates a derivation key representation given provided
	  * derivation key given in hex nobble pair string.
	  * See Use c_DataRepresentationFramework::parseHexNibblePairString() to
	  * for defintion of hex nibble pair string.
	  */
	c_UKPTDerivationKey::c_UKPTDerivationKey(const c_DataRepresentationFramework::c_AsciiString& sHexNibblePairDerivationKey)
		: m_sHexNibblePairDerivationKey(sHexNibblePairDerivationKey)
	{

	}

	/**
	  * Returns the key represented as a hex nibble pair string.
	  */
	c_DataRepresentationFramework::c_AsciiString c_UKPTDerivationKey::getHexNibblePairString() {
		return m_sHexNibblePairDerivationKey;
	}

	/**
	  * Returns the key in raw format.
	  */
	c_UkptRawData c_UKPTDerivationKey::getRaw() {
		c_UkptRawData result;
		try {
			result = c_DataRepresentationFramework::parseHexNibblePairString(m_sHexNibblePairDerivationKey);
		} catch (std::exception& e) {
			c_LogString sMessage = _Asciisz("c_UKPTDerivationKey::getRaw failed for key=\"");
			sMessage += m_sHexNibblePairDerivationKey;
			sMessage += _Asciisz("\". Excpetion = ");
			sMessage += _UTF8sz(e.what());
			LOG_DESIGN_INSUFFICIENCY(sMessage);
		}
		catch (...) {
			c_LogString sMessage = _Asciisz("c_UKPTDerivationKey::getRaw failed for key=\"");
			sMessage += m_sHexNibblePairDerivationKey;
			sMessage += _Asciisz("\". Excpetion (...)");
			LOG_DESIGN_INSUFFICIENCY(sMessage);
		}
		return result;
	}

	/**
	  * Constructs an UKPT session using provided derivation key.
	  * The derivation key defines the chryptografiz "zone" for
	  * this UKTP session
	  */
	c_AbstractUKPTSession::c_AbstractUKPTSession(const c_UKPTDerivationKey& derivation_key)
		: m_derivation_key(derivation_key)
	{

	}

	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------

	/**
	  * Consructs a KSN from provided hex nobbel pair KSN string.
	  * See Use c_DataRepresentationFramework::parseHexNibblePairString() to
	  * for defintion of hex nibble pair string.
	  */
	c_KSN::c_KSN(const c_DataRepresentationFramework::c_AsciiString& sHexNibblePairKSN)
		: m_sHexNibblePairKSN(sHexNibblePairKSN)
	{
	}

	/**
	  * Returns the key represented as a hex nibble pair string.
	  */
	c_DataRepresentationFramework::c_AsciiString c_KSN::getHexNibblePairString() {
		return m_sHexNibblePairKSN;
	}

	/**
	  * Returns the key in raw format.
	  */
	c_UkptRawData c_KSN::getRaw() {
		c_UkptRawData result;
		try {
			result = c_DataRepresentationFramework::parseHexNibblePairString(m_sHexNibblePairKSN);
		} catch (std::exception& e) {
			c_LogString sMessage = _Asciisz("c_AbstractUKPTSession::getRaw failed for KSN=\"");
			sMessage += m_sHexNibblePairKSN;
			sMessage += _Asciisz("\". Excpetion = ");
			sMessage += _UTF8sz(e.what());
			LOG_DESIGN_INSUFFICIENCY(sMessage);
		}
		catch (...) {
			c_LogString sMessage = _Asciisz("c_AbstractUKPTSession::getRaw failed for KSN\"");
			sMessage += m_sHexNibblePairKSN;
			sMessage += c_LogString("\". Excpetion (...)");
			LOG_DESIGN_INSUFFICIENCY(sMessage);
		}
		return result;

	}

	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	/**
	  * Constructs a MAC data instance
	  */
	c_MACData::c_MACData(int nrOfData)
		: m_HexNibblePAirDataArray(nrOfData)
	{

	}

	/**
	  * Copy constructor
	  */
	c_MACData::c_MACData(const c_MACData& other_value)
		: m_HexNibblePAirDataArray(3)
	{
		*this = other_value; // USe asignment operator
	}

	/**
	  * Assigment operator
	  */
	c_MACData& c_MACData::operator=(const c_MACData& other_value) {
		this->m_HexNibblePAirDataArray = other_value.m_HexNibblePAirDataArray;
		return *this;
	}

	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	/**
	  * Creates a single key MAC data instance
	  */
	c_SingleKeyMACData::c_SingleKeyMACData()
		: c_MACData(3)
	{

	}

	/**
	  * Copy constructor
	  */
	c_SingleKeyMACData::c_SingleKeyMACData(const c_SingleKeyMACData& other_value)
		: c_MACData(3)
	{
		*this = other_value; // Use asugment operator
	}

	/**
	  * Assignment operator
	  */
	c_SingleKeyMACData& c_SingleKeyMACData::operator=(const c_SingleKeyMACData& other_value) {
		c_MACData::operator=(other_value);
		return *this;
	}

	/**
	  * Returns accessor to MAC1 data in Hex nibble format
	  */
	c_DataRepresentationFramework::c_AsciiString& c_SingleKeyMACData::MAC1HexNibbleStringData() {
		return this->m_HexNibblePAirDataArray[0];
	}

	/**
	  * Returns accessor to MAC1 data in Hex nibble format
	  */
	c_DataRepresentationFramework::c_AsciiString& c_SingleKeyMACData::MAC2HexNibbleStringData() {
		return this->m_HexNibblePAirDataArray[1];

	}

	/**
	  * Returns accessor to MAC1 data in Hex nibble format
	  */
	c_DataRepresentationFramework::c_AsciiString& c_SingleKeyMACData::MAC3HexNibbleStringData() {
		return this->m_HexNibblePAirDataArray[2];
	}

	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	/**
	  * Constructs a double key MAC value instance
	  */
	c_DoubleKeyMACData::c_DoubleKeyMACData()
		: c_MACData(1)
	{

	}

	/**
	  * Copy constructor
	  */
	c_DoubleKeyMACData::c_DoubleKeyMACData(const c_DoubleKeyMACData& other_value)
		: c_MACData(1)
	{
    *this = other_value;
	}

	/**
	  * Asignment operator
	  */
	c_DoubleKeyMACData& c_DoubleKeyMACData::operator=(const c_DoubleKeyMACData& other_value) {
		c_MACData::operator=(other_value);
		return *this;
	}

	/**
	  * Returns an accessor to Data to MAC
	  */
	c_DataRepresentationFramework::c_AsciiString& c_DoubleKeyMACData::MACHexNibbleStringData() {
		return this->m_HexNibblePAirDataArray[0];
	}

	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------

	/**
	  * Constructs a MAC value from provided MAC value represented as
	  * an Hex nibble string.
	  */
	c_MACValue::c_MACValue(const c_DataRepresentationFramework::c_AsciiString& sMACHexNibbleString) {
		LOG_NOT_IMPLEMENTED;
	}

	/**
	  * Copy constructor
	  */
	c_MACValue::c_MACValue(const c_MACValue& other_value) {
		LOG_NOT_IMPLEMENTED;
	}

	/**
	  * Returns the MAC represented as a hex nibble pair string.
	  */
	c_DataRepresentationFramework::c_AsciiString c_MACValue::getHexNibblePairString() {
		c_DataRepresentationFramework::c_AsciiString result;
		LOG_NOT_IMPLEMENTED;
		return result;
	}

	/**
	  * Returns the MAC in raw format.
	  */
	c_UkptRawData c_MACValue::getRaw() {
		c_UkptRawData result;
		LOG_NOT_IMPLEMENTED;
		return result;
	}

	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------

	/**
	  * Default constructor creating a container with empty MAC values
	  */
	c_MACValues::c_MACValues(int nrOfValues)
		: std::vector<c_MACValue>(nrOfValues)
	{
		LOG_NOT_IMPLEMENTED;
	}

	/**
	  * Copy constructor
	  */
	c_MACValues::c_MACValues(const c_MACValues& other_value)
	{
		LOG_NOT_IMPLEMENTED;
	}

	/**
	  * Asignment operator
	  */
	c_MACValues& c_MACValues::operator=(const c_MACValues& other_value) {
		LOG_NOT_IMPLEMENTED;
		return *this;
	}

	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------

	/**
	  * Constructs an UKPT session using provided derivation key.
	  * The derivation key defines the chryptografiz "zone" for
	  * this UKTP session
	  */
	c_SingleKeyUKPTSession::c_SingleKeyUKPTSession(const c_UKPTDerivationKey& derivation_key)
		: c_AbstractUKPTSession(derivation_key)
	{

	}

	/**
	  * Returns a set of MACs (MAC1 .. MAC3) using provided MAC data
	  */
	c_MACValues c_SingleKeyUKPTSession::calculateMACs(c_SingleKeyMACData& mac_data,const c_KSN& cksn) {
		c_MACValues result(3);
		c_LogString sMessage = _Asciisz("c_SingleKeyUKPTSession::calculateMACs called with MAC values ");
		sMessage += mac_data.MAC1HexNibbleStringData();
		sMessage += _Asciic(',');
		sMessage += mac_data.MAC2HexNibbleStringData();
		sMessage += _Asciic(',');
		sMessage += mac_data.MAC3HexNibbleStringData();
		LOG_DEVELOPMENT_TRACE(sMessage);

// TEST
//unsigned char local_mac_data[33];
//if (mac_data.MAC1HexNibbleStringData().length()==32) {
//	strcpy(local_mac_data,mac_data.MAC1HexNibbleStringData().c_str());
//}
//else {
//	local_mac_data[0] = '\0';
//	c_LogString sMessage = _Asciisz("c_SingleKeyUKPTSession::calculateMACs failed. To short MAC data = ");
//	sMessage += mac_data.MAC1HexNibbleStringData();
//	LOG_DESIGN_INSUFFICIENCY(sMessage);
//}

// TODO 080204, fill ukpt struct with input values for single key MAC calculation
/*
UKPT ukpt;
   unsigned char cksn[20];  // Input, CKSN value
   unsigned char dk[32];    // Input, Derivation key
*/
//ukpt.type = 'S'; // Single key
//ukpt.mac_data = local_mac_data;
// int call_result = ukpt_curr_key(&ukpt);

		LOG_DESIGN_INSUFFICIENCY(_UTF8sz("c_SingleKeyUKPTSession::calculateMACs failed. Not implemented"));

		sMessage = _Asciisz("c_SingleKeyUKPTSession::calculateMACs returns MAC values ");
		sMessage += result[0].getHexNibblePairString();
		sMessage += _Asciic(',');
		sMessage += result[1].getHexNibblePairString();
		sMessage += _Asciic(',');
		sMessage += result[2].getHexNibblePairString();
		LOG_DEVELOPMENT_TRACE(sMessage);

		return result;
	}

	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------

	/**
	  * Constructs an UKPT session using provided derivation key.
	  * The derivation key defines the chryptografiz "zone" for
	  * this UKTP session
	  */
	c_DoubleKeyUKPTSession::c_DoubleKeyUKPTSession(const c_UKPTDerivationKey& derivation_key)
		: c_AbstractUKPTSession(derivation_key)
	{

	}

	/**
	  * Returns a set of MAC using provided MAC data
	  */
	c_MACValue c_DoubleKeyUKPTSession::calculateMAC(c_DoubleKeyMACData& mac_data,const c_KSN& cksn) {
		//                   12345678901234567890
		c_MACValue result;
		c_LogString sMessage = _UTF8sz("c_DoubleKeyUKPTSession::calculateMAC called with MAC value ");
		sMessage += mac_data.MACHexNibbleStringData();
		LOG_DEVELOPMENT_TRACE(sMessage);

		LOG_NOT_IMPLEMENTED;

		sMessage = _UTF8sz("c_DoubleKeyUKPTSession::calculateMAC returns MAC value ");
		sMessage += result.getHexNibblePairString();
		LOG_DEVELOPMENT_TRACE(sMessage);

		return result;

	}



	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------

	/**
	  * Retutnr this singleton, creating the instance if it does not yet exist
	  */
	c_SingleKeyUKPTSessionFactory* c_SingleKeyUKPTSessionFactory::instance() {
		if (m_instance == NULL) {
			m_instance = new c_SingleKeyUKPTSessionFactory();
		}
		return m_instance;
	}

	/**
	  * Creates a new UKPT session using provided derivation key.
	  */
	c_SingleKeyUKPTSession* c_SingleKeyUKPTSessionFactory::createUKPTSession(const c_UKPTDerivationKey& derivation_key) {
		c_SingleKeyUKPTSession* result = NULL;
		result = new c_SingleKeyUKPTSession(derivation_key);
		return result;
	}

	/**
	  * Private constructor of this singleton
	  */
	c_SingleKeyUKPTSessionFactory::c_SingleKeyUKPTSessionFactory() {

	}

	/**
	  * Private static storage of this singleton
	  */
	c_SingleKeyUKPTSessionFactory* c_SingleKeyUKPTSessionFactory::m_instance = NULL;

	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------

	/**
	  * Retutnr this singleton, creating the instance if it does not yet exist
	  */
	c_DoubleKeyUKPTSessionFactory* c_DoubleKeyUKPTSessionFactory::instance() {
		if (m_instance == NULL) {
			m_instance = new c_DoubleKeyUKPTSessionFactory();
		}
		return m_instance;
	}

	/**
	  * Creates a new UKPT session using provided derivation key.
	  */
	c_DoubleKeyUKPTSession* c_DoubleKeyUKPTSessionFactory::createUKPTSession(const c_UKPTDerivationKey& derivation_key) {
		c_DoubleKeyUKPTSession* result = NULL;
		result = new c_DoubleKeyUKPTSession(derivation_key);
		return result;
	}

	/**
	  * Private constructor of this singleton
	  */
	c_DoubleKeyUKPTSessionFactory::c_DoubleKeyUKPTSessionFactory() {

	}

	/**
	  * Priate static storage of this singleton
	  */
	c_DoubleKeyUKPTSessionFactory* c_DoubleKeyUKPTSessionFactory::m_instance = NULL;


}
