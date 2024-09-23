#include <bits/stdc++.h>

using namespace std;

ifstream s_inp;

void Solve (string str1, string str2)
{
	string substring,ChooseStr,OtherStr;
	string result = "";
	
	if (str1.length() <= str2.length()){
		ChooseStr = str1;
		OtherStr = str2;
	}
	else{
		ChooseStr = str2;
		OtherStr = str1;
	}
	
//	cout << ChooseStr << endl;
//	cout << OtherStr << endl;
	for(int i = 0; i < ChooseStr.length()-1; i++){
		for(int j = i + 1; j < ChooseStr.length(); j++){
//			cout << " --- i = " << i << " --- j = " << j << endl; 
			substring = ChooseStr.substr(i,j-i);
			
//			size_t found = OtherStr.find(substring);
//  			if (found != string::npos){
////  				cout << substring << endl;
//  				if (substring.length() > result.length()){
//					result = substring;
//				}
//			}
//			else{
//				break;
//			}
  
			regex pattern (substring);
			
			if (regex_search(OtherStr,pattern)){
				if (substring.length() > result.length()){
					result = substring;
				}
			}
			else{
				break;
			}
		}
	}
	
	cout << result << endl;
}

int main()
{
	s_inp.open("C:\\bt_c++\\de_hsg\\S.INP");
	
	string str1,str2;
	
	getline(s_inp,str1); 
	getline(s_inp,str2); 
	
//	str1 = "ababc";
//	str2 = "babca";
	
	Solve(str1,str2);
	s_inp.close();
	
}
