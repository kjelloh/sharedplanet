#include "iPosMessage.h"
#include <iterator> // std::begin(), ...

namespace ipos {

	using BerTlv = testbench::ipos::BerTlv;
	using BerTlvParser = testbench::ipos::BerTlvParser;

	struct Message::impl {
		const std::unique_ptr<const BerTlv> m_pBerTlv; // For now unmutable
		// Construct by moving from de-referenced temporary unique_ptr (Todo: Refactor this code to have parse return by value)
		// Note: The temporary unique_ptr will destruct after the call to m_BerTlv (destructing the moved-from object)
		impl(const BertlvByteVector& v) : m_pBerTlv(BerTlvParser::parseBerTlv(v)) {}
		~impl() = default;
		BertlvByteVector make_vector() { return m_pBerTlv->byteVector(); }
	};

	Message::Message(const BertlvByteVector& v) : pimpl(new impl(v)) {}
	Message::Message(const ipos_span& span) : Message(BertlvByteVector(std::begin(span),std::end(span))) {}
	Message::~Message() {}

	BertlvByteVector Message::make_vector() { return pimpl->make_vector(); }

}
