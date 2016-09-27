#include "meublebase.h"

MeubleBase::MeubleBase()
	: Meuble(string("")), largeur(0), hauteur(0), profondeur(0), prixBase(0)
{}

MeubleBase::MeubleBase(const string & d, double l, double h, double prof, double prix) 
	: Meuble(d), largeur(l), hauteur(h), profondeur(prof), prixBase(prix)
{}

MeubleBase::MeubleBase(const MeubleBase & m)
: Meuble(m), largeur(m.largeur), hauteur(m.hauteur), profondeur(m.profondeur), prixBase(m.prixBase)
{}

MeubleBase::~MeubleBase()
{}




double MeubleBase::prix() const{ 
	double prix = prixBase;
	for (int i = 0; i < options.size(); i++)
		prix += options[i]->prix();
	return prix;
}

MeubleBase * MeubleBase::clone() const{
	return new MeubleBase(*this);
}

ostream & MeubleBase::afficher(ostream & f) const{
	Meuble::afficher(f);
	f << ": l=" << largeur << " h=" << hauteur << " p=" << profondeur << " prix=" << prixBase << endl;
	return f;
}

const MeubleBase & MeubleBase::operator = (const MeubleBase & m){
	if (this != &m){
		Meuble::operator=(m);
		largeur = m.largeur;
		hauteur = m.hauteur;
		profondeur = m.profondeur;
		prixBase = m.prixBase;
	}
	return *this;
}

ostream & operator << (ostream & f, MeubleBase & m){
	 return m.afficher(f);
}