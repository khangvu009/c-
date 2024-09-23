#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

void Solve(long n, string str){
    long i = 0,result = 0;
	
	while(i < str.length()-1){
		if(str[i] == str[i+1]) i++;
		else i += 2;
		result++;
	}
	out << result+1;
}

int main(){
    inp.open("STRING.inp");
    out.open("STRING.out");
    
    long n;
    string str;
    
    inp >> n >> str;
    
    Solve(n,str);
    
    inp.close();
    out.close();
}

