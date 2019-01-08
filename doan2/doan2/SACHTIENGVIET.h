#ifndef __SACHTIENGVIET_H__
#define __SACHNTIENGVIET_H__
#pragma once
#include "SACH.h"
class SACHTIENGVIET :public SACH
{
public:
	SACHTIENGVIET();
	SACHTIENGVIET(int loaiSach, string tenSach, string maSach, string tacGia, string nhaXuatBan, double giaSach);
	virtual void nhapSach();
	virtual void xuatSach();
};
#endif
