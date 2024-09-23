#include<bits/stdc++.h>

using namespace std;

ifstream inp;

struct PATH{
	long count = 0;
	vector<vector<long>> Paths;
	long amount = 0;
};

vector<PATH> Dp;
vector<long> W;

bool IsPermutation(vector<long> T, vector<long> Way){
	sort(T.begin(),T.end());
	sort(Way.begin(),Way.end());
	
	if(T == Way) return false;
	return true;
}

void AddV(vector<vector<long>> &Paths, long w, vector<vector<long>> B){
	bool flag = true;
	vector<long> T;
	
	if(B.size() > 0){
		for(long i = 0; i < B.size(); i++){
			flag = true;
			if(Paths.size() == 0){
				auto it = find(B[i].begin(),B[i].end(),w);
				if(it != B[i].end()){
					T = B[i];
					Paths.push_back(T);
				}
				else{
					T = B[i];
					T.push_back(w);
					Paths.push_back(T);
				}
			}
			else{
				for(long j = 0; j < Paths.size(); j++){
					auto it = find(B[i].begin(),B[i].end(),w);
					if(it != B[i].end()){
						T = B[i];
						for(long k = 0; k < Paths.size(); k++){
							if(!IsPermutation(T,Paths[k])){
								flag = false;
							}	
						}
						if(flag){
							Paths.push_back(T);
						}
					}
					else{
						T = B[i];
						T.push_back(w);
						for(long k = 0; k < Paths.size(); k++){
							if(!IsPermutation(T,Paths[k])){
								flag = false;
							}	
						}
						if(flag){
							Paths.push_back(T);
						}
					}
				}
			}
		}
	}
}


//void FindMinTypeOfCoins(long n){
//	long min = LONG_MAX, count = 0;
//	vector<long> T;
//	bool flag = false;
//	for(long i = 0; i < Dp[n].Paths.size(); i++){
//		for(long j = 0; j < Dp[n].Paths[i].size(); j++){
//			for(long k = 0; k < T.size(); k++){
//				if(Dp[n].Paths[i][j] == T[k]){
//					flag = true;
//					break;
//				}
//			}
//			if(!flag){
//				T.push_back(Dp[n].Paths[i][j]);
//				count++;
//			}
//		}
//		flag = false;
//		T.clear();
//		if(min > count){
//			min = count;
//		}
//		count = 0;
//	}
//	cout << min;	
//}
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
	}
	
//	FindMinTypeOfCoins(n);
//	for(long i = 0; i < Dp.size(); i++){
//		cout << i << endl;
//		for(long j = 0; j < Dp[i].Paths.size(); j++){
//			cout << "      ";
//			for(long k = 0; k < Dp[i].Paths[j].size(); k++){
//				cout << Dp[i].Paths[j][k] << " ";
//			}
//			cout << endl;
//		}
//	}
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
