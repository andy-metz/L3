#pragma once
#include "Stage.h"
#include "ExTP1.h"

Stage::Stage(int min = MIN, int max = MAX, bool eval = false) : min(min), max(max), evaluation(eval){}

Stage::Stage(const Stage & s) : min(s.min), max(s.max), evaluation(s.evaluation){}
Stage::~Stage()
{
}


int Stage::getMin()  const{
	return min;
}
void Stage::setMin(int m){
	if (m < 1 || m > max)
		throw exTP1("Min doit être compris entre  1 et max");
	min = m;
}

int Stage::getMax() const{
	return max;
}
void Stage::setMax(int m){
	if (m < 1 || m < min)
		throw exTP1("Max doit être compris entre  1 et max");
	min = m;
}

bool Stage::getEval() const{
	return evaluation;
}
void Stage::setEval(bool e){
	evaluation = e;
}

ostream & operator << (ostream & f, const Stage & s){
	f << "min: " << s.min << " max: " << s.max << " Evaluation: " << (s.evaluation ? "oui" : "non");
	return f;
}