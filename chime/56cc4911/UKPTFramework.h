//---------------------------------------------------------------------------

#ifndef UKPTFrameworkH
#define UKPTFrameworkH
//---------------------------------------------------------------------------

#include <string>
#include <vector>
#include "DataRepresentationFrameWork.h"

//---------------------------------------------------------------------------

/**
  * Namespace cotaining the UKPT framework
  */
namespace ukpt_fw {

	/**
	  * Typedef of raw data used in UKPT framework
	  */
	typedef std::vector<unsigned char> c_UkptRawData;

	/**
	  * Represents a derviation key used to derive current PIN key and MAC key
	  * in a UKPT session
	  */
	class c_UKPTDerivationKey {
	public:
		/**
		  * Creates a derivation key representation given provided
		  * derivation key given in hex nobble pair string.
		  * See Use c_DataRepresentationFramework::parseHexNibblePairString() to
		  * for defintion of hex nibble pair string.
		  */
		c_UKPTDerivationKey(const c_DataRepresentationFramework::c_AsciiString& sHexNibblePairDerivationKey);

		/**
		  * Returns the key represented as a hex nibble pair string.
		  */
		c_DataRepresentationFramework::c_AsciiString getHexNibblePairString();

		/**
		  * Returns the key in raw format.
		  */
		c_UkptRawData getRaw();

	private:
		/**
		  * Private storage of this key in hex nibble pair representation
		  */
		c_DataRepresentationFramework::c_AsciiString m_sHexNibblePairDerivationKey;
	};

	/**
	  * Models a KSN (key serial number). May be used
	  * for CKSN (Current key serial number), IKSN (Initial key serial number) etc.
	  */
	class c_KSN {
	public:
		/**
		  * Consructs a KSN from provided hex nobbel pair KSN string.
		  * See Use c_DataRepresentationFramework::parseHexNibblePairString() to
		  * for defintion of hex nibble pair string.
		  */
		c_KSN(const c_DataRepresentationFramework::c_AsciiString& sHexNibblePairKSN);

		/**
		  * Returns the key represented as a hex nibble pair string.
		  */
		c_DataRepresentationFramework::c_AsciiString getHexNibblePairString();

		/**
		  * Returns the key in raw format.
		  */
		c_UkptRawData getRaw();

	private:
		/**
		  * Private storage of this KSN represented as a hex nibble pair string
		  */
		c_DataRepresentationFramework::c_AsciiString m_sHexNibblePairKSN;
	};

	/**
	  * Models all data needed to calculate MAC1 .. MAC3 for single key UKPT scheeme.
	  */
	class c_MACData  {
	public:
		// TODO 080131/KoH: Define contents from consulting Per Lundgren at BABS or
		// other authority or source.
		// Spring 2008. Fixed :-).

		/**
		  * Constructs a MAC data instance
		  */
		c_MACData(int nrOfData = 3);

		/**
		  * Copy constructor
		  */
		c_MACData(const c_MACData& other_value);

		/**
		  * Assigment operator
		  */
		c_MACData& operator=(const c_MACData& other_value);

	protected:
		/**
		  * Private storage of hex nibble strings
		  * mapped by this class to psecific usage through setters and getters
		  */
		std::vector<c_DataRepresentationFramework::c_AsciiString> m_HexNibblePAirDataArray;
	};

	class c_SingleKeyMACData : public c_MACData {
	public:
		/**
		  * Creates a single key MAC data instance
		  */
		c_SingleKeyMACData();

		/**
		  * Copy constructor
		  */
		c_SingleKeyMACData(const c_SingleKeyMACData& other_value);

		/**
		  * Assignment operator
		  */
		c_SingleKeyMACData& operator=(const c_SingleKeyMACData& other_value);

		/**
		  * Returns accessor to MAC1 data in Hex nibble format
		  */
		c_DataRepresentationFramework::c_AsciiString& MAC1HexNibbleStringData();

		/**
		  * Returns accessor to MAC1 data in Hex nibble format
		  */
		c_DataRepresentationFramework::c_AsciiString& MAC2HexNibbleStringData();

		/**
		  * Returns accessor to MAC1 data in Hex nibble format
		  */
		c_DataRepresentationFramework::c_AsciiString& MAC3HexNibbleStringData();

	private:
	};

	class c_DoubleKeyMACData : public c_MACData {
	public:
		/**
		  * Constructs a double key MAC value instance
		  */
		c_DoubleKeyMACData();

		/**
		  * Copy constructor
		  */
		c_DoubleKeyMACData(const c_DoubleKeyMACData& other_value);

		/**
		  * Asignment operator
		  */
		c_DoubleKeyMACData& operator=(const c_DoubleKeyMACData& other_value);

		/**
		  * Returns an accessor to Data to MAC
		  */
		c_DataRepresentationFramework::c_AsciiString& MACHexNibbleStringData();

	private:
	};


