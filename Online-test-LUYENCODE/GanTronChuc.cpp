#include<bits/stdc++.h>

using namespace std;

bool Check(long n){
	if(n % 10 == 0) return true;
	return false;
}

void Solve(long n){
	long result = 0;
	long i = n;
	long j = n;
	
	while(true){
		if(Check(i)){
			result = i;
			break;
		}
		if(Check(j)){
			result = j;
			break;
		}
		i++;
		j--;
	}
	
	cout << result;
}

int main(){
	long n;
	
	cin >> n;
	
	Solve(n);
}
