#include "piece.h"

Piece::Piece() :materiau(string(""))
{}

Piece::Piece(const string & s) : materiau(s)
{}

Piece::Piece(const Piece & p) : materiau(p.materiau)
{}

Piece::~Piece()
{}


const string & Piece::getMateriau() const{
	return materiau;
}
void Piece::setMateriau(const string & m){
	materiau = m;
}


ostream & Piece::afficher(ostream & f)const{
	f << materiau;
	return f;
}

const Piece & Piece::operator = (const Piece & p){
	if (this != &p){
		materiau = p.materiau;
	}
	return *this;
}

ostream & operator << (ostream & f, Piece & p){
	return p.afficher(f);
}