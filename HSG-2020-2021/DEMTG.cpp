#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

void Solve(long d, long n){
	unsigned long long tong,result;
	
	if (d != 0){
		tong = ((d+1)*(d+2))/2;
		result = tong *(n+1);
	}
	else result = n+1;
	
	cout << result;
}

int main(){
	inp.open("C:\\bt_c++\\HSG-2020-2021\\DEMTG.INP");	
	out.open("C:\\bt_c++\\HSG-2020-2021\\DEMTG.OUT");
	
	unsigned long long d,n;
	
	inp >> d >> n; 
	
	Solve(d,n);
	
	inp.close();
	out.close();
}
