#include <bits/stdc++.h>
using namespace std;

void Solve(long long n) {
    long long divisors_count = 1;
    long long p = 2;
    
    while (p * p <= n) {
        if (n % p == 0) {
            long long count = 0;
            while (n % p == 0) {
                n /= p;
                count++;
            }
            divisors_count *= (count + 1);
        }
        p++;
    }
    
    if (n > 1) {
        divisors_count *= 2;
    }
    
    cout << divisors_count;
}

int main() {
    long long n;

    cin >> n;

    Solve(n);
    
}

