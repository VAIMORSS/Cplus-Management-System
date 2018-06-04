// Final Project
//name: Vaibhav Moradiya
//ID: 146828165
//Program: CPD
//Course: OOP244
//============================================================================

#include <iostream>
#include "Perishable.h"
#include "ErrorMessage.h"
#include "Date.h"


using namespace std;
namespace sict {

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		NonPerishable::store(file, false);
		file << "," << expiry_date;
		if (newLine) {
			file << std::endl;
		}
		return file;
	}

	std::fstream& Perishable::load(std::fstream& file) {
		NonPerishable::load(file);
		file >> expiry_date;
		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		NonPerishable::write(os, linear);
		if (isClear()) {
			if (linear) {
				expiry_date.write(os);
			}
			else {
				os << endl << "Expiry date: " << expiry_date;
			}
		}
		return os;
	}

	std::istream& Perishable::read(std::istream& is) {
		NonPerishable::read(is);
		if (isClear()) {
			cout << "Expiry date (YYYY/MM/DD): ";
			Date date;
			date.Date::read(is);

			if (date.errCode() == NO_ERROR) {
				expiry_date = date;
			}
			else {
				switch (date.errCode()) {
				case CIN_FAILED:
					message("Invalid Date Entry");
					break;
				case YEAR_ERROR:
					message("Invalid Year in Date Entry");
					break;
				case MON_ERROR:
					message("Invalid Month in Date Entry");
					break;
				case DAY_ERROR:
					message("Invalid Day in Date Entry");
					break;
				}
				is.setstate(ios::failbit);
			}
		}
		return is;
	}

}
