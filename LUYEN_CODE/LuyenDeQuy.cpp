#include<bits/stdc++.h>

using namespace std;

void Solve(long long n){
	cout << "n = " << n << endl;
	if (n == 1) return;
	if (n % 2 == 0) Solve(n / 2);
	else Solve(n * 3 + 1);
}

int main(){
	long long n;
	
	cin >> n;
	
	Solve(n);	
}
