// Final Project
//name: Vaibhav Moradiya
//ID: 146828165
//Program: CPD
//Course: OOP244
//============================================================================

#include<iostream>
#include"ErrorMessage.h"
#include <cstring>
#include <string>

using namespace std;
namespace sict {

	ErrorMessage::ErrorMessage(const char* errorMessage) {
		if (errorMessage == nullptr) {
			m_errorMessage = nullptr;
		}
		else {
			m_errorMessage = new char[strlen(errorMessage) + 1];
			strcpy(m_errorMessage, errorMessage);
		}

	}
    ErrorMessage::~ErrorMessage() {
		clear();
	}

	void ErrorMessage::clear() {
		if (m_errorMessage != nullptr) {
			delete[] m_errorMessage;
			m_errorMessage = nullptr;
		}
	}

	bool ErrorMessage::isClear() const {
		return m_errorMessage == nullptr;
	}

	void ErrorMessage::message(const char* str) {
		clear();
		if (str != nullptr) {
			m_errorMessage = new char[strlen(str) + 1];
			strcpy(m_errorMessage, str);
		}
	}



	const char* ErrorMessage::message()const {
		return m_errorMessage;
	}


	std::ostream& operator<<(std::ostream& out, const ErrorMessage& error) {
		if (!error.isClear()) {
			return out << error.message();
		}
		return out;
	}
}
