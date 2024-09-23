#include <bits/stdc++.h>

using namespace std;

ifstream dem_tu_inp;
ofstream dem_tu_out;

long Count_trung_t1 (string str, bool &result)
{
	long count = 0;
	
	result = false;
	
	for(int i = 0; i < str.length()-1; i++){
		if (str[i] >= 'A' && str[i] <= 'z'){
			for(int j = i+1; j < str.length(); j++){
				if(str[j] >= 'A' && str[j] <= 'z'){	
					if (str[i] == str[j]){
						result = true;
						count++;
					}
					if (str[i] - str[j] == 32 || str[i] - str[j] == -32){
						count++;
						result = true;
					}
				}
			}
		}
	}
	
	return count;
}

long Count_trung_t2(string str, string str1, bool &result1)
{
	long count = 0;
	
	result1 = false;
	
	if(str.length() == str1.length()){
		for(int i = 0; i < str.length(); i++){
			if (str[i] - str1[i] == 0 || str[i] - str[i] - str1[i] == -32){
				count++;
			}	
		}
	}
	
	if (count == str.length()){
		result1 = true;
		count = 1;
	}
	else{
		count = 0;
	}
	
	return count;
}

void Take_words1(string str, vector<string> &R)
{
	R.push_back(str);
}

void Take_words2(string str, string str1 , vector<string> &R)
{
	R.push_back(str);
	R.push_back(str1);	
}

void Print(long total, vector<string> R)
{
	dem_tu_out << total << endl;
	
	for(int i = 0; i < R.size(); i++){
		for(int j = 0; j < R[i].length(); j++){
			dem_tu_out << R[i][j] << "";
		}
		if (i != R.size()-1){
			dem_tu_out << " ";
		}
	}
}

void Solve (vector <string> S)
{
	vector<string> R;
	
	long total;
	long trung1 = 0;
	long trung2 = 0;
	long check;
	bool result = false;
	bool dk = true;
	bool result1 = false;
		
	for(int i = 0; i < S.size(); i++){
		if(i < S.size()-1){
			trung2 = trung2 + Count_trung_t2(S[i],S[i+1],result1);
			if (result1 == true){
				Take_words2(S[i],S[i+1],R);
				dk = false;
			}
			else{
				dk = true;
			}
		}
		trung1 = trung1 + Count_trung_t1(S[i],result);
		if (result == true && dk == true){
			Take_words1(S[i],R);
		}
	}
	
	total = trung1+trung2;  
	
	Print(total,R);
}

int main()
{
	
	dem_tu_inp.open("C:\\bt_c++\\de_hsg\\DEMTUTL.INP");
	dem_tu_out.open("C:\\bt_c++\\de_hsg\\DEMTUTL.OUT");
	
	vector<string> S;
	
	string str;
	
	
		
	while(!dem_tu_inp.eof()){
		dem_tu_inp >> str;
		S.push_back(str);
	}
	 
	S.pop_back();
	
	Solve(S);
	
	dem_tu_out.close();
	dem_tu_inp.close();
}
