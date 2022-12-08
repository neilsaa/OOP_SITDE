#include <bits/stdc++.h>
using namespace std;
bool namNhuan(int y)
{
  if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
    return true;

  return false;
}
class Date
{
private:
  int day, month, year;

public:
  Date(int d = 1, int m = 1, int y = 1) : day{d}, month{m}, year{y}
  {
  }
  void input()
  {
    cout << "Nhap ngay thang nam (cach nhau boi dau cach) : ";
    cin >> day >> month >> year;
  }

  int daysIn(int m)
  {
    int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return day[m - 1];
  }

  void normalize()
  {
    while (day < 1 || day > daysIn(month))
    {
      cout << "Ngay khong hop le, moi nhap lai: ";
      cin >> day;
    }

    while (month < 1 || month > 12)
    {
      cout << "Thang khong hop le, moi nhap lai: ";
      cin >> month;
    }

    while (year < 1)
    {
      cout << "Thang khong hop le, moi nhap lai: ";
      cin >> year;
    }
  }

  void advance(int y, int m, int d)
  {
    day += d;
    while (day > daysIn(month))
    {

      day -= daysIn(month);
      month++;
      if (month > 12)
        month = 1;
    }
    month += m;
    while (month > 12)
    {
      month -= 12;
      year++;
    }
    year += y;
  }

  void reset(int y, int m, int d)
  {
    year = y;
    month = m;
    day = d;
  }

  Date operator+(int d)
  {

    this->advance(0, 0, d);
    return *this;
  }

  long long operator-(const Date &rhs)
  {
    int n = 0;
    for (int i = 1; i <= this->year; i++)
    {
      if (namNhuan(i))
        n++;
    }
    long long dayl = this->year * 365 + n;
    n = 0;

    for (int i = 1; i <= rhs.year; i++)
    {
      if (namNhuan(i))
        n++;
    }

    long long dayr = rhs.year * 365 + n;

    for (int i = 1; i <= this->month; i++)
    {
      dayl += (daysIn(i));
    }

    for (int i = 1; i <= rhs.month; i++)
    {
      dayr += (daysIn(i));
    }

    dayl += this->day;
    dayr += rhs.day;

    return dayl - dayr + 1;
  }

  void printDate()
  {
    cout << day << ' ' << month << ' ' << year << endl;
  }
};

int main()
{
  Date d;
  d.input();
  d.normalize();
  d.printDate();
  // d.advance(9, 4, 36);
  d.printDate();
  Date today(1, 10, 2022);

  cout << abs(d - today);
}