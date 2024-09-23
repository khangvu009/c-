#include<bits/stdc++.h>

using namespace std;

void Solve(long k, long n, long m){
	unsigned long long temp = 1,temp1 = 1,result,temp2,l = n-k;
	
	for(long i = 1; i <= n; i++){
		if (temp % m != 0 &&  i % m != 0) temp = ((temp % m) * (i % m)) % m;
		cout << temp << endl;
		if(i <= k) temp1 = temp;
		if(i <= l) temp2 = temp;
	}
	cout << temp << " " << temp1 << " " << temp2 << endl;
	result = (temp / ((temp2 % m)* (temp1 % m) % m)) % m;
	cout << result;
}

int main(){
	long k,n,m;
	
	cin >> k >> n >> m;
	
	Solve(k,n,m);
}
