#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;


void Solve(long k){
	long count = 0,sum = 0;
	
	sort(A.begin(),A.end());
	
	for(long i = A.size()-1; i >= 0; i--){
		sum += A[i];
		count++;
		if(sum >= k) break;
	}
	
	out << count;
	cout << count;
}

int main(){
	long n,k,input;
	
	inp.open("C:\\bt_c++\\HSG-2009-2010\\TONGSO.INP");
	out.open("C:\\bt_c++\\HSG-2009-2010\\TONGSO.OUT");
	
	
	inp >> n >> k;
	
	for(long i = 0; i< n; i++){
		inp >> input;
		A.push_back(input);
	}
	
	Solve(k);
	
	inp.close();
	out.close();
}
