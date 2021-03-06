// Final Project
//name: Vaibhav Moradiya
//ID: 146828165
//Program: CPD
//Course: OOP244
//============================================================================

#include <iostream>
#include <cstring>
#include<fstream>
#include <iomanip>
#include "Product.h"
#include "NonPerishable.h"


using namespace std;
namespace sict {

	const char* NonPerishable::name() const {
		return m_productName == nullptr ? nullptr : m_productName;
	}

	double NonPerishable::cost() const {
		return m_isTaxable ? (m_priceBeforeTax*(1 + tax_rate)) : m_priceBeforeTax;
	}

	void NonPerishable::message(const char* errorMessage) {
		error.message(errorMessage);
	}

    bool NonPerishable::isClear() const {
		return error.isClear();
	}

	void NonPerishable::forContructor() {
		m_productSku[0] = '\0';
		m_productName = nullptr;
		m_productUnit[0] = '\0';
		m_quantityOnHand = 0;
		m_quantityNeeded = 0;
		m_priceBeforeTax = 0;
		error.clear();
	}

	NonPerishable::NonPerishable() {
		m_productType = 'N';
		forContructor();
	}

	NonPerishable::NonPerishable(const char productType)
	{
		m_productType = productType;
		forContructor();
	}

	NonPerishable::NonPerishable(const char* productSku,
		const char* productName,
		const char *productUnit,
		int quantityOnHand,
		bool isTaxable,
		double priceBeforeTax,
		int quantity_needed)
	{
		m_productType = '\0';
		strcpy(m_productSku, productSku);
		m_productName = new char[strlen(productName) + 1];
		strcpy(m_productName, productName);
		strcpy(m_productUnit, productUnit);
		m_quantityOnHand = quantityOnHand;
		m_isTaxable = isTaxable;
		m_priceBeforeTax = priceBeforeTax;
		m_quantityNeeded = quantity_needed;

	}

    NonPerishable::NonPerishable(const NonPerishable& obj) {
		*this = obj;
	}

	NonPerishable& NonPerishable::operator = (const NonPerishable& temp) {
		if (this != &temp) {
			m_productName = new char[strlen(temp.m_productName) + 1];
			strcpy(m_productName, temp.m_productName);
			strcpy(m_productSku, temp.m_productSku);
			strcpy(m_productUnit, temp.m_productUnit);
			m_quantityOnHand = temp.m_quantityOnHand;
			m_isTaxable = temp.m_isTaxable;
			m_priceBeforeTax = temp.m_priceBeforeTax;
			m_quantityNeeded = temp.m_quantityNeeded;
		}
      return *this;
	}


	NonPerishable::~NonPerishable() {
		delete[]m_productName;
		m_productName = nullptr;
	}

	//storing value in the file
    std::fstream& NonPerishable::store(std::fstream& file, bool newLine) const {
		if (file.is_open()) {
			file << this->m_productType
				<< ','
				<< this->m_productSku
				<< ','
				<< this->m_productName
				<< ','
				<< this->m_priceBeforeTax
				<< ','
				<< this->m_isTaxable
				<< ','
				<< this->m_quantityOnHand
				<< ','
				<< this->m_productUnit
				<< ','
				<< this->m_quantityNeeded;
		}
		if (newLine) {
			file << endl;
		}
		return file;
	}

	//loading data from file and making a object of Non... class
	std::fstream& NonPerishable::load(std::fstream& file) {
		char sku_[max_sku_length];
		char name_[max_name_length];
		char unit_[max_unit_length];
		int Quantity_;
		int qtyNeeded_;
		bool istaxed_;
		double price_;
				      
		if (file.is_open()) {
			file.getline(sku_, max_sku_length + 1, ',');
			file.getline(name_, max_name_length, ',');
			file >> price_;
			file.ignore();
			file >> istaxed_;
			file.ignore();
			file >> Quantity_;
			file.ignore();
			file.getline(unit_, max_unit_length, ',');
			file >> qtyNeeded_;
			file.ignore();
			NonPerishable temp(sku_, name_, unit_, Quantity_, istaxed_, price_, qtyNeeded_);
			*this = temp;
			//seting value in the object
			//why the direct assining is not working???

		}
		return file;
	}

