#pragma once
#include <iostream>
#include <string>


using namespace std;
class Diplome;

class Etudiant
{
	string nom;
	int age;
	bool boursier;
	int * diplome;

public:
	Etudiant();
	Etudiant(const Etudiant &);
	Etudiant(const string & n, int a, bool b, Diplome * d);
	virtual ~Etudiant();

	// getter and setter
	const string & getNom() const;
	void setNom(const string &);

	int getAge() const;
	void setAge(int);

	bool getBoursier() const;
	void setBoursier(bool);

	Diplome * getDiplome() const;
	void setDiplome(Diplome *);

	const Etudiant & operator = (const Etudiant &);
	bool operator == (const Etudiant &) const;
	bool operator != (const Etudiant &e){ return !(*this == e); }

	friend ostream & operator << (ostream &f, const Etudiant &);

};
