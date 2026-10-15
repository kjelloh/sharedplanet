#pragma once

#include <vector>
#include <string>
#include <map>
//#include <stdexcept> //invalid_argument

namespace testbench {

	namespace c_DataRepresentationFramework {
		/**
		* Models the most basic raw byte of c_DataRepresentationFramework
		*/
		typedef unsigned char t_raw_byte;

		/**
		* Models a vector of t_raw_byte
		*/
		typedef std::vector<t_raw_byte> t_raw_vector;

		using c_AsciiString = std::string;
		using c_ISO_8859_1_String = std::string;

		template <typename S>
		std::string& anonymous(S& s) { return s; }


		/**
		* Creates a string from provided vector of unsigned chars
		*/
		c_AsciiString createString(const t_raw_vector& buf);

		/**
		* Returns provided integer as a decimal string
		*/
		c_AsciiString intToDecimalString(int val, int minNoOfDigits = -1);

		/**
		* Cretaes a string of hex nibble pairs from provided data buffer.
		* Each byte in the buffer is transalted into a two digit hexadecimal output.
		* data[0x23, 0x34 ...] is output in string as "2334..."
		*/
		c_AsciiString createHexNibbleString(const t_raw_vector& buf);

	}

	using _Literalsz = char*;
	using _UTF8sz = char*;
	using _Asciis = std::string;

	//---------------------------------------------------------------------------
	/**
	* **********************************************
	* A BerTlv API.
	*/
	namespace bertlv {

		//	/**
		//	 * To use for unsigned chars
		//	 */
		//	typedef unsigned char uchar;

		/**
		* bertlv::t_byte
		*/
		typedef c_DataRepresentationFramework::t_raw_byte t_byte;

		/**
		* Enumeration for boolean value
		*/
		enum E_Boolean {
			ETRUE, EFALSE, ENULL
		};

		//	/**
		//	  * Define tag value type
		//	  */
		//	typedef unsigned long t_TagValue;

		typedef c_DataRepresentationFramework::t_raw_vector c_BertlvByteVector;

		/**
		* Miscellaneous helper methods.
		*/
		class BerTlvHelperMethods {
		public:
			/**
			* pre-condition:
			* ((bitindex >= 1) && (bitindex <= 8))
			* @param byte The byte to check
			* @param bitindex to check (range 1-8)
			* @return true if bit at bitindex is set, otherwise false.
			* @throw invalid_argument if precondition not fulfilled.
			*/
			static bool isSet(t_byte byte, const int bitindex);

			/**
			* Runs sprintf and checks that the result is OK (>=0) and
			* that no more than maxchars is written (otherwise runtime_error is thrown).
			* @param buf buffer to write to
			* @param format The format string
			* @param val The value to write
			* @param maxchars Max number of chars to write
			*/
			//		static void safe_sprintf(c_DataRepresentationFramework::c_ISO_8859_1_String& buf, const c_DataRepresentationFramework::c_ISO_8859_1_String& format, int val, int maxchars);
			// maxchars not used after refactoring of methid 101118/KoH
			static void safe_sprintf(c_DataRepresentationFramework::c_ISO_8859_1_String& buf, const c_DataRepresentationFramework::c_ISO_8859_1_String& format, int val);
		};


		/**
		* Interface for look up of tag labels by their
		* value and vice versa.
		*/
		template <typename _Tag>
		class TagLookupIfc {
		public:

			// Begin TagLookupIfc

			/**
			* returns true and sets sResult to the label of provided tag value
			* if it is found.
			*/
			virtual bool lookup(const _Tag tagvalue, c_DataRepresentationFramework::c_ISO_8859_1_String& sResult) const = 0;

			//		/**
			//		 * @param tagvalue The tag value
			//		 * @return The label of the tag value
			//		 * @throw range_error If no label found
			//		 */
			//		virtual c_DataRepresentationFramework::c_ISO_8859_1_String lookup(const _Tag tagvalue) const = 0;
			//
			//		/**
			//		 * @param taglabel The tag label
			//		 * @return The value of the tag label
			//		 * @throw range_error If no value found
			//		 */
			//		virtual int lookup(const c_DataRepresentationFramework::c_ISO_8859_1_String & taglabel) const = 0;

			/**
			* This method can be used when no label is found on a look up.
			* Can return "N/A" or just an empty string ("") for example.
			* @return The string representing "no label present"
			*/
			virtual c_DataRepresentationFramework::c_ISO_8859_1_String getNoLabelAvailable() const = 0;

			// End TagLookupIfc

		};


		/**
		* A log interface.
		*/
		class BerTlvLogIfc {
		public:
			/**
			* Writes a line to the log.
			*/
			virtual void write(const c_DataRepresentationFramework::c_ISO_8859_1_String& line) = 0;

			/**
			* Writes a line followed by a newline.
			*/
			virtual void writeln(const c_DataRepresentationFramework::c_ISO_8859_1_String& line) = 0;
		};


		/**
		* Common interface of all items of a TLV container.
		*/
		class BerTlvItemIfc {
		public:
			/**
			* Destructor
			*/
			virtual ~BerTlvItemIfc() {
			}

			/**
			* @return returns current BerTlvItemIfc object
			* as a vector of bytes
			*/
			virtual c_BertlvByteVector byteVector() const = 0;
		};


		/**
		* The tag (type) item of a TLV container.
		*/
		template <typename _Tag>
		class BerTlvTagItem : public BerTlvItemIfc {
		public:

			/**
			* Constructor
			* @param value the tag value
			*/
			BerTlvTagItem(_Tag value) : value(value) {
			}

			/**
			* Destructor
			*/
			~BerTlvTagItem() {
			}

			/**
			* @return the tag value
			*/
			_Tag getValue() const {
				return value;
			}

			/**
			*
			* @see base class declaration
			*/
			c_BertlvByteVector byteVector() const {
				c_BertlvByteVector ret;
				bool done = false;
				_Tag bval = value;
				while (!done) {
					// e.g.
					// bval = 0xDDFF -> div = DD, mod = FF
					// put mod first in the vector
					t_byte div = static_cast<t_byte>(bval / 0x100);
					t_byte mod = bval % 0x100;
					ret.insert(ret.begin(), mod);
					if (div > 0) {
						// if more bytes -> divide further on by 0x100
						bval = static_cast<_Tag>(bval / 0x100);
					}
					else {
						// no more bytes
						done = true;
					}
				}
				return ret;
			}

		private:
			const _Tag value;
		};

		/**
		* The length item of a TLV container.
		*/
		template <typename _Length = unsigned long>
		class BerTlvLengthItem : public BerTlvItemIfc {
		public:
			/**
			* Constructor
			* @param value the length value
			*/
			BerTlvLengthItem(const long value);

			/**
			* Destructor
			*/
			~BerTlvLengthItem();
			/*
			*
			@see base class declaration
			*/
			c_BertlvByteVector byteVector() const;

			/**
			* @return the length value
			*/
			_Length getValue() const;
		private:
			const _Length value;
		};

		/**
		* Content interface (the value of a TLV container)
		*/
		class BerTlvContentItemIfc : public BerTlvItemIfc {
		public:
			virtual ~BerTlvContentItemIfc() {
			}

			/*
			*
			@see base class declaration
			*/
			virtual c_BertlvByteVector byteVector() const = 0;

			/**
			* @return true if this is a composite
			*/
			virtual bool isComposite() const = 0;
		};


		/**
		* Primitive content (byte contents).
		*/
		class BerTlvPrimitiveContent : public BerTlvContentItemIfc {
		public:
			/*
			*
			@see base class declaration
			*/
			c_BertlvByteVector byteVector() const;

			/**
			* @see base class declaration
			*/
			bool isComposite() const;

			/**
			* Constructor
			*/
			BerTlvPrimitiveContent(c_BertlvByteVector bytes);

			/**
			* Destructor
			*/
			virtual ~BerTlvPrimitiveContent();
		private:
			const c_BertlvByteVector bytes;
		};

		// Forward
		template <typename _Tag>
		class BerTlv;

		/**
		* Composite content (contain other BerTlv:s).
		*/
		template <typename _Tag>
		class BerTlvCompositeContent : public BerTlvContentItemIfc {
		public:
			/**
			* Constructor
			* @param items items included in the composite content
			*/
			BerTlvCompositeContent(std::vector < const BerTlv<_Tag>* > items);

			/**
			* Destructor
			*/
			virtual ~BerTlvCompositeContent();
			/*
			*
			@see base class declaration
			*/
			c_BertlvByteVector byteVector() const;

			/**
			* @see base class declaration
			*/
			bool isComposite() const;

			/**
			* @return an iterator (the first position)
			*/
			typename std::vector<const BerTlv<_Tag>*>::const_iterator iterator_begin() const;

			/**
			* @return an iterator (the last position)
			*/
			typename std::vector<const BerTlv<_Tag>*>::const_iterator iterator_end() const;

