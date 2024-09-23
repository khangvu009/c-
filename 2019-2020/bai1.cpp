#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void sort(int a, string& str) {
    char tem;
    for (int i = 0; i < a; i++) {
        for (int j = i + 1; j < a; j++) {
            if (str[i] > str[j]) {
                tem = str[i];
                str[i] = str[j];
                str[j] = tem;
            }
        }
    }
}

bool kt(int a, string& str, string& substring) {
    bool check = true;

    for (int i = 0; i < a; i++) {
        if (str[i] != substring[i]) {
            check = false;
            break;
        }
    }

    return check;
}

int main() {
    string str, str1, substring;
    int a, b, sap_xep, count;
    bool check;

    ifstream td_inp;
    td_inp.open("C:\\bt_c++\\2019-2020\\TD.INP");
    ofstream td_out;
    td_out.open("C:\\bt_c++\\2019-2020\\TD.OUT");
    
    td_inp >> str;
    td_inp >> str1;
    a = str.length();
    b = str1.length();
    count = 0;

    for (int i = 0; i <= b - a; i++) {
        substring = str1.substr(i, a);
        sort(a, substring);
        sort(a, str);
        check = kt(a, str, substring);
        if (check) {
            count++;
        }
    }

    td_out << count;
    td_inp.close();
    td_out.close();
}

