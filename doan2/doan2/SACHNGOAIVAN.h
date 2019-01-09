#ifndef __SACHNGOAIVAN_H__
#define __SACHNGOAIVAN_H__
#pragma once
#include "SACH.h"
class SACHNGOAIVAN :public SACH
{
private:
	string ISBN;
public:
	SACHNGOAIVAN();
	SACHNGOAIVAN(int loaiSach, string tenSach, string maSach, string tacGia, string nhaXuatBan, double giaSach, string maISBN);
	virtual void nhapSach();
	virtual void xuatSach();
	virtual string getISBN()const;
};
#endif
