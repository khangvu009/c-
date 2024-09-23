#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

void Solve(string str){
	long sum = 0;
	
	
	sort(str.begin(),str.end());
	reverse(str.begin(),str.end());
		
	for(long i = 0; i < str.length(); i++){
		sum += (long)(str[i]-'0');
	}
	
	if(str[str.length()-1] == '0' && sum % 3 == 0) out << str;
	else out << -1;
}

int main(){
	string str;
	
	inp.open("MATMA.INP");
	out.open("MATMA.OUT");
	
	
	inp >> str;
	
	Solve(str);
	
	inp.close();
	out.close();
}
