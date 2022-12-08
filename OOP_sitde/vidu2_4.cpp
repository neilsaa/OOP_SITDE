#include <bits/stdc++.h>
using namespace std;

class Sinhvien
{
  int msv;
  string ht;

protected:
  double dmh;

public:
  void nhaptt()
  {
    cout << "Nhap Ma Sinh Vien: " << endl;
    cin >> msv;
    cout << "Nhap Ho Ten Sinh Vien: " << endl;
    cin >> ht;
  }

  Sinhvien(int msv, string st, double dmh)
  {
    this->msv = msv;
    this->ht = ht;
    this->dmh = dmh;
  }
  ~Sinhvien()
  {
  }
};
class Node
{
public:
  Sinhvien *data;
  Node *next;

  Node()
  {
    data = NULL;
    next = NULL;
  }

  Node(Sinhvien *data)
  {
    this->data = data;
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

  void insert(Sinhvien *data)
  {
    Node *node = new Node(data);

    if (this->head == NULL)
    {
      this->head = node;
      this->tail = node;
      return;
    }
    else
    {
      this->tail->next = node;
      this->tail = node;
    }
  }
};
class Nienche : public Sinhvien
{
  double CC;
  double KT;
  double DT;

public:
  void nhapdiem()
  {
    Sinhvien::nhaptt();
    cout << "Nhap diem Chuyen Can: " << endl;
    cin >> CC;
    cout << "Nhap diem Kiem Tra: " << endl;
    cin >> KT;
    cout << "Nhap diem thi: " << endl;
    cin >> DT;
    dmh = 0.1 * CC + 0.2 * KT + 0.7 * DT;
  }
  void tinhdiem()
  {
    cout << "Diem mon hoc = " << dmh;
  }
};

class TinChi : public Sinhvien
{
  double kt, dt;

public:
  void nhapdiem()
  {
    Sinhvien::nhaptt();

    cout << "Nhap diem Kiem Tra: " << endl;
    cin >> kt;
    cout << "Nhap diem thi: " << endl;
    cin >> dt;
    dmh = 0.4 * kt + 0.6 * dt;
  }
}
}

int main()
{
}