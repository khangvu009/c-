#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;


struct Result{
	long x;
	long y;
	long sum;	
};

vector<vector<long>> A;
vector<Result> B;

void Sum(long a, long b, long n, long m){
	Result answer;
	answer.sum = 0;
	
	for(long i = a; i <= n; i++){
		for(long j = b; j <= m; j++){
			answer.sum += A[i][j];
		}
	}
	answer.x = a+1;
	answer.y = b+1;
	B.push_back(answer);
}

void Sort(){
	Result temp;
	
	for(long i = 0; i < B.size()-1; i++){
		for(long j = i + 1; j < B.size(); j++){
			if (B[i].sum < B[j].sum){
				temp = B[i];
				B[i] = B[j];
				B[j] = temp;
			}
		}
	}
}

void Solve(){
	for(long i = 0; i < A.size()-2; i++){
		for(long j = 0; j < A[i].size()-2; j++){
			Sum(i,j,i+2,j+2);
		}
	}
	
	Sort();
	
	out << B[0].sum << endl << B[0].x << " " << B[0].y;
}

int main(){
	long n,m,input;
	vector<long> T;
	
	inp.open("C:\\bt_c++\\HSG-2009-2010\\BANGSO.INP");
	out.open("C:\\bt_c++\\HSG-2009-2010\\BANGSO.OUT");
	
	inp >> n >> m;
	
	for(long i = 0; i < n; i++){
		for(long j = 0; j < m; j++){
			inp >> input;
			T.push_back(input);
		}
		A.push_back(T);
		T.clear();
	}
	
	Solve();
	
	inp.close();
	out.close();
}
