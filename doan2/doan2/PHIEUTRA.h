#ifndef __PHIEUTRA_H__
#define __PHIEUTRA_H__
#pragma once
#include "PHIEU.h"
class PHIEUTRA:public PHIEU
{
private:
	string ngayTra;
public:
	PHIEUTRA();
	PHIEUTRA(int type, string tenDG,string maDG, string tenS, string maS, string ngaytra);
	void nhapPhieu();
	void xuatPhieu();
	string getNgayTra();
	~PHIEUTRA();
};
#endif
