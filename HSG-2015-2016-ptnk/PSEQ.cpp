#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;


void Solve(long n){
	long i = 2,count = 0;
	
	while(n != 1){
		if(n % i == 0){
			n = n / i;
			count++;
		}
		else{
			i++;
		}
	}
	
	cout << count;
}

int main(){
	long n;
	inp.open("C:\\bt_c++\\HSG-2015-2016-ptnk\\PSEQ.INP");	
	out.open("C:\\bt_c++\\HSG-2015-2016-ptnk\\PSEQ.OUT");
	
	inp >> n;
	
	
	Solve(n);
	
	inp.close();
	out.close();
}
