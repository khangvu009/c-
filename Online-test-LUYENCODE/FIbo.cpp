#include<bits/stdc++.h>

using namespace std;

void Solve(unsigned long long n){
		
	unsigned long long sum = 2, pre1 = 1, pre2 = 1,cur = 0;
	
	if(n == 0) cout << 0;
	else if(n == 1) cout << 1;
	else if(n == 2) cout << 2;
	else{
		for(unsigned long long i = 3; i <= n; i++){
			cur = pre1 + pre2;
			pre2 = pre1;
			pre1 = cur;
			sum = (sum % 100 + cur % 100) %100;
		}
		cout << "cur = " << cur << endl;
		cout << sum;	
	}	
}


int main(){
	unsigned long long n;
	
	cin >> n;
	
	Solve(n);
}
