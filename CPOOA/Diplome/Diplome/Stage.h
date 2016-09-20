#pragma once
#include <iostream>

using namespace std;

class Stage
{
	static const int MIN = 4;
	static const int MAX = 8;

	int min;
	int max;
	bool evaluation;
public:
	Stage(int , int, bool);
	Stage(const Stage &);
	virtual ~Stage();

	// getters  and setters
	int getMin()  const;
	void setMin(int);

	int  getMax() const;
	void setMax(int);

	bool getEval() const;
	void setEval(bool);

	friend ostream & operator << (ostream & f, const Stage & s);
};

