#include<bits/stdc++.h>

using namespace std;

vector<long> A,B;


void CreateV(long max){
	vector<long> C(max+1,0);
	
	for(long i = 0; i < A.size(); i++){
		C[A[i]] = 1;
	}
	
	for(long i = 1; i < C.size(); i++){
		if(C[i] == 0) B.push_back(i);
	}
}

void Solve(long n){
	long max = n * 2,result = 0,j = 0;
	
	CreateV(max);
	
	
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	
//	for(long i = 0; i < A.size(); i++){
//		cout << A[i] << " ";
//	}
//	cout << endl;
// 	
//	for(long i = 0; i < B.size(); i++){
//		cout << B[i] << " ";
//	}
//	cout << endl;
	
	for(long i = 0; i < A.size(); i++){
		while(j < B.size()){
			if(B[j] > A[i]){
//				cout << A[i] << " " << B[j] << endl;
				result++;
				j++;
				break;
			}
			j++;
		}
	}
	cout << result;
}

int main(){
	long n,input;
	
	cin >> n;
	
	for(long i = 0; i < n; i++){
		cin >> input;
		A.push_back(input);
	}
	
	Solve(n);
}
