#include "chemise.h"
#include "atelier.h"
#include "soutiengorges.h"

#include <iostream>

using namespace std;

int main()
{
	Chemise c(string("tissu"), 25);
	Soutiengorges s(string("dentelle"), 10, 'B');

	cout << c << endl;

	Atelier a("AT1", &c);

	cout << a << endl;

	Piece * p;
	p = a.fabriquePiece();

	cout << *p << endl;

	cout << a << endl;

	cout << endl;
	Atelier a2("AT2", &s);
	cout << a2;

	Piece * p2 = a2.fabriquePiece();
	cout << a2.surfaceUtilisee() << endl;
	Piece * p3 = a2.fabriquePiece();
	cout << a2.surfaceUtilisee() << endl;
	delete p3;
	p = a2.fabriquePiece();
	cout << a2.surfaceUtilisee() << endl;
	cout << a2 << endl;

	cout << *a2.getPatron() << endl;
	cout << *a.getPatron() << endl;
	system("pause");
	return 0;
}