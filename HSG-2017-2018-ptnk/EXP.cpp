#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

void FindIndexAndMinAndMax(long long &min, long long &min1, long long &index, long long &index1){
	for(long i = 0; i < A.size(); i++){
		if (min > A[i] && A[i] >= 0){
			min = A[i];
			index = i;
		}
		if (min1 > A[i] && A[i] < 0){
			min1 = A[i];
			index1 = i;
		}
	}
}

long long Sum(){
	long long sum = 0;
	
	for(long i = 0; i < A.size(); i++){
		sum+= A[i];
	}
	
	return sum;
}

void Solve(){
	long long min = LLONG_MAX,min1 = LLONG_MAX,index,index1;
	FindIndexAndMinAndMax(min,min1,index,index1);
	A[index] = -min1;
	A[index1] = -min;
	
	long long sum = Sum();
	
	cout << sum;
	
}

int main(){
	long n,input;
	
	inp.open("C:\\bt_c++\\HSG-2017-2018-ptnk\\EXP.INP");
	out.open("C:\\bt_c++\\HSG-2017-2018-ptnk\\EXP.OUT");
	
	inp >> n;
	
	for(long i = 1; i <= n; i++){
		inp >> input;
		if (i % 2 == 0) input = -input;
		A.push_back(input);
	}
	
	for(long i = 0; i < A.size(); i++){
		cout << A[i] << " ";
	}
	cout << endl;
	
	Solve();
	
	inp.close();
	out.close();
}
