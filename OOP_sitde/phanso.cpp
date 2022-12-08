#include <bits/stdc++.h>
using namespace std;

int UCLN(int a, int b)
{
  return (b == 0) ? a : UCLN(b, a % b);
}

class PHANSO
{

public:
  int tu, mau;
};

PHANSO toi_gian(PHANSO a)
{
  PHANSO c;
  c.tu = a.tu / UCLN(a.tu, a.mau);
  c.mau = a.mau / UCLN(a.tu, a.mau);
  return c;
}

PHANSO cong(PHANSO a, PHANSO b)
{
  PHANSO c;
  c.tu = a.tu * b.mau + a.mau * b.tu;
  c.mau = a.mau * b.mau;
  toi_gian(c);
  return c;
}

PHANSO tru(PHANSO a, PHANSO b)
{
  PHANSO c;
  c.tu = a.tu * b.mau + a.mau * b.tu;
  c.mau = a.mau * b.mau;
  toi_gian(c);
  return c;
}

void xuat(PHANSO a)
{
  cout << a.tu << '/' << a.mau;
}

int main()
{
  PHANSO a, b, c;
  int n;
  PHANSO ps[n];
  cout << "\nNhap phan so a : ";
  cin >> a.tu >> a.mau;
  cout << "\nNhap phan so b : ";
  cin >> b.tu >> b.mau;
  cout << "\nPhan so a toi gian : ";
  a = toi_gian(a);
  xuat(a);
  cout << "\nphan so b toi gian : ";
  b = toi_gian(b);
  xuat(b);
  cout << "\nTong cua hai phan so :";
  c = toi_gian(cong(a, b));
  xuat(c);
  cout << "\nHieu cua hai phan so :";
  c = toi_gian(tru(a, b));
  xuat(c);
  PHANSO sum;
  sum.tu = 0;
  sum.mau = 1;
  for (int i = 0; i < n; i++)
  {
    cout << "\nNhap phan so : ";
    cin >> ps[i].tu >> ps[i].mau;
  }

  for (int i = 0; i < n; i++)
  {
    sum = cong(sum, ps[i]);
  }

  cout << "Tong day so la ";
  xuat(toi_gian(sum));

}