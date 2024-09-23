#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <algorithm>

using namespace std;

string itoS (long n)
{
	long phan_du,phan_nguyen;
	
	string str = "";
	
	
	while(n > 0){
		phan_du = n % 10;
		phan_nguyen = n / 10;	
		n = phan_nguyen;
		str = str + char(phan_du+(int)'0');
	}
	reverse(str.begin() , str.end());
	
	cout  << "-- str = " << str << endl;
	return str;
}
string nen_chuoi (long n, string str)
{
	long count = 0;
	char c = ' ';
	string S1 = "";
	
	n = str.length();
	
	for (int i = 0; i < n; i++){
		count++;
		c = str[i];
//		cout << "-- i = " << i << " -- count = " << count << " -- c = " << c << " -- S1 = " << S1 << endl;
		if (str[i] != str[i+1] || i == n-1){
			S1 = S1 + c + itoS(count);
			count = 0;
			c = ' ';
		}
	}
	
	return S1;
}

long Solve (long n, string *Str)
{
	for (int i = 0; i < n; i++){
		cout << nen_chuoi(n,Str[i]) << endl;
	}
	
	return 0;
}


int main()
{
	long n;
	string Str[1000];
	
	cin >> n;
	
	for (int i = 0; i <n; i++){
		cin >> Str[i];
	} 
	
	Solve(n,Str);
}
