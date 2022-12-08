#include <bits/stdc++.h>
using namespace std;

class GIANG_VIEN
{
private:
protected:
  char ma_so[10];
  char ho_ten[30];
  float gio_nghien_cuu;

public:
  static int so_giang_vien;
  static int get_so_giang_vien()
  {
    return so_giang_vien;
  }
  GIANG_VIEN()
  {
    so_giang_vien++;
  }
  ~GIANG_VIEN()
  {
    so_giang_vien--;
  }

  void nhap()
  {
    cout << "Moi ban nhap ma so: ";
    cin.get(ma_so, 10);
    cout << "Moi ban nhap ho va ten: ";
    cin.ignore();
    cin.get(ho_ten, 30);
  }

  bool operator<(GIANG_VIEN &rhs)
  {
    return this->gio_nghien_cuu > rhs.gio_nghien_cuu;
  }
};
int GIANG_VIEN::so_giang_vien = 0;
class GIANG_VIEN_CO_HUU : virtual public GIANG_VIEN
{
private:
  int so_bai_bao;
  float gio_bai_bao, huong_dan_nghien_cuu, he_so_nghien_cuu;

public:
  void nhap_co_huu()
  {
    cout << "Moi ban nhap so bai bao: ";
    cin >> so_bai_bao;
    cout << "Moi ban nhap gio bai bao: ";
    cin >> gio_bai_bao;
    cout << "Moi ban nhap huong dan nghien cuu: ";
    cin >> huong_dan_nghien_cuu;
    cout << "Moi ban nhap he so nghien cuu: ";
    cin >> he_so_nghien_cuu;

    gio_nghien_cuu = so_bai_bao * gio_bai_bao + huong_dan_nghien_cuu * he_so_nghien_cuu;
  }
};

class GIANG_VIEN_KIEM_GIANG : virtual public GIANG_VIEN
{
private:
  int so_bai_bao;
  float gio_bai_bao, gio_kiem_giang;

public:
  void nhap_kiem_giang()
  {
    cout << "Moi ban nhap so bai bao: ";
    cin >> so_bai_bao;
    cout << "Moi ban nhap gio bai bao: ";
    cin >> gio_bai_bao;
    cout << "Moi ban nhap gio kiem giang: ";
    cin >> gio_kiem_giang;

    gio_nghien_cuu = so_bai_bao * gio_bai_bao + gio_kiem_giang;
  }
};

class Giang_vien : public GIANG_VIEN_CO_HUU, public GIANG_VIEN_KIEM_GIANG
{
public:
  void nhap_giang_vien()
  {
    nhap();
    if (ma_so[0] == 'c')
      nhap_co_huu();
    else
      nhap_kiem_giang();
  }

  void hoanvi(Giang_vien *g1, Giang_vien *g2)
  {
    Giang_vien *temp = g2;
    g2 = g1;
    g1 = temp;
  }

  string get_ma_so()
  {
    return ma_so;
  }

  char *get_ho_ten()
  {
    return ho_ten;
  }

  float get_gio()
  {
    return gio_nghien_cuu;
  }

  void xuat(int stt)
  {
    printf("|%-5d|%-9s|%-20s|%-18f|\n", stt, ma_so, ho_ten, gio_nghien_cuu);
  }
};
class Node
{
public:
  Giang_vien *data;
  Node *next;
  Node()
  {
    data = 0;
    next = NULL;
  }
  Node(Giang_vien *d)
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

  void insert(Giang_vien *d)
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
};

int main()
{
  LinkedList *list = new LinkedList();
  int choice = 1;
  int stt = 0;
  while (choice)
  {
    stt++;
    Giang_vien *temp = new Giang_vien();
    cout << "Moi ban nhap thong tin cho giang vien thu " << stt << ": " << endl;
    temp->nhap_giang_vien();
    list->insert(temp);

    cout << "Ban co muon nhap them du lieu? (1 la co, 0 la khong muon nhap them): ";
    cin >> choice;
    cin.ignore();
  }

  Node *curPtr = list->head;
  while (curPtr != NULL)
  {
    Node *temp = curPtr->next;

    while (temp != NULL)
    {
      if (temp->data->get_gio() > curPtr->data->get_gio())
      {
        Giang_vien *tg = temp->data;
        temp->data = curPtr->data;
        curPtr->data = tg;
      }

      temp = temp->next;
    }

    curPtr = curPtr->next;
  }
  curPtr = list->head;
  stt = 0;
  cout << "| STT |  Ma so  |       Ho ten       |  Gio nghien cuu  |" << endl;
  while (curPtr != NULL)
  {
    stt++;
    curPtr->data->xuat(stt);
    curPtr = curPtr->next;
  }

  cout << "           Tong so giang vien: " << GIANG_VIEN::so_giang_vien;
}