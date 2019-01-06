#ifndef __THUVIEN_H__
#define __THUVIEN_H__
#pragma once
#include "SACHNGOAIVAN.h"
#include <vector>
class THUVIEN
{
private:
	vector<SACH*> listBook;
	int nBook;
public:
	void nhapThuVien();
	void xuatThuVien();
	friend ostream& operator<<(ostream& outDev, const THUVIEN &library);

};
#endif
