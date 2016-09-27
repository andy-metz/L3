#pragma once
#include <string>

using namespace std;


class Piece{
	string materiau;

public:
	Piece();
	Piece(const string &);
	Piece(const Piece &);
	virtual ~Piece();

	const string & getMateriau() const;
	void setMateriau(const string &);

	virtual double surface() const = 0;
	virtual Piece * clone() const = 0;
	virtual ostream & afficher(ostream &) const;

	const Piece & operator = (const Piece &);

	friend ostream & operator << (ostream & f, Piece &);

};