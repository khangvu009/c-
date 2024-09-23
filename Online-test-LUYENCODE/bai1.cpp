#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

void Solve(long m){
}

int main(){
	long n,q,input;
	
	inp.open("C:\\Users\\Ok Ok\\Documents\\Shipper.inp");
	out.open("C:\\Users\\Ok Ok\\Documents\\Shipper.out");
	
	inp >> n >> q;
	
	for(long i = 0; i < n; i++){
		inp >> input;
		A.push_back(input);	
	}
	
	Solve(m);
	
	inp.close();
	out.close();
}