	/**
	  * Helper class to hold one MAC value
	  */
	class c_MACValue : public c_DataRepresentationFramework::c_AsciiString {
	public:
		/**
		  * Constructs a MAC value from provided MAC value represented as
		  * an Hex nibble string.
		  */
		c_MACValue(const c_DataRepresentationFramework::c_AsciiString& sMACHexNibbleString = _Asciisz("00000000000000000000"));

		/**
		  * Copy constructor
		  */
		c_MACValue(const c_MACValue& other_value);

		/**
		  * Returns the MAC represented as a hex nibble pair string.
		  */
		c_DataRepresentationFramework::c_AsciiString getHexNibblePairString();

		/**
		  * Returns the MAC in raw format.
		  */
		c_UkptRawData getRaw();

	private:
	};

	/**
	  * Helper class taht holds MAC1 (Request), MAC2 (OK Respponse) and MAC3 (Failed Resposne)
	  * values to enable storage of these values by for example SPDH router
	  * from request to respons to enable calculating correct MAC of a modified
	  * SPDH respnse back to Client.
	  */
	class c_MACValues : public std::vector<c_MACValue> {
	public:
		/**
		  * Default constructor creating a container with empty MAC values
		  */
		c_MACValues(int nrOfValues);

		/**
		  * Copy constructor
		  */
		c_MACValues(const c_MACValues& other_value);

		/**
		  * Asignment operator
		  */
		c_MACValues& operator=(const c_MACValues& other_value);

		typedef std::vector<c_MACValue>::iterator iterator;

	private:

	};

	/**
	  * Base class of an UKPT session generating a unique key per transaction
	  * defined by current KSN (Key serial number).
	  */
	class c_AbstractUKPTSession {
	public:
		/**
		  * Constructs an UKPT session using provided derivation key.
		  * The derivation key defines the chryptografiz "zone" for
		  * this UKTP session
		  */
		c_AbstractUKPTSession(const c_UKPTDerivationKey& derivation_key);

	protected:
		/**
		  * Private storage of this session derivation key
		  */
		const c_UKPTDerivationKey m_derivation_key;

	private:

	};

	/**
	  * Models an UKPT session generating a unique key per transaction
	  * defined by current KSN (Key serial number).
	  */
	class c_SingleKeyUKPTSession : public c_AbstractUKPTSession {
	public:
		/**
		  * Constructs an UKPT session using provided derivation key.
		  * The derivation key defines the chryptografiz "zone" for
		  * this UKTP session
		  */
		c_SingleKeyUKPTSession(const c_UKPTDerivationKey& derivation_key);

		/**
		  * Returns a set of MACs (MAC1 .. MAC3) using provided MAC data
		  */
		c_MACValues calculateMACs(c_SingleKeyMACData& mac_data,const c_KSN& cksn);

	private:
	};

	/**
	  * Models an UKPT session generating a unique key per transaction
	  * defined by current KSN (Key serial number).
	  * Implements double keys UKPT session
	  */
	class c_DoubleKeyUKPTSession : public c_AbstractUKPTSession {
	public:
		/**
		  * Constructs an UKPT session using provided derivation key.
		  * The derivation key defines the chryptografiz "zone" for
		  * this UKTP session
		  */
		c_DoubleKeyUKPTSession(const c_UKPTDerivationKey& derivation_key);

		/**
		  * Returns a set of MAC using provided MAC data
		  */
		c_MACValue calculateMAC(c_DoubleKeyMACData& mac_data,const c_KSN& cksn);

	private:

	};

	/**
	  * Factory singleton that creates new instances of UKPT session to
	  * be used to process UKPT artefacts like PIN blocks, MAC blocks etc.
	  * WIll produce single key length UKPT sessions
	  */
	class c_SingleKeyUKPTSessionFactory {
	public:
		/**
		  * Retutnr this singleton, creating the instance if it does not yet exist
		  */
		static c_SingleKeyUKPTSessionFactory* instance();

		/**
		  * Creates a new UKPT session using provided derivation key.
		  */
		c_SingleKeyUKPTSession* createUKPTSession(const c_UKPTDerivationKey& derivation_key);

	private:
		/**
		  * Private constructor of this singleton
		  */
		c_SingleKeyUKPTSessionFactory();

		/**
		  * Priate static storage of this singleton
		  */
		static c_SingleKeyUKPTSessionFactory* m_instance;
	};


	/**
	  * Factory singleton that creates new instances of UKPT session to
	  * be used to process UKPT artefacts like PIN blocks, MAC blocks etc.
	  * WIll produce double key length UKPT sessions
	  */
	class c_DoubleKeyUKPTSessionFactory {
	public:
		/**
		  * Retutnr this singleton, creating the instance if it does not yet exist
		  */
		static c_DoubleKeyUKPTSessionFactory* instance();

		/**
		  * Creates a new UKPT session using provided derivation key.
		  */
		c_DoubleKeyUKPTSession* createUKPTSession(const c_UKPTDerivationKey& derivation_key);

	private:
		/**
		  * Private constructor of this singleton
		  */
		c_DoubleKeyUKPTSessionFactory();

		/**
		  * Priate static storage of this singleton
		  */
		static c_DoubleKeyUKPTSessionFactory* m_instance;
	};


}

#endif