			/**
			* @return a items non-const end iterator
			*/
			typename std::vector<const BerTlv<_Tag>*>::iterator iterator_end();

			/**
			* insert of provided pItem at provide iterator.
			*/
			typename std::vector<BerTlv<_Tag>*>::iterator insert(typename std::vector<const BerTlv<_Tag>*>::iterator _where, const BerTlv<_Tag>* pItem);

			/**
			* Searches for the item with provided tag value and instance index
			* where the first instance has index 0, or NULL
			* if not found.
			* Searches this item contents only. WIll not search recurivelly.
			* @param tag tag value of item to find
			* @instance_index the required tag instance where 0 is the first occurence.
			* @return Item with a tag value matching the tag param.
			*/
			const BerTlv<_Tag>* findItem(const _Tag tag, int instance_index = 0) const;

		private:
			/**
			* The items of the composite
			*/
			std::vector < const BerTlv<_Tag>* > items;

			/**
			* @clientCardinality 1
			* @supplierCardinality 0..*
			* @directed
			*/
			BerTlv<_Tag>* lnkBerTlv;
		};

		/**
		* Class containing a tag (type), length and a content (value).
		* The user of this class can build tree structures of BerTlv:s e.g:
		* (C=Composite, P=Primitive)
		* C1
		* |
		* --P1
		* |
		* --P2
		* |
		* --C1.1
		* |
		* --P1.1
		* |
		* --P1.2
		* IMPORTANT: The user of the class is always responsible for deleting the "root" (C1 above)
		*/
		template <typename _Tag>
		class BerTlv {
		public:
			/**
			* Factory method creating a primitive (simple) BerTlv.
			* IMPORTANT: If this is a "stand-alone" BerTlv (not a part of a BerTlv tree structure)
			* the caller is responsible for deleting it (see class comment for further information).
			* @param tagvalue the tagvalue
			* @param bytes a list of bytes
			* @return the BerTlv
			*/
			static const BerTlv<_Tag>* createPrimitiveBerTlv(const _Tag tagvalue, const c_BertlvByteVector bytes);

			/**
			* Factory method creating a BerTlv with composite content (contains other BerTlv:s which can be
			* primitives and/or other composites)
			* IMPORTANT: If this is a "root" BerTlv (doesn't have any other BerTlv node above it in a tree structure)
			* the caller is responsible for deleting it (see class comment for further information).
			* @param tagvalue the tagvalue
			* @param items a list of other BerTlv:s
			*/
			static const BerTlv<_Tag>* createCompositeBerTlv(const _Tag tagvalue, std::vector < const BerTlv<_Tag>* > items);
			/*
			*
			@see base class declaration
			*/
			c_BertlvByteVector byteVector() const;

			/**
			* Destructor
			*/
			virtual ~BerTlv();

			/**
			* @return value of tag
			*/
			_Tag getTagValue() const;

			/**
			* @return value of length
			*/
			int getLengthValue() const;

			/**
			* @return content
			*/
			const BerTlvContentItemIfc * const getContent() const;

		private:
			/**
			* Constructor
			* @param tagvalue tag value
			* @content content
			*/
			BerTlv(const _Tag tagvalue, const BerTlvContentItemIfc * const pContent);

			/**
			* tag object
			*/
			const BerTlvTagItem<_Tag> m_tag;

			/**
			* length object
			*/
			const BerTlvLengthItem<> m_length;

			/**
			* pointer to content
			*/
			const BerTlvContentItemIfc * const m_pContent;
		};


		/**
		* Parses a byte vector to a BerTlv object.
		*/
		template <typename _Tag>
		class BerTlvParser {
		public:
			/**
			* Parses byte vector parameter to BerTlv object
			* @param bytes byte vector
			* @return pointer to BerTlv object
			*/
			static const BerTlv<_Tag>* parseBerTlv(const c_BertlvByteVector& bytes);

		private:
			/**
			* Parses byte vector parameter to BerTlv object
			* @param bytes byte vector
			* @param offset position to start parsing (included since recursive method)
			* @return vector of pointers to BerTlv objects
			*/
			static std::vector < const BerTlv<_Tag>* > parseBerTlv(const c_BertlvByteVector& bytes, const size_t length,
				const size_t offset);

			/**
			* Reads tag from byte vector parameter
			* @param bytes byte vector
			* @param offset position to start reading
			* @param bytesReadReference call by ref param. Returns number of bytes of the tag.
			* @return tag value
			*/
			static _Tag readTag(const c_BertlvByteVector& bytes, const size_t offset, int & bytesReadReference);

			/**
			* Reads length from byte vector parameter
			* @param bytes byte vector
			* @param offset position to start reading
			* @param bytesReadReference call by ref param. Returns number of bytes of the length.
			* @return length value
			*/
			static int readLength(const c_BertlvByteVector& bytes, const size_t offset, int& bytesReadReference);
		};
		// ============================ BerTlvParser =================================
		/**
		* Parses byte vector parameter to BerTlv object
		* @param bytes byte vector
		* @param offset position to start parsing (included since recursive method)
		* @return vector of pointers to BerTlv objects
		*/
		template <typename _Tag>
		const BerTlv<_Tag>* BerTlvParser<_Tag>::parseBerTlv(const c_BertlvByteVector& bytes) {
			BerTlv<_Tag>* result = NULL;
			std::vector <const BerTlv<_Tag>*> ret = parseBerTlv(bytes, bytes.size(), 0);
			// return the first and only element since one root element
			if (ret.size() == 1) {

				result = const_cast<BerTlv<_Tag>*>(*ret.begin());
			}
			else {
				// Failed! No items or more than 1 item!
			}
			return result;
		}

		/**
		* Reads tag from byte vector parameter
		* @param bytes byte vector
		* @param offset position to start reading
		* @param bytesReadReference call by ref param. Returns number of bytes of the tag.
		* @return tag value
		*/
		template <typename _Tag>
		_Tag BerTlvParser<_Tag>::readTag(const c_BertlvByteVector& bytes, const size_t offset, int & bytesReadReference) {
			_Tag tot;
			_Tag first = static_cast<_Tag>(bytes[offset + 0]);
			bytesReadReference = 1;
			int bit5to1 = first & 0x1F;
			// Check if bit 5 -> bit 1 is in <= 30 or > 30
			if (bit5to1 <= 30) {
				// it's a tag included in a single octet
				tot = first;
			}
			else {
				// it's a tag included in more than one octet
				bool done = false;
				// initialize tot to the value of the first byte,
				// start the loop at the second byte
				tot = first;
				int index = 1;
				// Read until bit 8 is 0
				while (!done) {
					_Tag val = static_cast<_Tag>(bytes[offset + index]);
					tot = static_cast<_Tag>(tot * 0x100 + val);
					if (BerTlvHelperMethods::isSet(val, 8)) {
						// continue with next byte
						index++;
					}
					else {
						// the last byte
						done = true;
					}
				}
				bytesReadReference += index;
			}
			return tot;
		}

		template <typename _Tag>
		int BerTlvParser<_Tag>::readLength(const c_BertlvByteVector& bytes, const size_t offset, int & bytesReadReference) {
			// bool done = false;
			// size_t index = 0;
			// int totlen = 0;
			int first = bytes[offset];
			int tot = 0;
			if (first <= 127) {
				bytesReadReference = 1;
				tot = first;
			}
			else {
				int nbrOfBytes = first & 0x7F;
				bytesReadReference = nbrOfBytes + 1;
				for (int i = 1; i <= nbrOfBytes; i++) {
					tot = tot * 0x100 + bytes[offset + i];
					//int v = bytes[offset + i] << ((nbrOfBytes-i) * 8);
					//tot += v;
				}
			}
			return tot;
		}

		/**
		* Parses byte vector parameter to BerTlv object
		* @param bytes byte vector
		* @param offset position to start parsing (included since recursive method)
		* @return vector of pointers to BerTlv objects
		*/
		template <typename _Tag>
		std::vector < const BerTlv<_Tag>* > BerTlvParser<_Tag>::parseBerTlv(const c_BertlvByteVector& bytes, const size_t length, const size_t offset) {
			std::vector<const BerTlv<_Tag>*> items;
			// check arguments
			//		VALIDATE3(bytes.size() >= offset, "bytes.size()=%i <= offset=%i", bytes.size(), offset);
			if (offset <= bytes.size()) {
				// Ok to proceed
				// current position in bytes vector
				size_t localoffset = offset;

				//			bool done = false;
				//			// length can be 0 (ref. cdoOP_OPEN)
				//			if (length == 0) {
				//				done = true;
				//			}
				bool done = (length == 0);

				while (!done) {
					// called method will write nbr of read bytes
					// in this reference (call by reference)
					int bytesReadReference;
					// read tag
					const _Tag tag = readTag(bytes, localoffset, bytesReadReference);
					// check if bit 6 is set (-> it's a composite)
					const bool isComposite = BerTlvHelperMethods::isSet(bytes[0 + localoffset], 6);
					// increment by nbr of tag bytes
					localoffset += bytesReadReference;
					// read length field
					const int len = readLength(bytes, localoffset, bytesReadReference);
					// increment offset by nr of bytes in length field
					localoffset += bytesReadReference;
					const BerTlv<_Tag>* tlv;
					if (isComposite) {
						// A composite
						// parse composite contents
						std::vector < const BerTlv<_Tag>* > children = parseBerTlv(bytes, len, localoffset);
						tlv = BerTlv<_Tag>::createCompositeBerTlv(tag, children);
					}
					else {
						// A leaf
						c_BertlvByteVector value;
						for (int i = 0; i < len; i++) {
							value.push_back(bytes[localoffset + i]);
						}
						tlv = BerTlv<_Tag>::createPrimitiveBerTlv(tag, value);
					}
					items.push_back(tlv);
					// increase local offset by content length
					localoffset += len;
					// check if we've read all bytes we're supposed to read
					if (localoffset - offset >= length) {
						done = true;
					}
				}
			}
			else {
				c_DataRepresentationFramework::c_ISO_8859_1_String sMessage("BerTlvParser<_Tag>::parseBerTlv failed. Called with offset outside bytes array");
				throw std::runtime_error(sMessage);
			}

			return items;
		}
		// ============================ (END) BerTlvParser =================================
		// ==========================================================================


