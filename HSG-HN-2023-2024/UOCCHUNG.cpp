#include<bits/stdc++.h>
#define ll long long

using namespace std;

ifstream inp;
ofstream out;

ll GCD(ll a, ll b){
	if(a == 0) return b;
	return GCD(b%a,a);
}

void Solve(ll a, ll b){
	ll gcd = GCD(a,b);
	
	gcd--;
	
	while(a % gcd != 0 || b % gcd != 0){
		gcd--;
	}
	cout << gcd;
}

int main(){
	ll a,b;
	inp.open("UOCCHUNG.INP");
	out.open("UOCCHUNG.OUT");
	
	inp >> a >> b;
	
	Solve(a,b);
	
	
	inp.close();
	out.close();
}
