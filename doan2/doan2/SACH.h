#ifndef __SACH_H__
#define __SACH_H__
#pragma once
#include <iostream>
#include <string>
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
public:
	virtual void nhapSach();
	virtual void xuatSach();
	string getBookName();
	string getBookID();
	string getAuthor();
	string getNXB();
	double getPrice();
	int getLoaiSach();
	virtual string getISBN();
};
#endif
