#include <stdlib.h>
#include "ordinateur.h"
#include "ecran.h"


int main()
{
	Ordinateur o(string("Bureau"));


	cout << o << endl;

	Ecran e2(string("LG"), 1, 1250, 2);

	Composant * c = new Ecran(string("Sony"), Ecran::SVGA, 1250, 2);
	Composant * c2 = new Ecran(string("HP"), Ecran::QSXGA, 1450, 3);

	cout << e2 << endl;

	o = o + c + c2;

//	o[0]->afficher(cout);

	cout << endl << o << endl;


	cout << "prix " << e2.getDescription() << ": " << e2.prix() << endl;
	cout << "prix de la configuration: " << o.prix() << endl;

	system("pause");
}