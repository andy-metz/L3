#include "Diplome.h"


string titre;
Stage * stage;
//	vector <Etudiant> inscrit;
//	vector <Option> option;


	Diplome::Diplome(const string & s) : titre(s), stage(NULL){}

	Diplome::Diplome(const string & s, const Stage & st) : titre(s), stage(NULL){
		stage = &Stage(st);
	}

	Diplome::Diplome(const Diplome & d) : titre(d.titre), stage(NULL){
		if (d.stage)
			stage = &Stage(*d.stage);
	}

	Diplome::~Diplome(){}

	const string & Diplome::getTitre() const{
		return titre;
	}
	void Diplome::setTitre(const string&){}

	bool Diplome::aStage() const{
		return (stage != NULL);
	}

	//	const Stage & Diplome::getStage() const;
	//	void Diplome::setStage(const Stage &);

	const Diplome & Diplome::operator=(const Diplome &){
		return *this;
	}

	ostream & operator << (ostream & f, const Diplome & d){
		f << d.titre << endl;
		if (d.stage)
			f << "Stage:min " << *d.stage.
		return f;
	}