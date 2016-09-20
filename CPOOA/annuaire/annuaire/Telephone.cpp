#include "Telephone.h"
#include <string.h>

Telephone::Telephone() :type(MOBILE), numero(_strdup("")){}

Telephone::Telephone(int t, const char * n) : type(t), numero(_strdup(n)){}

Telephone::Telephone(const Telephone & t) : type(t.type), numero(_strdup(t.numero)){}

Telephone::~Telephone(){
	free(numero);
}

const char  * Telephone::getNumero() const{
	return numero;
}

void Telephone::setNumero(const char *n){
	if (n != numero){
		free(numero);
		numero = _strdup(n);
	}
}

int Telephone::getType() const{
	return type;
}

void Telephone::setType(int t){
	type = t;
}

Telephone& Telephone::operator=(const Telephone & t){
	if (this != &t)
		{
			free(numero);
			numero = _strdup(t.numero);
			type = t.type;
		}
	return *this;
}
bool Telephone::operator == (const Telephone & t) const{
	return (!strcmp(numero, t.numero));
}


ostream & operator<<(ostream & f, const Telephone& t){
	f << t.type << " : " << t.numero;
	return f;
}