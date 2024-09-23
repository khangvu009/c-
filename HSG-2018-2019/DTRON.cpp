#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

void Solve(long k){
	long count = 0;
	
	for(long i = 0; i < A.size(); i++){
		if (A[i] > k) count++;
	}
	
	cout << count;
} 

int main(){
	long n,k,input;
	
	inp.open("C:\\bt_c++\\HSG-2018-2019\\DTRON.INP");	
	out.open("C:\\bt_c++\\HSG-2018-2019\\DTRON.OUT");
	
	inp >> n >> k;
	
	for(long i = 0; i < n; i++){
		inp >> input;
		A.push_back(input);
	}
	
	Solve(k);
	
	inp.close();
	out.close();
}
