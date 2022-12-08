#include <bits/stdc++.h>
using namespace std;

class String
{
private:
  string s;
  int length;

public:
  String(string str) : s{str}
  {
  }

  void nhap()
  {
    cout << "Nhap chuoi s: ";
    cin >> s;
  }

  void in()
  {
    cout << s;
  }

  char character(int i)
  {
    return s[i];
  }
};