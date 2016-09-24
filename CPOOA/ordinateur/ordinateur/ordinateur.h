#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "composant.h"

class Ordinateur{
	string nom;
	vector<Composant *> composants;

public:
	Ordinateur();
	Ordinateur(const Ordinateur &);
	Ordinateur(const string &);

	virtual ~Ordinateur();

	// getters and setters
	const string & getNom() const;
	void setNom(const string &);




	const Ordinateur & operator = (const Ordinateur &);

	const Composant * operator[] (const int) const;
	Ordinateur operator + (const Composant *) const;

	void supprime(const int);
	double prix() const;

	void operator += (const Composant *);





	friend ostream  & operator << (ostream & f, const Ordinateur &);

};