#include<bits/stdc++.h>

using namespace std;

vector<string> Pearl;

bool Check(string str, long st, string S){
	long i = st,j = 0;
	bool flag = true;
	long qc = st;
	
	while(true){
		if(i == S.length()){
			i = 0;
			flag = false;
		}	
		if(flag) if(str[j] != S[i]){
			return false;
		}
		if(!flag) if(str[j] != S[i]){
			return false;
		}
		i++;
		j++;
		if(i == st) return true;
	}
}

void Solve(string S, long k, long n){
	bool flag = true;
	
	for(long i = 0; i < k; i++){
		for(long j = 0; j < n; j++){
			if(S[j] == Pearl[i][0]){
				if(S == Pearl[i]){
					cout << "YES" << endl;
					flag = false;	
				}
				else{
					if(Check(Pearl[i],j,S)){
						cout << "YES" << endl;
						flag = false;
						break;
					}
				}
			}
		}
		if(flag) cout << "NO" << endl;
		flag = true;
	}
}

int main(){
	string S,str;
	long n,k;
	
	cin >> n >> k >> S;
	
	for(long i = 0; i < k; i++){
		cin >> str;
		Pearl.push_back(str);
	}
	
	Solve(S,k,n);
}
