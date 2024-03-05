//http://www.upcoder.xyz/'index.php/1c01c36678b0938b5cf3f2d1eaf5217e528077b2ed93be16f0d95b5f553f1bd9/jytsG''y3w&xqLqNex@y43'iSLK3~rhs'qvqjlPot'uzbRlu'891'h7:K74!K5M9.89_-jAhc~9f:b-0N.gg7'L?C2T@q1?CBk@xiSk~zk:1S3/31f2e9302a00611fbe3e7e7ebd3fd07e9ff7ea0b06742bfc2e511c0a5e0011da
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <cmath>
using namespace std;

class Diem {
private:
    int size;
    float diem[10000];
public:
    Diem() {
        size = 1;
        diem[0] = 0;
    }
    Diem(int n) {
        size = n;
        for (int i = 0; i < n; i++) {
            diem[i] = 0;
        }
    }
    Diem(int n, float a[]) {
        size = n;
        for (int i = 0; i < n; i++) {
            diem[i] = a[i];
        }
    }

    friend istream& operator>>(istream& in, Diem& diem) {
        int n = 0;
        string s;
        getline(in, s);
        stringstream ss(s);
        string x;
        while (ss >> x) { 
            diem.diem[n] = stof(x); 
            n++;
        }
        diem.size = n;
        return in;
    }
    friend ostream& operator<<(ostream& ou, const Diem& diem) {
        for (int i = 0; i < diem.size; i++)
            cout << diem.diem[i] << " ";
        return ou;
    }

    float operator[](int k) const {
        return diem[k];
    }

    float DTB() const {
        float res = 0;
        for (int i = 0; i < size; i++) {
            res += diem[i];
        }
        return res / size;
    }
};

class MangSinhVien {
private:
    int sl;
    string name[100];
    string mssv[100];
    Diem diemm[100];
public:
    MangSinhVien(int a) : sl(a) {}

    friend istream& operator>>(istream& in, MangSinhVien& sv) {
        for (int i = 0; i < sv.sl; i++) {
             
            getline(in, sv.name[i]);
            getline(in, sv.mssv[i]);
            in >> sv.diemm[i];
        }
        return in;
    }

    int Max() const {
        int maxIndex = 0;
        float maxDTB = diemm[0].DTB();
        for (int i = 1; i < sl; ++i) {
            float dtb = diemm[i].DTB();
            if (dtb > maxDTB) {
                maxDTB = dtb;
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    friend ostream& operator<<(ostream& ou, const MangSinhVien& sv) {
        int i = sv.Max();
        ou << "Ho Ten: " << sv.name[i] << endl;
        ou << "Ma Sinh Vien: " << sv.mssv[i] << endl;
        ou << "DTB: " ; printf("%.1f",sv.diemm[i].DTB());ou << endl;
        return ou;
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    MangSinhVien sv(n);
        cin >> sv;
        cout << sv << endl;
    return 0;
}