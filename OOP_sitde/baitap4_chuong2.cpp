#include <bits/stdc++.h>
using namespace std;

class Sinhvien
{
  pair<string, double> diemthi[9];
  vector<int> thilai;

public:
  void nhapdiem()
  {
    cout << "Nhap diem 9 mon hoc: " << endl;
    for (auto &&i : diemthi)
    {
      cout << "Nhap ten mon hoc: " << endl;
      cin >> i.first;
      cout << "Nhap diem mon hoc: " << endl;
      cin >> i.second;
    }
  }
  bool checktren5()
  {
    bool trentb = true;
    for (auto &&i : diemthi)
    {
      if (i.second < 5)
      {
        trentb = false;
      }
    }
    return trentb;
  }

  double diemtb()
  {
    double sum = 0;
    for (auto &&i : diemthi)
    {
      sum += i.second;
    }
    return sum / 9;
  }

  bool checkkhoaluan()
  {
    return (checktren5() && diemtb() >= 7);
  }

  bool checktotnghiep()
  {
    return (diemtb() < 7 && checktren5());
  }

  bool checkthilai()
  {
    if (checktren5())
      cout << "Sinh vien khong phai thi lai mon nao";
    else
    {
      cout << "Sinh vien thi lai nhung mon sau: " << endl;
      for (auto &&i : diemthi)
      {
        if (i.second < 5)
          cout << i.first << ' ';
      }
      cout << endl;
    }
  }
};

int main()
{
  Sinhvien sv;
  // sv.nhapdiem();
  // sv.checkkhoaluan();
  // sv.checktotnghiep();
  // sv.checkthilai();
}