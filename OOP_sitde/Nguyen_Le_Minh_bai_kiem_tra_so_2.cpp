#include <bits/stdc++.h>
using namespace std;

class SinhVien
{
private:
  string maSinhVien, tenSinhVien;

protected:
  double dmh;

public:
  SinhVien(string msv = "Chua co thong tin", string tsv = "Chua co thong tin", double diem = 0.0)
  {
    this->maSinhVien = msv;
    this->tenSinhVien = tsv;
    this->dmh = diem;
  }
  ~SinhVien()
  {
  }

  virtual void nhap()
  {
    cout << "Nhap ma sinh vien: ";
    cin >> maSinhVien;
    cout << "Nhap ten sinh vien: ";
    cin >> tenSinhVien;
  }
  string getMSV()
  {
    return maSinhVien;
  }
  string getTSV()
  {
    return tenSinhVien;
  }
  double getDiem()
  {
    return dmh;
  }
  void setTSV(string tsv)
  {
    this->tenSinhVien = tsv;
  }
  void setMSV(string msv)
  {
    this->maSinhVien = msv;
  }
  void setDiem(double dmh)
  {
    this->dmh = dmh;
  }
};

class NienChe : virtual public SinhVien
{
private:
  double CC, KT, DT;

public:
  NienChe(double cc = 0.0, double kt = 0.0, double dt = 0.0)
  {
    this->CC = cc;
    this->KT = kt;
    this->DT = dt;
  }

  void nhap() override
  {
    SinhVien::nhap();
    cout << "Nhap diem chuyen can: ";
    cin >> CC;
    cout << "Nhap diem kiem tra: ";
    cin >> KT;
    cout << "Nhap diem thi: ";
    cin >> DT;

    dmh = 0.1 * CC + 0.2 * KT + 0.7 * DT;
  }
};

class TinChi : virtual public SinhVien
{
private:
  double KT, DT;

public:
  TinChi(double kt = 0.0, double dt = 0.0)
  {

    this->KT = kt;
    this->DT = dt;
  }

  void nhap() override
  {
    SinhVien::nhap();

    cout << "Nhap diem kiem tra: ";
    cin >> KT;
    cout << "Nhap diem thi: ";
    cin >> DT;

    dmh = 0.4 * KT + 0.6 * DT;
  }
};
// bool compare(SinhVien sv1, SinhVien sv2)
// {
//   return sv1.getDiem() > sv2.getDiem();
// }

class Node
{
public:
  SinhVien *data;
  Node *next;
  Node()
  {
    data = 0;
    next = NULL;
  }
  Node(SinhVien *d)
  {
    this->data = d;
    this->next = NULL;
  }
};

class LinkedList
{
public:
  Node *head;
  Node *tail;

  LinkedList()
  {
    this->head = NULL;
  }

  void insert(SinhVien *d)
  {
    Node *node = new Node(d);
    if (head == NULL)
    {
      this->head = node;
      this->tail = node;
    }
    else
    {
      this->tail->next = node;
      this->tail = node;
    }
  }

  void print()
  {
    Node *temp = head;
    if (temp == NULL)
      cout << "Danh sach trong" << endl;
    else
    {
      while (temp != NULL)
      {
        cout << "TenSV: " << temp->data->getTSV() << endl
             << "Diem mon hoc: " << temp->data->getDiem() << endl;
        cout << "=========================" << endl;
        temp = temp->next;
      }
    }
  }

  void printHighest()
  {

    Node *cur = head;
    double max = head->data->getDiem();
    while (cur != NULL)
    {
      if (cur->data->getDiem() > max)
      {
        max = cur->data->getDiem();
      }
      cur = cur->next;
    }

    Node *temp = head;

    while (temp != NULL)
    {
      if (temp->data->getDiem() == max)
      {
        cout << "TenSV: " << temp->data->getTSV() << endl
             << "Diem mon hoc: " << temp->data->getDiem() << endl;
        cout << "=========================" << endl;
      }

      temp = temp->next;
    }
  }
};

int main()
{
  LinkedList *lists = new LinkedList();
  int option = 1;
  while (option == 1)
  {
    char c;
    cout << "Nhap loai sinh vien ban muon nhap (t la tin chi, n la nienche ): ";
    cin >> c;

    if (c == 't')
    {
      TinChi *temp = new TinChi();

      temp->nhap();
      lists->insert(temp);
    }
    else if (c == 'n')
    {
      NienChe *temp = new NienChe();
      temp->nhap();
      lists->insert(temp);
    }

    cout << "Co nhap them sinh vien nua khong (1 la co nhap them, 0 la khong nhap them): ";
    cin >> option;
  }
  cout << "Nhung sinh vien co diem cao nhat la: " << endl;
  lists->printHighest();
  delete lists;
}