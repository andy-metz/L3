#include "Diplome.h"

int main(int argc, char * arrgv[]){
	string s("L3 info");

	Stage st(2, 2, false);

	// cout << st << endl;

	Diplome d(s, st);

	cout << d << endl;

	Diplome d2(string("L2"));
	cout << d2 << endl;
	d2.setStage(Stage(2, 6, true));
	cout << d2 << endl;
}