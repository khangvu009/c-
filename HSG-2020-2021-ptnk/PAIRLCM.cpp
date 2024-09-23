#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

bool IsPrime(long n){
	for(long i = 2; i < sqrt(n)+1; i++) if (n % i == 0) return false;
	return true;
}

void Solve(long n){
	long i,j;
		
	if (n % 2 == 0){
		i = n / 2 - 1;
		j = n / 2 + 1;
	}
	else{
		i = n / 2 + 1;
		j = n / 2 + 1 -1; 
	}
	
	while(true){
		if (IsPrime(i)){
			if(IsPrime(j)){
				cout << i*j << endl;
				break;
			}
		}
		i++;
		j--;
	}
	
}

int main(){
	long n;
	
	inp.open("C:\\bt_c++\\HSG-2020-2021-ptnk\\PAIRLCM.INP");
	out.open("C:\\bt_c++\\HSG-2020-2021-ptnk\\PAIRLCM.OUT");
	
	inp >> n;
	
	Solve(n);
	
	inp.close();
	out.close();
}
