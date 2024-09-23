#include <iostream>
#include <fstream>
using namespace std;
const int MAX_SIZE = 100;

int lan_day_dau(int n, int dau, int c) {
    int tam = n;
    int count = 0;
    
    while (tam < c) {
        tam = tam + dau;
        count++;    
    }
    
    return count;
}

void sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int num_element = 0;
    int N[MAX_SIZE], C[MAX_SIZE], a, diem_dau, day_them, count, tam1, b;

    ifstream hsg_inp;
    hsg_inp.open("C:\\bt_c++\\2016-2017\\HSG.INP");
    ofstream hsg_out;
    hsg_out.open("C:\\bt_c++\\2016-2017\\HSG.OUT");
    
    a = 0;
    count = 0;

    while (num_element < MAX_SIZE && hsg_inp >> N[num_element]) {
        num_element++;
    }

    day_them = N[1];
    diem_dau = N[2];

    for (int i = 0; i < num_element; i++) {
        C[i] = 0;
    }
    
    int j = 0; 
    for (int i = 3; i < num_element; i++) {
        if (i + 1 < num_element) {
            if (i % 2 == 1){
                int tam = lan_day_dau(N[i], N[i+1], diem_dau);
                C[j] = tam;
                j++;
            }
        }
    }

    sort(C, j);

    for (int i = 0; i < j; i++) {
        if (day_them - C[i] >= 0) {
            day_them = day_them - C[i];
            count++;
        } else {
            break; 
        }
    }

    hsg_out << count;
    hsg_inp.close();
    hsg_out.close();
}

