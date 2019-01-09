#include "DOCGIA.h"



DOCGIA::DOCGIA()
{
}
DOCGIA::DOCGIA(string ten, string id, string dob, string phone, string dc)
{
	this->nameReader = ten;
	this->IDReader = id;
	this->DOB = dob;
	this->phoneNumber = phone;
	this->address = dc;
}
void DOCGIA::nhapDocGia()
{
	cin.ignore();
	cout << "Nhap ten doc gia: ";
	getline(cin, this->nameReader);
	cout << "Nhap ma doc gia: ";
	getline(cin, this->IDReader);
	cout << "Nhap ngay sinh doc gia: ";
	getline(cin, this->DOB);
	cout << "Nhap so dien thoai doc gia: ";
	getline(cin, this->phoneNumber);
	cout << "Nhap dia chi nha doc gia: ";
	getline(cin, this->address);
}
void DOCGIA::xuatDocGia()
{
	cout << "\tTen doc gia: " << this->nameReader<<endl;
	cout << "\tMa doc gia: " << this->IDReader << endl;;
	cout << "\tNgay thang nam sinh: " << this->DOB<<endl;
	cout << "\tSo dien thoai: " << this->phoneNumber<<endl;
	cout << "\tDia chi: " << this->address<<endl;
}

string DOCGIA::getNameReader()
{
	return this->nameReader;
}
string DOCGIA::getIDReader()
{
	return this->IDReader;
}
string DOCGIA::getDOB()
{
	return this->DOB;
}
string DOCGIA::getPhoneNumber()
{
	return this->phoneNumber;
}
string DOCGIA::getAddress()
{
	return this->address;
}

DOCGIA::~DOCGIA()
{
}
