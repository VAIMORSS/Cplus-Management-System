// Final Project
//name: Vaibhav Moradiya
//ID: 146828165
//Program: CPD
//Course: OOP244
//============================================================================

#ifndef SICT_DATE_H_
#define SICT_DATE_H_

const int min_year = 2000;
const int max_year = 2030;

const int NO_ERROR = 0;
const int CIN_FAILED = 1;
const int YEAR_ERROR = 2;
const int MON_ERROR = 3;
const int DAY_ERROR = 4;

#include <iostream>

namespace sict {


	class Date {
	private:
		int m_year;
		int m_month;
		int m_day;
		int m_readerrorcode;
		int value() const;
		void errCode(int errorCode);
	public:
		Date();
		Date(int year, int month, int day);
		int mdays(int, int) const;
		std::istream & read(std::istream & istr);
		std::ostream & write(std::ostream & ostr) const;
		bool operator==(const Date & rhs) const;
		bool operator!=(const Date & rhs) const;
		bool operator<(const Date & rhs) const;
		bool operator>(const Date & rhs) const;
		bool operator<=(const Date & rhs) const;
		bool operator>=(const Date & rhs) const;
		int errCode() const;
		bool bad() const;
	};
	std::ostream & operator<<(std::ostream & ostr, const Date & d);
	std::istream & operator>>(std::istream & istr, Date & d);
}
#endif
