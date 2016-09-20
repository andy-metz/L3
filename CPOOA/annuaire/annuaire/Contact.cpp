#include "Contact.h"
#include "ExTP1.h"
#include <string.h>

Contact::Contact() :prenom(_strdup("")), nom(_strdup("")), tel(NULL), nb(0){}

Contact::Contact(const Contact &  c): prenom(_strdup(c.prenom)), nom(_strdup(c.nom)), tel(NULL), nb(c.nb)
{
	tel = new Telephone[nb];
	for (int i = 0; i < nb; i++)
		tel[i] = c.tel[i];
}

Contact::Contact(const char *p, const char * n):prenom(_strdup(p)), nom(_strdup(n)), tel(NULL), nb(0){}

Contact::~Contact(){
	free(nom);
	free(prenom);
	delete [] tel;
}

const char * Contact::getNom() const{
	return nom;
}

void Contact::setNom(const char * n){
	if (n != nom){
		free(nom);
		nom = _strdup(n);
	}
}

const char * Contact::getPrenom() const{
	return prenom;
}
void Contact::setPrenom(const char * p){
	if (p != prenom){
		free(prenom);
		prenom = _strdup(p);
	}
}


int Contact::getNb() const{
	return nb;
}

const Telephone & Contact::operator[](int i) const{
	if ((i < 0) || (i >= nb))
		throw exTP1("Index hors limite");
	return tel[i];
}

Contact Contact::operator + (const Telephone & t) const{
	Contact c(prenom, nom);
	Telephone * t2 = new Telephone[nb + 1];

	for (int i=0; i < nb; i++)
		t2[i] = tel[i];
	t2[nb] = t;
	c.tel = t2;
	c.nb = nb + 1;
	return c;
}

void Contact::supprime(int indice){
	if ((indice < 0) || (indice >= nb))
		throw exTP1("Index hors limite");
	for (int i = indice; i < nb - 1; i++)
		tel[i] = tel[i + 1];
	nb--;
}

void Contact::operator += (const Telephone &t){
	Telephone * t2 = new Telephone[nb + 1];

	for (int i=0; i < nb; i++)
		t2[i] = tel[i];
	t2[nb] = t;
	nb++;
	delete[] tel;
	tel = t2;
}

const Contact&  Contact::operator = (const Contact & c){
	if (this != &c){
		
		free(nom);
		nom = _strdup(c.nom);
		free(prenom);
		prenom = _strdup(c.prenom);
		delete[] tel;
		tel = new Telephone[c.nb];
		for (int i = 0; i < c.nb; i++)
			tel[i] = c.tel[i];
		nb = c.nb;
	}
	return *this;
}

ostream & operator << (ostream & f, const Contact &c){
	f  << c.prenom << " " << c.nom << " :  ";
	for (int i = 0; i < c.nb; i++)
		f << " (" << c.tel[i] << ")";
	return f;
}