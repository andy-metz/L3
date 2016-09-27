#include "atelier.h"
#include "ExTP1.h"

Atelier::Atelier() : nom(string("")), nbp(0), patron(NULL)
{}

Atelier::Atelier(string n, const Piece * p) : nom(n), nbp(0), patron(NULL)
{
	if (p == NULL) throw exTP1("patron absent");
	patron = p->clone();
}

Atelier::Atelier(const Atelier & a) : nom(a.nom), nbp(0), patron(NULL)
{
	patron = a.patron->clone();
}

Atelier::~Atelier(){
	delete patron;
}

const string & Atelier::getNom() const{
	return nom;
}
void Atelier::setNom(const string & n){
	nom = n;
}

int Atelier::getNbp() const{
	return nbp;
}

Piece * Atelier::getPatron() const{
	return patron->clone();
}

void Atelier::setPatron(const Piece & p){
	if (&p == NULL)  throw exTP1("patron absent");
	delete(patron);
	patron = p.clone();
}

int Atelier::surfaceUtilisee() const{
	return nbp * patron->surface();
}

Piece * Atelier::fabriquePiece(){
	nbp++;
	return patron->clone();
}

const Atelier & Atelier::operator = (const Atelier & a){
	nom = a.nom;
	nbp = a.nbp;
	delete patron;
	patron = a.patron->clone();
	return(*this);
}

ostream & operator << (ostream & f, const Atelier & a){
	f << a.nom << ":" << a.nbp << ":" << endl;
	f << *a.patron;
	return f;
}