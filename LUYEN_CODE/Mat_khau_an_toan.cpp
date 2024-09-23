#include <iostream>
#include <string>

using namespace std;

int Min (int m)
{
	if(m <= 5){
		return m;
	}
	else{
		return 5;
	}
}

int Max (int m)
{
	if (m >= 0){
		return m;
	}
	else{
		return 0;
	}
}

int Amount_char_type(string str, int len)
{
	int letter = 0;
	int capital_letter = 0;
	int number = 0;
	
	for (int i = 0; i < len; i++){
		if (number == 1 && letter == 1 && capital_letter == 1){
			break;
		}
		if (str[i] >= 'a' && str[i] <= 'z'){
			letter = 1;
		}
		if (str[i] >= 'A' && str[i] <= 'Z'){
			capital_letter = 1;
		}
		if (str[i] >= '0' && str[i] <= '9'){
			number = 1;
		}
	}
	
	return capital_letter + letter + number;
		
}

int Exchange_points (int n)
{
	if (n == 0){
		return 0;
	}
	if (n == 1){
		return 1;
	}
	if (n == 2){
		return 2;
	}
	if (n == 3){
		return 5;
	}
}

int Sum_point (string str)
{
	int len = str.length();
	int max,sum,min,amount,after_exchange;
	
	max = Max(len-5);
	min = Min(max);	
	amount = Amount_char_type(str,len);
	after_exchange = Exchange_points(amount);
	sum = min + after_exchange;
	
	return sum;
}

void Solve(string *Str, int n)
{
	int result;
	
	for (int i = 0; i < n; i++){
		result = Sum_point(Str[i]);
		if (i < n-1){
			cout << result << " ";
		}
		else{
			cout << result;
		}
	}	
}

int main()
{
	int n;
	string Str[100];
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> Str[i];
	}
	
	Solve(Str,n);
}
