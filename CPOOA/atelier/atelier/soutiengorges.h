#pragma once
#include "Piece.h"

class Soutiengorges : public Piece{

	int tourPoitrine;
	char bonnet;

public:
	Soutiengorges();
	Soutiengorges(const string &, int, char);
	Soutiengorges(const Soutiengorges &);
	virtual ~Soutiengorges();

	const int & getTourPoitrine() const;
	void setTourPoitrine(const int);

	const char getBonnet() const;
	void setBonnet(char);

	double surface() const;
	Soutiengorges * clone() const;
	virtual ostream & afficher(ostream &) const;

	const Soutiengorges & operator = (const Soutiengorges &);

	friend ostream & operator << (ostream &, const Soutiengorges &);
};