#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


void Reverse_str (string &str)
{
	reverse(str.begin(),str.end());
}

void Solve(long long n)
{
	long long h = 0;
	long long m = 0;
	long long s = 0;
	string str_h = "";
	string str_m = "";
	string str_s = "";
	int len_h,len_m,len_s;

	h = n / 3600;
	m = (n % 3600) / 60;
	s = (n % 3600) % 60;
	
	str_h = to_string(h);
	str_m = to_string(m);
	str_s = to_string(s);
	
	len_h = str_h.length();
	len_m = str_m.length();
	len_s = str_s.length();
	
	if (len_h == 1){
		str_h = str_h + '0';
		Reverse_str(str_h);
	}
	if (len_m == 1){
		str_m = str_m + '0';
		Reverse_str(str_m);
	}
	if (len_s == 1){
		str_s = str_s + '0';
		Reverse_str(str_s);
	}
	
	cout << str_h << ":" << str_m << ":" << str_s;
}

int main()
{
	long long n;
	
	cin >> n;
	
	Solve(n);
}
