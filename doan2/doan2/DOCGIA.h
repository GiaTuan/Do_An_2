#ifndef __DOCGIA_H__
#define __DOCGIA_H__
#pragma once
#include <iostream>
#include <string>
using namespace std;
class DOCGIA
{
private:
	string nameReader;
	string IDReader;
	string DOB;
	string phoneNumber;
	string address;
public:
	DOCGIA();
	DOCGIA(string ten, string id, string dob, string phone, string dc);
	void nhapDocGia();
	void xuatDocGia();
	string getNameReader();
	string getIDReader();
	string getDOB();
	string getPhoneNumber();
	string getAddress();
	~DOCGIA();
};
#endif

