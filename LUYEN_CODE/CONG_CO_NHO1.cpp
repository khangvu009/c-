#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int string_to_int (char c)
{
	return (int)(c - '0');
	
}


int dao_chuoi(string &str)
{
	cout << str << endl;
	reverse(str.begin(),str.end());
	cout << str << endl;
}


int add_0 (string &str1, string &str2)
{
	int len1 = str1.length();
	int len2 = str2.length();
	string temp;
	
	if (len2 > len1) {
		temp = str1;
		str1 = str2;
		str2 = temp;
	}

	for (int i = len1; i < len2; i++){
		str2 = str2 + '0';
	}
	
	cout << "add 0: " << str1 << "---------" << str2 << endl;
}

int dem_sl_nho(string str1, string str2)
{
	int len = str1.length();
	int count = 0;
	int nho = 0;
	int tam1 = 0;
	int tam2 = 0;
	
	for (int i = 0; i < len; i++){
		tam1 =string_to_int(str1[i]);
		tam2 = string_to_int(str2[i]);
		if (tam1 + tam2 + nho >= 10){
			count++;
			nho = 1;
		}
		else{
			nho = 0;
		}
		cout << i << "-----" << count << "-------" << nho << endl;
	}	
	
	return count;
}

int Solve (string str1, string str2)
{

	dao_chuoi(str1);
	dao_chuoi(str2);
	add_0(str1,str2);
	return dem_sl_nho(str1,str2);
}

int main()
{
	string str1,str2;
	int result;
	ifstream cong_co_nho_inp;
	cong_co_nho_inp.open("C:\\bt_c++\\LUYEN_CODE\\CONGCONHO.INP");
	ofstream cong_co_nho_out;
	cong_co_nho_out.open("C:\\bt_c++\\LUYEN_CODE\\CONGCONHO.OUT");
	
	cong_co_nho_inp >> str1;
	cong_co_nho_inp >> str2;
	
	result = Solve(str1,str2);
	
	cong_co_nho_out << result; 
	
	cong_co_nho_inp.close();
	cong_co_nho_out.close();
}
