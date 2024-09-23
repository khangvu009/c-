#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

long ToInt(char fdigit, char sdigit, char ldigit){
	long first = (int)(fdigit)- '0';
	long second = (int)(sdigit)- '0'; 
	long third = (int)(ldigit)- '0';
	long result = (first * 10 + second) * 10 + third;
	
	return result;
}

void Solve(string str){
	long number,count = 0;
	
	if (str.length() > 2){
		for(long i = 0; i < str.length()-2; i++){
			number = ToInt(str[i],str[i+1],str[i+2]);
			cout << "str[i] = " << str[i] << " str[i+1] = " << str[i+1] << " str[i+2] = " << str[i+2] << " number = " << number << endl;
			if (number % 11 == 0){
				if((number / 100) + (number % 10) == (number / 10 ) % 10) count++;
			}
		}
	}
	cout << count;
}

int main(){
	string str;
	
	inp.open("C:\\bt_c++\\HSG-2014-2015-ptnk\\BOISO.INP");
	out.open("C:\\bt_c++\\HSG-2014-2015-ptnk\\BOISO.OUT");
	
	inp >> str;
	
	Solve(str);
	
	inp.close();
	out.close();
}
