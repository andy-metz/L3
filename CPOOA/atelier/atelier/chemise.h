#pragma once
#include "Piece.h"

class Chemise : public Piece{

	int taille;

public:
	Chemise();
	Chemise(const string &, int);
	Chemise(const Chemise &);
	virtual ~Chemise();

	const int & getTaille() const;
	void setTaille(const int);

	double surface() const;
	Chemise * clone() const;
	virtual ostream & afficher(ostream &) const;

	const Chemise & operator = (const Chemise &);

	friend ostream & operator << (ostream &, const Chemise &);
};