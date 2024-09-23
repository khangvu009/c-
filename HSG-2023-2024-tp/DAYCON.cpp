#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

long Sum(long a, long b){
	long sum = 0;
	
	for(long i = a; i <= b; i++){
		sum += A[i];
	}
	
	return sum;
}

void Solve(long k){
	long sum,count = 0;
	
	for(long i = 0; i < A.size()-1; i++){
		for(long j = i+1; j < A.size(); j++){
			sum = accumulate(A.begin() + i, A.begin() + j +1, 0);
//			cout << sum << endl;
//			sum = Sum(i,j);
//			cout << sum << endl << endl;
			if(sum >= k) count++;
		}
	}
	
	cout << count;
}

int main(){
	long n,k,input;
	
	inp.open("C:\\bt_c++\\HSG-2023-2024-tp\\DAYCON.INP");
	out.open("C:\\bt_c++\\HSG-2023-2024-tp\\DAYCON.OUT");
	
	inp >> n >> k;
	
	for(long i = 0; i < n; i++){
		inp >> input;
		A.push_back(input);
	}
	
	Solve(k);
	
	inp.close();
	out.close();	
}
