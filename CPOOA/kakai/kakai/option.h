#pragma once;
#include <string>

using namespace std;

class MeubleBase;

class Option{
	string designation;
	MeubleBase * meubleBase;

public:
	Option();
	Option(const string & d);
	Option(const Option &);
	virtual ~Option();

	const string & getDesignation() const;
	void setDesignation(const string &);

	virtual double prix() const = 0;
	virtual Option * clone() const = 0;
	virtual ostream & afficher(ostream &) const;

	const Option & operator = (const Option &);

	friend ostream & operator << (ostream & f, Option &);
};