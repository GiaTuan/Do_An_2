#include "PHIEUMUON.h"



PHIEUMUON::PHIEUMUON()
{
}
PHIEUMUON::PHIEUMUON(int type, string tenDG,string maDG, string tenS, string maS, string ngaymuon) :PHIEU(type, tenDG,maDG, tenS, maS)
{
	this->ngayMuon = ngaymuon;
}
void PHIEUMUON::nhapPhieu()
{
	this->PHIEU::nhapPhieu();
	cout << "Nhap ngay muon: ";
	getline(cin, this->ngayMuon);
	this->type = 1;
}

void PHIEUMUON::xuatPhieu()
{
	this->PHIEU::xuatPhieu();
	cout << "\tNgay muon: " << this->ngayMuon<<endl;
}
string PHIEUMUON::getNgayMuon()
{
	return this->ngayMuon;
}
PHIEUMUON::~PHIEUMUON()
{
}
