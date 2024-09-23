#include <bits/stdc++.h>
using namespace std;

ifstream inp;
ofstream out;

bool IsPrime(long long n) {
    if (n == 2) return true;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void Solve(long long n) {
    long count = 0;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0 && IsPrime(i)) count++;
        while (n % i == 0) {
           n /= i;
       }
    }
    if (n > 1) count++;
    
    out << count;
}

int main() {
    long long n;
    inp.open("UocNT.inp");
    out.open("UocNT.out");
    inp >> n;
    Solve(n);
    inp.close();	
    out.close();
}
