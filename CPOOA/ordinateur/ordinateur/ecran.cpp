#include "ecran.h"
#include <iostream>


Ecran::Ecran(){}

Ecran::Ecran(const Ecran & e) 
	:Composant(e), format(e.format), taille(e.taille), pitch(e.pitch){}

Ecran::Ecran(const string & description, const int format, const int taille, const int pitch)
	: Composant(description), format(format), taille(taille), pitch(pitch){}

Ecran::~Ecran(){}


double Ecran::prix() const{
	switch (format){
	case VGA:
		return taille * 50 + pitch * 150;
	case SVGA:
		return taille * 60 + pitch * 180;
	case QSXGA:
		return taille * 80 + pitch * 200;

	}
}



int Ecran::getFormat() const{
	return format;
}
void Ecran::setFormat(const int f){
	format = f;
}

int Ecran::getTaille() const{
	return taille;
}
void Ecran::setTaille(const int t){
	taille = t;
}

int Ecran::getPitch() const{
	return pitch;
}
void Ecran::setPitch(const int p){
	pitch = p;
}


Composant * Ecran::clone() const{
	return new Ecran(*this);
}





const Ecran & Ecran::operator = (const Ecran & e)
{
	if (this != &e){
		Composant::operator=(e);
		format = e.format;
		taille = e.taille;
		pitch = e.pitch;
	}

	return *this;
}


bool Ecran::operator == (const Ecran & e) const{
	return this->Composant::operator==(&e) && format == e.format && taille == e.taille && pitch == e.pitch;
}


ostream &  Ecran::afficher(ostream & f) const{
	Composant::afficher(f);
	f << format << ":" << taille << ":" << pitch << endl;
	return f;
}

ostream & operator << (ostream & f, Ecran & e){
	return e.afficher(f);
}