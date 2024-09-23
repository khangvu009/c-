#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

struct Point{
	long start;
	long end;
};

vector<Point> A;

void Sort(){
	Point temp;
	
	for(long i = 0; i < A.size()-1; i++){
		for(long j = i + 1; j < A.size(); j++){
			if(A[i].end > A[j].end){
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
}

void Solve(long n){
	long result = 0;
	vector<long> Dp(n+1,1);
	
	Sort();
	
	for(long i = 1; i < A.size(); i++){
		for(long j = 0; j < i; j++){
			if(A[i].start >= A[j].end){
				Dp[i] = max(Dp[i],Dp[j]+1);
			}
			result = max(result,Dp[i]);
		}		
	}
	
	cout << result;	
}

int main(){
	long n;
	Point p;
	
	inp.open("C:\\bt_c++\\Online-test-LUYENCODE\\PHONGHOP.INP");
	out.open("C:\\bt_c++\\Online-test-LUYENCODE\\PHONGHOP.OUT");
	
	inp >> n;
	
	for(long i = 0; i < n; i++){
		inp >> p.start >> p.end;
		A.push_back(p);
	}
	
	Solve(n);
	
	inp.close();
	out.close();
}
