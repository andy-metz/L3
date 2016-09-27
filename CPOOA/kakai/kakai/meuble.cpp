#include "meuble.h"

Meuble::Meuble(): designation(string(""))
{}

Meuble::Meuble(const string & d): designation(d)
{}

Meuble::Meuble(const Meuble & m) : designation(m.designation)
{}

Meuble::~Meuble()
{}

// getters and setters
const string & Meuble::getDesignation() const{
	return designation;
}
void Meuble::setDesignation(const string & d){
	designation = d;
}

ostream & Meuble::afficher(ostream & f) const{
	f << designation;
	return f;
}

const Meuble & Meuble::operator = (const Meuble & m){
	if (this != &m){
		designation = m.designation;
	}
	return *this;
}

ostream & operator << (ostream & f, Meuble & m){
	return m.afficher(f);
}