#include <iostream>
#include <string>
#include <math.h>
#include <sstream>

using namespace std;

int Ctoi (char c)
{
	int tem = c - '0';
	return tem;
}

unsigned long long Pow(long long n)
{
	int m = 2;
	unsigned long long tem = 1;
	
	if (n == 0){
		return tem;
	}
	
	for (int i = 0; i < n; i++){
		tem = tem * m;
//		printf("--tem=%u\n" ,tem);
	}
	
	return tem;
}

unsigned long long biary_to_decimal(string str)
{
	int len = str.length();
	unsigned long long  j = 0;
	unsigned long long S = 0;
	unsigned long long tem = 0;
	
	for (int i = len-1; i >= 0; i--){
		tem = (Ctoi(str[i]) * Pow(j));
		S = S + tem;
		j++;
	}
	
	return S;
}

void Solve (string *Str, int n)
{
	for (int i = 0; i < n; i++){
		cout << biary_to_decimal(Str[i]) << endl;
	}
}

int main()
{
	int n;
	string Str[10000];

	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> Str[i];
	}
	
	Solve(Str,n);
}
