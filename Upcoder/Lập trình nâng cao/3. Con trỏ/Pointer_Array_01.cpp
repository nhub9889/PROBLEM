//http://www.upcoder.xyz/'index.php/4ce37517e8eb3b33504f904636a4fd2a7952425837b21bce34ce2f1f969805dc/ixvr:''x0y$usKpMLw.530'kRdP0_Tjr'supinOmy'tygqiz'776'f@f6_.9b@9gjL@69Ce.9@b8L-_8-dF_4':Tn*wsEA:_3C2$O:1?ph1/df5f76336c3eabfc868becb5c2ac4cc79ff0884657a94d35915dfd0dae2be129
#include <iostream>
using namespace std;

bool check(int* arr, int n) {
    for (int i = 0; i <= n/2; i++) 
        if (*(arr + i) != *(arr + n - i - 1))
            return false;
    return true;
}

void print(int* arr, int n) {
    if (check(arr, n)) cout << "mang doi xung";
    else {
        cout << "mang khong doi xung" << endl;
        for (int i = 0; i < n/2; i++) 
            if (*(arr + i) != *(arr + n - i - 1))
                cout << *(arr + i) << " " << *(arr + n - i - 1) << endl;
    }
    return;
}

int main() {

    int n; cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    print(arr, n);
    delete[] arr;
    return 0;
}