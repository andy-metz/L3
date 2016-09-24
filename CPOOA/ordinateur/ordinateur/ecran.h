#pragma once

#include "composant.h"

class Ecran : public Composant{


	int format;
	int taille;
	int pitch;

public:
	static const int VGA = 1;
	static const int SVGA = 2;
	static const int QSXGA = 3;


	Ecran();
	Ecran(const Ecran &);
	Ecran(const string & description, const int format, const int taille, const int pitch);
	~Ecran();


	// getters et setters
	int getFormat() const;
	void setFormat(const int);

	int getTaille() const;
	void setTaille(const int);

	int getPitch() const;
	void setPitch(const int);

	double prix() const;
	Composant * clone() const;
	ostream &  afficher(ostream &) const;

	const Ecran & operator = (const Ecran &);
	bool operator == (const Ecran &) const;
	bool operator != (const Ecran & e)const { return !(*this == e); }



	friend ostream & operator << (ostream & f, Ecran & e);
};