		/**
		* Interface to formatter of primitive BerTlv contents.
		* The client implements a formatter for type or tag specific
		* contents and provides them in a BerTlv formatter and provides it
		* to the Log output formatter (printToStr).
		*/
		class BerTlvPrimitiveContentsFormatterIfc {
		public:
			/**
			* Returns a formatted string of provided primitive content
			*/
			virtual c_DataRepresentationFramework::c_ISO_8859_1_String toString(const BerTlvPrimitiveContent * const pContent, const c_DataRepresentationFramework::c_ISO_8859_1_String& sIndent) = 0;
		};


		/**
		* Interface to Formatter of primitive BerTlv contents.
		* Client implements a formatter with this interface and provides
		* it to logger funktion to control formatting of contents in Log.
		*/
		template <typename _Tag>
		class BerTlvContentsFormatterIfc {
		public:
			/**
			* Returns true if there is a formatter for provided tag
			*/
			virtual bool tagSpecificFormatterExists(_Tag tagval) = 0;

			/**
			* Returns a formatter for provided tag id or null if none registered
			*/
			virtual BerTlvPrimitiveContentsFormatterIfc * getTagSpecificFormatter(_Tag tagval) = 0;
		};


		/**
		* Formatter of primitive BerTlv contents.
		* Client implements a formatter with this interface and provides
		* it to logger funktion to control formatting of contents in Log.
		*/
		template <typename _Tag>
		class BerTlvContentsFormatter : public BerTlvContentsFormatterIfc<_Tag> {
		public:
			/**
			* Registers a formatter for a tag id.
			*/
			void addTagSpecificFormatter(_Tag tagvalue, BerTlvPrimitiveContentsFormatterIfc * formatter);
			// --------------------------------------------------------------
			// Implementation of BerTlvContentsFormatterIfc<_Tag>

			/**
			* Returns true if there is a formatter for provided tag
			*/
			bool tagSpecificFormatterExists(_Tag tagval);

			/**
			* Returns a formatter for provided tag id or null if none registered
			*/
			BerTlvPrimitiveContentsFormatterIfc * getTagSpecificFormatter(_Tag tagval);
			// End of Implementation of BerTlvContentsFormatterIfc<_Tag>
			// --------------------------------------------------------------

		private:
			/**
			* Private storage of formatters for specific tag ids
			*/
			std::map < _Tag, BerTlvPrimitiveContentsFormatterIfc * > m_TagSpecificFormatters;

			/**
			* Private storage of formatters for specific tag types
			*/
			std::map < _Tag, BerTlvPrimitiveContentsFormatterIfc * > m_TypeSpecificFormatters;

		};
		// ==========================================================================


		/**
		* Prints a BerTlv object or raw byte data.
		* Used in tracing/debugging.
		*/
		template <typename _Tag>
		class BerTlvPrinter {
		public:
			/**
			* Formats provided BerTlv to provided string using provided formatters and TagLookup
			*/
			static void printToStr(const BerTlv<_Tag>* tlv, c_DataRepresentationFramework::c_ISO_8859_1_String & str, int level, const TagLookupIfc<_Tag> * tagLookup,
				BerTlvContentsFormatterIfc<_Tag> * pContentsFormatter = NULL);

			/**
			* Prints BerTlv object to the log object
			* @param tlv the BerTlv object
			* @param log c_BerTlvLogIfc object to log to
			*/
			static void print(const BerTlv<_Tag>* tlv, BerTlvLogIfc & log, const TagLookupIfc<_Tag> * tagLookup,
				BerTlvContentsFormatterIfc<_Tag> * pContentsFormatter = NULL);

			/**
			* Prints bytes to the log object
			* @param bytes the bytes to write
			* @param log c_BerTlvLogIfc object to log to
			*/
			static void printBytes(const c_BertlvByteVector bytes, BerTlvLogIfc & log);
		};

		// ============================ BerTlvCompositeContent =================================
		template <typename _Tag>
		typename std::vector<const BerTlv<_Tag>*>::const_iterator BerTlvCompositeContent<_Tag>::iterator_begin() const {
			return items.begin();
		}

		template <typename _Tag>
		typename std::vector<const BerTlv<_Tag>*>::const_iterator BerTlvCompositeContent<_Tag>::iterator_end() const {
			return items.end();
		}

		/**
		* @return a items non-const end iterator
		*/
		template <typename _Tag>
		typename std::vector<const BerTlv<_Tag>*>::iterator BerTlvCompositeContent<_Tag>::iterator_end() {
			return items.end();
		}

		/**
		* insert of provided pItem at provide iterator.
		*/
		template <typename _Tag>
		typename std::vector<BerTlv<_Tag>*>::iterator BerTlvCompositeContent<_Tag>::insert(typename std::vector<const BerTlv<_Tag>*>::iterator _where, const BerTlv<_Tag>* pItem) {
			items.insert(_where, pItem);
		}

		/**
		* Returns the item with a tag value matching the tag param.
		* Note: Doesn't search recursively. The finder is only for
		* items one level below current (i.e. the children not the grand children).
		* If no item found -> NULL is returned.
		* @param tag tag value of item to find
		* @return Item with a tag value matching the tag param.
		* instance_no = 0 requests the first occurenec of the tag, 1 the second and so on.
		*/
		template <typename _Tag>
		const BerTlv<_Tag>* BerTlvCompositeContent<_Tag>::findItem(const _Tag tag, int instance_index) const {
			const BerTlv<_Tag>* result = NULL; // default
			typename std::vector<const BerTlv<_Tag>*>::const_iterator iterator = this->iterator_begin();
			typename std::vector<const BerTlv<_Tag>*>::const_iterator end = this->iterator_end();
			int instanceCount = 0;
			while (iterator != end) {
				if (((*iterator))->getTagValue() == tag) {
					instanceCount++;
					if ((instanceCount - 1) == instance_index) {
						result = (*iterator);
					}
				}
				iterator++;
			}
			// if no match -> return NULL
			return result;
		}

		template <typename _Tag>
		bool BerTlvCompositeContent<_Tag>::isComposite() const {
			return true;
		}

		template <typename _Tag>
		BerTlvCompositeContent<_Tag>::BerTlvCompositeContent(std::vector < const BerTlv<_Tag>* > items) : items(items) {
		}

		template <typename _Tag>
		BerTlvCompositeContent<_Tag>::~BerTlvCompositeContent() {
			// delete all content of the composite
			//		typename std::vector<const BerTlv<_Tag>*>::const_iterator iter = iterator_begin();
			//		typename std::vector<const BerTlv<_Tag>*>::const_iterator end = iterator_end();
			typename std::vector<const BerTlv<_Tag>*>::iterator iter = items.begin();;
			typename std::vector<const BerTlv<_Tag>*>::iterator end = items.end();
			while (iter != end) {
				delete * iter;
				iter++;
			}
		}

		template <typename _Tag>
		c_BertlvByteVector BerTlvCompositeContent<_Tag>::byteVector() const {
			c_BertlvByteVector ret;
			typename std::vector<const BerTlv<_Tag>*>::const_iterator i;
			// Loop through all BerTlv items and append their
			// bytes to the result ret
			for (i = items.begin(); i != items.end(); i++) {
				const BerTlv<_Tag>* b = *i;
				c_BertlvByteVector thisPart = b->byteVector();
				ret.insert(ret.end(), thisPart.begin(), thisPart.end());
			}
			return ret;
		}

		// ============================ (END) BerTlvCompositeContent =================================

