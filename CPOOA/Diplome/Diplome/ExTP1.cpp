#include "ExTP1.h"

ostream & operator << (ostream &   f, const exTP1 & e){
	f << e.msg;
	return f;
}