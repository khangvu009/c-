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
	
	for(long i = 0; i < A.size(); i++){
		if(A[i].x+1 == di.x && A[i].y+1 == di.y){
			result += A[i].value;
		}
		else if(A[i].x+1 == di.x && A[i].y == di.y){
			result += A[i].value;
		}
		else if(A[i].x+1 == di.x && A[i].y-1 == di.y){
			result += A[i].value;
		}
		else if(A[i].x == di.x && A[i].y+2 == di.y){
			result += A[i].value;
		}
		else if(A[i].x == di.x && A[i].y+1 == di.y){
			result += A[i].value;
		}
		else if(A[i].x == di.x && A[i].y == di.y){
			result += A[i].value;
		}
		else if(A[i].x == di.x && A[i].y-1 == di.y){
			result += A[i].value;
		}
		else if(A[i].x == di.x && A[i].y-2 == di.y){
			result += A[i].value;
		}
		else if(A[i].x-1 == di.x && A[i].y+1 == di.y){
			result += A[i].value;
		}
		else if(A[i].x-1 == di.x && A[i].y == di.y){
			result += A[i].value;
		}
		else if(A[i].x-1 == di.x && A[i].y-1 == di.y){
			result += A[i].value;
		}
		else if(A[i].x-2 == di.x && A[i].y == di.y){
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
