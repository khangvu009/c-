#include<bits/stdc++.h>

using namespace std;

vector<long> A;

void Solve(string str){
	sort(str.begin(),str.end());
	reverse(str.begin(),str.end());
	
	cout << str;
}

int main(){
	string str = "",input;
	long n;
	
	cin >> n;
	
	for(long i = 0; i < n; i++){
		cin >> input;
		str += input;
	}
		
	Solve(str);
}
