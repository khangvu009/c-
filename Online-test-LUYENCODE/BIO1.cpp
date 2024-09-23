#include<bits/stdc++.h>

using namespace std;

void Solve(long k, long n, long m){
	unsigned long long temp = 1,temp1 = 1,result,temp2,l = n-k;
	
	for(long i = 1; i <= n; i++){
		temp = temp * i;
		if(i <= k) temp1 = temp;
		if(i <= l) temp2 = temp;
	}
	
	result = (temp / (temp2 * temp1)) % m;
	cout << result;
}

int main(){
	long k,n,m;
	
	cin >> k >> n >> m;
	
	Solve(k,n,m);
}
