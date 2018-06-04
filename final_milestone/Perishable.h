
// Final Project
//name: Vaibhav Moradiya
//ID: 146828165
//Program: CPD
//Course: OOP244
//============================================================================
#ifndef SICT_PERISHABLE_H__
#define SICT_PERISHABLE_H__
#include "Product.h"
#include "Date.h"
#include "ErrorMessage.h"
#include "NonPerishable.h"

namespace sict
{
	class Perishable : public NonPerishable
	{
	private:
		Date expiry_date;

	public:
		Perishable() : NonPerishable('P')
		{};
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);

		const Date& expiry() const {
			return expiry_date;
		}

		Product* CreatePerishable() {
			Product* p = nullptr;
			p = new Perishable;
			return p;
		}
	};
}
#endif
