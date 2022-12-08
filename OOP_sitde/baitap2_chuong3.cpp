#include <bits/stdc++.h>
using namespace std;

class Nguoi
{
  string ht;

protected:
  string maso;
  float luong;

public:
  void nhapms()
  {
    cout << "Nhap ma so: ";
    cin >> this->maso;
  }
  void nhap()
  {
    cin.ignore();
    cout << "Nhap ho ten: ";
    cin >> this->ht;
    cout << "Nhap luong: ";
    cin >> this->luong;
  }
  string getms()
  {
    return maso;
  }
  void in()
  {

    cout << "Ho ten: " << ht << endl;
    cout << "Luong: " << luong;
    cout << endl;
  }
};

class bienche : public Nguoi
{
protected:
  float hsl, tpc;

public:
  void nbienche()
  {
    Nguoi::nhap();
    cout << "Nhap he so luong: ";
    cin >> hsl;
    cout << "Nhap phu cap: ";
    cin >> tpc;
    luong = hsl * luong + tpc;
  }

  void inbienche()
  {
    cout << "bien che: " << endl;
    Nguoi::in();
  }
};

class hopdong : public Nguoi
{
protected:
  float nc, tc, hs;

public:
  void nhopdong()
  {
    Nguoi::nhap();
    cout << "Nhap ngay cong: ";
    cin >> nc;
    cout << "Nhap tien cong: ";
    cin >> tc;
    cout << "Nhap he so vuot gio: ";
    cin >> hs;
    if (nc > 24)
      luong = (24 + (nc - 24) * hs) * tc;
    else
      luong = nc * tc;
  }

  void inhopdong()
  {
    cout << "hop dong: " << endl;
    Nguoi::in();
  }
};

class Nhanvien : public hopdong, public bienche
{
private:
  string maso;

public:
  void nhapnv()
  {
    cout << "Nhap ma so: ";
    cin >> maso;
    if (maso[0] == '0')
    {
      bienche::nbienche();
    }
    else
    {
      hopdong::nhopdong();
    }
  }

  void print()
  {
    if (maso[0] == '0')
    {
      cout << "Nhan vien thuoc loai ";
      bienche::inbienche();
      cout << "Ma so la: " << maso << endl;
    }
    else
    {
      cout << "Nhan vien thuoc loai ";
      hopdong::inhopdong();
      cout << "Ma so la: " << maso << endl;
    }
  }
};

int main()
{
  int n;
  cout << "Nhap so nhan vien: ";
  cin >> n;
  Nhanvien nv[n];
  for (int i = 0; i < n; i++)
  {
    cout << "Nhap thong tin cho nhan vien thu " << i + 1 << endl;
    nv[i].nhapnv();
  }
  cout << "In ra thong tin tat ca nhan vien" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "Nhan vien thu " << i + 1 << endl;
    nv[i].print();
  }
}