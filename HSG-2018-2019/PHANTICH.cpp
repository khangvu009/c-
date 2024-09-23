#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

long UCLN(long a, long b){
	if (a == 0) return b;
	return UCLN(b%a,a);
}

void TimUoc(long n){
	bool flag = true;
	
	for(long i = 2; i < n / 2+1; i++){
		if(n % i == 0){
			for(long j = 0; j < A.size(); j++){
				if (i % A[j] == 0) flag = false;
				break;
			}
			if (flag) A.push_back(i);
			flag = true;
		}	
	}
}

void Processing (long n){
	bool flag = true, flag1 = true,flag2 = true;
	
	for(long i = 0; i < A.size(); i++){
		if (n % A[i] == 0){
			cout << A[i] << " " << n / A[i];
			flag = false;
			break;
		}
	}
	
	
	for (long i = 0; i < A.size(); i++) cout << A[i] << " ";
	cout << endl;
	
	long i = 0;
	long temp;
	
	if (flag){
		while(flag1){
			if (flag2){
				temp = n % A[i] + A[i];
				flag2 = false;	
			}
			
			else temp = temp + A[i];
			for(long j = i+1; j < A.size(); j++){
				if (A[j] % temp == 0){
					cout << A[i] << " " << (n / A[i] - j)  << endl << A[j] << " " << A[j] / temp;
					flag1 = false;
					break;
				}
			}
		}
	}
}

void Analyse(long n, long k){
	
	long ucln = UCLN(n,k);
	if (ucln == 1){
		TimUoc(k);
		Processing(n);
	}
	else cout << ucln << " " << n / ucln;
}

void Solve(long n, long k){
	if (n == 1 || k == 1) cout << 0;
	else Analyse(n,k);
}

int main(){
	long n,k;
	
	inp.open("C:\\bt_c++\\HSG-2018-2019\\PHANTICH.INP");	
	out.open("C:\\bt_c++\\HSG-2018-2019\\PHANTICH.OUT");
	
	inp >> n >> k;
	
	Solve(n,k);
	
	inp.close();
	out.close();	
}
