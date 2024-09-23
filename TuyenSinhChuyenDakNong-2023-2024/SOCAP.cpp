#include<bits/stdc++.h>

using namespace std;

int main(){
	long n,k;
	
	cin >> n >> k;
	
	if(n == k) cout << n;
	else cout << abs(n-k);
}
