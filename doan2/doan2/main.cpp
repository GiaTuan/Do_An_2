#include <iostream>
#include <string>
#include "THUVIEN.h"
#include <fstream>
using namespace std;

int main()
{
	THUVIEN library;
	library.nhapThuVien();
	library.xuatThuVien();
	ofstream books_out;
	books_out.open("Books.txt", ios::out);
	books_out << library;
	system("pause");
	return 0;
}