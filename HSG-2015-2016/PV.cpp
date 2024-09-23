#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

long Take2LastDigits(long n, long secondLastDigit, long lastDigit, long k) {
    if (k == 1) return n;
    
    long t = n % 10;
    long t1 = (n % 100) / 10;
    long t2 = (lastDigit * t) % 10;
    long t3 = (lastDigit * t) / 10;
    long t4 = (lastDigit * t1) % 10;
    long t5 = (secondLastDigit * t) % 10;
    long t6 = ((t3 + t4 + t5) % 10) * 10 + t2;
    
    cout << "k = " << k << " n = " << n << " t6 = " << t6 << endl;
    return Take2LastDigits(t6, secondLastDigit, lastDigit, k - 1);
}

bool CheckIsDifferent(long n) {
    for (long i = 0; i < A.size(); i++) if (A[i] == n) return false;
    A.push_back(n);
    return true;
}

void Print() {
    for (long i = 0; i < A.size() - 1; i++) cout << A[i] << " ";
    cout << A.back();
}

void Solve(long n, long k) {
    long secondLastDigit = (n % 100) / 10;
    long lastDigit = n % 10;
    
    long temp = Take2LastDigits(n, secondLastDigit, lastDigit, k);
    if (CheckIsDifferent(temp)) Solve(temp, k);
    else Print();
}

int main() {
    long n, k;
    
    inp.open("C:\\bt_c++\\HSG-2015-2016\\PV.INP");
    out.open("C:\\bt_c++\\HSG-2015-2016\\PV.OUT");
    
    inp >> n >> k;
    Solve(n, k);
    
    inp.close();
    out.close();
}

