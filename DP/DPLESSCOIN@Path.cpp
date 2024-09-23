#include<bits/stdc++.h>

using namespace std;

vector<long> W;

struct Way{
	long value;
	long x;
};

void Solve(long n, long k){
	vector<Way> Dp;
	Way wy;
	
	for(long i = 0; i <= k; i++){
		wy.value = LONG_MAX;
		wy.x = 0;
		Dp.push_back(wy);
	}
	Dp[0].value = 0;
		
	for(long j = 1; j <= k; j++){
		for(long i = 0; i < n; i++){
			if(j-W[i] >= 0){
				if(Dp[j-W[i]].value != LONG_MAX){
					if(Dp[j].value > Dp[j-W[i]].value +1){
						Dp[j].x = W[i];
					}
					Dp[j].value = min(Dp[j].value,Dp[j-W[i]].value + 1);
				}
			}
		}
	}
	
	for(long t = 0; t <= k; t++){
			cout << Dp[t].value << ":" << Dp[t].x << "  "; 
		}
	cout << endl;
	
	long j = Dp[k].x;
	long temp = k,temp1 = k;
		
	while(true){
		if(j == 0) break;
		cout << Dp[j].x << " ";
		temp1 = temp;
		temp -= Dp[j].x;
		j = temp1 - Dp[j].x;
	}
	cout << endl;
	cout << Dp[k].value;
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
