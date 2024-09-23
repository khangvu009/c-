#include <iostream>
#include <string>

using namespace std;


string turn_C_I_to_S(char c, long sl)
{
	string S = "";
	
	while (sl > 0){
		S = S + c;
		sl--;
	}	
	
	return S;
}

long Ctoi (char c)
{
	long tem = (int)c - (int)'0';
	
	cout << "---- c = " << c << "---- (int)c = " << tem << endl;
//	int i = 1;
//	char c1 = (char)(i + (int)'0');
//	cout << c1 << endl; 
//	cout << (char)(48+9)<< endl;
	return tem;	
}

string Giai_nen (string str)
{
	long len = str.length();
	long sl = 0;
	char c = ' ';
	
	string S1 = "";
	str = str + "";
	
	for (int i = 0; i <= len; i++){
		cout << "-- i = " << i << "-- str[i] = " << str[i] << "-- S1 = " << S1 << endl;
		if (str[i]-'0' >= 0 && str[i]-'0' <= 9){
			sl = sl * 10 + Ctoi(str[i]);
			cout << "-- sl = " << sl << endl;
		}
		else{
			S1 = S1 + turn_C_I_to_S(c,sl);
			c = str[i];
			cout << "-- S1 = " << S1 << "-- c = " << c << endl;
			sl = 0;
		}
	}
	
	return S1;
	
}

string Solve (string *Str, long n)
{	
	string S;
	
	for (int i = 0; i < n; i++){
		cout << Giai_nen(Str[i]) << endl;
	}
}

int main()
{
	long n;
	string Str[1000];
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> Str[i];
	}
	
	Solve(Str,n);
	return 0;
}