		// ============================ BerTlv =================================
		template <typename _Tag>
		const BerTlv<_Tag>* BerTlv<_Tag>::createPrimitiveBerTlv(const _Tag tagvalue, const c_BertlvByteVector bytes) {
			BerTlvPrimitiveContent * pContent = new BerTlvPrimitiveContent(bytes);
			const BerTlv<_Tag>* primitive = new BerTlv(tagvalue, pContent);
			return primitive;
		}

		template <typename _Tag>
		const BerTlv<_Tag>* BerTlv<_Tag>::createCompositeBerTlv(const _Tag tagvalue, std::vector < const BerTlv<_Tag>* > items) {
			BerTlvCompositeContent<_Tag> * pContent = new BerTlvCompositeContent<_Tag>(items);
			const BerTlv<_Tag>* composite = new BerTlv<_Tag>(tagvalue, pContent);
			return composite;
		}

		template <typename _Tag>
		BerTlv<_Tag>::BerTlv(const _Tag tagvalue, const BerTlvContentItemIfc * const pContent)
			: m_tag(BerTlvTagItem<_Tag>(tagvalue))
			//	      ,length(BerTlvLengthItem((long)content->byteVector().size())), content(content) {
			, m_length(BerTlvLengthItem<>(pContent->byteVector().size())), m_pContent(pContent) {
		}

		template <typename _Tag>
		BerTlv<_Tag>::~BerTlv() {
			delete m_pContent;
		}

		template <typename _Tag>
		c_BertlvByteVector BerTlv<_Tag>::byteVector() const {
			c_BertlvByteVector ret;
			c_BertlvByteVector::iterator iter;
			c_BertlvByteVector src = m_tag.byteVector();
			ret.insert(ret.end(), src.begin(), src.end());
			src = m_length.byteVector();
			ret.insert(ret.end(), src.begin(), src.end());
			src = m_pContent->byteVector();
			ret.insert(ret.end(), src.begin(), src.end());
			return ret;
		}

		template <typename _Tag>
		_Tag BerTlv<_Tag>::getTagValue() const {
			return m_tag.getValue();
		}

		template <typename _Tag>
		int BerTlv<_Tag>::getLengthValue() const {
			return m_length.getValue();
		}

		template <typename _Tag>
		const BerTlvContentItemIfc * const BerTlv<_Tag>::getContent() const {
			return m_pContent;
		}

		// ============================ (END) BerTlv =================================

		// ============================ BerTlvLengthItem =================================
		template <typename _Length>
		BerTlvLengthItem<_Length>::BerTlvLengthItem(const long value) : value(value) {
		}

		template <typename _Length>
		BerTlvLengthItem<_Length>::~BerTlvLengthItem() {
		}

		template <typename _Length>
		_Length BerTlvLengthItem<_Length>::getValue() const {
			return value;
		}

		template <typename _Length>
		c_BertlvByteVector BerTlvLengthItem<_Length>::byteVector() const {
			c_BertlvByteVector ret;
			if (value <= 127) {
				// a single octet length
				// just return the value in one byte
				ret.push_back((t_byte)value);
			}
			else {
				// the first byte
				// bit 8 = 1
				// following bits represent number of subsequent length bytes
				int first = ((value / 0xFF) + 1) + 0x80;
				bool done = false;
				int bval = value;
				while (!done) {
					// e.g.
					// bval = 0xDDFF -> div = DD, mod = FF
					// put mod first in the vector
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
				// set the first "length" byte as leading
				ret.insert(ret.begin(), first);
			}
			return ret;
		}

		// ============================ (END) BerTlvLengthItem =================================

		// ============================ BerTlvPrinter =================================

		/**
		* Prints BerTlv object to a string
		* @param tlv the BerTlv object
		* @param str the string to print to
		* @param level current level of the bertlv structures. This parameter
		* @param tagLookup A tag lookup object
		* controls the indentation of the output
		*/
		template <typename _Tag>
		void BerTlvPrinter<_Tag>::printToStr(const BerTlv<_Tag>* tlv, c_DataRepresentationFramework::c_ISO_8859_1_String & str, int level, const TagLookupIfc<_Tag> * tagLookup,
			BerTlvContentsFormatterIfc<_Tag> * pContentsFormatter) {
			// set indentation of current level in the bertlv structure
			c_DataRepresentationFramework::c_ISO_8859_1_String indent("  ");
			for (int i = 0; i < level; i++) {
				indent += _Literalsz("   ");
			}
			const _Tag tagval = tlv->getTagValue();
			// get label (e.g. cdoOPInit) of current tag value
			// if no TagLookupIfc<_Tag> instance -> write empty string ("")
			// if label not found -> write value returned from getNoLabelAvailable
			c_DataRepresentationFramework::c_ISO_8859_1_String taglabel;
			//		   if (tagLookup == NULL) {
			//			   taglabel = _Literalsz("");
			//		   }
			//		   else {
			//			   try {
			//				   taglabel = tagLookup->lookup(tagval);
			//			   }
			//			   catch (...) {
			//				   taglabel = _Literalsz("#failed#");
			//			   }
			//		   }
			if (tagLookup == NULL) {
				taglabel = _Literalsz("?Name?");
			}
			else {
				if (!tagLookup->lookup(tagval, taglabel)) {
					taglabel = _Literalsz("?Name?");
				}
			}
			const int lenval = tlv->getLengthValue();
			c_DataRepresentationFramework::c_ISO_8859_1_String tagvalbuf;
			BerTlvHelperMethods::safe_sprintf(tagvalbuf, _Literalsz("%x"), tagval);
			c_DataRepresentationFramework::c_ISO_8859_1_String lenvalbuf;
			BerTlvHelperMethods::safe_sprintf(lenvalbuf, _Literalsz("%d"), lenval);
			str.append(indent);
			str.append(taglabel);
			str.append("\t");
			str.append(tagvalbuf);
			str.append("(");
			str.append(lenvalbuf);
			str.append(")");
			const BerTlvContentItemIfc * const pContents = tlv->getContent();
			if (pContents->isComposite()) {
				str.append("\n");
				const BerTlvCompositeContent<_Tag>* composite = dynamic_cast<const BerTlvCompositeContent<_Tag>*>(pContents);
				typename std::vector<const BerTlv<_Tag>*>::const_iterator end = composite->iterator_end();
				typename std::vector<const BerTlv<_Tag>*>::const_iterator iter = composite->iterator_begin();
				while (iter != end) {
					const BerTlv<_Tag>* tlv = *iter;
					// recursive call to print
					// print the items of the composite
					printToStr(tlv, str, level + 1, tagLookup, pContentsFormatter);
					iter++;
				}
			}
			else {
				str.append(" = ");
				const BerTlvPrimitiveContent * primitiveItem = (BerTlvPrimitiveContent *)pContents;
				bool contentsFormatted = false; // Flag to signal if content is formatted
												// Check if there is a tag specific rule
				if (pContentsFormatter != NULL) {
					if (pContentsFormatter->tagSpecificFormatterExists(tagval)) {
						BerTlvPrimitiveContentsFormatterIfc * lf = pContentsFormatter->getTagSpecificFormatter(tagval);
						str.append(lf->toString(dynamic_cast < const BerTlvPrimitiveContent * const > (pContents), indent));
						contentsFormatted = true;
					}
					// Else Check if there is a registered type dependent rule
					// Todo: Write code here
					/*
					if (pContentsFormatter != NULL) {
					if (pContentsFormatter->typeSpecificFormatterExists(tagval)) {
					BerTlvPrimitiveContentsFormatterIfc* lf = pContentsFormatter->getTypeSpecificFormatter(tagval);
					str.append(lf->toString(dynamic_cast<const BerTlvPrimitiveContent* const>(contents)));
					contentsFormatted = true;
					}
					*/
				}
				if (!contentsFormatted) {
					// Append as string
					str.append("\"");
					str += c_DataRepresentationFramework::createBracketedHexValueISO8859_1String(primitiveItem->byteVector());
					str.append("\"");
				}
				str.append("\n");
			}
		}

		template <typename _Tag>
		void BerTlvPrinter<_Tag>::print(const BerTlv<_Tag>* tlv, BerTlvLogIfc & log, const TagLookupIfc<_Tag> * tagLookup, BerTlvContentsFormatterIfc<_Tag> * pContentsFormatter) {
			c_DataRepresentationFramework::c_ISO_8859_1_String str;
			printToStr(tlv, str, 0, tagLookup, pContentsFormatter);
			log.write(str);
		}

		template <typename _Tag>
		void BerTlvPrinter<_Tag>::printBytes(const c_BertlvByteVector bytes, BerTlvLogIfc & log) {
			c_DataRepresentationFramework::c_ISO_8859_1_String str;
			c_BertlvByteVector::const_iterator iter;
			int index = 0;
			for (iter = bytes.begin(); iter != bytes.end(); iter++) {
				int uc = (int)* iter;
				str.append("|");
				if (uc <= 15) {
					str.append("0");
				}
				c_DataRepresentationFramework::c_ISO_8859_1_String hexbuf;
				BerTlvHelperMethods::safe_sprintf(hexbuf, _Literalsz("%x"), uc);
				// write in 8 byte row length
				if ((++index % 8) == 0) {
					str.append("|");
				}
			}
			log.write(str);
		}
		// ============================ (END) BerTlvPrinter =================================
		// ============================ BerTlvContentsFormatter =================================

		/**
		* Returns true if there is a formatter for provided tag
		*/
		template <typename _Tag>
		bool BerTlvContentsFormatter<_Tag>::tagSpecificFormatterExists(_Tag tagval) {
			return (getTagSpecificFormatter(tagval) != NULL);
		};

		/**
		* Returns a formatter for provided tag id or null if none registered
		*/
		template <typename _Tag>
		BerTlvPrimitiveContentsFormatterIfc * BerTlvContentsFormatter<_Tag>::getTagSpecificFormatter(_Tag tagval) {
			BerTlvPrimitiveContentsFormatterIfc * result = NULL;
			typename std::map<_Tag, BerTlvPrimitiveContentsFormatterIfc*>::iterator iter;
			iter = m_TagSpecificFormatters.find(tagval);
			if (iter != m_TagSpecificFormatters.end()) {
				// Found one!
				result = iter->second;
			}
			return result;
		};

		/**
		* Registers a formatter for a tag id.
		*/
		template <typename _Tag>
		void BerTlvContentsFormatter<_Tag>::addTagSpecificFormatter(_Tag tagvalue, BerTlvPrimitiveContentsFormatterIfc * formatter) {
			m_TagSpecificFormatters[tagvalue] = formatter;
		};
		// ============================ (END) BerTlvContentsFormatter =================================


	}; // namespace bertlv

