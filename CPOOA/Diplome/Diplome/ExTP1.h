#include <iostream>
#include <string>

using namespace std;

class exTP1{
	string msg;

public:
	exTP1(const string & m) :msg(m){}

	const string & getMessage() const{
		return msg;
	}

	friend ostream & operator << (ostream &   f, const exTP1 & e);
};

