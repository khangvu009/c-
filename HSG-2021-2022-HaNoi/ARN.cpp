#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;



void Solve(string str, string str1){
	long count = 0, temp = 0,result = 0,temp1;
	long distance = str1.length();
	
	for(long i = 0; i < str1.length(); i++){
		if (Processing(str,temp)) count++;
	}
	
//	cout << result;
}

int main(){
	string str,str1;
	
	inp.open("C:\\bt_c++\\HSG-2021-2022-HaNoi\\ARN.INP");
	out.open("C:\\bt_c++\\HSG-2021-2022-HaNoi\\ARN.OUT");
	
	inp >> str >> str1;
	
	
	Solve(str,str1);
	
	inp.close();
	out.close();
	
}
