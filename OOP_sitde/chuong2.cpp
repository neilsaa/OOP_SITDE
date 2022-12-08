#include <bits/stdc++.h>
using namespace std;

class Two_nums
{
private:
  int x, y;

public:
  Two_nums(int X = 0, int Y = 0) : x{X}, y{Y} {};
  ~Two_nums(){};
  void input()
  {
    cin >> x >> y;
  }
  int sum()
  {
    return x + y;
  };
  int minus()
  {
    return x - y;
  }
  int multiply()
  {
    return x * y;
  }
  double divide()
  {
    return (double)x / y;
  }
  int gcd()
  {
    int tempx = x, tempy = y;

    if (tempx == 0 || tempy == 0)
    {
      return tempx + tempy;
    }
    while (tempx != tempy)
    {
      if (tempx > tempy)
      {
        tempx -= tempy;
      }
      else
      {
        tempy -= tempx;
      }
    }
    return tempx;
  }

  int lcm()
  {

    return multiply() / gcd();
  }

  int get_max()
  {
    return max(x, y);
  }

  int get_min()
  {
    return min(x, y);
  }
};

int main()
{

  Two_nums test{};
  test.input();
  cout << test.sum() << endl;
  cout << test.minus() << endl;
  cout << test.multiply() << endl;
  cout << test.divide() << endl;
  cout << test.gcd() << endl;
  cout << test.lcm() << endl;
  cout << test.get_max() << endl;
  cout << test.get_min() << endl;
}