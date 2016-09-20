#include "Annuaire.h"
#include "ExTP1.h"
#include <string.h>
#include <string.h>

Annuaire::Annuaire() : nom(_strdup("")), c(NULL), nb(0){}

Annuaire::Annuaire(const char* nom) : nom(_strdup(nom)), c(NULL), nb(0)
{}

Annuaire::Annuaire(const Annuaire &a): nom(_strdup(a.nom)), c(NULL), nb(0){
	if (a.nb){
		c = new Contact[a.nb];
		for (int i = 0; i < a.nb; i++)
			c[i] = a.c[i];
		nb = a.nb;
	}
}

Annuaire::~Annuaire(){
	free(nom);
	delete[] c;
}

const char * Annuaire::getNom() const{
	return nom;
}

void Annuaire::setNom(const char *n){
	free(nom);
	nom = _strdup(n);
}

int Annuaire::getNb() const{
	return nb;
}

const Contact & Annuaire::recherche(const char *prenom, const char *nom) const{
	string s;
	for (int i = 0; i < nb; i++)
	if (!strcmp(nom, c[i].getNom()) && !strcmp(prenom, c[i].getPrenom()))
		return c[i];

	
	 s = s + prenom + nom + " n'est pas dans l'annuaire";
	throw exTP1(s);
}

const Contact & Annuaire::operator[](int i) const{
	if (i < 0 || i > nb - 1)
		throw exTP1("Index hors limite");
	return c[i];
}

void Annuaire::supprime(const Contact &ct){
	int i;
	string s;

	for (i = 0; i < nb; i++)
	if (!strcmp(c[i].getNom(), ct.getNom()) && !strcmp(c[i].getPrenom(), ct.getPrenom()))
		break;
	if (i == nb){
		s =  s + ct.getPrenom() + ct.getNom() + " n'est pas dans l'annuaire";
		throw exTP1(s);
	}
	for (; i < nb - 1; i++)
		c[i] = c[i + 1];
	nb--;
}

void Annuaire::supprime(int i){
	if ((i < 0) || (i >= nb))
		throw exTP1("Indice hors limite");
	for (int j = i; j < nb - 1; j++)
		c[i] = c[i + 1];
	nb--;
}

Annuaire Annuaire::operator + (const Contact &c) const{
	if (contient(c.getPrenom(), c.getNom())){
		string s;
		s = s + c.getPrenom() + " " + c.getNom() + " existe deja dans l'annuaire";
		throw exTP1(s);
	}

	Annuaire a(nom);
	Contact * c2 = new Contact[nb + 1];

	for (int i = 0; i < nb; i++)
		c2[i] = this->c[i];
	c2[nb] = c;
	a.c = c2;
	a.nb = nb + 1;
	return a;
}

bool Annuaire::contient(const char * prenom, const char * nom) const{
	for (int i = 0; i < nb; i++)
	if (!strcmp(nom, c[i].getNom()) && !strcmp(prenom, c[i].getPrenom()))
		return true;

	return false;
}

const Annuaire & Annuaire::operator = (const Annuaire &a){
	if (this != &a){
		free(nom);
		nom = _strdup(a.nom);
		nb = a.nb;
		delete[] c;
		c = new Contact[a.nb];

		for (int i = 0; i < a.nb; i++)
			c[i] = a.c[i];
	}
	return *this;

}



ostream & operator << (ostream & f, const Annuaire &a){
	f << a.nom << " :" << endl;
	for (int i = 0; i < a.nb; i++)
		f << "\t" << a.c[i] << endl;
	return f;
}