#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int doi(string c, int cd) {
    int tong = 0;

    for (int i = 0; i < cd; i++) {
        int n = c[i] - '0';
        tong = tong * 10 + n;
    }

    return tong;
}

int dem(int n) {
    int count = 0;
    if (n % 4 == 0) {
        count++;
    }
    return count;
}

int main() {
    string str, substring;
    int cd, n, count, i, m, A[100], tam;

    ifstream xau_inp;
    xau_inp.open("C:\\bt_c++\\2018-2019\\XAU.INP");
    ofstream xau_out;
    xau_out.open("C:\\bt_c++\\2018-2019\\XAU.OUT");

    xau_inp >> str;
    xau_inp.close();

    cd = str.length();

    for (int i = 0; i < cd; i++) {
        A[i] = 0;
    }

    i = cd - 1;
    tam = 0;
    count = 0;

    while (true) {
        if (A[0] == 1 && A[cd - 1] == 1) {
            break;
        }
        if (i >= 0) {
            if (A[0] == 0) {
                A[i] = 1;
                if (A[i + 1] == 1) {
                    A[i] = 1;
                    A[i - 1] = 0;
                }
            } else {
                i = cd;
                A[i] = 1;
            }
        }
        while (true) {
            if (A[i] == 0) {
                break;
            }
            if (A[0] == 1 && A[cd - 1] == 1) {
                break;
            }
            if (A[i + 1]) {
                tam++;
            }
            substring = str.substr(i, tam);
            n = doi(substring, cd);
            m = dem(n);
            count = count + m;
        }

        i--;
    }
    xau_out << count;
    xau_out.close();
}

