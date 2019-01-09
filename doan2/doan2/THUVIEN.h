#ifndef __THUVIEN_H__
#define __THUVIEN_H__
#pragma once
#include "SACHNGOAIVAN.h"
#include "SACHTIENGVIET.h"
#include "DOCGIA.h"
#include "PHIEUMUON.h"
#include "PHIEUTRA.h"
#include <vector>
#include <fstream>
#include <iomanip>
class THUVIEN
{
private:
	vector<SACH*> listBook;
	static int nBook;
	vector<DOCGIA> listReader;
	static int nReader;
	vector<PHIEUMUON> listPhieuMuon;
	static int nPhieuMuon;
	vector<PHIEUTRA> listPhieuTra;
	static int nPhieuTra;
public:
	//book
	void nhapSach();
	void xuatSach();
	void saveBook();
	void read();
	void addBook();
	void deleteBook();
	void fixBook();
	void findBook();

	//reader
	void nhapDocGia();
	void xuatDocGia();
	void saveReader();
	void addReader();
	void deleteReader();
	void fixReader();
	void findReader();

	//phieu
	void nhapPhieu();
	void xuatPhieu();
	void savePhieu();
	void addPhieu();
	void deletePhieu();
	void findPhieu();

	//trich danh sach
	void tachNgay(string date, string &ngay, string &thang, string &nam);
	int tinhNgay(int ngayMuon, int thangMuon, int namMuon, int ngayTra, int thangTra, int namTra);
	int MyDate(string ngay1, string ngay2);
	void xuatDanhSachQuaHan(string maDG, int soNgay, int tien);
	void danhSachQuaHan();

	~THUVIEN();
};
#endif
