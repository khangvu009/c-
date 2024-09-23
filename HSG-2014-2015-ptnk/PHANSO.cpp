#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

struct fraction{
	long numerator;
	long denominator;
};

long ToInt(string str){
	long result = 0;
	
	for(long i = 0; i < str.length(); i++){
		result = result * 10 + ((int)(str[i]-'0'));
	}
	
	return result;
}

long GCD (long a, long b){
	if (a == 0) return b;
	return GCD(b%a,a);
}

fraction ShortenFraction(long numerator, long denominator){
	long long gcd = GCD(numerator,denominator);
	fraction f;
	f.denominator = denominator / gcd;
	f.numerator = numerator / gcd;
	
	return f;
}

void Solve(long n, string str){
	long condition = 1;
	fraction f;
	long count = str.length();
	long m = ToInt(str);
	bool flag = false;
	
	if (n < 0){
		condition = -1;
	}
	if (n == 0){
		n = pow(10,count);
		flag = true;
	}
	
	if (!flag) f = ShortenFraction(m*(pow(10,count)),m*(pow(10,count)));
	if (flag) f = ShortenFraction(m*(pow(10,count)),n*(pow(10,count)));
	f.numerator * condition;
	
	cout << f.numerator << " " << f.denominator;
}

int main(){
	long n;
	string str;
	
	inp.open("C:\\bt_c++\\HSG-2014-2015-ptnk\\PHANSO.INP");
	out.open("C:\\bt_c++\\HSG-2014-2015-ptnk\\PHANSO.OUT");
	
	inp >> n >> str;
	
	Solve(n,str);
	
	inp.close();
	out.close();
}
