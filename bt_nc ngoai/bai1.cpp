#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;


int Compare_string(string substring1,string substring2)
{
	int result;
//	cout << " + Compare_string: " << substring1 << endl;
	reverse(substring2.begin(), substring2.end();	
	result = substring1.compare(substring2);
//	cout << "    - " << substring1 << " " << substring2 << " " << result << endl;
	return result;
}
int main()
{

	string str,substring1,str_result;
	int len,b,len1,max_len;
	ifstream symmetry_inp;
	symmetry_inp.open("C:\\bt_c++\\bt_nc ngoai\\STRINGSYMMETRY.INP");
	ofstream symmetry_out;
	symmetry_out.open("C:\\bt_c++\\bt_nc ngoai\\STRINGSYMMETRY.OUT");
	
	symmetry_inp >> str;
	len = str.length();
	len1 = 0;
	max_len = 0;
	for (int i = 0; i <= len; i++){
		for(int j = 0; j <= len; j++){
			substring1 = str.substr(i,j);
			len1 = substring1.length();
			b = Compare_string(substring1,substring1);
			if (b == 0 && max_len < len1){
				max_len = len1;
				str_result = substring1;
				cout << "-----max = " << str_result << endl;
			}
		}
	}
	symmetry_out << str_result;
	symmetry_inp.close();
	symmetry_out.close();
}
    	
