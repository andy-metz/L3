#include "chemise.h"
using namespace std;

Chemise::Chemise() : Piece(string("")), taille(0)
{}

Chemise::Chemise(const string & m, int t) : Piece(m), taille(t)
{}

Chemise::Chemise(const Chemise & c) : Piece(c), taille(c.taille)
{}

Chemise::~Chemise()
{}


const int & Chemise::getTaille() const{
	return taille;
}

void Chemise::setTaille(const int t){
	taille = t;
}

double Chemise::surface() const{
	return 45. * taille;
}

Chemise * Chemise::clone() const{
	return new Chemise(*this);
}
ostream & Chemise::afficher(ostream &   f) const{
	Piece::afficher(f);
	f << "taille : " << taille;
	return f;
}

const Chemise & Chemise::operator = (const Chemise & c){
	if (this != &c){
		Piece::operator=(c);
		taille = c.taille;
	}
	return *this;
}

ostream & operator << (ostream & f, const Chemise & c){
	return c.afficher(f);
}