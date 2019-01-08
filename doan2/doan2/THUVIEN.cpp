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
			listBook.push_back(new SACHTIENGVIET);
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
		cout << "THONG TIN SACH THU " << i + 1 << ": " << endl;
		listBook[i]->xuatSach();
		cout <<"======================================================="<< endl;
	}
}

void THUVIEN::addBook()
{
	int x;
	int i = 0;
	cout << "Nhap so luong sach can them: ";
	cin >> x;
	cout << "Chon 1 de nhap sach tieng viet." << endl;
	cout << "Chon 2 de nhap sach ngoai van." << endl;
	while (i <x)
	{
		int key;
		cout << "\tMoi ban nhap: ";
		cin >> key;
		if (key == 1)
		{
			listBook.push_back(new SACHTIENGVIET);
			listBook[this->nBook+i]->nhapSach();
		}
		else if (key == 2)
		{
			listBook.push_back(new SACHNGOAIVAN);
			listBook[this->nBook+i]->nhapSach();
		}
		cout << endl;
		i++;
	}
	this->nBook += x;
	cout << "\tTHEM SACH HOAN TAT!" << endl;
}

void THUVIEN::deleteBook()
{
	string maSach;
	cout << "Nhap ma sach can xoa: ";
	getline(cin, maSach);
	bool flag = false;
	for (int i = 0; i < this->nBook; i++)
	{
		if (this->listBook[i]->getBookID() == maSach)
		{
			listBook.erase(listBook.begin() + i);
			flag = true;
		}
	}
	this->nBook -= 1;
	if (flag == true)
	{
		cout << "XOA SACH HOAN TAT!" << endl;
	}
	else
	{
		cout << "KHONG TIM THAY SACH CO MA SO " << maSach << " TRONG TU DIEN." << endl;
	}
}

void THUVIEN::fixBook()
{
	string maSach;
	cout << "Nhap ma sach can sua: ";
	getline(cin, maSach);
	bool flag = false;
	for (int i = 0; i < this->nBook; i++)
	{
		if (this->listBook[i]->getBookID() == maSach)
		{
			int x;
			cout << "Chon 1 de doi thong tin thanh sach tieng viet." << endl;
			cout << "Chon 2 de doi thong tin thanh sach ngoai van." << endl;
			cout << "Moi ban chon: ";
			cin >> x;
			if (x == 1)
			{
				listBook[i] = new SACHTIENGVIET();
				listBook[i]->nhapSach();
			}
			if (x == 2)
			{
				listBook[i] = new SACHNGOAIVAN();
				listBook[i]->nhapSach();
			}
			flag = true;
		}
	}
	if (flag == true)
	{
		cout << "SUA SACH HOAN TAT!" << endl;
	}
	else
	{
		cout << "KHONG TIM THAY SACH CO MA SO " << maSach << " TRONG TU DIEN."<<endl;
	}
}
void THUVIEN::findBook()
{
	string maSach;
	cout << "Nhap ma sach can tim: ";
	getline(cin, maSach);
	bool flag = false;
	for (int i = 0; i < this->nBook; i++)
	{
		if (this->listBook[i]->getBookID() == maSach)
		{
			cout << "THONG TIN SACH CAN TIM KIEM: " << endl;
			listBook[i]->xuatSach();
			flag = true;
		}
	}
	if (flag == false)
	{
		cout << "KHONG TIM THAY SACH CO MA SO " << maSach << " TRONG TU DIEN." << endl;
	}
}

void THUVIEN::save(int type)
{
	if (type == 1)
	{
		ofstream fileOutBook;
		fileOutBook.open("a.txt");
		if (fileOutBook)
		{
			for (int i = 0; i < this->nBook; i++)
			{
				fileOutBook << this->listBook[i]->getLoaiSach() << ";";
				fileOutBook << this->listBook[i]->getBookName() << ";";
				fileOutBook << this->listBook[i]->getBookID() << ";";
				fileOutBook << this->listBook[i]->getAuthor() << ";";
				fileOutBook << this->listBook[i]->getNXB() << ";";
				fileOutBook << this->listBook[i]->getPrice();
				if (this->listBook[i]->getLoaiSach() == 2)
				{
					fileOutBook << ";" << this->listBook[i]->getISBN();

				}
				fileOutBook << endl;
			}
			fileOutBook.close();
		}
	}
}
void THUVIEN::read()
{
	ifstream fileBookIn;
	fileBookIn.open("a.txt");
	if (fileBookIn)
	{
		this->nBook = 0;
		int loaiSach;
		string tenSach;
		string maSach;
		string tacGia;
		string nhaXuatBan;
		double giaSach;
		string maISBN;
		while (fileBookIn >> loaiSach)
		{
		//	fileBookIn >> loaiSach;
			fileBookIn.seekg(1, ios::cur);
			getline(fileBookIn, tenSach, ';');
			getline(fileBookIn, maSach, ';');
			getline(fileBookIn, tacGia, ';');
			getline(fileBookIn, nhaXuatBan, ';');
			fileBookIn >> giaSach;
			fileBookIn.seekg(1, ios::cur);
			if (loaiSach == 2)
			{
				getline(fileBookIn, maISBN);
			}
			if (loaiSach == 1)
			{
				this->listBook.push_back(new SACHTIENGVIET(loaiSach, tenSach, maSach, tacGia, nhaXuatBan, giaSach));
				this->nBook++;
			}
			if (loaiSach == 2)
			{
				this->listBook.push_back(new SACHNGOAIVAN(loaiSach, tenSach, maSach, tacGia, nhaXuatBan, giaSach, maISBN));
				this->nBook++;
			}
		}
		fileBookIn.close();
	}
}
THUVIEN::~THUVIEN()
{
	for (int i = 0; i < this->nBook; i++)
	{
		delete this->listBook[i];
	}
}