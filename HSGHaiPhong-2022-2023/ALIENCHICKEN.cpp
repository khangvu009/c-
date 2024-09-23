#include<bits/stdc++.h>

using namespace std;

struct Chicken{
	long long ftime;
	long long time;
};

vector<Chicken> A;

void Solve(long long x){
	long long time = 0;
	
	if(A.size() == 1){
		time += A[0].ftime;
		x--;
		time += A[0].time * x;
	}
	
	cout << time;
}

int main(){
	Chicken ch;
	long long n,x;

	cin >> n >> x;
	
	for(long i = 0; i < n; i++){
		cin >> ch.ftime >> ch.time;
		A.push_back(ch);
	}
	
	Solve(x);
}
