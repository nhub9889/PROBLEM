//http://www.upcoder.xyz/'index.php/498cf349af57234206de0ced9c02ede8ada328ca371a3c5c033d2aefe688f99f/nwuTF''4zx!wrcrLKv~4y7'jqKOx&SiT'rrrhmNBx'yxfpky'?E3%274~1PC-:C.5FCd-ekbP57jL_5P_g~-~5_%27Tmom_3l2Eo&16/1e5e3c3b5ca7bb1d4d08570d9b713c4765380592078cf868a3f7d244b6e2bfab
#include <iostream>
#include <string>

using namespace std;

class Diem {
private:
    float diem[3];
public:
    friend istream& operator>>(istream& in, Diem& diem) {
        for (int i = 0; i < 3; i++) {
            in >> diem.diem[i];
        }
        return in;
    }

    float DTB() {
        float res = 0;
        for (int i = 0; i < 3; i++) {
            res += diem[i];
        }
        return res / 3;
    }
};

class SinhVien {
public:
    string name;
    Diem diem;
    
    friend istream& operator>>(istream& in, SinhVien& sv) {
        getline(in >> ws, sv.name);
        in >> sv.diem;

        return in;
    }
};

int findMaxIndex(SinhVien sv[], int n) {
    int maxIndex = 0;
    float maxDTB = sv[0].diem.DTB();
    for (int i = 1; i < n; ++i) {
        float dtb = sv[i].diem.DTB();
        if (dtb > maxDTB) {
            maxDTB = dtb;
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    SinhVien students[100];
    int numStudents = 0;


    while (cin >> students[numStudents]) {
        numStudents++;
    }


    int maxIndex = findMaxIndex(students, numStudents);

   
    cout << students[maxIndex].name << endl;
   

    return 0;
}
