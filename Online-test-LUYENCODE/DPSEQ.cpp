#include <bits/stdc++.h>

using namespace std;

vector<long long> A;

long long Solve(long long k){
    vector<long long> dp(A.size());
    
    for (long i = 1; i < A.size(); i++) {
        dp[i] = LONG_MIN;
        for (long j = max(0LL, i - k); j < i; j++) {
            dp[i] = max(dp[i], A[i] + dp[j]);
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

int main(){
    long long n, k, input;
    
    cin >> n >> k;
    
    for(long i = 0; i < n; i++){
        cin >> input;
        A.push_back(input);
    }
    
    cout << Solve(k);
}

