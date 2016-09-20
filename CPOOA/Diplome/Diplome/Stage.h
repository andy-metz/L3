#pragma once
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
	~Stage();
};

