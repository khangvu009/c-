#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A,B;

bool IsAllDivide(long n){
	long temp = n,phandu;
	
	while(temp > 0){
		phandu = temp % 10;
		if(phandu == 0 || n % phandu != 0) return false;
		temp /= 10;
	}
	
	return true;
}

void Solve(){
	long temp,count = 0;
	
	for(long i = 0; i < A.size(); i++){
		temp = A[i];
		if(IsAllDivide(temp)){
			count++;
			B.push_back(temp);
		}
	}
	cout << count << endl;
	for(long i = 0; i < B.size()-1; i++){
		cout << B[i] << " ";
	}
	cout << B[B.size()-1];
}

int main(){
	int n;
	long input;
	
	inp.open("SOCHIAHET.INP");
	out.open("SOCHIAHET.OUT");
	
	inp >> n;
	
	for(long i = 0; i < n; i++){
		inp >> input;
		A.push_back(input);
	}	
	
	Solve();
	
	inp.close();
	out.close();
}
