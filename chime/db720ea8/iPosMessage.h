#pragma once
#include <memory> // std::unique_ptr,...
#include "TestBenchReused.h"

namespace ipos {

	using BertlvByteVector = testbench::bertlv::c_BertlvByteVector;

	struct ipos_span {
		unsigned char* Data;
		int DataLen;
		unsigned char* begin() { return Data; }
		unsigned char* end() { return &Data[DataLen]; }
		const unsigned char* begin() const { return Data; }
		const unsigned char* end() const { return &Data[DataLen]; }
	};

	class Message {
	public:
		Message(const BertlvByteVector& v);
		Message(const ipos_span& span);
		~Message();

		BertlvByteVector make_vector();
	private:
		struct impl;
		std::unique_ptr<impl> pimpl;
	};

}


