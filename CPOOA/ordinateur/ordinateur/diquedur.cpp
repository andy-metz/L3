#include "DisqueDur.h"
#include <iostream>


DisqueDur::DisqueDur(){}

DisqueDur::DisqueDur(const DisqueDur & dd)
	:Composant(dd), capacite(dd.capacite), vitesse(dd.vitesse){}

DisqueDur::DisqueDur(const string & description, const int c, const int v)
	: Composant(description), capacite(c), vitesse(v){}

DisqueDur::~DisqueDur(){}


double DisqueDur::prix() const{
	return 0;
}



int DisqueDur::getCapacite() const{
	return capacite;
}
void DisqueDur::setCapacite(const int f){
	capacite = f;
}

int DisqueDur::getVitesse() const{
	return vitesse;
}
void DisqueDur::setVitesse(const int v){
	vitesse = v;
}



Composant * DisqueDur::clone() const{
	return new DisqueDur(*this);
}





const DisqueDur & DisqueDur::operator = (const DisqueDur & dd)
{
	if (this != &dd){
		Composant::operator=(dd);
		capacite = dd.capacite;
		vitesse = dd.vitesse;
	}

	return *this;
}


bool DisqueDur::operator == (const DisqueDur & dd) const{
	return this->Composant::operator==(&dd) && capacite == dd.capacite && vitesse == dd.vitesse;
}


ostream &  DisqueDur::afficher(ostream & f) const{
	Composant::afficher(f);
	f << capacite << ":" << vitesse << endl;
	return f;
}

ostream & operator << (ostream & f, DisqueDur & e){
	return e.afficher(f);
}