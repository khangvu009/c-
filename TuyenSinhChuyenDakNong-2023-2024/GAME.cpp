#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

void Solve(long n){
	long long sum = 0;
	
	for(long i = 1; i <= n; i++){
		sum += i * i;
	}
	
	string str = to_string(sum);
	
	cout << str[str.length()-2] << str[str.length()-1];	
}

int main(){
	long n;
	
	inp.open("GAME.INP");
	out.open("GAME.OUT");

	inp >> n;
	
	Solve(n);
	
	inp.close();
	out.close();
}
