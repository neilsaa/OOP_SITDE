#include <bits/stdc++.h>
using namespace std;
class NGUOI
{
protected:
  char ma_so[10], ho_ten[50];
  float luong;

public:
  static float tong_luong;
  NGUOI()
  {
  }

  ~NGUOI()
  {
    tong_luong -= luong;
  }
  void nhap()
  {
    cout << "Nhap ma so (ma so bat dau bang chu 'g' cho giang vien va bat dau bang chu 'n' cho nhan vien hanh chinh): ";
    cin.ignore();
    cin.get(ma_so, 10);
    cout << "Nhap ho va ten: ";
    cin.ignore();
    cin.get(ho_ten, 50);
  }

  string xep_loai_luong()
  {
    if (luong < 5000000)
      return "Thu nhap thap";
    else if (luong >= 10'000'000)
      return "Thu nhap cao";
    else
      return "Thu nhap trung binh";
  }

  bool operator>(const NGUOI &rhs) const
  {
    return this->luong > rhs.luong;
  }
};
float NGUOI::tong_luong = 0;

class Giang_vien : virtual public NGUOI
{
private:
  float he_so_luong, luong_co_ban, phu_cap;
  int so_tiet;

public:
  void nhap_giang_vien()
  {
    cout << "Nhap he so luong: ";
    cin >> he_so_luong;
    cout << "Nhap luong co ban: ";
    cin >> luong_co_ban;
    cout << "Nhap phu cap: ";
    cin >> phu_cap;
    cout << "Nhap so tiet: ";
    cin >> so_tiet;

    luong = he_so_luong * luong_co_ban + (so_tiet - 270) * 90000 + phu_cap;
  }
};

class Nhan_vien_hanh_chinh : virtual public NGUOI
{
private:
  float he_so_luong, luong_co_ban, phu_cap_hanh_chinh;

public:
  void nhap_nhan_vien_hanh_chinh()
  {
    cout << "Nhap he so luong: ";
    cin >> he_so_luong;
    cout << "Nhap luong co ban: ";
    cin >> luong_co_ban;
    cout << "Nhap phu cap hanh chinh: ";
    cin >> phu_cap_hanh_chinh;

    luong = he_so_luong * luong_co_ban + phu_cap_hanh_chinh;
  }
};

class Nhan_vien : public Giang_vien, public Nhan_vien_hanh_chinh
{
public:
  void nhap_nhan_vien()
  {

    while (1)
    {
      nhap();

      if (ma_so[0] == 'g')
      {
        nhap_giang_vien();
        break;
      }
      else if (ma_so[0] == 'n')
      {
        nhap_nhan_vien_hanh_chinh();
        break;
      }
      else
        cout << "Ma nhan vien khong hop le vui long nhap lai! ! ! (Ma nhan vien phai bat dau bang g hoac n)" << endl;
    }
  }

  void in(int i)
  {
    printf("|%-5d|%-7s|%-29s|%-13.2f|", i + 1, ma_so, ho_ten, luong);
    cout << xep_loai_luong() << setw(21 - xep_loai_luong().length()) << '|' << endl;
  }

  bool operator<(const Nhan_vien &rhs) const
  {
    return strcmp(this->ho_ten, rhs.ho_ten) < 0;
  }
};

int main()
{
  int n;
  cout << "Nhap so nhan vien ban muon quan li: ";
  cin >> n;

  Nhan_vien a[n];

  for (int i = 0; i < n; i++)
  {
    cout << "Nhap thong tin cho nhan vien thu " << i + 1 << ": " << endl;
    a[i].nhap_nhan_vien();
  }

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (a[j] < a[i])
      {
        Nhan_vien temp = a[j];
        a[j] = a[i];
        a[i] = temp;
      }
    }
  }

  cout << "| STT |Ma h.so|          Ho va ten          |    Luong    |      Xep loai      |" << endl;

  for (int i = 0; i < n; i++)
  {
    a[i].in(i);
  }
}