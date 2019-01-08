#ifndef __THUVIEN_H__
#define __THUVIEN_H__
#pragma once
#include "SACHNGOAIVAN.h"
#include "SACHTIENGVIET.h"
#include <vector>
#include <fstream>
class THUVIEN
{
private:
	vector<SACH*> listBook;
	int nBook;
public:
	void nhapThuVien();
	void xuatThuVien();
	void save(int type);
	void read();
	void addBook();
	void deleteBook();
	void fixBook();
	void findBook();
	~THUVIEN();
};
#endif
