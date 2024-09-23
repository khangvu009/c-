#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int string_to_int (char c)
{
	return (int)(c - '0');
	
}

int Solve (string str1, string str2)
{
	int nho = 0;
	int count = 0;
	int len1 = str1.length();
	int len2 = str2.length();
	int i = 1;
	int tam1 = 0;
	int tam2 = 0;
	int I_s1,I_s2;
	
	while (true){
		
		
		if (len1 - i < 0){
			tam1 = 0;
		}
		else{
			tam1 = string_to_int(str1[len1 - i]);
		}
		if (len2 - i < 0){
			tam2 = 0;
		}
		else{
			tam2 = string_to_int(str2[len2 - i]);
		}
		if (tam1 + tam2 + nho >= 10){
			nho = 1;
			count++;
		}
		else{
			nho = 0;
		}
		if ((len1 - i < 0 && nho == 0 ) || (len2 - i < 0 && nho == 0)){
			break;
		}
		
		cout << i << "------" << count << "---------" << nho << endl;
		i++;
	}
	return count;
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
