#include <bits/stdc++.h>
using namespace std;

class capSoNguyen
{
private:
  int a, b;

public:
  capSoNguyen(int a = 0, int b = 0)
  {
    this->a = a;
    this->b = b;
  }
  void nhap()
  {
    cout << "Nhap 2 so a va b: ";
    cin >> a >> b;
  }

  int UCLN(int a, int b)
  {
    return (b == 0) ? a : UCLN(b, a % b);
  }

  void in()
  {
    cout << a << ' ' << b << endl;
  }

  // int geta() { return a; };
  // int getb() { return b; };

  bool nguyenToCungNhau()
  {
    if (UCLN(a, b) == 1)
      return true;
    return false;
  }

  capSoNguyen operator-()
  {
    return capSoNguyen(-(this->a), -(this->b));
  }

  bool operator<(const capSoNguyen &rhs)
  {
    return (this->a * this->b) < (rhs.a * rhs.b);
  }
};

int main()
{
  int n;
  cout << "Nhap so doi tuong ban muon tao: ";
  cin >> n;
  capSoNguyen a[n];

  for (int i = 0; i < n; i++)
  {
    a[i].nhap();
  }
  for (int i = 0; i < n; i++)
  {
    a[i].in();
  }

  bool sorted = true;

  for (int i = 0; i < n - 1; i++)
  {
    if (a[i] < a[i + 1])
    {
      sorted = false;
      break;
    }
  }

  if (sorted)
  {
    cout << "Day da duoc sap xep giam dan" << endl;
  }
  else
  {
    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (a[i] < a[j])
        {
          capSoNguyen temp = a[i];
          a[i] = a[j];
          a[j] = temp;
        }
      }
    }

    cout << "Day sau khi duoc sap xep la: " << endl;
    for (int i = 0; i < n; i++)
    {
      a[i].in();
    }
  }

  // a[3] = -a[3];

  // a[3].in();
}
