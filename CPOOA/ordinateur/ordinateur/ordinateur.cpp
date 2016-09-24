#include "ordinateur.h"
#include <iostream>
#include "ExTP1.h"

Ordinateur::Ordinateur() :nom(string("")){}

Ordinateur::Ordinateur(const Ordinateur & o) : nom(o.nom){
	for (unsigned int i = 0; i < o.composants.size(); i++)
		composants.push_back(o.composants[i]->clone());
}

Ordinateur::Ordinateur(const string & n) : nom(n){

}


Ordinateur::~Ordinateur(){
	for (int i = 0; i < composants.size(); i++)
		delete composants[i];
}


// getters and setters
const string & Ordinateur::getNom() const{
	return nom;
}
void Ordinateur::setNom(const string & n){
	nom = n;
}


const Ordinateur & Ordinateur::operator = (const Ordinateur & o){
	if (this != &o)
	{
		nom = o.nom;


		for (int i = 0; i < composants.size(); i++)
			delete composants[i];
		composants.clear();

		if (!o.composants.empty())
		{
			for (unsigned int i = 0; i < o.composants.size(); i++)
				composants.push_back(o.composants[i]->clone());
		}
	}
	return *this;
}


const Composant * Ordinateur::operator[] (const int i) const
{
	return composants[i];
}

Ordinateur Ordinateur::operator + (const Composant * c) const
{
	Ordinateur o(*this);
	o.composants.push_back(c->clone());
	return o;
}

void Ordinateur::supprime(const int i){
	if (i < 0 || i >= composants.size()) 
		throw exTP1("Index hors limite");

	composants.erase(composants.begin() + i);
}

double Ordinateur::prix() const{
	double somme = 0;
	for (unsigned int i = 0; i < composants.size(); i++)
		somme += composants[i]->prix();
	return somme;
}

void Ordinateur::operator += (const Composant * c){
	static Ordinateur o(*this);
	o.composants.push_back(c->clone());
}



ostream & operator << (ostream & f, const Ordinateur & o){
	f << o.nom << ":" << endl;
	for (int i = 0; i < o.composants.size(); i++)
		o.composants[i]->afficher(f);
	return f;
}
