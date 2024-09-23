#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

void Solve(string str){
	long index,number = 0;
	
	for(long i = 0; i < str.length(); i++){
		if(str[i] != '?') number = number + ((int)(str[i]-'0')* (i+1));
		else index = i+1;
	}
	
	for(long i = 0; i <= 9; i++){
		if( (number + index * i) % 11 == 0){
			cout << i;
			out << i;
			break;
		}
	}
}

int main(){
	string str;
	
	inp.open("ENCODE.INP");
	out.open("ENCODE.OUT");
	
	inp >> str;
	
	Solve(str);
	
	inp.close();
	out.close();
}
