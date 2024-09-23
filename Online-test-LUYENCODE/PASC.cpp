#include<bits/stdc++.h>

using namespace std;

vector<long long> Pre;

void Proc(vector<long long> &A, long n){	
	if(n == 2) A.push_back(1);
	else if(n == 3){
		vector<long long> B(A.size()+1,1);
		B[1] = 2;
		A = B;
		Pre = A;
	}
	else if (n > 3){
		vector<long long > D(Pre.size()+1,1);
		for(long i = 1; i < D.size()-1; i++){
			D[i] = Pre[i-1] + Pre[i];
		}
		A = D;
		Pre = A;
	}
}

void Solve(long n){
	vector<long long> A(1,1);
	
	for(long i = 1; i <= n; i++){
		Proc(A,i);
		for(long i = 0; i < A.size(); i++){
			cout << A[i] << " ";
		}
		cout << endl;
	}
}

int main(){
	long n;
	
	cin >> n;
	
	Solve(n);
}
