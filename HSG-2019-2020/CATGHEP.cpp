#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> AddToIntVector(string str){
	vector<long> A;
	
	long temp = 0;
	
	for(long i = 0; i < str.length(); i++){
		if(str[i] != ' ') temp = temp * 10 + ((int)(str[i]) - '0');
		else{
			A.push_back(temp);
			temp = 0;
		}
	}
	A.push_back(temp);
	
	return A;
}

bool CanAccess(string &str, long n){
	vector<long> A;
	
	long count = 0;
	
	string str1 = to_string(n);
	
	for(long i = 0; i < str1.length(); i++){
		for(long j = 0; j < str.length(); j++){
			if(str1[i] == str[j]){
				count++;
				A.push_back(j);
				break;
			}
		}		
	}
	if (count == str1.length()){
		for(long i = 0; i < A.size(); i++) str[A[i]] = 'a';
		return true;	
	}
	return false;
}

void Print(vector<long> B, vector<long> C){
	for(long i = B.size()-1; i > 0; i--) cout << B[i] << " ";
	cout << B[0];
	if (C.size() != 0){
		cout << endl;
		for(long i = 0; i < C.size()-1; i++) cout << C[i] << " ";
		cout << C.back();
	}
	
}

void Solve(string str, string str2){
	vector<long> A,B,C;
	
	A = AddToIntVector(str2);
	sort(A.begin(),A.end());
	for(long i = 0; i < A.size(); i++){
		if (CanAccess(str,A[i])) B.push_back(A[i]);
		else C.push_back(A[i]);
	}
	
	Print(B,C);
}

int main(){
	string str,str1,str2;
	inp.open("C:\\bt_c++\\HSG-2019-2020\\CATGHEP.INP");
	out.open("C:\\bt_c++\\HSG-2019-2020\\CATGHEP.OUT");
	
	inp >> str;
	getline(inp,str1);
	getline(inp,str2);
	
	Solve(str,str2);
	
	inp.close();
	out.close();
}
