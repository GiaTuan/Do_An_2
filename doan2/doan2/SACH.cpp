#include "SACH.h"

void SACH::nhapSach()
{
	cin.ignore();
	cout << "Nhap ten sach: ";
	getline(cin, this->bookName);
	cout << "Nhap ma sach: ";
	getline(cin, this->bookID);
	cout << "Nhap tac gia sach: ";
	getline(cin, this->author);
	cout << "Nhap nha xuat ban: ";
	getline(cin, this->NXB);
	cout << "Nhap gia sach: ";
	cin >> this->price;
	this->type = 1;
}
void SACH::xuatSach()
{
	cout << "Ten sach: " << this->bookName << endl;
	cout << "Ma sach: " << this->bookID << endl;
	cout << "Tac gia: " << this->author << endl;
	cout << "Nha xuat ban: " << this->NXB << endl;
	cout << "Gia sach: " << this->price << endl;
}

string SACH::getBookName()
{
	return this->bookName;
}
string SACH::getBookID()
{
	return this->bookID;
}
string SACH::getAuthor()
{
	return this->author;
}
string SACH::getNXB()
{
	return this->NXB;
}
double SACH::getPrice()
{
	return this->price;
}
int SACH::getLoaiSach()
{
	return this->type;
}
string SACH::getISBN()
{

}
