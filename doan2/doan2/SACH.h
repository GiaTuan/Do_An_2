#ifndef __SACH_H__
#define __SACH_H__
#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class SACH
{
protected:
	string bookName;
	string bookID;
	string author;
	string NXB;
	double price;
	int type;
	//virtual void print(ostream &fileout)const = 0;
public:
	SACH();
	SACH(int loaiSach, string tenSach, string maSach, string tacGia, string nhaXuatBan, double giaSach);
	virtual void nhapSach();
	virtual void xuatSach();
	string getBookName()const;
	string getBookID()const;
	string getAuthor()const;
	string getNXB()const;
	double getPrice()const;
	int getLoaiSach()const;
	virtual string getISBN()const;
	friend ostream& operator<<(ostream& os, const SACH &book);
};
#endif
