#include "Diplome.h"

int main(int argc, char * arrgv[]){
	string s("L3 info");

	Stage st(2, 2, false);

	Diplome d(s, st);

	cout << d << endl;

	// cout << s << endl;
}