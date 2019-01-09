#include "THUVIEN.h"
int THUVIEN::nBook = 0;
int THUVIEN::nReader = 0;
int THUVIEN::nPhieuMuon = 0;
int THUVIEN::nPhieuTra = 0;
void THUVIEN::nhapSach()
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

void THUVIEN::xuatSach()
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
			break;
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
			break;
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
			break;
		}
	}
	if (flag == false)
	{
		cout << "KHONG TIM THAY SACH CO MA SO " << maSach << " TRONG TU DIEN." << endl;
	}
}

void THUVIEN::saveBook()
{
	ofstream fileOutBook;
	fileOutBook.open("Sach.txt");
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
void THUVIEN::read()
{
	ifstream fileBookIn,fileReaderIn,filePhieuIn;
	fileBookIn.open("Sach.txt");
	if (fileBookIn)
	{
		this->listBook.clear();
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
	fileReaderIn.open("DocGia.txt");
	if (fileReaderIn)
	{
		this->listReader.clear();
		this->nReader = 0;
		string tenDocGia;
		string maDocGia;
		string dobDocGia;
		string sdtDocGia;
		string diaChiDocGia;
		while (getline(fileReaderIn, tenDocGia, ';'))
		{
			getline(fileReaderIn, maDocGia, ';');
			getline(fileReaderIn, dobDocGia, ';');
			getline(fileReaderIn, sdtDocGia, ';');
			getline(fileReaderIn, diaChiDocGia);
			DOCGIA docGia(tenDocGia, maDocGia, dobDocGia, sdtDocGia, diaChiDocGia);
			listReader.push_back(docGia);
			this->nReader++;
		}
		fileReaderIn.close();
	}
	filePhieuIn.open("Phieu.txt");
	if (filePhieuIn)
	{
		this->listPhieuMuon.clear();
		this->listPhieuTra.clear();
		this->nPhieuMuon = 0;
		this->nPhieuTra = 0;
		int type;
		string tenDG;
		string maDG;
		string tenS;
		string maS;
		string ngay;
		PHIEUMUON phieuMuon;
		PHIEUTRA phieuTra;
		while (filePhieuIn >> type)
		{
			filePhieuIn.seekg(1, ios::cur);
			getline(filePhieuIn, tenDG, ';');
			getline(filePhieuIn, maDG, ';');
			getline(filePhieuIn, tenS, ';');
			getline(filePhieuIn, maS, ';');
			getline(filePhieuIn, ngay);
			if (type == 1)
			{
				phieuMuon = PHIEUMUON(type, tenDG,maDG,tenS, maS, ngay);
				this->listPhieuMuon.push_back(phieuMuon);
				this->nPhieuMuon++;
			}
			else if (type == 2)
			{
				phieuTra = PHIEUTRA(type, tenDG,maDG, tenS, maS, ngay);
				this->listPhieuTra.push_back(phieuTra);
				this->nPhieuTra++;
			}
		}
		filePhieuIn.close();
	}
}

void THUVIEN::nhapDocGia()
{
	cout << "Nhap so luong doc gia: ";
	cin >> this->nReader;
	DOCGIA reader;
	for (int i = 0; i < nReader; i++)
	{
		cout << "NHAP DOC GIA THU " << i + 1 << endl;
		reader.nhapDocGia();
		this->listReader.push_back(reader);
		cout << endl;
	}
}
void THUVIEN::xuatDocGia()
{
	int n = this->listReader.size();
	for (int i = 0; i <n; i++)
	{
		cout << "THONG TIN DOC GIA THU " << i + 1 << endl;
		this->listReader[i].xuatDocGia();
		cout << "=======================================================" << endl;
	}
}


void THUVIEN::saveReader()
{
	ofstream fileOutReader;
	fileOutReader.open("DocGia.txt");
	if (fileOutReader)
	{
		for (int i = 0; i < this->nReader; i++)
		{
			fileOutReader << this->listReader[i].getNameReader() << ";";
			fileOutReader << this->listReader[i].getIDReader() << ";";
			fileOutReader << this->listReader[i].getDOB() << ";";
			fileOutReader << this->listReader[i].getPhoneNumber() << ";";
			fileOutReader << this->listReader[i].getAddress()<<endl;		
		}
		fileOutReader.close();
	}
}
void THUVIEN::addReader()
{
	DOCGIA docgia;
	int x;
	cout << "Nhap so luong doc gia can them: ";
	cin >> x;
	int i = 0;
	while (i < x)
	{
		cout << "THEM DOC GIA THU " << i + 1 << endl;
		docgia.nhapDocGia();
		this->listReader.push_back(docgia);
		cout << endl;
		i++;
	}
	this->nReader += x;
	cout << "HOAN TAT THEM DOC GIA" << endl;
}

void THUVIEN::deleteReader()
{
	string maDG;
	cin.ignore();
	cout << "Nhap ma doc gia can xoa: ";
	getline(cin, maDG);
	bool flag = false;
	for (int i = 0; i < this->nReader; i++)
	{
		if (this->listReader[i].getIDReader() == maDG)
		{
			this->listReader.erase(listReader.begin() + i);
			flag = true;
			break;
		}
	}
	this->nReader -= 1;
	if (flag == true)
	{
		cout << "HOAN TAT XOA DOC GIA" << endl;
	}
	else
	{
		cout << "KHONG TIM THAY DOC GIA CO MA " << maDG << " TRONG THU VIEN" << endl;
	}
}
void THUVIEN::fixReader()
{
	string maDG;
	cin.ignore();
	cout << "Nhap ma doc gia can sua: ";
	getline(cin, maDG);
	bool flag = false;
	for (int i = 0; i < this->nReader; i++)
	{
		if (this->listReader[i].getIDReader() == maDG)
		{
			this->listReader[i].nhapDocGia();
			flag = true;
			break;
		}
	}
	if (flag == true)
	{
		cout << "HOAN TAT NHAP DOC GIA" << endl;
	}
	else
	{
		cout << "KHONG TIM THAY DOC GIA CO MA " << maDG << " TRONG THU VIEN" << endl;
	}
}
void THUVIEN::findReader()
{
	string maDG;
	cin.ignore();
	cout << "Nhap ma doc gia can tim: ";
	getline(cin, maDG);
	bool flag = false;
	for (int i = 0; i < this->nReader; i++)
	{
		if (this->listReader[i].getIDReader() == maDG)
		{
			this->listReader[i].xuatDocGia();
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		cout << "KHONG TIM THAY DOC GIA CO MA " << maDG << " TRONG THU VIEN" << endl;
	}
}

//
void THUVIEN::nhapPhieu()
{
	cout << "\t\tNHAP PHIEU MUON" << endl;
	cout << "Nhap so luong phieu muon: ";
	cin >> this->nPhieuMuon;
	PHIEUMUON phieuMuon;
	PHIEUTRA phieuTra;
	for (int i = 0; i<this->nPhieuMuon; i++)
	{
		cout << "\tNHAP PHIEU MUON THU " << i + 1 << endl;
		phieuMuon.nhapPhieu();
		this->listPhieuMuon.push_back(phieuMuon);
	}
	cout << "\n\tHOAN TAT NHAP PHIEU MUON " << endl;
	cout << "\t\tNHAP PHIEU TRA" << endl;
	cout << "Nhap so luong phieu tra: ";
	cin >> this->nPhieuTra;
	for (int i = 0; i < this->nPhieuTra; i++)
	{
		cout << "\tNHAP PHIEU TRA THU " << i + 1 << endl;
		phieuTra.nhapPhieu();
		this->listPhieuTra.push_back(phieuTra);
	}
	cout << "\n\tHOAN  TAT NHAP PHIEU TRA" << endl;
}

void THUVIEN::xuatPhieu()
{
	cout << "\t\tXUAT PHIEU MUON" << endl;
	for (int i = 0; i < this->nPhieuMuon; i++)
	{
		cout << "PHIEU MUON THU " << i + 1<<endl;
		this->listPhieuMuon[i].xuatPhieu();
		cout << "------------------------------------------------------" << endl;

	}
	cout << "=======================================================" << endl;
	cout << "\n\t\tXUAT PHIEU TRA" << endl;
	for (int i = 0; i < this->nPhieuTra; i++)
	{
		cout << "PHIEU TRA THU " << i + 1 << endl;
		this->listPhieuTra[i].xuatPhieu();
		cout << "------------------------------------------------------" << endl;

	}
}
void THUVIEN::savePhieu()
{
	ofstream filePhieuOut;
	filePhieuOut.open("Phieu.txt");
	if (filePhieuOut)
	{
		for (int i = 0; i < this->nPhieuMuon; i++)
		{
			filePhieuOut << this->listPhieuMuon[i].getType() << ";";
			filePhieuOut << this->listPhieuMuon[i].getTenDG() << ";";
			filePhieuOut << this->listPhieuMuon[i].getMaDG() << ";";
			filePhieuOut << this->listPhieuMuon[i].getTenS() << ";";
			filePhieuOut << this->listPhieuMuon[i].getMa() << ";";
			filePhieuOut << this->listPhieuMuon[i].getNgayMuon() <<endl;
		}
		for (int i = 0; i < this->nPhieuTra; i++)
		{
			filePhieuOut << this->listPhieuTra[i].getType() << ";";
			filePhieuOut << this->listPhieuTra[i].getTenDG() << ";";
			filePhieuOut << this->listPhieuTra[i].getMaDG() << ";";
			filePhieuOut << this->listPhieuTra[i].getTenS() << ";";
			filePhieuOut << this->listPhieuTra[i].getMa() << ";";
			filePhieuOut << this->listPhieuTra[i].getNgayTra() << endl;
		}
		filePhieuOut.close();
	}

}
void THUVIEN::addPhieu()
{
	int x;
	cout << "Nhap so luong phieu can them: ";
	cin >> x;
	int i = 0;
	cout << "Nhap 1 de them phieu muon:" << endl;;
	cout << "Nhap 2 de them phieu tra: " << endl;
	int key;
	PHIEUMUON phieuMuon;
	PHIEUTRA phieuTra;
	while (i < x)
	{
		cout << "\nMoi nhap: ";
		cin >> key;
		if (key == 1)
		{
			phieuMuon.nhapPhieu();
			listPhieuMuon.push_back(phieuMuon);
			this->nPhieuMuon++;
		}
		else if (key == 2)
		{
			phieuTra.nhapPhieu();
			listPhieuTra.push_back(phieuTra);
			this->nPhieuTra++;
		}
		i++;
	}
}
void THUVIEN::deletePhieu()
{
	cout << "Nhap 1 de xoa phieu muon" << endl;;
	cout << "Nhap 2 de xoa phieu tra" << endl;
	cout << "Nhap loai phieu can xoa: ";
	int x;
	cin >> x;
	string ma;
	cout << "\nNhap ma phieu can xoa: ";
	cin.ignore();
	getline(cin,ma);
	bool flag = false;
	if (x == 1)
	{
		for (int i = 0; i, this->nPhieuMuon; i++)
		{
			if (this->listPhieuMuon[i].getMa() == ma)
			{
				this->listPhieuMuon.erase(listPhieuMuon.begin() + i);
				this->nPhieuMuon--;
				flag = true;
				break;
			}
		}
	}
	if (x == 2)
	{
		for (int i = 0; i, this->nPhieuTra; i++)
		{
			if (this->listPhieuTra[i].getMa() == ma)
			{
				this->listPhieuTra.erase(listPhieuTra.begin() + i);
				this->nPhieuTra--;
				flag = true;
				break;
			}
		}
	}
	if (flag == true)
	{
		cout << "XOA PHIEU HOAN TAT" << endl;
	}
	else
	{
		cout << "KHONG TIM THAY PHIEU CO MA " << ma << " TRONG THU VIEN" << endl;
	}
}
void THUVIEN::findPhieu()
{
	cout << "Nhap 1 de tim phieu muon" << endl;;
	cout << "Nhap 2 de tim phieu tra" << endl;
	cout << "Nhap loai phieu can tim: ";
	int x;
	cin >> x;
	string ma;
	cout << "\nNhap ma phieu can tim: ";
	cin.ignore();
	getline(cin, ma);
	bool flag = false;
	if (x == 1)
	{
		for (int i = 0; i, this->nPhieuMuon; i++)
		{
			if (this->listPhieuMuon[i].getMa() == ma)
			{
				this->listPhieuMuon[i].xuatPhieu();
				flag = true;
				break;
			}
		}
	}
	if (x == 2)
	{
		for (int i = 0; i, this->nPhieuTra; i++)
		{
			if (this->listPhieuTra[i].getMa() == ma)
			{
				this->listPhieuTra[i].xuatPhieu();
				flag = true;
				break;
			}
		}
	}
	if (flag == false)
	{
		cout << "KHONG TIM THAY PHIEU CO MA " << ma << " TRONG THU VIEN" << endl;
	}
}
//===============================================================================
void THUVIEN::tachNgay(string date, string &ngay, string &thang, string &nam)
{
	int n = date.size();
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (date[i] == '/')
		{
			flag++;
			continue;
		}
		if (flag == 0)
		{
			ngay.push_back(date[i]);
		}
		if (flag == 1)
		{
			thang.push_back(date[i]);
		}
		if (flag == 2)
		{
			nam.push_back(date[i]);
		}
	}
}
int THUVIEN::tinhNgay(int ngayMuon, int thangMuon, int namMuon, int ngayTra, int thangTra, int namTra)
{
	int soNgay = 0;
	if (thangTra == thangMuon)
	{
		soNgay = ngayTra - ngayMuon + 1;
	}
	else
	{
		if (thangMuon == 1 || thangMuon == 3 || thangMuon == 5 || thangMuon == 7 || thangMuon == 8 || thangMuon == 10 || thangMuon == 12)
		{
			soNgay = 31 - ngayMuon + 1;
		}
		else if (thangMuon == 4 || thangMuon == 6 || thangMuon == 9 || thangMuon == 11)
		{
			soNgay = 30 - ngayMuon + 1;
		}
		else if (thangMuon == 2 && namMuon % 400 == 0 || (namMuon % 4 == 0 && namMuon % 100 != 0))
		{
			soNgay = 29 - ngayMuon + 1;
		}
		else
		{
			soNgay = 28 - ngayMuon + 1;
		}
		int thang = thangMuon + 1;
		for (thang; thang < thangTra; thang++)
		{
			if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
			{
				soNgay += 31;
			}
			else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
			{
				soNgay += 30;
			}
			else if (thang == 2 && namMuon % 400 == 0 || (namMuon % 4 == 0 && namMuon % 100 != 0))
			{
				soNgay += 29;
			}
			else
			{
				soNgay += 28;
			}
		}
		soNgay += ngayTra;
	}
	return soNgay;
}
int THUVIEN::MyDate(string ngay1, string ngay2)
{
	string ngaymuon, ngaytra, thangmuon, thangtra, nammuon, namtra;
	tachNgay(ngay1, ngaymuon, thangmuon, nammuon);
	tachNgay(ngay2, ngaytra, thangtra, namtra);
	int ngayMuon, thangMuon, namMuon, ngayTra, thangTra, namTra;
	ngayMuon = stoi(ngaymuon);
	thangMuon = stoi(thangmuon);
	namMuon = stoi(nammuon);
	ngayTra = stoi(ngaytra);
	thangTra = stoi(thangtra);
	namTra = stoi(namtra);
	int soNgay=0;
	if (namMuon == namTra)
	{
		soNgay = tinhNgay(ngayMuon, thangMuon, namMuon, ngayTra, thangTra, namTra);
	}
	else
	{
		soNgay = tinhNgay(ngayMuon, thangMuon, namMuon, 31, 12, namMuon);
		int nam = namMuon + 1;
		while (nam < namTra)
		{
			if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
			{
				soNgay += 366;
			}
			else
			{
				soNgay += 365;
			}
			nam++;
		}
		soNgay += tinhNgay(1, 1, namTra, ngayTra, thangTra, namTra);
	}
	return soNgay;
}
void THUVIEN::xuatDanhSachQuaHan(string maDG, int soNgay,int tien)
{
	for (int i = 0; i < this->nReader; i++)
	{
		if (maDG == this->listReader[i].getIDReader())
		{
			cout << this->listReader[i].getNameReader();
			cout << setw(35);
			cout << this->listReader[i].getIDReader();
			cout << setw(30);
			cout << soNgay;
			cout << setw(30);
			cout << tien << endl;
		}
	}
}


void THUVIEN::danhSachQuaHan()
{
	int tien=0;
	cout << "\t\t\tDANH SACH CAC DOC GIA MUON SACH QUA HAN VA SO TIEN CAN NOP PHAT"<<endl;
	cout << "Ten doc gia" << setw(30) << "Ma doc gia" <<setw(30)<<"So ngay muon" <<setw(40) << "So tien can nop phat" << endl;
	for (int i = 0; i < this->nPhieuMuon; i++)
	{
		for (int j = 0; j < this->nPhieuTra; j++)
		{
			if (this->listPhieuMuon[i].getMa() == this->listPhieuTra[j].getMa())
			{
				int soNgay = MyDate(this->listPhieuMuon[i].getNgayMuon(), this->listPhieuTra[j].getNgayTra());
				if (soNgay > 7)
				{
					for (int k = 0; k < this->nBook; k++)
					{
						if (this->listPhieuMuon[i].getMa() == this->listBook[k]->getBookID())
						{
							if (this->listBook[k]->getLoaiSach() == 1)
							{
								tien = soNgay * 10000;
								xuatDanhSachQuaHan(this->listPhieuMuon[i].getMaDG(),soNgay, tien);
							}
							else if (this->listBook[k]->getLoaiSach() == 2)
							{
								tien = soNgay * 20000;
								xuatDanhSachQuaHan(this->listPhieuMuon[i].getMaDG(),soNgay, tien);
							}
							break;
						}
					}
				}
			}
		}
	}
}
THUVIEN::~THUVIEN()
{
	for (int i = 0; i < this->nBook; i++)
	{
		delete this->listBook[i];
	}
}