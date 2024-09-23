#include<bits/stdc++.h>

using namespace std;

void Solve(string str){
	long count = 0;
	
	for(long i = 0; i <= str.length()-5; i++){
		if(str[i] == 'v' && str[i+1] == 'i' && str[i+2] == 'r' && str[i+3] == 'u' && str[i+4] == 's'){
			count++;
		}
	}
	cout << count;
}

int main(){
	string str;
	
	cin >> str;
	
	Solve(str);
}
