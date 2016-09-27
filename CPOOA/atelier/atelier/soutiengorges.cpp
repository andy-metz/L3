#include "soutiengorges.h"
using namespace std;

Soutiengorges::Soutiengorges(): Piece(string("")), tourPoitrine(40), bonnet('A')
{}

Soutiengorges::Soutiengorges(const string & m, int t, char b) : Piece(m), tourPoitrine(t), bonnet(b)
{}

Soutiengorges::Soutiengorges(const Soutiengorges & c) : Piece(c), tourPoitrine(c.tourPoitrine), bonnet(c.bonnet)
{}

Soutiengorges::~Soutiengorges()
{}


const int & Soutiengorges::getTourPoitrine() const{
	return tourPoitrine;
}

void Soutiengorges::setTourPoitrine(const int t){
	tourPoitrine = t;
}

const char Soutiengorges::getBonnet() const{
	return bonnet;
}
void Soutiengorges::setBonnet(char b){
	bonnet = b;
}

double Soutiengorges::surface() const{
	return 11*tourPoitrine + 2*(5*(bonnet -'A')+20);
}

Soutiengorges * Soutiengorges::clone() const{
	return new Soutiengorges(*this);
}
ostream & Soutiengorges::afficher(ostream &   f) const{
	Piece::afficher(f);
	f << "tour de poitrine : " << tourPoitrine << "; bonnet : " << bonnet;
	return f;
}

const Soutiengorges & Soutiengorges::operator = (const Soutiengorges & c){
	if (this != &c){
		Piece::operator=(c);
		tourPoitrine = c.tourPoitrine;
	}
	return *this;
}

ostream & operator << (ostream & f, const Soutiengorges & c){
	return c.afficher(f);
}