	   //---------------------------------------------------------------------------

	namespace ipos {

		//	typedef unsigned char uchar;

		/**
		* Tag constants
		*/
		// enum ETAGS {
		enum e_iPosTags : unsigned long {
			eiPosTags_Undefined = 0x000000
			, cdoSA_iPOS = 0xFFF001
			, cdoiPOS_SA = 0xFFF10A
			, pdoType = 0xDFF002
			, pdoSeqNbr = 0xDFF003
			, pdoResult = 0xDFF004
			, pdoEcho = 0xDFF005,
			// OP_INIT
			cdoOP_INIT = 0xFF8101
			, pdoTermPath = 0xDF8114
			, cdoPayTerm = 0xFF810A
			, pdoPayTermSer = 0xDF810B
			, pdoPayTermIp = 0xDF810C
			, pdoPayTermUsb = 0xDF810D
			, pdoMaxDspLength = 0xDF810E
			, pdoNbrRow = 0xDFB106
			, pdoDspTimer = 0xDF810F
			, cdoLocalNetworkConfig = 0xFF8110
			, pdoLocalIp = 0xDF8111
			, pdoSubnetMask = 0xDF8112
			, pdoGateway = 0xDF8113
			, pdoiPOSRestart = 0xDF8115
			, cdoPayTermInfo = 0xFFB102
			, pdoPedType = 0xDF8208
			, pdoPedId = 0xDF8209
			// DI_INFO
			, cdoDI_INFO = 0xFFE101
			, cdoDIMessage = 0xFFE102
			, pdoTextId = 0xDFC102
			, pdoDIForce = 0xDFE103
			, cdoDsp = 0xFFB602
			, pdoDspRow = 0xDFB603
			, pdoDspJustified = 0xDFB604
			, pdoDIDspText = 0xDFE104
			, cdoKbd = 0xFFB60D
			, pdoKbdKey = 0xDFB608
			, pdoKbdKeyVal = 0xDFB208
			, pdoKbdRow = 0xDFB609
			, pdoKbdPos = 0xDFB60A
			, pdoKbdInMax = 0xDFB60B
			, pdoKbdEndFnc = 0xDFB60C
			, pdoKbdEndFncSel = 0xDFB202
			, cdoDIChar = 0xFFE105
			, pdoChar = 0xDFE106
			, pdoDspPos = 0xDFE107
			, cdoDIEvent = 0xFFE108
			, pdoDIEventType = 0xDFE109
			// SR_MESSAGE
			, cdoSR_MESSAGE = 0xFFC101
			, pdoIposErrorText = 0xDFC103
			// OP_CONNECT
			, cdoOP_CONNECT = 0xFF8201
			, cdoiPOSTsp = 0xFF8202
			, pdoTSPId = 0xDF8203
			, pdoTSPAddr = 0xDF8204
			, cdoSA = 0xFF8205
			, pdoSettId = 0xDF8206
			, cdoPPId = 0xFF8207
			, pdoDate = 0xDF820A
			, pdoTime = 0xDF820B
			, cdoLastTrans = 0xFFB115 // 070330 KoH
			, pdoTypeLastTrans = 0xDFB116 // 070330 KoH
			, pdoSASensitiveDataProtectionLevel = 0xDF820D // 100208 KoH
														   // OP_OPEN
			, cdoOP_OPEN = 0xFF8601
			// OP_NEW_CUSTOMER
			, cdoOP_NEW_CUSTOMER = 0xFF8C01
			, pdoTransactionType = 0xDF8C06
			, pdoCardContinue = 0xDF8C02
			, pdoCardReader = 0xDF8C03
			, pdoDspText = 0xDFB605
			, pdoOpenFuncKey = 0xDF8C04
			// OP_NEW_CUSTOMER response
			, pdoAmountBeforeCardSupported = 0xDF8C07
			// OP_END
			, cdoOP_END = 0xFF9001
			// OP_AUTHORIZE
			, cdoOP_AUTHORIZE = 0xFF9401 // 070329 KoH
			, pdoOpenTransactionHandling = 0xDF9402 // 070329 KoH
													// OP_DEBIT
			, cdoOP_DEBIT = 0xFF9601 // 070329 KoH
			, pdoCreateAdvice = 0xDF9602 // 070329 KoH
										 // SR_CARD_READ
			, cdoSR_CARD_READ = 0xFFD101
			, pdoCardTypeIndikator = 0xDFD102
			, pdoCardType = 0xDFD103
			, cdoPayment = 0xFFD10F
			, cdoBonus = 0xFFD110
			, cdoUnKnownCard = 0xFFD111
			// pdoPAN = 0x5A,
			, pdoPAN = 0xDFD10E // 2006-06-12 DPN
			, pdoMaskedPAN = 0xDFC330 // 2011-05-17, KoH

			, pdoEncryptedTrack2Part = 0xdfc331 // 2015-12-30, KoH
			, pdoKSNCurrent = 0xdfbb02 // 2015-12-30, KoH
			, pdoCardNumberAlias = 0xdfd11a // 2015-12-30, KoH
			, pdoWithdravelAmount = 0xdfd105 // 2015-12-30, KoH
			, pdoEncryptedSettlemtData = 0xDFC333 // 2015-12-30, KoH

			, pdoCardUserID = 0xDFC332 // 2010-02-10 KoH
			, cdoLoyaltyList = 0xFFD116
			, pdoAID = 0x4F
			, pdoMaxCashBackAmount = 0xDFD104
			, pdoWithdrawalAmount = 0xDFD105
			, pdoMinPurchaseAmount = 0xDFD106
			, pdoMaxPurchaseAmount = 0xDFD107
			, pdoMaxRefundAmount = 0xDFD10D
			, pdoBonusApplication = 0xDFD108
			, pdoBitfields_1 = 0xDFD110
			, pdoBitfields_2 = 0xDFD111
			, pdoBitfields_3 = 0xDFD112
			, pdoBitfields_4 = 0xDFD113
			, pdoBitfields_5 = 0xDFD114
			, pdoFinancialInstitution = 0xDFC31D
			, pdoCardHolderName = 0xDFD10B
			, pdoTrack1Data = 0xDFA602
			, pdoTrack2Data = 0xDFA603
			, pdoTrack3Data = 0xDFA604
			// SR_CARD_READ response
			, pdoLoyaltyDone = 0xDFD115
			, pdoOpenLowLevel = 0xDFD10C
			// OP_PAY
			, cdoOP_PAY = 0xFF9201
			, pdoTransactionAmount = 0xDFAF11
			, pdoTransactionVAT = 0xDFC305
			, pdoTransCurrencyCode = 0xDFC318
			, pdoCashBackAmount = 0xDFC306
			, pdoMerchantCategoryCode = 0xDF9202
			, pdoCashierId = 0xDF9203
			// OP_REFUND
			, cdoOP_REFUND = 0xFF9801
			//pdoTransactionAmount = 0xDFAF11, // Already declared
			//pdoTransCurrencyCode = 0xDFC318,
			//pdoTransactionVAT = 0xDFC305,
			//pdoMerchantCategoryCode= 0xDF9202,
			//pdoCashierId = 0xDF9203,
			, cdoChangeAcqBank = 0xFF820C
			// OP_STATUS
			, cdoOP_STATUS = 0xFFB001
			// OP_CORR
			, cdoOP_CORR = 0xFFA401
			, cdoSR_STATUS_CHANGE = 0xFFD301
			, pdoTermNbrChar = 0xDFB107
			, pdoTrack1 = 0xDFB108
			, pdoTrack2 = 0xDFB109
			, pdoTrack3 = 0xDFB10A
			, pdoChip = 0xDFB10B
			, pdoName = 0xDFB10C
			, pdoHWVer = 0xDFB10D
			, pdoSWVer = 0xDFB10E
			, pdoHWSecurityVer = 0xDFB10F
			, pdoSWSecurityVer = 0xDFB110
			, cdoiPOS = 0xFFB111
			, pdoiPOSVer = 0xDFB112
			, cdoStatus = 0xFFB113
			, pdoCurrState = 0xDFB114
			, pdoStateChange = 0xDFD302
			, pdoStateChangeIndicator = 0xDFD303
			// OP CANCEL
			, cdoOP_CANCEL = 0xFF8A01
			// OP CLOSE
			, cdoOP_CLOSE = 0xFF8801
			// SR REQUEST DATA
			, cdoSR_REQUEST_DATA = 0xFFC501
			, pdoTagList = 0xDFAA03
			, cdoTagListData = 0xFFAA04
			// SR SEND HOST
			, cdoSR_SEND_HOST = 0xFFC901
			, cdoHostAddr = 0xFFC702
			, pdoPrimPhonNbr = 0xDFC704
			, pdoSecondPhonNbr = 0xDFC705
			, pdoPrimIPAdr = 0xDFC706
			, pdoSecondIPAdr = 0xDFC707
			, pdoExpectResponse = 0xDFC708
			, pdoSPDH = 0xDFC902
			, cdoFileTSP = 0xFFC90A

