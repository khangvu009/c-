#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

void F(long a, string &str){
	string str1 = "";
	
	for(long i = a; i < str.length(); i++){
		str1 += str[i];
	}
	
	str1 += str;
	str = str1;
}

void Solve(long n, long k, string str){
	for(long i = 1; i <= k; i++){
		F(n,str);
	}
	
	cout << str;
}

int main(){	
	long n,k;
	string str;
	
	inp.open("C:\\bt_c++\\HSG-2013-2014\\CSTRING.INP");
	out.open("C:\\bt_c++\\HSG-2013-2014\\CSTRING.OUT");	

	inp >> n >> k >> str;
	
	Solve(n,k,str);
	
	inp.close();
	out.close();
}

