// Final Project
//name: Vaibhav Moradiya
//ID: 146828165
//Program: CPD
//Course: OOP244
//============================================================================


#ifndef SICT_ERRORMESSAGE_H
#define SICT_ERRORMESSAGE_H

#include <iostream>
#include <cstring>

namespace sict
{
	class ErrorMessage
	{
		char *m_errorMessage;

	public:
		explicit ErrorMessage(const char *errorMessage = nullptr);
		ErrorMessage(const ErrorMessage&) = delete;
		ErrorMessage& operator=(const ErrorMessage&) = delete;
		virtual ~ErrorMessage();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char *message() const;
		friend std::ostream& operator<<(std::ostream&, const ErrorMessage&);
	};
	std::ostream& operator<<(std::ostream&, const ErrorMessage&);
}
#endif //!SICT_ERRORMESSAGE_H