			, pdoUserId = 0xDFC90B
			, pdoPassword = 0xDFC90C
			, pdoFileNameTSP = 0xDFC90D
			, pdoFileNameLocal = 0xDFC90E
			, pdoFileSendOrReceive = 0xDFC90F

			// SR SEND HOST RESP
			, pdoResponseCodeFTP = 0xDFC9A0
			// SR RECEIVE DATA
			, cdoSR_RECEIVE_DATA = 0xFFC301
			, cdoReceiptData = 0xFFC302
			, pdoDebitStatus = 0xDFC303
			, pdoDebitStatusText = 0xDFC304
			, pdoAcqRefNbr = 0xDFC321
			// used by hypercom as name pdoAcqRefNbr - not according to spec v. 2.5 draft
			, pdoAcqRefNbr_HC = 0x9F4D
			, pdoBankAgentName = 0xDFC31C
			, pdoCardProductName = 0xDFC31E
			, pdoTransactionDate = 0xDFC322
			, pdoTransactionTime = 0xDFC323
			// used by hypercom as name pdoTransactionTime - not according to spec v. 2.5 draft
			, pdoTransactionTime_HC = 0x9F21
			// , pdoOrganisationNbr = 0x9F25
			, pdoOrganisationNbr = 0xDFC328
			, pdoTransactionCode = 0xDFC309
			, pdoExpirationDate = 0xDFC30A
			, pdoAccountType = 0xDFC30B
			, pdoIDMethod = 0xDFC30C
			, pdoPOSEntryMode = 0xDFC30D
			, pdoRetrievalReferenceNumber = 0xDFC319
			, pdoAuthorisationMethod = 0xDFC30F
			, pdoAuthorisationResponseCode = 0xDFC310
			// pdoAuthorisationCode = 0x89,
			, pdoAuthorisationCode = 0xDFC329
			, pdoTerminalIdentifier = 0xDFC31A
			, pdoOpenTransactionNumber = 0xDF9403
			, cdoEMVData = 0xFFC31B
			, pdoTVR = 0x95
			, pdoTSI = 0x9B
			, cdoLogData = 0xFFC311
			, pdoTerminalCapability = 0xDFC315
			, pdoCardInput = 0xDFC316
			, pdoAuthorisingEntity = 0xDFC320
			, pdoPaymentCode = 0xDFC324
			, pdoAC = 0x9F26
			, pdoCryptoAmount = 0x9F02
			, pdoCryptoInfoData = 0x9F27
			, pdoIAD = 0x9F10
			, pdoUnpredicNumber = 0x9F37
			, pdoATC = 0x9F36
			, pdoAIP = 0x82
			, pdoCryptoTransactionDate = 0x9A
			, pdoCryptoTransType = 0x9C
			, pdoCryptoCurrency = 0x5F2A
			, pdoTermCountryCode = 0x9F1A
			, pdoEMVTerminalType = 0x9F35
			, pdoDFName = 0x84
			, pdoAppVersNumber = 0x9F08
			, pdoTermAppVersNumber = 0x9F09
			, pdoOtherAmount = 0x9F03
			, pdoPANSeqNumber = 0x5F34
			, pdoEMVResponseCode = 0x8A
			, pdoCVMResult = 0xDFC326
			, pdoScriptResult = 0xDFC327
			, pdoTermCapabilities = 0xDFC32A
			, pdoAdditionalRID = 0xDFC32B
			, pdoMaxAllowedAmount = 0xDFC312
			, pdoLogReason = 0xDFC313
			, cdoiPOSLogData = 0xFFC313
			, pdoTypeOfLog = 0xDFAE02
			, pdoLogBlock = 0xDFAE10
			, pdoiPOSData = 0xDFC314
			, pdoTrack2Part = 0xDFC325
			// OP_TRACE
			, cdoOP_TRACE = 0xFFB201
			, pdoTraceLevel = 0xDFB204
			, pdoTraceInfo = 0xDFB205
			// OP_PROPRIETARY
			, cdoOP_PROPRIETARY = 0xFFBD01
			, cdoSR_HANDLE_PROPRIETARY_DATA = 0xFFDA01
			, pdoProprietaryApplicationID = 0xDFBD02
			, pdoProprietaryCommandData = 0xDFBD03
			// OP_LOG
			, cdoOP_LOG = 0xFFAE01
			, pdoRequestType = 0xDFAE03
			, pdoSearchData = 0xDFAE04
			, pdoLogFileName = 0xDFAE05
			// OP_PUT_CARD_DATA
			, cdoOP_PUT_CARD_DATA = 0xFFA801
			, pdoCardInputIndicator = 0xDFA802
			//pdoPAN = 0xDFD10E, // Already declared
			//pdoTrack1Data = 0xDFA602,
			//pdoTrack2Data = 0xDFA603,
			//pdoTrack3Data = 0xDFA604
			// OP_TERMINAL_DIALOG
			, cdoOP_TERMINAL_DIALOG = 0xFFB601
			, cdoOPMessage = 0xFFB610
			, pdoBeep = 0xDFB60F
			, cdoDspIdle = 0xFFB60E
			// cdoOP_NEW_PARAMETERS
			, cdoOP_NEW_PARAMETERS = 0xFF8D01
			// cdoOP_MAINTENANCE
			, cdoOP_MAINTENANCE = 0xFFB301
			, pdoTypeOfFunction = 0xDFB302
			, pdoUserPW = 0xDFB307
			, pdoDumpData = 0xDFB303
			, pdoLSPDHDate = 0xDFB304
			, pdoLSPDHTime = 0xDFB305
			, pdoLSPDHRspCode = 0xDFB306
			, cdoParameterInfo = 0xFFD304
			, pdoFileNamePPL = 0xDFD305
			// ,pdoHWVer = 0xDFB10D already declared
			// ,pdoSWVer = 0xDFB10E
			// ,pdoHWSecurityVer = 0xDFB10F
			// ,pdoSWSecurityVer = 0xDFB110
			// ,cdoiPOS = 0xFFB111
			// ,pdoiPOSVer = 0xDFB112
			, pdoTransactionCategoryCode = 0x9F53
			, cdoCloseBatch = 0xFFB120
			, pdoCBTerm = 0xDFB121
			, pdoCBHost = 0xDFB122
			// Extension - Language selection designed by Sagem
			, cdoOP_SET_LANGUAGE = 0xFFE201
			, pdoIso639Code = 0xDFE202
			, cdoOP_GET_LANGUAGES = 0xFFE210
			, pdoLanguageCount = 0xDFE211
			, cdoSR_LANGUAGE_CHANGE = 0xFFE310
			, cdoSR_LANGUAGE_MISMATCH = 0xFFE410
			, cdoOP_READ_WRITE_CARD = 0xFFBA01
			, pdoReaderCMD = 0xDFB102
			, pdoDspTextIdle = 0xDFB607
			, cdoTrackText = 0xFFB806

			// Background commands extension
			, cdoSA_iPOS_B = 0xFFF201
			, cdoiPOS_SA_B = 0xFFF30A

			// cdoOP_CASH_ADVANCE
			, cdoOP_CASH_ADVANCE = 0xFFBE01
			, eiPosTags_Unknown = 0xFFFFFF

		};

		typedef e_iPosTags t_TagValue;
		//	typedef unsigned long t_TagValue;

