#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<char> A;

bool IsTheSame(char c){
	if (A.size() == 0) return true;
	for(long i = 0; i < A.size(); i++) if (A[i] == c) return false;
	return true;
}

void Solve(string str, long len){
	long count = 0;
	
	for (long i = 0; i < len; i++){
		if (IsTheSame(str[i])) A.push_back(str[i]);
		else count++;	
	}
	
	cout << count;
}

int main(){
	long n;
	string str;
	
	inp.open("C:\\bt_c++\\HSG-2016-2017\\KB.INP");
	out.open("C:\\bt_c++\\HSG-2016-2017\\KB.OUT");
	
	inp >> n >> str;
	
	Solve(str,n);
	
	inp.close();
	out.close();
}
