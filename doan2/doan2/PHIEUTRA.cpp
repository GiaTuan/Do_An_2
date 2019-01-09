#include "PHIEUTRA.h"



PHIEUTRA::PHIEUTRA()
{
}
PHIEUTRA::PHIEUTRA(int type, string tenDG,string maDG, string tenS, string maS, string ngaytra) :PHIEU(type, tenDG,maDG, tenS, maS)
{
	this->ngayTra = ngaytra;
}
void PHIEUTRA::nhapPhieu()
{
	this->PHIEU::nhapPhieu();
	cout << "Nhap ngay tra: ";
	getline(cin, this->ngayTra);
	this->type = 2;
}
void PHIEUTRA::xuatPhieu()
{
	this->PHIEU::xuatPhieu();
	cout << "\tNgay tra: " << this->ngayTra << endl;
}
string PHIEUTRA::getNgayTra()
{
	return this->ngayTra;
}
PHIEUTRA::~PHIEUTRA()
{
}
