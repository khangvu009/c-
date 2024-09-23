#include<bits/stdc++.h>

using namespace std;

ifstream inp;

struct PATH{
	long count = 0;
	vector<vector<long>> Paths;
};

vector<PATH> Dp;
vector<long> W;

void AddV(vector<vector<long>> &Paths, long w, vector<vector<long>> B){
	vector<long> T;
	
	if(B.size() > 0){
		for(long i = 0; i < B.size(); i++){
			for(long j = 0; j < B[i].size(); j++){
				T.push_back(B[i][j]);
			}
			T.push_back(w);
			Paths.push_back(T);
			T.clear();
		}
	}
}

void Solve(long n){
	PATH pa;
	vector<long> T;
	
	for(long i = 0; i <= n; i++){
		Dp.push_back(pa);
	}
	
	Dp[0].count = 1;
		
	for(long j = 1; j < Dp.size(); j++){
		for(long i = 0; i < W.size(); i++){
			if(j-W[i] >= 0){
				Dp[j].count += Dp[j-W[i]].count;
				if(j-W[i] > 0){
					AddV(Dp[j].Paths,W[i],Dp[j-W[i]].Paths);
				}
				else{
					T.push_back(W[i]);
					Dp[j].Paths.push_back(T);
					T.clear();
				}
			}
		}
		cout << "weigh = " << j << " " << Dp[j].count << endl;
	}
	
	for(long i = 0; i < Dp.size(); i++){
		cout << i << endl;
		for(long j = 0; j < Dp[i].Paths.size(); j++){
			cout << "      ";
			for(long k = 0; k < Dp[i].Paths[j].size(); k++){
				cout << Dp[i].Paths[j][k] << " ";
			}
			cout << endl;
		}
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
