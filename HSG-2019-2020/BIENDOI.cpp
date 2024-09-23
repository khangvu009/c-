#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

bool Scp(long n){
	long temp = sqrt(n) + 1 - 1;
	if (temp * temp == n) return true;
	return false;
}

void Print(long n){
	if (n == 1)  cout << A[0] << endl;
	else cout << A[0] << " ";
	for(long i = 1; i < A.size(); i++){
		if ((i+1) % (n) == 0){
			if (i == A.size()-1) cout << A[i];
			else cout << A[i] << endl;	
		}
		else cout << A[i] << " ";
	}
}

void Solve(long n){
	bool flag = true, flag1 = true;
	long current;
	
	reverse(A.begin(), A.end());
	
	long rule = A[1] - A[0];
	
	if (rule < 0) cout << 0;
	else{
		for(long i = 0; i < A.size(); i++){
			if (A[i] == 0){
				A[i] = A[i-1] + rule;	
				if (Scp(A[i])) A[i] = sqrt(A[i]) + 1;
			}
		}
	}
	
 Print(n);
}

int main(){
	long n,input;
	
	inp.open("C:\\bt_c++\\HSG-2019-2020\\BIENDOI.INP");
	out.open("C:\\bt_c++\\HSG-2019-2020\\BIENDOI.OUT");
	
	inp >> n;
	
	for(long i = 0; i < n*n; i++){
		inp >> input;
		A.push_back(input);
	}
	
	Solve(n);
	
	inp.close();
	out.close();
}
