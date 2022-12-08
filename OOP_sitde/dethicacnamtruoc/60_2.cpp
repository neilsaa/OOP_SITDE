#include <bits/stdc++.h>
using namespace std;

class NGUOI
{
protected:
  char ma_so[10];
  char ho_ten[50];
  float luong;

public:
  static int tong_so_nhan_vien;
  NGUOI()
  {
    tong_so_nhan_vien++;
  }
  ~NGUOI()
  {
    tong_so_nhan_vien--;
  }

  void nhap()
  {
    cout << "Nhap ma so (ma so bat dau bang chu 'h' la nhan vien hanh chinh, 'l' la nhan vien lam ca):";
    cin.ignore();
    cin.get(ma_so, 10);
    cout << "Nhap ho va ten: ";
    cin.ignore();
    cin.get(ho_ten, 50);
    // cin >> luong;
  }

  friend bool operator<(NGUOI &lhs, NGUOI &rhs)
  {
    return lhs.luong < rhs.luong;
  }
};
int NGUOI::tong_so_nhan_vien = 0;
class Nhan_vien_hanh_chinh : virtual public NGUOI
{
private:
  float he_so_luong, luong_co_ban, phu_cap;

public:
  void nhap_nhan_vien_hanh_chinh()
  {
    cout << "Nhap he so luong: ";
    cin >> he_so_luong;
    cout << "Nhap luong co ban: ";
    cin >> luong_co_ban;
    cout << "Nhap phu cap: ";
    cin >> phu_cap;

    luong = he_so_luong * luong_co_ban + phu_cap;
  }
};

class Nhan_vien_lam_ca : virtual public NGUOI
{
private:
  int so_ca;
  float tien_cong_mot_ca, tien_an_ca, phu_cap_doc_hai;

public:
  void nhap_nhan_vien_lam_ca()
  {
    cout << "Nhap so ca: ";
    cin >> so_ca;
    cout << "Nhap tien cong 1 ca: ";
    cin >> tien_cong_mot_ca;
    cout << "Nhap tien an ca: ";
    cin >> tien_an_ca;
    cout << "Nhap phu cap doc hai: ";
    cin >> phu_cap_doc_hai;

    luong = so_ca * tien_cong_mot_ca + tien_an_ca + phu_cap_doc_hai;
  }
};

class Nhan_vien : public Nhan_vien_hanh_chinh, public Nhan_vien_lam_ca
{
public:
  void nhap_nhan_vien()
  {
    while (1)
    {
      nhap();
      if (ma_so[0] == 'h')
      {
        nhap_nhan_vien_hanh_chinh();
        break;
      }
      else if (ma_so[0] == 'l')
      {
        nhap_nhan_vien_lam_ca();
        break;
      }
      else
        cout << "Ma nhan vien khong hop le yeu cau nhap lai ! ! !" << endl;
    }
  }

  void in(int i)
  {
    printf("|%-5d|%-10s|%-29s|%-13.2f|\n", i + 1, ma_so, ho_ten, luong);
  }
};

int main()
{
  int n;
  cout << "Nhap so nhan vien ban muon quan ly: ";
  cin >> n;
  Nhan_vien a[n];

  for (int i = 0; i < n; i++)
  {
    cout << "Nhap thong tin cho nhan vien thu: " << i + 1 << ": " << endl;

    a[i].nhap_nhan_vien();
  }

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (a[i] < a[j])
      {
        Nhan_vien temp = a[j];
        a[j] = a[i];
        a[i] = temp;
      }
    }
  }

  cout << "| STT | Ma ho so |          Ho va ten          |    Luong    |" << endl;

  for (int i = 0; i < n; i++)
  {
    a[i].in(i);
  }
}