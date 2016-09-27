#pragma once
#include <vector>
#include "meuble.h"
#include "option.h"

using namespace std;


class MeubleBase: public Meuble{
	double prixBase;
	double largeur;
	double hauteur;
	double profondeur;
	vector <Option *> options;

public:
	MeubleBase();
	MeubleBase(const string & d, double l, double h, double prof, double prix);
	MeubleBase(const MeubleBase &);
	virtual ~MeubleBase();

	const string & getDesignation() const;
	void setDesignation(const string &);

	double prix() const;
	MeubleBase * clone() const;
	ostream & afficher(ostream &) const;


	const MeubleBase & operator = (const MeubleBase &);

	friend ostream & operator << (ostream & f, MeubleBase &);

};