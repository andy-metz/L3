#include "Etudiant.h"


Etudiant::Etudiant()
{}
Etudiant::Etudiant(const Etudiant &){}
Etudiant::Etudiant(const string & n, int a, bool b, Diplome * d){}
Etudiant::~Etudiant(){}

// getter and setter
const string & Etudiant::getNom() const{
	return nom;
}
void Etudiant::setNom(const string &n){
	nom = n;
}

int Etudiant::getAge() const{
	return age;
}
void Etudiant::setAge(int a){
	age = a;
}

bool Etudiant::getBoursier() const{
	return boursier;
}
void Etudiant::setBoursier(bool b){
	boursier = b;
}

//Diplome * Etudiant::getDiplome() const;
//void Etudiant::setDiplome(Diplome *);

const Etudiant & Etudiant::operator = (const Etudiant &e){
	if (this != &e){

	}
	return *this;
}

bool Etudiant::operator == (const Etudiant &e) const{
	return nom == e.nom && age == e.age && boursier == e.boursier;
}


ostream & operator << (ostream &f, const Etudiant &e){
	f << e.nom;
	return f;
}