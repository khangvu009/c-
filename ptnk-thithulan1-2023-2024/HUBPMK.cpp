#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<string> A;

vector<int> StoV(string str){
	int temp;
	vector<int> B;
	
	for(long i = 0; i < str.length(); i++){
		if(str[i] != ' '){
			temp = (int)(str[i] - '0');
			B.push_back(temp);
		}
	}
	
	return B;
}

long TakingNum(vector<int> B,vector<int> C){
	long result = 0;
	
	for(long i = 0; i < B.size(); i++){
		if(C[i] == 1) result = result * 10 + B[i];
	}
	
	return result;
}

bool IsPrime(long n){
	if(n == 2) return true;
	
	cout << "n = " << n << endl << endl;
	for(long i = 2; i * i <= n; i++){
		if(n % i == 0) return false;	
	}
	
	cout << "	is prime " << endl;
	return true;
}

long BinaryCount(vector<int> B){
	long temp = B.size(),count = 0;
	vector<int> C (temp,0);
	bool flag = true;
	int i = C.size()-1;
	
	while(flag){
		C[i]++;
		while(C[i] > 1){
			i--;
			if(i == -1){
				flag = false;
				break;
			}
			C[i]++;
		}
		long num = TakingNum(B,C);
		if(IsPrime(num)) count++;
	}
	
	return count;
}

void Solve(){
	long count;
	vector<int> B;
	
	for(int i = 1; i < A.size(); i++){
		B = StoV(A[i]);
		count = BinaryCount(B);
		cout << count << endl;
	}
}

int main(){
	int n;
	string str;
	
	inp.open("HUBPMK.INP");
	out.open("HUBPMK.OUT");
	
	inp >> n;
	
	for(long i = 0; i < n; i++){
		getline(inp,str);
		A.push_back(str);
	}
	
	Solve();
	
	inp.close();
	out.close();
}
