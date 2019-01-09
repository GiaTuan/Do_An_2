#ifndef __PHIEU_H__
#define __PHIEU_H__
#pragma once
#include <iostream>
#include <string>
using namespace std;
class PHIEU
{
protected:
	string tenDocGia;
	string maDocGia;
	string tenSach;
	string maSach;
	int type;
public:
	PHIEU();
	PHIEU(int type, string tenDG,string maDG, string tenS, string maS);
	void nhapPhieu();
	void xuatPhieu();
	string getTenDG();
	string getMaDG();
	string getTenS();
	string getMa();
	int getType();
	~PHIEU();
};
#endif

