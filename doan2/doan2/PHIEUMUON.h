#ifndef __PHIEUMUON_H__
#define __PHIEUMUON_H__
#pragma once
#include "PHIEU.h"
class PHIEUMUON:public PHIEU
{
private:
	string ngayMuon;
public:
	PHIEUMUON();
	PHIEUMUON(int type, string tenDG,string maDG, string tenS, string maS, string ngaymuon);
	void nhapPhieu();
	void xuatPhieu();
	string getNgayMuon();
	~PHIEUMUON();
};
#endif
