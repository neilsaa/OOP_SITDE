#include <bits/stdc++.h>
using namespace std;

void hoanvi(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

int main()
{
  int a = 1, b = 2;
  hoanvi(a, b);
  cout << a << b;
}