#pragma once;
#include "piece.h"

class Atelier{
	string nom;
	int nbp;
	Piece * patron;

public:
	Atelier();
	Atelier(string, const Piece *);
	Atelier(const Atelier &);
	virtual ~Atelier();

	const string & getNom() const;
	void setNom(const string &);

	int getNbp() const;

	Piece * getPatron() const;
	void setPatron(const Piece &);

	int surfaceUtilisee() const;

	Piece * fabriquePiece();

	const Atelier & operator = (const Atelier &);

	friend ostream & operator << (ostream & f, const Atelier &);


};