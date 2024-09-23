#include<bits/stdc++.h>

using namespace std;

ifstream inp;

struct DP{
	long count = 1;
	vector<long> Path;
};

vector<long> A;
vector<DP> Dp;

void Solve(){
	long maxlen = 0,index;
	
	for(long i = 0; i < A.size(); i++){
		DP dp;
		dp.Path.push_back(A[i]);
		Dp.push_back(dp);
		for(long j = 0; j < i; j++){
			if(A[j] <= A[i]){
				if(Dp[i].count < Dp[j].count+1){
					Dp[i].count = Dp[j].count+1;
					Dp[i].Path = Dp[j].Path;
					Dp[i].Path.push_back(A[i]);
					
				}
			}
		}
//		maxlen = max(maxlen,Dp[i].count); 
		if(maxlen < Dp[i].count) {
			maxlen = Dp[i].count;
			index = i;
		}
	}
	
	for(long i = 0; i < Dp[index].Path.size(); i++){
		cout << Dp[index].Path[i] << " ";
	}
	
	cout << endl << maxlen;
}

int main(){
	long n,input;
	
	inp.open("C:\\bt_c++\\DP\\LIS.INP");
	
	inp >> n;
	
	cout << n << endl;
	for(long i = 0;  i < n; i++){
		inp >> input;
//		cout << input << " ";
		A.push_back(input);
	}
	
	cout << endl; 
	
	Solve();
	
	inp.close();
}
