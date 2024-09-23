#include<bits/stdc++.h>

using namespace std; 

ifstream inp;
ofstream out;

vector<long> A;

long UCLN(long a, long b){
	if (a == 0) return b;
	return UCLN(b%a,a);
}

void Solve(long k){
	vector<long> B;
	long ucln,max = 0;
	for(long i = 0; i < A.size()- k; i++){
		for(long j = i; j < i + k; j++) B.push_back(A[j]);
		ucln = UCLN(B[0],B[1]);
		for(long k = 2; k < B.size(); k++) ucln = UCLN(ucln,B[k]);
		B.clear();
		if (max < ucln) max = ucln;
	}
	
	cout << max;
}

int main(){
	long n,input,k;
	
	inp.open("C:\\bt_c++\\HSG-2019-2020-ptnk\\GCD.INP");
	out.open("C:\\bt_c++\\HSG-2019-2020-ptnk\\GCD.OUT");
	
	inp >> n >> k;
	
	for(long i = 0; i < n; i++){
		inp >> input;
		A.push_back(input);
	}
	
	Solve(k);
	
	inp.close();
	out.close();
}
