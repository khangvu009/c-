#include<bits/stdc++.h>

using namespace std;

vector<long> C, W;

void Solve(long k) {
    vector<vector<long long> > Dp(C.size() + 1, vector<long long>(k + 1, 0));

    for (long i = 1; i <= C.size(); i++) {
        for (long j = 0; j <= k; j++) {
            Dp[i][j] = Dp[i-1][j];
            if (j >= W[i-1]) {
                Dp[i][j] = max(Dp[i][j], Dp[i-1][j-W[i-1]] + C[i-1]);
            }
        }
    }

    cout << Dp[C.size()][k];
}

int main(){
    long n,k,input;
    cin >> n >> k;

    for(long i = 0; i < n; i++){
        cin >> input;
        C.push_back(input);
        W.push_back(input);
    }

    Solve(k);
}

