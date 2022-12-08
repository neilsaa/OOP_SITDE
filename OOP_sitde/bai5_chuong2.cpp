#include <iostream>

#include <iomanip>

#include <stdio.h>

#include <conio.h>

#include <string.h>

#include <bits/stdc++.h>

using namespace std;

class hoadon
{

  int shd;

  char ten[20];

  float tienban;

  static int tong_don;

  static float tong_tien;

public:
  hoadon *next;

  void nhap()
  {

    cout << "Nhap vao thong tin hoa don";

    cout << "\nNhap so hoa don: ";
    cin >> shd;

    cout << "Nhap ten hang: ";
    cin.ignore(1);
    cin.get(ten, 20);

    cout << "Nhap tien ban: ";
    cin >> tienban;

    tong_don++;

    tong_tien = tong_tien + gia;
  }

  void in()
  {

    cout << "\n"
         << setw(6) << shd << setw(21) << ten << setw(10) << tienban;
  }

  friend doicho(hoadon &i, hoadon &j)
  {

    hoadon tg;

    tg.shd = i.shd;
    i.shd = j.shd;
    j.shd = tg.shd;

    strcpy(tg.ten, i.ten);
    strcpy(i.ten, j.ten);
    strcpy(j.ten, tg.ten);

    tg.gia = i.gia;
    i.gia = j.gia;
    j.gia = tg.gia;
  }

  static void tinhtong()
  {

    cout << "\nTong so hoa don: " << tong_don;

    cout << "\nTong so tien ban: " << tong_tien;
  }

  int getgia()
  {

    return (gia);
  }
};

int hoadon::tong_don = 0;

float hoadon::tong_tien = 0.0;

main()
{

  tinhtong();

  hoadon *d = NULL, *c = NULL;

  char tiep = 'c';

  while (tiep == 'c')
  {

    hoadon *hd = new hoadon();

    hd->nhap();

    hd->next = NULL;

    if (d == NULL)
    {

      d = c = hd;
    }

    else
    {

      c->next = hd;

      c = hd;
    }

    cout << "nhap tiep (c: tiep): ";
    cin >> tiep;
  }

  // In danh sach sau khi nhap

  hoadon *in = d;

  cout << "Danh sach hoa don";

  cout << "\n"
       << "|-----|--------------------|---------|";

  cout << "\n"
       << "|So hd|       Ten hang     |   Gia   |";

  cout << "\n"
       << "|-----|--------------------|---------|";

  while (in != NULL)
  {

    in->in();

    in = in->next;
  }

  hoadon *i = d;

  hoadon *j;

  while (i != NULL)
  {

    j = i->next;

    while (j != NULL)
    {

      if (i->getgia() < j->getgia())

        doicho(*i, *j);

      j = j->next;
    }

    i = i->next;
  }

  in = d;

  cout << "\nDanh sach hoa don da duoc sap xep";

  cout << "\n"
       << "|-----|--------------------|---------|";

  cout << "\n"
       << "|So hd|       Ten hang     |   Gia   |";

  cout << "\n"
       << "|-----|--------------------|---------|";

  while (in != NULL)
  {

    in->in();

    in = in->next;
  }

  hoadon::tinhtong();
}