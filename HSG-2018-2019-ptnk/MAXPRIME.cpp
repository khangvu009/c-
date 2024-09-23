#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

void FindIndexOFQuestionMark(string str,int &index, int &index1){
	index = -1;	
	for(int i = 0; i < str.length(); i++){
		if (index == -1){
			if (str[i] == '?') index = i;
		}
		else{
			if (str[i] == '?') index1 = i;	
		}
	}
	cout << index << " " << index1 << endl;
}

bool IsPrime(long long n){
	for(long long i = 2; i <= sqrt(n)+1; i++){
		if (n % i == 0) return false;
	}
	return true;
}

long long ToInt(string &str, int index, int index1, int first_digit, int second_digit){
	str[index] = (char)(first_digit) + '0';
	str[index1] = (char)(second_digit)+ '0';
	
	long long result = 0;
	
	for(long i = 0; i < str.length(); i++){
		result = result * 10 + ((int) ((str[i]) - '0'));
//		cout << "result = " << result << endl;
	}
	cout << str << endl;
	return result;
}

void Solve(string str){
	int first_digit = 9,second_digit = 9,index,index1,condition = 0;
	long long number;
	
	FindIndexOFQuestionMark(str,index,index1);
	
	while (true){
		if (condition != 0){
			if (condition - (first_digit*10 + second_digit) % 3 != 0){
				number = ToInt(str,index,index1,first_digit,second_digit);
				if (IsPrime(number)) break;
			}
		}
		else{
				number = ToInt(str,index,index1,first_digit,second_digit);
				if (IsPrime(number)) break;
		}
		second_digit--;
		if (second_digit < 1){
			second_digit = 9;
			first_digit--;
		}
		if (first_digit == 1 && second_digit == 1){
			cout << "----------------khong co ";
			break;
		}
		if (number % 3 == 0) condition = first_digit * 10 + second_digit;
	}
	
	cout << number;
}

int main(){
	string str;
	
	inp.open("C:\\bt_c++\\HSG-2018-2019-ptnk\\MAXPRIME.INP");
	out.open("C:\\bt_c++\\HSG-2018-2019-ptnk\\MAXPRIME.OUT");
	
	inp >> str;
	
	Solve(str);
	
	inp.close();
	out.close();
}
