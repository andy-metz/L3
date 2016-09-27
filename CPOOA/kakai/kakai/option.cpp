#include "option.h"


Option::Option() : designation(string(""))
{
}
Option::Option(const string & d) : designation(string())
{}

Option::Option(const Option & o) : designation(o.designation)
{}

Option::~Option()
{}

const string & Option::getDesignation() const{
	return designation;
}
void Option::setDesignation(const string & d){
	designation = d;
}


ostream & Option::afficher(ostream & f) const{
	f << designation;
	return f;
}

const Option & Option::operator = (const Option & o){
	if (this != &o){
		designation = o.designation;
		meubleBase = o.meubleBase;
	}
	return *this;
}

ostream & operator << (ostream & f, Option & o){
	return o.afficher(f);
}