		/**
		* ipos::TagLookupIfc
		*/
		typedef bertlv::TagLookupIfc<t_TagValue> TagLookupIfc;

		/**
		* ipos::t_byte
		*/
		typedef bertlv::t_byte t_byte;

		/**
		* ipos::c_BertlvByteVector
		*/
		typedef bertlv::c_BertlvByteVector c_BertlvByteVector;

		/**
		* ipos::BerTlvContentItemIfc
		*/
		typedef bertlv::BerTlvContentItemIfc BerTlvContentItemIfc;

		/**
		* ipos::BerTlvPrimitiveContent
		*/
		typedef bertlv::BerTlvPrimitiveContent BerTlvPrimitiveContent;

		/**
		* ipos::BerTlvCompositeContent
		*/
		typedef bertlv::BerTlvCompositeContent<t_TagValue> BerTlvCompositeContent;

		/**
		* Models an iPos bertlv (ipos::BerTlv)
		*/
		typedef bertlv::BerTlv<t_TagValue> BerTlv;

		/**
		* ipos::BerTlvPrimitiveContentsFormatterIfc
		*/
		typedef bertlv::BerTlvPrimitiveContentsFormatterIfc BerTlvPrimitiveContentsFormatterIfc;

		/**
		* ipos::BerTlvContentsFormatterIfc
		*/
		typedef bertlv::BerTlvContentsFormatterIfc<t_TagValue> BerTlvContentsFormatterIfc;

		/**
		* ipos::BerTlvContentsFormatter
		*/
		typedef bertlv::BerTlvContentsFormatter<t_TagValue> BerTlvContentsFormatter;

		/**
		* ipos::BerTlvPrinter
		*/
		typedef bertlv::BerTlvPrinter<t_TagValue> BerTlvPrinter;

		/**
		* ipos::BerTlvParser
		*/
		typedef bertlv::BerTlvParser<t_TagValue> BerTlvParser;

		/**
		* Miscellaneous helper methods
		*/
		class iPosHelperMethods {
		public:
			/**
			* Converts given c_DataRepresentationFramework::c_ISO_8859_1_String to bytes
			* @param value c_DataRepresentationFramework::c_ISO_8859_1_String to convert
			* @return the bytes
			*/
			static c_BertlvByteVector stringToBytes(const c_DataRepresentationFramework::c_ISO_8859_1_String & value);

			/**
			* Converts bytes to c_DataRepresentationFramework::c_ISO_8859_1_String
			* @param value bytes to convert
			* @return the c_DataRepresentationFramework::c_ISO_8859_1_String
			*/
			static c_DataRepresentationFramework::c_ISO_8859_1_String bytesToString(const c_BertlvByteVector & value);

			/**
			* Converts the integer to bytes
			* @param value integer to convert
			* @return the bytes
			*/
			static c_BertlvByteVector toByteVector(const int value);

			/**
			* Converts three bytes to an integer value
			* @param mostSignificant The most significant byte
			* @param middle The middle byte
			* @param leastSignificant The least significant byte
			* @return the integer value
			*/
			static int toInt(const t_byte mostSignificant, const t_byte middle, const t_byte lestSignificant);

			/**
			* Returns the 7-bit value of the byte.
			* Example: byte=11111111 (0xFF)
			* -> 1111111 (0x7F) is returned
			* @param byte The byte to get 7-bit value from
			* @return an int (the 7-bit value)
			*/
			static int getSevenBitValue(const t_byte byte);

			/**
			* @param value
			* @return The value parameter converted to A data format
			* (according to iPOS Message and Command spec.)
			*/
			static c_BertlvByteVector toA(const t_byte value);

			/**
			* @param value
			* @return The value parameter converted to AN data format
			* (according to iPOS Message and Command spec.)
			*/
			static c_BertlvByteVector toAN(const c_DataRepresentationFramework::c_ISO_8859_1_String & value);

			/**
			* @param value
			* @return The value parameter converted to AN data format
			* (according to iPOS Message and Command spec.)
			*/
			static c_BertlvByteVector toAN(const int value);

			/**
			* @param value
			* @return The value parameter converted to ANS data format
			* (according to iPOS Message and Command spec.)
			*/
			static c_BertlvByteVector toANS(const c_DataRepresentationFramework::c_ISO_8859_1_String & value);

			/**
			* @param value
			* @return The value parameter converted to BOOL data format
			* (according to iPOS Message and Command spec.)
			*/
			static c_BertlvByteVector toBool(const bool value);

			/**
			* @param value
			* @return The value parameter converted to CN data format
			* (according to iPOS Message and Command spec.)
			*/
			static c_BertlvByteVector toCN(const c_DataRepresentationFramework::c_ISO_8859_1_String & value, const int nbrOfBytes);

			/**
			* @param value
			* @return The value parameter converted to N data format
			* (according to iPOS Message and Command spec.)
			*/
			static c_BertlvByteVector toN(const c_DataRepresentationFramework::c_ISO_8859_1_String & value);

			/**
			* @param value
			* @return The value parameter converted to Nb data format
			* (according to iPOS Message and Command spec.)
			*/
			static c_BertlvByteVector toNb(const c_DataRepresentationFramework::c_ISO_8859_1_String & value, int len);

			/**
			* @param len
			* @return a std::vector of len number of binary zeroes.
			*/
			static c_BertlvByteVector toBinaryZeroNb(const int len);

			/**
			* @param value
			* @return The value parameter converted to char data format
			*/
			static char aToChar(const t_byte value);

			/**
			* @param value AN data format
			* (according to iPOS Message and Command spec.)
			* @return The value converted c_DataRepresentationFramework::c_ISO_8859_1_String
			*/
			static c_DataRepresentationFramework::c_ISO_8859_1_String anToString(const c_BertlvByteVector & value);

			/**
			* @param value AN data format
			* (according to iPOS Message and Command spec.)
			* @return The value converted long
			*/
			static long anToLong(const c_BertlvByteVector & value);

			/**
			* @param value N data format
			* (according to iPOS Message and Command spec.)
			* @return The value converted c_DataRepresentationFramework::c_ISO_8859_1_String
			*/
			static c_DataRepresentationFramework::c_AsciiString nToString(const c_BertlvByteVector & value);

			/**
			* @param value ANS data format
			* (according to iPOS Message and Command spec.)
			* @return The value converted c_DataRepresentationFramework::c_ISO_8859_1_String
			*/
			static c_DataRepresentationFramework::c_ISO_8859_1_String ansToString(const c_BertlvByteVector & value);

			/**
			* @param value Bool
			* (according to iPOS Message and Command spec.)
			* @return The Bool value as bool primitive datatype
			*/
			static bool toBool(const t_byte value);

			/**
			* Expands parameter byte array and stores as a c_DataRepresentationFramework::c_ISO_8859_1_String
			* which is returned.
			* This compressed byte array is used in tags e.g.:
			* pdoAID
			* pdoTVR
			* pdoTSI
			* @param value
			* @return (see comment above)
			*/
			static c_DataRepresentationFramework::c_AsciiString compressed_bToString(const c_BertlvByteVector & value);

			/**
			* @param value CN data format
			* (according to iPOS Message and Command spec.)
			* @return The value converted c_DataRepresentationFramework::c_ISO_8859_1_String
			*/
			static c_DataRepresentationFramework::c_AsciiString cnToString(const c_BertlvByteVector & value);

			/**
			* @param value CN data format
			* (according to iPOS Message and Command spec.)
			* @return The value converted long
			*/
			static long cnToLong(const c_BertlvByteVector & value);

			/**
			* @param value N data format
			* (according to iPOS Message and Command spec.)
			* @return The value converted c_DataRepresentationFramework::c_ISO_8859_1_String
			*/
			static c_DataRepresentationFramework::c_AsciiString toN(const c_BertlvByteVector & value);

			/**
			* @param value Nb data format
			* (according to iPOS Message and Command spec.)
			* @return The value converted c_DataRepresentationFramework::c_ISO_8859_1_String
			*/
			static c_DataRepresentationFramework::c_AsciiString toNb(const c_BertlvByteVector & value);

			/**
			* @param tagList Taglist from pdoTagList
			* @return list of extracted tags
			*/
			static std::vector < t_TagValue > extractTagList(const c_BertlvByteVector & tagList);
		};


		///**
		//* Singleton.
		//* Handle for ipos dll interface
		//*/
		//class iPosHandle {
		//public:
		//	/**
		//	* @param dllfile path to dll file
		//	* @return returns an iPosHandle instance
		//	*/
		//	static iPosHandle * getInstance(const c_FilePath& dllfile_path);

		//	/**
		//	* Returns true if loaded api has provided function name
		//	* in its interface.
		//	*/
		//	bool apiHasFunction(const char* szMemberFunctionName);

		//	/**
		//	* Initializes the dll
		//	* @param ptr call back function pointer
		//	* @param id Id of terminal
		//	*/
		//	int init(iPosAPI::TOnRecvEvent ptr, const int id);

