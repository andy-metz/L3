#pragma once
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include "Stage.h"
#include "Etudiant.h"
#include "Option.h"

using namespace std;

class Diplome{
	string titre;
	Stage * stage;
	vector <Etudiant> inscrit;
	vector <Option> option;

public:
	Diplome(const string &);
	Diplome(const string &, const Stage &);
	Diplome(const Diplome &);
	~Diplome();

	const string & getTitre() const;
	void setTitre(const string &);

	bool aStage() const;
//	const Stage & getStage() const;
//	void setStage(const Stage &);

	const Diplome & operator=(const Diplome &);

	friend ostream & operator << (ostream &, const Diplome &);

};