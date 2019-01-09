#include "SACH.h"
SACH::SACH()
{
}
SACH::SACH(int loaiSach, string tenSach, string maSach, string tacGia, string nhaXuatBan, double giaSach)
{
	this->type = loaiSach;
	this->bookName = tenSach;
	this->bookID = maSach;
	this->author = tacGia;
	this->NXB = nhaXuatBan;
	this->price = giaSach;
}

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
	cout << "\tTen sach: " << this->bookName << endl;
	cout << "\tMa sach: " << this->bookID << endl;
	cout << "\tTac gia: " << this->author << endl;
	cout << "\tNha xuat ban: " << this->NXB << endl;
	cout << "\tGia sach: " << this->price << endl;
}

string SACH::getBookName()const
{
	return this->bookName;
}
string SACH::getBookID()const
{
	return this->bookID;
}
string SACH::getAuthor()const
{
	return this->author;
}
string SACH::getNXB()const
{
	return this->NXB;
}
double SACH::getPrice()const
{
	return this->price;
}
int SACH::getLoaiSach()const
{
	return this->type;
}
string SACH::getISBN()const
{
	return NULL;
}
