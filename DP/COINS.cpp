#include<bits/stdc++.h>

using namespace std;

ifstream inp;

vector<long> W;

void Solve(long n){
	vector<long> Dp;
	
	for(long i = 0; i <= n; i++){
		Dp.push_back(0);
	}
	
	Dp[0] = 1;
	
	for(long j = 1; j < Dp.size(); j++){
		for(long i = 0; i < W.size(); i++){
			if(j - W[i] >= 0){
				cout << j<< " " << W[i] << endl;
				Dp[j] += Dp[j-W[i]];
			}
		}
	}
	
	for(long i = 1; i < Dp.size(); i++){
		cout << Dp[i] << " ";
	}
}

int main(){
	long n,k,input;
	
	inp.open("C:\\bt_c++\\DP\\COINS.INP");
	
	inp >> n >> k;
	
	cout << n << " " << k << endl;
	for(long i = 0;  i < n; i++){
		inp >> input;
		cout << input << " ";
		W.push_back(input);
	}
	
	cout << endl; 
	
	Solve(k);
	
	inp.close();
}
