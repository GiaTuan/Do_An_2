#include "SACHNGOAIVAN.h"



void SACHNGOAIVAN::nhapSach()
{
	this->SACH::nhapSach();
	cin.ignore();
	cout << "Nhap ma ISBN: ";
	getline(cin, this->ISBN);
	this->type = 2;
}

void SACHNGOAIVAN::xuatSach()
{
	this->SACH::xuatSach();
	cout << "Ma ISBN: " << this->ISBN << endl;
}

string SACHNGOAIVAN::getISBN()
{
	return this->ISBN;
}