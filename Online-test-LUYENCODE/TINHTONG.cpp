#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

void Solve(unsigned long long  n){
	unsigned long long i = 2;
	unsigned long long sum = 0;
		
	while(i < n){
		sum+= i;
		i+= 2;	
	}
	
	out << sum;
}

int main(){
	unsigned long long n;
	
	inp.open("C:\\bt_c++\\Online-test-LUYENCODE\\TINHTONG.INP");
	out.open("C:\\bt_c++\\Online-test-LUYENCODE\\TINHTONG.OUT");
	
	inp >> n;
	
	Solve(n);
	
	inp.close();
	out.close();
}
