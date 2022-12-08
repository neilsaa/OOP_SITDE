#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class SoNguyen
{
private:
  int a, b;

public:
  SoNguyen() {}
  SoNguyen(int a, int b)
  {
    this->a = a;
    this->b = b;
  }

  void input()
  {
    cout << "nhap a : ";
    cin >> a;
    cout << "nhap b : ";
    cin >> b;
  }

  void output()
  {
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
  }

  string DoiCoSo()
  {
    string m;
    int a1 = a;
    int b1 = b;
    while (a1 != 0)
    {
      m = (char)(a1 % b1 + 48) + a1;
      a1 = a1 / b1;
    }
    return m;
  }

  int travea()
  {
    return this->a;
  }
  int traveb()
  {
    return this->b;
  }

  friend void sortList(SoNguyen *arr, int n)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (arr[i].b < arr[j].b)
        {
          SoNguyen temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }
      }
    }
    std::cout << "\nSap xep danh sach theo thu tu giam dan cua thanh phan b:" << std::endl;
    std::cout << std::setw(10) << "a" << std::setw(10) << "b" << std::endl;
    for (int i = 0; i < n; i++)
    {
      std::cout << std::setw(10) << arr[i].a << std::setw(10) << arr[i].b << std::endl;
    }
  }
};

int main()
{
  SoNguyen m, n;
  m.input();
  cout << m.DoiCoSo();
  if (m.travea() * m.traveb() > n.travea() * n.traveb())
  {
    cout << "M > N";
  }
  else if (m.traveb() * m.travea() == n.travea() * n.traveb())
  {
    cout << " M = N";
  }
  else
  {
    cout << " M < N";
  }
}