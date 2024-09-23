#include<bits/stdc++.h>

using namespace std;

struct Diamond{
	long x;
	long y;
	long value;
};

vector<Diamond> A;

long long MDia(Diamond di){
	long long result = 0;
	long disx,disy;
	
	for(long i = 0; i < A.size(); i++){
		disx = abs(A[i].x - di.x);
		disy = abs(A[i].y - di.y);
		if(disx <= 1 && disy <= 1){
			result += A[i].value;
		}	
		else if((disx == 0 || disy == 0) && (disx == 2 || disy == 2)){
			result += A[i].value;
		}
	}
	
	return result;
}

void Solve(){
	long long max1 = -1;
	
	for(long i = 0; i < A.size(); i++){
		max1 = max(max1,MDia(A[i]));	
	}
	
	cout << max1;
}

int main(){
	long n;	
	Diamond di;
	
	cin >> n;
	
	for(long i = 0; i < n; i++){
		cin >> di.x >> di.y >> di.value;
		A.push_back(di);
	}
	
	Solve();
}
