#include <iostream>
#include <string>

using namespace std;

void Chuan_hoa(string & str)
{
	int len = str.length();
	
	if(str[0] >= 'a' && str[0] <= 'z'){
		str[0] = (char)(str[0] -32);
	}
	
	for(int i = 1; i < len; i++){
		if(str[i] >= 'a' && str[i] <= 'z' && str[i-1] == ' '){
			str[i] = (char)(str[i]-32);
		}
		 if( str[i] >= 'A' && str[i] <= 'Z' && str[i-1] != ' ' ){
		 	str[i] = (char)(str[i]+32);
		 }
	}
}

void Solve(string *Str, int n)
{
	for(int i = 0; i < n; i++){
		Chuan_hoa(Str[i]);
	}
}

int main()
{
	int n;
	string Str[1000];
	
	cin >> n;
	cin.get();
	
	for (int i = 0; i < n; i++){
		getline(cin,Str[i]);
	}
	
	Solve(Str,n);
	
	for(int i = 0; i < n; i++){
		if (i < n-1){
			cout << Str[i] << endl;
		}
		else{
			cout << Str[i];
		}
	}
//	cout << (char)('b'-32); 
}
