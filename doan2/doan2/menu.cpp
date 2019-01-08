#include "menu.h"

void menu()
{
	cout << "\t\tCHUONG TRINH QUAN LI THU VIEN" << endl;
	cout << "Nhap: " << endl;
	cout << "\t1: Quan li sach trong thu vien" << endl;
	cout << "\t2: Quan li doc gia trong thu vien" << endl;
	cout << "\t3: Quan li phieu muon/tra sach trong thu vien" << endl;
	cout << "\t4: Liet ke cac doc gia muon sach qua han" << endl;
}
void menu2()
{
	cout << "\t\tTRANG QUAN LI SACH" << endl;
	cout << "Nhap: " << endl;
	cout << "\t1: Nhap danh sach cac sach trong thu vien" << endl;
	cout << "\t2: Xem danh sach cac sach trong thu vien" << endl;
	cout << "\t3: Them sach vao thu vien" << endl;
	cout << "\t4: Xoa sach trong thu vien" << endl;
	cout << "\t5: Sua sach trong thu vien" << endl;
}
void phimTat(int &key)
{
	cout << "\nMoi ban nhap: ";
	cin >> key;
}

void xuLy(THUVIEN &library,int &t)
{
	library.read();
	while (1)
	{
		if (t == 1)
		{
			system("cls");
			menu2();
			int key;
			phimTat(key);
			while (1)
			{
				if (key == 1)
				{
					system("cls");
					library.nhapThuVien();
					library.save(1);
					cout << "Nhap 0 de quay tro ve menu: ";
					phimTat(key);
				}
				else if (key == 2)
				{
					system("cls");
					library.xuatThuVien();
					cout << "Nhap 0 de quay tro ve menu: ";
					phimTat(key);
				}
				else if (key == 3)
				{
					system("cls");
					library.addBook();
					library.save(1);
					cout << "Nhap 0 de quay tro ve menu: ";
					phimTat(key);
				}
				else if (key == 4)
				{
					system("cls");
					cin.ignore();
					library.deleteBook();
					library.save(1);
					cout << "Nhap 0 de quay tro ve menu: ";
					phimTat(key);
				}
				else if (key == 5)
				{
					system("cls");
					cin.ignore();
					library.fixBook();
					library.save(1);
					cout << "Nhap 0 de quay tro ve menu: ";
					phimTat(key);
				}
				else if (key == 6)
				{
					system("cls");
					cin.ignore();
					library.findBook();
					library.save(1);
					cout << "Nhap 0 de quay tro ve menu: ";
					phimTat(key);
				}
				else if (key == 0)
				{
					system("cls");
					menu2();
					phimTat(key);
				}
				else if (key == -1)
				{
					system("cls");
					menu();
					phimTat(t);
				}
				else
				{
					cout << "Phim tat khong hop le, moi nhap lai." << endl;
					phimTat(key);
				}
			}
		}
	}
	library.~THUVIEN();
}