		//	/**
		//	* Writes data to ipos.
		//	* @param data buffer to write
		//	* @param dataLen length of data to write
		//	* @param id TODO
		//	*/
		//	int write(unsigned char * data, const int dataLen, const int id);

		//	/**
		//	* Reads data from ipos.
		//	* @param data buffer to read data into.
		//	* @param maxLen max length of data buffer
		//	* @param dataLen length of data written to buffer
		//	* @param id TODO
		//	*/
		//	int read(unsigned char * data, const int maxLen, int * dataLen, int id);

		//	/**
		//	* Closes ipos dll interface
		//	* @param id Id of terminal
		//	*/
		//	int close(const int id);

		//	/**
		//	* Reads version info from dll.
		//	* @param struct pointer to read version info into.
		//	*/
		//	int getVersion(iPosAPI::IPOS_VERSIONINFO * versionInfo);

		//	/**
		//	* Calls ipos API ipos_Conf
		//	*/
		//	int conf(const char* szConfigString, int Id);

		//	/**
		//	* Destructor
		//	*/
		//	virtual ~iPosHandle();

		//private:
		//	/**
		//	* Current instance
		//	*/
		//	static iPosHandle * instance;

		//	/**
		//	* Constructor
		//	*/
		//	iPosHandle(const HINSTANCE hDLL);

		//	/**
		//	* Private storage of function pointers to iPOS API
		//	*/
		//	iPosAPI::ipos_Init* m_fn_ipos_Init;
		//	iPosAPI::ipos_Write* m_fn_ipos_Write;
		//	iPosAPI::ipos_Read* m_fn_ipos_Read;
		//	iPosAPI::ipos_GetVersion* m_fn_ipos_GetVersion;
		//	iPosAPI::ipos_Close* m_fn_ipos_Close;
		//	iPosAPI::ipos_Conf* m_fn_ipos_Conf;

		//	/**
		//	* Private storage of this singleton instance
		//	*/
		//	const HINSTANCE hDLL;
		//};


		///**
		//* IPos message helper class.
		//*/
		//class iPosMessageHelper {
		//public:
		//	/**
		//	* Reads a message from iPOS
		//	* @param handle A handle to iPOS
		//	* @param maxlength Maximun length of message to read
		//	* @return A BerTlv.
		//	* IMPORTANT: The caller is responsible for deleting the BerTlv.
		//	* @throw exception in case of error
		//	*/
		//	static const BerTlv * readMessage(iPosHandle * handle, const int maxlen, int deviceNo);

		//	/**
		//	* Writes a message to iPOS
		//	* @param handle A handle to iPOS
		//	* @param message The message to write
		//	*/
		//	static int writeMessage(iPosHandle * handle, const BerTlv * message, int deviceNo);


		//private:

		//};


		/**
		* Two-way map between tag values and labels (e.g. cdoOP_INIT) used for debug prints.
		*/
		class TagConst : public TagLookupIfc {
		public:

			typedef std::pair < c_DataRepresentationFramework::c_ISO_8859_1_String, int > c_TagLabelPair;

			/**
			* Maps tag values to tag label strings
			*/
			typedef std::vector <c_TagLabelPair> c_TagLabelPairVector;

			/**
			* Constructor
			*/
			TagConst(const c_TagLabelPairVector& v = TagConst::createVector());
			//		TagConst(const c_TagLabelPairVector& v = c_TagLabelPairVector());

			/**
			* Destructor
			*/
			virtual ~TagConst();

			// Begin TagLookupIfc

			/**
			* returns true and sets sResult to the label of provided tag value
			* if it is found.
			*/
			virtual bool lookup(const t_TagValue tagvalue, c_DataRepresentationFramework::c_ISO_8859_1_String& sResult) const;

			//		/**
			//		 * @param tagvalue The tag value
			//		 * @return The label of the tag value
			//		 * @throw range_error If no label found
			//		 */
			//		virtual c_DataRepresentationFramework::c_ISO_8859_1_String lookup(const t_TagValue tagvalue) const;
			//
			//		/**
			//		 * @param taglabel The tag label
			//		 * @return The value of the tag label
			//		 * @throw range_error If no value found
			//		 */
			//		virtual int lookup(const c_DataRepresentationFramework::c_ISO_8859_1_String & taglabel) const;

			/**
			* This method can be used when no label is found on a look up.
			* Can return "N/A" or just an empty string ("") for example.
			* @return The string representing "no label present"
			*/
			virtual c_DataRepresentationFramework::c_ISO_8859_1_String getNoLabelAvailable() const;

			// End TagLookupIfc

			//		/**
			//		 * @return returns a pointer to a TagConst object
			//		 */
			//		static TagConst * getInstance();

		private:

			/**
			* Creates a std::vector of value-tag-pairs used to initialize the maps
			*/
			static c_TagLabelPairVector& createVector();

			//        /**
			//         * Current instance
			//         */
			//        static TagConst * instance;

			/**
			* Map from tag value to tag label
			*/
			std::map < int, c_DataRepresentationFramework::c_ISO_8859_1_String > m1;

			/**
			* Map from tag label to tag value
			*/
			std::map < c_DataRepresentationFramework::c_ISO_8859_1_String, int > m2;
		};

		/**
		* Formatter that formats provided BerTlv content in a maksed way
		* so that complete content may not be seen in Log output
		*/
		class ContentMaskedFormatter : public BerTlvPrimitiveContentsFormatterIfc {
		public:
			/**
			* Returns a formatted c_DataRepresentationFramework::c_ISO_8859_1_String of provided primitive content
			*/
			virtual c_DataRepresentationFramework::c_ISO_8859_1_String toString(const BerTlvPrimitiveContent * const content, const c_DataRepresentationFramework::c_ISO_8859_1_String& sIndent = _Literalsz(""));
		};


		/**
		* Formats output for several compressed numeric contents by
		* producing a hex nibble pair c_DataRepresentationFramework::c_ISO_8859_1_String of provided data
		* In BerTlv and iPOS hanldes CN, HB, cn etc.
		*/
		class HexNibblePairContentsFormatter : public BerTlvPrimitiveContentsFormatterIfc {
		public:
			/**
			* Returns a formatted c_DataRepresentationFramework::c_ISO_8859_1_String of provided primitive content
			*/
			virtual c_DataRepresentationFramework::c_ISO_8859_1_String toString(const BerTlvPrimitiveContent * const content, const c_DataRepresentationFramework::c_ISO_8859_1_String& sIndent = _Literalsz(""));
		};

		/**
		* Defines one field of a struct contents definition.
		*/
		class c_StructContentsFieldDefinition {
		public:
			/**
			* Constructor
			*/
			c_StructContentsFieldDefinition(c_DataRepresentationFramework::c_ISO_8859_1_String sCaption = _Literalsz("#name?#"), int fieldSizeInBytes = -1);

			/**
			* Copy constructor
			*/
			c_StructContentsFieldDefinition(const c_StructContentsFieldDefinition& other_instance);

			/**
			* Assignment operator
			*/
			c_StructContentsFieldDefinition& operator=(const c_StructContentsFieldDefinition& other_instance);

			/**
			* Returns this field caption
			*/
			c_DataRepresentationFramework::c_ISO_8859_1_String Caption();
			/**
			* Returns the size in bytes of this field
			*/
			int getFieldSizeInBytes();

		private:
			/**
			* Private storage of this field caption
			*/
			c_DataRepresentationFramework::c_ISO_8859_1_String m_sCaption;
			/**
			* Private storage of the size in bytes of this field
			*/
			int m_FieldSizeInBytes;
		};

		typedef std::vector<c_StructContentsFieldDefinition> c_StructContentsDefinition;

		/**
		* formats output according to provided struct definition.
		*/
		class StructContentsFormatter : public BerTlvPrimitiveContentsFormatterIfc {
		public:
			/**
			* Creates a structure contents formatter using the provided
			* structure definition.
			*/
			StructContentsFormatter(const c_StructContentsDefinition& structContentsDefinition);

			/**
			* Assignment operator
			*/
			StructContentsFormatter& operator=(const StructContentsFormatter& other_instance);

			/**
			* Returns a formatted c_DataRepresentationFramework::c_ISO_8859_1_String of provided primitive content
			*/
			virtual c_DataRepresentationFramework::c_ISO_8859_1_String toString(const BerTlvPrimitiveContent * const content, const c_DataRepresentationFramework::c_ISO_8859_1_String& sIndent = _Literalsz(""));
		private:
			/**
			* Private storage of structure definition to be asumed
			* when formatting putput.
			*/
			c_StructContentsDefinition m_StructContentsDefinition;
		};


		// 111201, Moved to iPOS Messaging frame work/KoH
		//	/**
		//	 * Creates a formatted receipt from provided receipt data
		//	 */
		//	c_DataRepresentationFramework::c_ISO_8859_1_String createReceiptString(const BerTlv * pCdoReceiptData);
	}; // namespace ipos

}