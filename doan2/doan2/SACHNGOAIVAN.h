#ifndef __SACHNGOAIVAN_H__
#define __SACHNGOAIVAN_H__
#pragma once
#include "SACH.h"
class SACHNGOAIVAN:public SACH
{
private:
	string ISBN;
public:
	virtual void nhapSach();
	virtual void xuatSach();
	virtual string getISBN();
};
#endif