	//making string for a good output for user only when the all values are acceptable
	std::ostream& NonPerishable::write(std::ostream& os, bool linear) const {
		if (!error.isClear()) {
			os << error.message();
			//sending error message in spite of sending the object loaded of
			//garbadge or the wrong value
			//never forget to work on this part
		}
		else {
			if (linear) {
				os << setw(max_sku_length) << left << setfill(' ')
					<< m_productSku << '|'
					<< setw(20) << left << setfill(' ')
					<< m_productName << '|'
					<< setw(7) << right << setfill(' ') << fixed << setprecision(2)
					<< cost() << '|'
					<< setw(4) << right << setfill(' ')
					<< m_quantityOnHand << '|'
					<< setw(10) << left << setfill(' ')
					<< m_productUnit << '|'
					<< setw(4) << right << setfill(' ')
					<< m_quantityNeeded << '|';
			}else {
				os << "Sku: " << m_productSku << endl;
				os << "Name: " << m_productName << endl;
				os << "Price: " << m_priceBeforeTax << endl;
				if (m_isTaxable) {
					os << "Price after tax: " << cost() << endl;
				}
				else {
					os << "Price after tax: " << "N/A" << endl;
				}
				os << "Quantity On Hand: " << m_quantityOnHand <<" "<< m_productUnit<< endl;
				os << "Quantity Needed: " << m_quantityNeeded;
			}
		}
		return os;
	}

	//reading from user for testing
	std::istream& NonPerishable::read(std::istream& is) {

		this->message(nullptr);
		char sku_[max_sku_length];
		char name_[max_name_length];
		char unit_[max_unit_length];
		char taxed_;
		double price_;
		int Quantity_;
		int qtyNeeded_;
		bool istaxed_;

		if (error.isClear()) {
			cout << " Sku: ";
			is >> sku_;
			cout << " Name: ";
			is >> name_;
			cout << " Unit: ";
			is >> unit_;

			if (!is.fail()) {
				cout << " Taxed? (y/n): ";
				is >> taxed_;
				if (taxed_ == 'Y' || taxed_ == 'y') {
					istaxed_ = true;
				}
				else if (taxed_ == 'N' || taxed_ == 'n') {
					istaxed_ = false;
				}
				else {
					is.istream::setstate(std::ios::failbit);
					error.message("Only (Y)es or (N)o are acceptable");
				}
			}
			if (!is.fail() ) {
				cout << " Price: ";
				is >> price_;
				if (is.fail() || price_<0) {
					error.message("Invalid Price Entry");
				}
			}
			if (!is.fail()) {
				cout << "Quantity On hand: ";
				is >> Quantity_;
				if (is.fail() || Quantity_<0) {
					error.message("Invalid Quantity Entry");
				}
			}
			if (!is.fail()) {
				cout << "Quantity Needed: ";
				is >> qtyNeeded_;
				if (is.fail() || qtyNeeded_<0) {
					error.message("Invalid Quantity Needed Entry");
				}
			}
	   if (!is.fail()) {
				NonPerishable temp(sku_,name_,unit_,Quantity_,istaxed_,price_,qtyNeeded_);
				*this = temp;
			}
		}
		return is;
	}


	bool NonPerishable::operator==(const char* sku) const {
		return strcmp(m_productSku, sku) == 0;
	}

	double NonPerishable::total_cost() const {
		return cost() *m_quantityOnHand;
	}

	void NonPerishable::quantity(int qty) {
		m_quantityOnHand = qty;
	}

	bool NonPerishable::isEmpty() const {
		return m_productName == nullptr;
	}

	int NonPerishable::qtyNeeded() const {
		return m_quantityNeeded;
	}

	int NonPerishable::quantity() const {
		return m_quantityOnHand;
	}

	bool NonPerishable::operator>(const char* sku) const {
		return strcmp(m_productSku, sku) > 0;
	}
	int NonPerishable::operator+=(int newquantityOnHand)
	{
		if (newquantityOnHand > 0) {
			return m_quantityOnHand += newquantityOnHand;
		}
		return m_quantityOnHand;
	}

	bool NonPerishable::operator>(const Product& object) const {
		return strcmp(m_productName, name()) > 0;
	}

	std::ostream& operator<<(std::ostream& out, const Product& object) {
		object.write(out, true);
		return out;
	}

	std::istream& operator>>(std::istream& in, Product&object) {
		object.read(in);
		return in;
	}

	double operator+=(double& totalcost, const Product& obj) {
		return (totalcost += obj.total_cost());
	}

	Product* CreateProduct() {
		Product* p = nullptr;
		p = new NonPerishable('\0');
		return p;
	}
}
