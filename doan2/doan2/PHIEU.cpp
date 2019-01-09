#include "PHIEU.h"



PHIEU::PHIEU()
{
}
PHIEU::PHIEU(int type, string tenDG,string maDG, string tenS, string maS)
{
	this->type = type;
	this->tenDocGia = tenDG;
	this->maDocGia = maDG;
	this->tenSach = tenS;
	this->maSach = maS;
}

void PHIEU::nhapPhieu()
{
	cin.ignore();
	cout << "Nhap ten doc gia muon sach: ";
	getline(cin, this->tenDocGia);
	cout << "Nhap ma doc gia muon sach: ";
	getline(cin, this->maDocGia);
	cout << "Nhap ten sach doc gia muon: ";
	getline(cin, this->tenSach);
	cout << "Nhap ma sach doc gia muon: ";
	getline(cin, this->maSach);
}

void PHIEU::xuatPhieu()
{
	cout << "\tTen doc gia: " << this->tenDocGia<<endl;
	cout << "\tMa doc gia: " << this->maDocGia << endl;
	cout << "\tTen sach: " << this->tenSach << endl;
	cout << "\tMa sach: " << this->maSach << endl;
}
string PHIEU::getTenDG()
{
	return this->tenDocGia;
}
string PHIEU::getMaDG()
{
	return this->maDocGia;
}
string PHIEU::getTenS()
{
	return this->tenSach;
}
string PHIEU::getMa()
{
	return this->maSach;
}
int PHIEU::getType()
{
	return this->type;
}
PHIEU::~PHIEU()
{
}
