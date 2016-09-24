#pragma once

#include "composant.h"

class DisqueDur : public Composant{


	int capacite;
	int vitesse;


public:

	DisqueDur();
	DisqueDur(const DisqueDur &);
	DisqueDur(const string & description, const int capacite, const int vitesse);
	~DisqueDur();


	// getters et setters
	int getCapacite() const;
	void setCapacite(const int);

	int getVitesse() const;
	void setVitesse(const int);



	double prix() const;
	Composant * clone() const;
	ostream &  afficher(ostream &) const;

	const DisqueDur & operator = (const DisqueDur &);
	bool operator == (const DisqueDur &) const;
	bool operator != (const DisqueDur & dd)const { return !(*this ==dd); }



	friend ostream & operator << (ostream & f, DisqueDur &);
};