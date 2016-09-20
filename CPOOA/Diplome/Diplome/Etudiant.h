#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <iostream>
#include <string>
#include "Diplome.h"

using namespace std;

class Etudiant
{
	string nom;
	int age;
	bool boursier;
	int * diplome;

public:
	Etudiant(const Etudiant &);
	Etudiant(const string & n, int a, bool b, Diplome * d);
	virtual ~Etudiant();

	// getter and setter
	const string & getNom() const:
	void setNom(const string &);

	int getAge() const;
	void setAge(int);

	bool getBoursier() const;
	void setBoursier(bool);

	Diplome * getDiplome() const;
	void setDiplome(Diplome *);

	const Etudiant & operator = (const Etudiant &);

	bool operator == (const Etudiant &) const;
	bool operaator != (const Etudiant &e){ return !(*this == e); }

};


#endif