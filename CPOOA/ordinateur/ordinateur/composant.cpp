#include "composant.h"
#include <iostream>

using namespace std;


Composant::Composant() :description(string("")){}

Composant::Composant(const string & d) : description(d){}

Composant::Composant(const Composant & c) : description(c.description){}

Composant::~Composant(){}


//
const string & Composant::getDescription() const{
	return description;
}
void Composant::setDescription(const string & d){
	description = d;
}



ostream & Composant::afficher(ostream & f) const{
	f << description << endl;
	return f;
}

const Composant * Composant::operator=(const Composant * c){
	if (this != c)
		description = c->description;
	return this;
}

bool Composant::operator == (const Composant * c) const{
	return description == c->description;
}