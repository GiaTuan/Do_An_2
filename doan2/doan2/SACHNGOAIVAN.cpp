#include "SACHNGOAIVAN.h"
SACHNGOAIVAN::SACHNGOAIVAN()
{

}
SACHNGOAIVAN::SACHNGOAIVAN(int loaiSach, string tenSach, string maSach, string tacGia, string nhaXuatBan, double giaSach,string maISBN) :SACH(loaiSach, tenSach, maSach, tacGia, nhaXuatBan, giaSach)
{
	this->ISBN = maISBN;
}
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
	cout << "\tMa ISBN: " << this->ISBN << endl;
}

string SACHNGOAIVAN::getISBN()const
{
	return this->ISBN;
}