#include <bits/stdc++.h>

using namespace std;

void Weight (vector<long> &Dp, long j, vector<long> W)
{
	for (long i = 0; i < W.size(); i++){
		if (j - W[i] >= 0){
			Dp[j] = Dp[j] + Dp[j-W[i]];
		}
	}
}

void Solve (vector<long> W, vector<long> Dp)
{
	for (long j = 0; j < Dp.size(); j++){
		Weight(Dp,j,W);
	}
	
//	for (long i = 0; i < Dp.size()-1; i++){
//		cout << " Dp[" << i << "] = " << Dp[i] << endl;
//	}
}

int main()
{
	long n;
	vector<long> W {1,3,5};
	vector<long> Dp;
	
	Dp.push_back(1);
	
	n = 1000;
	
	for (long i = 0; i <= n; i++){
		Dp.push_back(0);
	}
	
	Solve(W,Dp);
}
