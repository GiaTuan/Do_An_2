#include "menu.h"
int main()
{
	THUVIEN library;
	library.read();
	menu();
	int key;
	phimTat(key);
	xuLy(library,key);
	system("pause");
	return 0;
}