#include <bits/stdc++.h>

using namespace std;

int main()
{
	char c;	
	long long tong,n;
	int tam;
	
	n = 1000000000000;
	c = 'A';
	tam = (int)'A';
	
	tong = n * (n+1) /2;
	
	if (tong % 26 == 0){
		c = 'Z';
	}
	else{
		tam += (tong % 26 );	
		c = (char)(tam);
	}
	
	cout << c;
}
