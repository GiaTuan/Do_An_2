#include "SACHTIENGVIET.h"
SACHTIENGVIET::SACHTIENGVIET()
{

}

SACHTIENGVIET::SACHTIENGVIET(int loaiSach, string tenSach, string maSach, string tacGia, string nhaXuatBan, double giaSach) :SACH(loaiSach,tenSach,maSach,tacGia,nhaXuatBan,giaSach)
{

}
void SACHTIENGVIET::nhapSach()
{
	this->SACH::nhapSach();
}

void SACHTIENGVIET::xuatSach()
{
	this->SACH::xuatSach();
}
