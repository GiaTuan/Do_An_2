#include "menu.h"

void menu()
{
	cout << "\t\tCHUONG TRINH QUAN LI THU VIEN" << endl;
	cout << "Nhap: " << endl;
	cout << "\t1: Quan li sach trong thu vien" << endl;
	cout << "\t2: Quan li doc gia trong thu vien" << endl;
	cout << "\t3: Quan li phieu muon/tra sach trong thu vien" << endl;
	cout << "\t4: Liet ke cac doc gia muon sach qua han" << endl;
	cout << "\t-1: Ket thuc chuong trinh" << endl;

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
	cout << "\t6: Tim sach trong thu vien" << endl;
	cout << "\t-1: Quay tro ve trang quan li thu vien" << endl;
}
void menu3()
{
	cout << "\t\tTRANG QUAN LI DOC GIA" << endl;
	cout << "Nhap: " << endl;
	cout << "\t1: Nhap danh sach cac doc gia trong thu vien" << endl;
	cout << "\t2: Xem danh sach cac doc gia trong thu vien" << endl;
	cout << "\t3: Them doc gia vao thu vien" << endl;
	cout << "\t4: Xoa doc gia trong thu vien" << endl;
	cout << "\t5: Sua doc gia trong thu vien" << endl;
	cout << "\t6: Tim doc gia trong thu vien" << endl;
	cout << "\t-1: Quay tro ve trang quan li thu vien" << endl;
}
void menu4()
{
	cout << "\t\tTRANG QUAN LI PHIEU MUON/TRA" << endl;
	cout << "Nhap: " << endl;
	cout << "\t1: Nhap danh sach cac phieu trong thu vien" << endl;
	cout << "\t2: Xem danh sach cac phieu trong thu vien" << endl;
	cout << "\t3: Them phieu vao thu vien" << endl;
	cout << "\t4: Xoa phieu trong thu vien" << endl;
	cout << "\t5: Tim phieu trong thu vien" << endl;
	cout << "\t-1: Quay tro ve trang quan li thu vien" << endl;
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
					library.nhapSach();
					library.saveBook();
					cout << "Nhap 0 de quay tro ve trang quan li sach: ";
					phimTat(key);
				}
				else if (key == 2)
				{
					system("cls");
					library.xuatSach();
					cout << "Nhap 0 de quay tro ve trang quan li sach: ";
					phimTat(key);
				}
				else if (key == 3)
				{
					system("cls");
					library.addBook();
					library.saveBook();
					cout << "Nhap 0 de quay tro ve trang quan li sach: ";
					phimTat(key);
				}
				else if (key == 4)
				{
					system("cls");
					cin.ignore();
					library.deleteBook();
					library.saveBook();
					cout << "Nhap 0 de quay tro ve trang quan li sach: ";
					phimTat(key);
				}
				else if (key == 5)
				{
					system("cls");
					cin.ignore();
					library.fixBook();
					library.saveBook();
					cout << "Nhap 0 de quay tro ve trang quan li sach: ";
					phimTat(key);
				}
				else if (key == 6)
				{
					system("cls");
					cin.ignore();
					library.findBook();
					cout << "Nhap 0 de quay tro ve trang quan li sach: ";
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
					break;
				}
				else
				{
					cout << "Phim tat khong hop le, moi nhap lai.";
					phimTat(key);
				}
			}
		}
		if (t == 2)
		{
			system("cls");
			menu3();
			int key;
			phimTat(key);
			while (1)
			{
				if (key == 1)
				{
					system("cls");
					library.nhapDocGia();
					library.saveReader();
					cout << "Nhap 0 de quay tro ve trang quan li doc gia";
					phimTat(key);
				}
				else if (key == 2)
				{
					system("cls");
					library.xuatDocGia();
					cout << "Nhap 0 de quay tro ve trang quan li doc gia";
					phimTat(key);
				}
				else if (key == 3)
				{
					system("cls");
					library.addReader();
					library.saveReader();
					cout << "Nhap 0 de quay tro ve trang quan li doc gia";
					phimTat(key);
				}
				else if (key == 4)
				{
					system("cls");
					library.deleteReader();
					library.saveReader();
					cout << "Nhap 0 de quay tro ve trang quan li doc gia";
					phimTat(key);
				}
				else if (key == 5)
				{
					system("cls");
					library.fixReader();
					library.saveReader();
					cout << "Nhap 0 de quay tro ve trang quan li doc gia";
					phimTat(key);
				}
				else if (key == 6)
				{
					system("cls");
					library.findReader();
					cout << "Nhap 0 de quay tro ve trang quan li doc gia";
					phimTat(key);
				}
				else if (key == 0)
				{
					system("cls");
					menu3();
					phimTat(key);
				}
				else if (key == -1)
				{
					system("cls");
					menu();
					phimTat(t);
					break;
				}
				else
				{
					cout << "Phim tat khong hop le, moi nhap lai.";
					phimTat(key);
				}
			}
		}
		if (t == 3)
		{
			system("cls");
			menu4();
			int key;
			phimTat(key);
			while (1)
			{
				if (key == 1)
				{
					system("cls");
					library.nhapPhieu();
					library.savePhieu();
					cout << "Nhap 0 de quay tro ve trang quan li doc gia";
					phimTat(key);
				}
				else if (key == 2)
				{
					system("cls");
					library.xuatPhieu();
					cout << "Nhap 0 de quay tro ve trang quan li doc gia";
					phimTat(key);
				}
				else if (key == 3)
				{
					system("cls");
					library.addPhieu();
					library.savePhieu();
					cout << "Nhap 0 de quay tro ve trang quan li doc gia";
					phimTat(key);
				}
				else if (key == 4)
				{
					system("cls");
					library.deletePhieu();
					library.savePhieu();
					cout << "Nhap 0 de quay tro ve trang quan li doc gia";
					phimTat(key);
				}
				else if (key == 5)
				{
					system("cls");
					library.findPhieu();
					cout << "Nhap 0 de quay tro ve trang quan li doc gia";
					phimTat(key);
				}
				else if (key == -1)
				{
					system("cls");
					menu();
					phimTat(t);
					break;
				}
				else if (key == 0)
				{
					system("cls");
					menu4();
					phimTat(key);
				}
				else
				{
					cout << "Phim tat khong hop le, moi nhap lai.";
					phimTat(key);
				}
			}
		}
		if (t == 4)
		{
			int key;
			system("cls");
			library.danhSachQuaHan();
			cout << "Nhap 0 de quay tro ve trang quan li thu vien";
			phimTat(key);
			if (key == 0)
			{
				system("cls");
				menu();
				phimTat(t);
			}
		}
		else if (t == -1)
		{
			break;
		}
		else
		{
			cout << "Phim tat khong hop le, moi nhap lai.";
			phimTat(t);
		}
	}
	library.~THUVIEN();
}