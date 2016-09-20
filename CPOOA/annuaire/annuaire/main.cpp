#include "ExTP1.h"
#include "Annuaire.h"


int main(){

	// test de la classe Telephoe
	Telephone t1(MOBILE, "+33612345678");
	cout << "t1 = " << t1 << endl;
	cout << "t1 = " << t1.getType() << " : " << t1.getNumero() << endl;

	Telephone t2(t1);
	t2 = Telephone(DOMICILE, "03871234563");
	cout << "t2 = " << t2 << endl;

	// test de la classe Contact
	Contact c1("Jean", "Dupont");
	cout << "c1 = " << c1 << endl;

	c1 = c1 + t1 + t2;
//	c1 += t1;
	cout << "c1 = " << c1 << endl;

	cout << "c1 = " << c1.getPrenom() << " " << c1.getNom() << endl;
	for (int i = 0; i < c1.getNb(); i++)
		cout << "\t" << c1[i].getType() << " : " << c1[i].getNumero() << endl;

	c1.supprime(1);
	cout << "c1 = " << c1 << endl;

	try{
		c1.supprime(1);
	}
	catch(exTP1 e){
		cout << "Erreur: " << e << endl;
	}

	// test de la classe Annuaire
	// 
	Annuaire a("Test");
	cout << "a = " << a << endl;

	a = a + c1;
	cout << "a = " << a;

	cout << "Jean Dupont est dans cet annuaire : "
		<< (a.contient("Jean", "Dupont") ? "Vrai" : "Faux") << endl;

	cout << "Jean Durant est dans cet annuaire : "
		<< (a.contient("Jean", "Durant") ? "Vrai" : "Faux") << endl;

	try{
		// un contact   vide
		Contact c;

		c = a.recherche("Jean", "Dupont");
		cout << "c = " << c << endl;

		c = a.recherche("Jean", "Durant");
		cout << "c = " << c << endl;
	}
	catch (exTP1 e){
		cout << "Erreur : " << e << endl;
	}

	try{
		a = a + c1; // akout d'un contact existant
	}
	catch(exTP1 e){
		cout << "Erreur : " << e << endl;
	}

	Contact c2("Jean", "Durant");
	c2 = c2 + Telephone(BUREAU, "+0035212345678");
	cout << "c2 = " << c2 << endl;

	a = a + c2;

	cout << "a = " << a.getNom() << endl;
	for (int i = 0; i < a.getNb(); i++)
		cout << "\t" << a[i] << endl;

	try{
		a.supprime(0);
		cout << "a = " << a;
		a.supprime(c1); // Le contact n'est plus dans l'annuaire
		cout << "a = " << endl;
	}
	catch(exTP1 e){
		cout << "Erreur : " << e << endl;
	}

	system("pause");
}