#include <bits/stdc++.h>
using namespace std;

class SACH
{
private:
protected:
  char ten_sach[50];
  double gia_bia;
  char ma_sach[10];

public:
  SACH()
  {
  }

  ~SACH()
  {
  }

  void nhap()
  {
    cout << "Moi ban nhap ma sach (Bat dau bang ki tu 'b' la co bia, 'k' la khong co bia): ";
    cin.ignore();
    cin.get(ma_sach, 10);
    cout << "Moi ban nhap ten sach: ";
    cin.ignore();
    cin.get(ten_sach, 50);
    // cout << "Moi ban nhap gia bia: ";
    // cin >> gia_bia;
  }

  string qua_tang()
  {
    if (gia_bia >= 500000)
      return "Qua dac biet";

    if (gia_bia < 200000)
      return "Khong tang qua";

    return "Qua tang";
  }

  bool operator>(const SACH &rhs) const
  {
    return this->gia_bia > rhs.gia_bia;
  }
};

class SACH_VE_BIA : virtual public SACH
{
private:
  int so_trang;
  double dongia_trang, gia_ve_bia;

public:
  void nhap_sach_ve_bia()
  {
    cout << "Moi ban nhap so trang: ";
    cin >> so_trang;
    cout << "Moi ban nhap don gia trang: ";
    cin >> dongia_trang;
    cout << "Moi ban nhap gia ve bia: ";
    cin >> gia_ve_bia;
    gia_bia = dongia_trang * so_trang + gia_ve_bia;
  }
};

class SACH_KHONG_VE_BIA : virtual public SACH
{
private:
  int so_trang;
  double dongia_trang;

public:
  void nhap_sach_khong_ve_bia()
  {
    cout << "Moi ban nhap so trang: ";
    cin >> so_trang;
    cout << "Moi ban nhap don gia trang: ";
    cin >> dongia_trang;
    gia_bia = dongia_trang * so_trang;
  }
};

class BOOK : public SACH_KHONG_VE_BIA, public SACH_VE_BIA
{
public:
  void nhap_book()
  {
    nhap();
    if (ma_sach[0] == 'b')
      nhap_sach_ve_bia();
    else
      nhap_sach_khong_ve_bia();
  }

  string get_ten()
  {
    return this->ten_sach;
  }

  string get_ma()
  {
    return this->ma_sach;
  }

  double get_gia()
  {
    return this->gia_bia;
  }

  void set_gia(double gia)
  {
    this->gia_bia = gia;
  }
  void in(int i)
  {
    printf("|%-5d|%-20s|%-13.2f|", i + 1, ten_sach, gia_bia);
    cout << qua_tang() << setw(17 - qua_tang().length()) << '|' << endl;
  }
};

int main()
{
  int n;
  cout << "Moi ban nhap so sach can quan li: ";
  cin >> n;
  BOOK a[n];
  for (int i = 0; i < n; i++)
  {
    cout << "Moi ban nhap thong tin quyen sach thu " << i + 1 << ":" << endl;
    a[i].nhap_book();
  }
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (a[i].get_ten() > a[j].get_ten())
      {
        BOOK temp = a[j];
        a[j] = a[i];
        a[i] = temp;
      }
    }
  }
  cout << "| STT |      Ten sach      |   Gia bia   |    Qua Tang    |" << endl;
  for (int i = 0; i < n; i++)
  {
    // printf("|%-5d|%-20s|%-10.2f|%-16s|", i + 1, a[i].get_ten(), a[i].get_gia(), a[i].qua_tang());

    // cout << '|' << i + 1 << setw(5) << '|' << a[i].get_ten() << setw(21 - a[i].get_ten().length()) << '|';
    // printf("%-13.2lf", a[i].get_gia());
    // cout << '|' << a[i].qua_tang() << setw(17 - a[i].qua_tang().length()) << '|' << endl;
    a[i].in(i);
  }
}