#include<bits/stdc++.h>

using namespace std;

ifstream inp;

struct DP{
	long count = 1;
	vector<long> Path;
};

vector<long> A;
vector<DP> Dp;
vector<bool> IsInLIS;

void Solve(){
	long max = 0,index;
	
	for(long i = 0; i < A.size(); i++){
		DP dp;
		IsInLIS.push_back(true);
		dp.Path.push_back(i);
		Dp.push_back(dp);
		for(long j = 0; j < i; j++){
			if(A[j] <= A[i]){
				if(Dp[j].count+1 > Dp[i].count){
					Dp[i].count = Dp[j].count+1;
					Dp[i].Path = Dp[j].Path;
					Dp[i].Path.push_back(i);
				}
			}
		}
		if (max < Dp[i].count){
			max = Dp[i].count;
			index = i;
		}
	}
	
	for(long i = 0; i < Dp[index].Path.size(); i++){
		IsInLIS[Dp[index].Path[i]] = false;
	}
	
	for(long i = 0; i < A.size(); i++){
		if(IsInLIS[i]) cout << A[i] << " ";
	}
}

int main(){
	long n,input;
	
	inp.open("C:\\bt_c++\\DP\\LIS.INP");
	
	inp >> n;
	
	cout << n << endl;
	for(long i = 0;  i < n; i++){
		inp >> input;
		cout << input << " ";
		A.push_back(input);
	}
	
	cout << endl; 
	
	Solve();
	
	inp.close();
}
