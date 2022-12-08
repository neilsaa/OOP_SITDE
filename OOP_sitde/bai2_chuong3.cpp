#include <bits/stdc++.h>
using namespace std;
class Nguoi
{
private:
  string maSo, hoTen;
  double luong;

public:
  Nguoi(string ms = "", string ht = "", double l = 0.0) : maSo{ms}, hoTen{ht}, luong{l}
  {
    cout << "Nguoi cons" << endl;
  }
};

class Bienche : public Nguoi
{
private:
  double heSo, phuCap;

public:
  Bienche(string ms = "", string ht = "", double l = 0.0, double h = 0.0, double p = 0.0) : Nguoi(ms, ht, l), heSo{h}, phuCap{p}
  {
    cout << "Bien che cons" << endl;
  }
};

class Hopdong : public Nguoi
{
private:
  double tienCong, heSo;
  int soNgay;

public:
  Hopdong(string ms = "", string ht = "", double l = 0.0, double t = 0.0, double h = 0.0, int s = 0) : Nguoi(ms, ht, l), tienCong{t}, heSo{h}, soNgay{s}
  {
    cout << "Hop dong cons" << endl;
  }
};

int main()
{
  Nguoi p = Nguoi("001", "Phong", 40000000);
  Bienche n = Bienche("002", "Nghia", 2000000, 3.2, 300000);
  Hopdong m = Hopdong("003", "Minh", 70000000, 2000000, 2.3, 24);
}