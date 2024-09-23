#include<bits/stdc++.h>

using namespace std;

vector<long> W;

void Solve(long n, long k){
	vector<long> Dp(k+1,LONG_MAX);
	
	Dp[0] = 0;
		
	
	for(long i = 0; i < n; i++){
		for(long j = 1; j <= k; j++){
			if(j-W[i] >= 0){
				if(Dp[j-W[i]] != LONG_MAX){
					Dp[j] = min(Dp[j],Dp[j-W[i]] + 1);
				}
			}
		}
		for(long x = 0; x <= k; x++){
			cout << Dp[x] << " "; 
		}
		cout << endl;
	}
	cout << Dp[k];
}

int main(){
	long n,k,input;
		
	cin >> n >> k;
	
	for(long i = 0; i  < n; i++){
		cin >> input;
		W.push_back(input);
	}
	
	Solve(n,k);
}
