#pragma once
#include <string>

using namespace std;

class Composant{
	string description;

public:
	Composant();
	Composant(const string &);
	Composant(const Composant &);
	virtual ~Composant();

	//
	const string & getDescription() const;
	void setDescription(const string &);


	virtual double prix() const = 0;
	virtual  Composant * clone() const = 0;
	virtual ostream & afficher(ostream &) const;


	const Composant * operator=(const Composant *);

	virtual bool operator == (const Composant *) const;

};