#include<bits/stdc++.h>

using namespace std;

ifstream inp;

vector<long> A;
vector<long> F;

void Solve(){
	long maxlen = 0;
	
	for(long i = 0; i < A.size(); i++){
		F.push_back(1);
		for(long j = 0; j < i; j++){
			if(A[j] <= A[i]){
				F[i] = max(F[i],F[j]+1);
			}
		}
		maxlen = max(maxlen,F[i]); 
	}
	
	cout << maxlen;
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
