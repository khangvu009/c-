#include <iostream>
#include <string>

using namespace std;

int Doi1 (char c)
{
	int result;
	
	switch (c){
		case 'I':
			result = 1;
			break;	
		case 'V':
			result = 5;
			break;	
		case 'X':
			result = 10;
			break;	
		case 'L':
			result = 50;
			break;	
		case 'C':
			result = 100;
			break;	
		case 'D':
			result = 500;
			break;	
		case 'M':
			result = 1000;
			break;	
	}
	return result;
}

int Doi2 (string c, string c1)
{
	int result = 0;
	
	if (c+c1 == "IV"){
		result = 4;
	}
	else if (c+c1 == "IX"){
		result = 9;
	}
	else if (c+c1 == "XL"){
		result = 40;
	}
	else if (c+c1 == "XC"){
		result = 90;
	}
	else if (c+c1 == "CD"){
		result = 400;
	}
	else if (c+c1 == "CM"){
		result = 900;
	}
	return result;
}

int Solve (string str)
{
	int len = str.length();
	int doi1,doi2;
	int result = 0;
	
	for(int i = 0; i < len; i++){
		if (i+1 < len){
			doi2 = Doi2(str.substr(i,1),str.substr(i+1,1));
			result = result + doi2;
		}
		else {
			doi2 = 0;
		}
		
		if (doi2 == 0){
			doi1 = Doi1(str[i]);
			result = result + doi1;
		}
		else{
			i++;
		}
	}
	return result;
	
}

int main()
{
	string str;
	int result;
	
	cin >> str;
	result = Solve(str);
	cout << result << endl;
}
