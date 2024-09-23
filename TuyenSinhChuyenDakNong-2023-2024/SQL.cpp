#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

struct Point {
	long start;
	long end;
};
vector<Point> A;

void FindMax(long long &max, vector<long long> &C){
	long index;
	for(long i = 1; i < C.size()-1; i++){
		if(max < C[i]){
			max = C[i];
			index = i;
		}
	}
	C[index] = LONG_MIN;
}

void Solve(long n,long k){
	long long condition = -1,max = LONG_MIN,max1 = LONG_MIN,max2 = LONG_MIN, result;
	vector<long long> B(n+2,0);
	vector<long long> C (n+2,0);
	
	for(long i = 0; i < A.size(); i++){
		B[A[i].start] += k;
		B[A[i].end+1] -= k;
	}
	
	for(long i = 1; i < C.size()-1; i++){
		C[i] = C[i-1] + B[i]; 
	}
	
	for(long i = 1; i < C.size()-1; i++){
		cout << C[i] << " "; 
	}
	
	cout << endl;
	
	FindMax(max,C);
	FindMax(max1,C);
	FindMax(max2,C);
	
	result = max + max1 + max2;
	
	cout << result;
}

int main(){
	Point p;
	long n,m,k;
	
	inp.open("SQL.INP");
	out.open("SQL.OUT");
	
	inp >> n >> m >> k;
	
	for(long i = 0; i < m; i++){
		inp >> p.start >> p.end;
		A.push_back(p);
	}
	
	Solve(n,k);
	
	inp.close();
	out.close();
}
