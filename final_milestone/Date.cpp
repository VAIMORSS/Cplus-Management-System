// Final Project
//name: Vaibhav Moradiya
//ID: 146828165
//Program: CPD
//Course: OOP244
//============================================================================

#include "Date.h"

using namespace std;

namespace sict {
	int Date::value() const {

		return m_year * 372 + m_month * 31 + m_day;
	}


	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errcd) {
		m_readerrorcode = errcd;
	}

	Date::Date() {
		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_readerrorcode = NO_ERROR;
	}

	Date::Date(int c_year, int c_month, int c_day) {

		if (c_year >= min_year && c_year <= max_year && c_month <= 12 && c_month >= 1 && mdays(c_month, c_year)) {
			m_year = c_year;
			m_month = c_month;
			m_day = c_day;
			m_readerrorcode = NO_ERROR;
		}
		else {
			*this = Date();//corrected code duplication
		}
	}


	istream & Date::read(istream & istr) {

		istr >> m_year;
		istr.ignore();
		istr >> m_month;
		istr.ignore();
		istr >> m_day;



		if (!(istr.fail())) {
			if (m_year < min_year || m_year > max_year)
			{
				m_year = 0;
				m_month = 0;
				m_day = 0;
				m_readerrorcode = YEAR_ERROR;
			}
			else if (m_month < 1 || m_month > 12)
			{
				m_year = 0;
				m_month = 0;
				m_day = 0;
				m_readerrorcode = MON_ERROR;
			}
			else if (m_day < 1 || m_day > mdays(m_month, m_year))
			{
				m_year = 0;
				m_month = 0;
				m_day = 0;
				m_readerrorcode = DAY_ERROR;
			}
			else
			{
				m_readerrorcode = NO_ERROR;
			}
		}

		else
			m_readerrorcode = NO_ERROR;

		return istr;
	}


	ostream & Date::write(ostream & ostr) const {
		ostr << m_year << "/";
		(m_month >= 0 && m_month <= 9) ? ostr << "0" << m_month << "/" : ostr << m_month << "/";
		(m_day >= 0 && m_day <= 9) ? ostr << "0" << m_day : ostr << m_day;
		return ostr;
	}


	ostream & operator<<(ostream & ostr, const Date & d) {
		d.write(ostr);
		return ostr;
	}

	istream & operator>>(istream & istr, Date & d) {
		d.read(istr);
		return istr;
	}



	bool Date::operator==(const Date & rhs) const
	{
		return (this->value() == rhs.value()) ? true : false;
	}

	bool Date::operator!=(const Date & rhs) const
	{
		return (this->value() != rhs.value()) ? true : false;
	}

	bool Date::operator<(const Date & rhs) const
	{
		return (this->value() < rhs.value()) ? true : false;
	}

	bool Date::operator>(const Date & rhs) const
	{
		return (this->value() > rhs.value()) ? true : false;
	}

	bool Date::operator<=(const Date & rhs) const
	{
		return (this->value() <= rhs.value()) ? true : false;
	}

	bool Date::operator>=(const Date & rhs) const
	{
		return (this->value() >= rhs.value()) ? true : false;
	}

	int Date::errCode() const {
		return m_readerrorcode;
	}

	bool Date::bad() const {
		return (errCode() != 0) ? true : false;
	}
}
