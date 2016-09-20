#pragma once
#include <iostream>
#include "Telephone.h"

using namespace std;

class Contact{
	char *nom;
	char * prenom;
	Telephone * tel;
	int nb;

public:
	Contact();
	Contact(const Contact &);
	Contact(const char *p, const char * n);
	~Contact();

	const char * getNom() const;
	void setNom(const char *);

	const char * getPrenom() const;
	void setPrenom(const char *);

	int getNb() const;

	const Telephone & operator[](int i) const;

	Contact operator + (const Telephone &) const;

	void supprime(int indice);

	void operator += (const Telephone &);

	const Contact & operator = (const Contact &);

	friend ostream & operator << (ostream & f, const Contact &);
};