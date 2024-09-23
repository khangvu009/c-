#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

void TurnFractionToDecimalFraction(double n, long &tu, long &mau){
	n = n * 10;
	tu = n + 1;
	mau = mau * 10;
	if (n == tu-1){
		tu--;
		return;
	}
	
	return TurnFractionToDecimalFraction(n,tu,mau);
}

long UCLN(long a, long b){
	if (a == 0) return b;
	return UCLN(b % a, a);
}

void MakeSmallest(long &tu, long &mau){
	long ucln = UCLN(tu,mau);
	tu = tu / ucln;
	mau = mau / ucln;
}

void Solve(double n){
	long tu,mau = 1;
	
	TurnFractionToDecimalFraction(n,tu,mau);
	MakeSmallest(tu,mau);
	
	cout << tu << " " << mau;
}

int main(){
	double n;
	
	inp.open("C:\\bt_c++\\HSG-2015-2016\\PHANSO.INP");
    out.open("C:\\bt_c++\\HSG-2015-2016\\PHANSO.OUT");
	
	inp >> n;

	Solve(n);
		
    inp.close();
    out.close();
}
