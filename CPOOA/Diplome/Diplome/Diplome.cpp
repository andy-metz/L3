#pragma  once
#include "Diplome.h"


string titre;
Stage * stage;
//	vector <Etudiant> inscrit;
//	vector <Option> option;


	Diplome::Diplome(const string & s) : titre(s), stage(NULL){}

	Diplome::Diplome(const string & s, const Stage & st) : titre(s), stage(NULL){
		stage = new Stage(st);
	}

	Diplome::Diplome(const Diplome & d) : titre(d.titre), stage(NULL){
		if (d.stage)
			stage = new Stage(*d.stage);
	}

	Diplome::~Diplome(){
		delete stage;
	}

	const string & Diplome::getTitre() const{
		return titre;
	}
	void Diplome::setTitre(const string&){}

	bool Diplome::aStage() const{
		return (stage != NULL);
	}

	const Stage & Diplome::getStage() const{
		if (!stage)
			throw exTP1("Pas de stage");
		return *stage;

	}

	void Diplome::setStage(const Stage & s){
		delete stage;
		stage = new Stage(s);
	}

	const Diplome & Diplome::operator=(const Diplome &){
		return *this;
	}

	ostream & operator << (ostream & f, const Diplome & d){
		f << d.titre << endl;
		if (d.stage)
			f << *d.stage;
		return f;
	}