// Final Project
//name: Vaibhav Moradiya
//ID: 146828165
//Program: CPD
//Course: OOP244
//============================================================================
#ifndef SICT_NONPERISHABLE_H
#define SICT_NONPERISHABLE_H
#include "ErrorMessage.h"
#include "Product.h"
#include <iostream>
#include <fstream>

namespace sict {
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13;

	class NonPerishable : public Product {
	private:
		char m_productType;
		char m_productSku[max_sku_length + 1];
		char* m_productName;
		char m_productUnit[max_unit_length + 1];
		int m_quantityOnHand;
		int m_quantityNeeded;
		double m_priceBeforeTax;
		bool m_isTaxable;

	protected:
		ErrorMessage error;
		void name(const char*);
		const char* name() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;

	public:
		 NonPerishable();
		NonPerishable(const char ) ;
		NonPerishable(const char* , const char* , const char*, int quantityOnHand = 0, bool isTaxable = true, double priceBeforeTax = 0, int quantityNeeded = 0);
		NonPerishable(const NonPerishable&);
		NonPerishable& operator=(const NonPerishable&);

		~NonPerishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		bool operator>(const char*) const;
		int operator+=(int);
		bool operator>(const Product&) const;
		int qtyNeeded() const;
		int quantity() const;
		void forContructor();

	};

	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
	Product* CreateProduct();
}
#endif
