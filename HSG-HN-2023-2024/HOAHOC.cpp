#include<bits/stdc++.h>
#define ull unsigned long long

using namespace std;

ifstream inp;
ofstream out;

void Solve(ull A, ull B){
	ull result = B / 3;
	
	cout << result;
}

int main(){
	ull A,B;
	
	inp.open("HOAHOC.INP");
	out.open("HOAHOC.OUT");
	
	inp >> A >> B;
	
	Solve(A,B);
	
	
	inp.close();
	out.close();
}
