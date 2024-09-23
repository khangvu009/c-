#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

struct Point{
	long start;
	long end;
	long value;
};

vector<Point> A;

void Sort(){
	
	for(long i = 0; i < A.size()-1; i++){
		for(long j = i + 1; j < A.size(); j++){
			if(A[i].end > A[j].end){
				swap(A[i],A[j]);
			}
		}
	}
}

void Solve(long n){
	long result = 0;
	vector<long> Dp(n,0);
	
	Sort();
	
	for(long i = 0; i < A.size(); i++){
		Dp[i] = A[i].value;
		for(long j = 0; j < i; j++){
			if(A[i].start > A[j].end){
				Dp[i] = max(Dp[i],Dp[j]+A[i].value);
			}
		}	
		result = max(result,Dp[i]);	
	}
	
	for(long i = 0; i < Dp.size(); i++){
		cout << Dp[i] << " ";
	}
	cout << endl;
	cout << result;	
}

int main(){
	long n;
	Point p;
	
	inp.open("C:\\bt_c++\\Online-test-LUYENCODE\\MAYTINH.INP");
	out.open("C:\\bt_c++\\Online-test-LUYENCODE\\MAYTINH.OUT");
	
	inp >> n;
	
	for(long i = 0; i < n; i++){
		inp >> p.start >> p.end >> p.value;
		A.push_back(p);
	}
	
	Solve(n);
	
	inp.close();
	out.close();
}
