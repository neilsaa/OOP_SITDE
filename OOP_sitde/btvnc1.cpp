#include <bits/stdc++.h>

using namespace std;

class Student
{

public:
  string maSinhVien;
  string ten;
  string lop;
  int diemTrungBinh;

  Student(){};
  Student(string msv, string name, string clas, int diem)
  {
    maSinhVien = msv;
    ten = name;
    lop = clas;
    diemTrungBinh = diem;
  }
};

bool compare(Student s1, Student s2)
{
  return s1.diemTrungBinh > s2.diemTrungBinh;
}
int main()
{

  int n;
  cout << "Nhap so sinh vien: ";
  cin >> n;

  Student *students = new Student[n];

  for (int i = 0; i < n; i++)
  {
    rewind(stdin);
    string maSinhVien, ten, lop;
    cout << "Nhap ma sinh vien: ";
    cin >> maSinhVien;
    rewind(stdin);
    cout << "Nhap ten sinh vien: ";
    getline(cin, ten);
    rewind(stdin);
    cout << "Nhap lop sinh vien: ";
    getline(cin, lop);

    int diemTrungBinh;
    cout << "Nhap diem trung binh: ";
    cin >> diemTrungBinh;

    Student sinhVien(maSinhVien, ten, lop, diemTrungBinh);

    *(students + i) = sinhVien;
  }

  sort(students, students + n, compare);

  for (int i = 0; i < n; i++)
  {
    cout << students[i].maSinhVien << ' ' << students[i].ten << ' ' << students[i].lop << ' ' << students[i].diemTrungBinh << endl;
  }

  delete[] students;
}
