#include<bits/stdc++.h>

using namespace std;

ifstream inp;

struct PATH{
	long count = 0;
	vector<vector<long>> Paths;
	long len = 0;
};

vector<PATH> Dp;
vector<long> W;

void PrintV(vector<long> T){
	for(long i = 0; i < T.size(); i++){
		cout << T[i] << " ";
	}
	cout << endl;
}

void AddV(vector<vector<long>> &Paths, long w, vector<vector<long>> B, long index){
	vector<long> T;
	
	if(B.size() > 0){
		for(long i = 0; i < B.size(); i++){
//			T = B[i];
//			T.push_back(w);
//			Paths.push_back(T);
//			cout <<  "-- len = " << Dp[index].len << " index = " << i << " weigh = " << w << " size = " << B[i].size()+1 << endl;
			if(Dp[index].len == 0 || B[i].size()+1 < Dp[index].len) {
				Dp[index].len = B[i].size()+1;
				T = B[i];
				T.push_back(w);
				if (Paths.size() > 0) {
					Paths[0] = T;
				} else { 
					Paths.push_back(T);
//					PrintV(T);
				}
			}
		}
	}
}

void Solve(long n){
	PATH pa;
	vector<long> T;
	long index,min = LONG_MAX;
	
	for(long i = 0; i <= n; i++){
		Dp.push_back(pa);
	}
	
	Dp[0].count = 1;
		
	for(long j = 1; j < Dp.size(); j++){
		for(long i = 0; i < W.size(); i++){
			if(j-W[i] >= 0){
				Dp[j].count += Dp[j-W[i]].count;
				if(j-W[i] > 0){
					AddV(Dp[j].Paths,W[i],Dp[j-W[i]].Paths,j);
				}
				else{
					T.push_back(W[i]);
					Dp[j].Paths.push_back(T);
					T.clear();
					Dp[j].len = 1;
				}
			}
		}
		cout << "weigh = " << j << " len = " << Dp[j].len << " count = " << Dp[j].count << endl;
	}
	
	
	for(long i = 0; i < Dp[n].Paths.size(); i++){
		if(min > Dp[n].Paths[i].size()){
			min = Dp[n].Paths[i].size();
			index = i;
		}
	}
	
	for(long i = 0; i < Dp[n].Paths[index].size(); i++){
		cout << Dp[n].Paths[index][i] << " ";
	}
	cout << endl;
	cout << min;
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
