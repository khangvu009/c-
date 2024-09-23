#include<bits/stdc++.h>

using namespace std;

void Solve(long n){
	long result = 0;
		
	for(long i = n-1; i >= 3; i--){
		if(i % 3 == 0){
			result = i;
			break;
		}
	}
	
	cout << result;
}

int main(){
	long n;
	
	cin >> n;
	
	Solve(n);
}
