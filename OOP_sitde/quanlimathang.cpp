#include <bits/stdc++.h>
using namespace std;

class mhang
{
  int maso;
  float gia;

public:
  void Setdata(int a, float b)
  {
    maso = a;
    gia = b;
  }
  void show()
  {
    cout << "\nMa so: " << maso << endl;
    cout << "Gia: " << gia << endl;
  }
};

int main()
{
  int k;
  cout << "\nNhap tong so hang mat hang :";
  cin >> k;
  mhang *p = new mhang[k];
  mhang *d = p;
  int x, i;
  float y;
  cout << "\nNhap vao du lieu " << k << " mat hang :";
  for (i = 0; i < k; i++)
  {
    cout << "\nNhap ma hang va don gia cho mat hang thu " << i + 1 << ": ";
    cin >> x >> y;
    p->Setdata(x, y);
    p++;
  }

  for (i = 0; i < k; i++)
  {
    cout << "\nMat hang thu: " << (i + 1) << endl;
    d->show();
    d++;
  }

  delete d;
  delete p;
}
