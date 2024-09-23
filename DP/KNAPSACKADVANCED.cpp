#include<bits/stdc++.h>

using namespace std;

const long mod = 1e9+7;

vector<long> A;

void Solve(long n, long k){
	vector<vector<long long> > Dp(n+1,vector<long long>(k+1,0));
	
	for(long i = 0; i <= n; i++){
		Dp[i][0] = 1;
	}
	
	cout << Dp.size() << endl;
	for(long i = 1; i < Dp.size(); i++){
		for(long j = 0; j < Dp[i].size(); j++){
			Dp[i][j] = Dp[i-1][j];
			if(j >= A[i]){
				Dp[i][j] = ((Dp[i-1][j] % mod )+ (Dp[i-1][j-A[i]] % mod)) % mod;
			}
		}
	}
	
	for(long i = 0; i < Dp.size(); i++){
		for(long j = 0; j < Dp[i].size(); j++){
			cout << Dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << Dp[n][k];
}

int main(){
	long n,k,input;
	
	cin >> n >> k;
	
	A.push_back(0);
	
	for(long i = 0; i < n; i++){
		cin >> input;
		A.push_back(input);
	}
	
	Solve(n,k);
}
