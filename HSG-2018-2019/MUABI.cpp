#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;
vector<long> Amount;

void Sort(){
	for(long i = 0; i < A.size()-1;i++){
		long temp,temp1;
		for(long j = i+1; j < A.size(); j++){
			if (A[i] <= A[j]){
				temp = A[i];
				A[i] = A[j];
				A[j] = temp; 
				temp1 = Amount[i];
				Amount[i] = Amount[j];
				Amount[j] = temp1; 
			}
		}
	}
}

long Greedy(long m){
	long result = 0;
	long i = 0;
	
	while(m > 0){
		if (Amount[i] == 0) i++;
		if (Amount[i] <= m){
			result = result + Amount[i] * A[i]; 
			m = m - Amount[i];
			i++;
		}
		else{
			result = result + A[i];
			Amount[i]--;
			m--;
		}
	}
	
	return result;
}

void Solve(long m){
	Sort();
	long result = Greedy(m);
	cout << result;
}

int main(){
	long n,m,input;
	
	inp.open("C:\\bt_c++\\HSG-2018-2019\\MUABI.INP");	
	out.open("C:\\bt_c++\\HSG-2018-2019\\MUABI.OUT");
	
	inp >> m >> n;
	
	for(long i = 0; i < n; i++){
		inp >> input;
		Amount.push_back(input);	
		inp >> input;
		A.push_back(input);
	}
	
	Solve(m);
	
	inp.close();
	out.close();
}
