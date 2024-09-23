#include<bits/stdc++.h>

using namespace std;

void Solve(long long n){
	while (true){
		cout << "n = " << n << endl;
		if (n == 1 ) break;
		if (n % 2 == 0) n = n / 2;
		else n = n * 3 + 1;
	}
}

int main(){
	long long n;
	
	cin >> n;
	
	Solve(n);	
}
