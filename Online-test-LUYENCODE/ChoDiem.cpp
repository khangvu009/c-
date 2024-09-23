#include<bits/stdc++.h>

using namespace std;

int main(){
	long p,result = 0,s;
	for(long i = 0; i < 6; i++){
		cin >> p >> s;
		result = result + (p-(s-1)*(p/10));
	}
	
	if(result < 0) result = 0;
	
	cout << result;
}
