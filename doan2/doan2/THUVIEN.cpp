#include "THUVIEN.h"

void THUVIEN::nhapThuVien()
{
	cout << "Nhap so luong sach co trong thu vien: ";
	cin >> this->nBook;
	cout << "Chon 1 de nhap sach tieng viet." << endl;
	cout << "Chon 2 de nhap sach ngoai van." << endl;
	int x;
	for (int i = 0; i < nBook; i++)
	{
		cout << "\tMoi ban nhap: ";
		cin >> x;
		if (x == 1)
		{
			listBook.push_back(new SACH);
			listBook[i]->nhapSach();
		}
		if (x == 2)
		{
			listBook.push_back(new SACHNGOAIVAN);
			listBook[i]->nhapSach();
		}
		cout << endl;
	}
}

void THUVIEN::xuatThuVien()
{
	for (int i = 0; i < this->nBook; i++)
	{
		listBook[i]->xuatSach();
		cout << endl;
	}
}

//int THUVIEN::getNBook()
//{
//	cout << this->nBook;
//}

//int THUVIEN::getType()
//{
//	return 
//}
ostream& operator<<(ostream& outDev, const THUVIEN &library)
{
	for (int i = 0; i < library.nBook; i++)
	{
		outDev << library.listBook[i]->getBookName() << ";";
		outDev << library.listBook[i]->getBookID() << ";";
		outDev << library.listBook[i]->getAuthor() << ";";
		outDev << library.listBook[i]->getNXB() << ";";
		outDev << library.listBook[i]->getPrice() << ";";
		if (library.listBook[i]->getLoaiSach() == 2)
		{
		outDev << library.listBook[i]->getISBN()<< ";";
		}
		outDev << endl;
	}
	return outDev;
}
//void THUVIEN::saveBookFile(ofstream& fileout)
//{
//
//}
