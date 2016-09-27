#pragma once
#include <string>

using namespace std;


class Meuble{
	string designation;


public:
	Meuble();
	Meuble(const string &);
	Meuble(const Meuble &);
	virtual ~Meuble();

	const string & getDesignation() const;
	void setDesignation(const string &);

	virtual double prix() const = 0;
	virtual Meuble * clone() const = 0;
	virtual ostream & afficher(ostream &) const;

	const Meuble & operator = (const Meuble &);

	friend ostream & operator << (ostream & f, Meuble &);

};