#pragma once
#include <iostream>
//#include "Contact.h"

using namespace std;

#define MOBILE 1
#define DOMICILE 2
#define BUREAU 3

class Telephone{
	char * numero;
	int type;

public:
	Telephone();
	Telephone(const Telephone &);
	Telephone(int, const char *);
	~Telephone();

	const char  * getNumero() const;
	void setNumero(const char *);

	int getType() const;
	void setType(int);

	Telephone& operator=(const Telephone &);



	bool operator == (const Telephone &) const;
	bool operator !=(const Telephone &t){ return !(*this == t); }


	friend ostream & operator<<(ostream &, const Telephone&);
};