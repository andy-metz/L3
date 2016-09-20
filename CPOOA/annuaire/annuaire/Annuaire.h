#pragma once
#include <iostream>
#include "Contact.h"

using namespace std;

class Annuaire{
	char *nom;
	Contact * c;
	int nb;
public:
	Annuaire();
	Annuaire(const char*);
	Annuaire(const Annuaire &);
	~Annuaire();

	const char * getNom() const;
	void setNom(const char *);

	int getNb() const;

	const Contact & recherche(const char *nom, const char *prenom) const;
	const Contact & operator[](int i) const;
	void supprime(const Contact &);
	void supprime(int i);
	Annuaire operator + (const Contact &) const;
	bool contient(const char * nom, const char * prenom) const;
	const Annuaire & operator = (const Annuaire &);

	friend ostream & operator << (ostream &, const Annuaire &);
};
