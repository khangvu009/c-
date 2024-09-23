#include<bits/stdc++.h>

using namespace std;

bool Way(long method,long method1, long problem){
	
}

char Solve(long coin, long k, long l){
	if(coin == k || coin == l || coin == 1) return 'A';
	else{
		if (Way(k,l,coin)) return 'A';
		else return 'B';
	}
}

int main(){
	char c;
	string str = "";
	long n,k,l,coin;
	
	cin >> n >> k >> l;
	
	for(long i = 0; i < n; i++){
		cin >> coin;
		c = Solve(coin,k,l);
		str += c;
	}
}
