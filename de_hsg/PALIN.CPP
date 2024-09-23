#include <bits/stdc++.h>

using namespace std;

ifstream palin_inp;
ofstream palin_out;


void Solve (vector<string> A)
{	
	for (long i = 0; i < A.size(); i++){
		string str = A[i];
		string str1 = str;
		reverse(str1.begin(),str1.end());
		if (str == str1){
			if (i < A.size()-1){
				palin_out << "YES" << endl;
			}
			else{
				palin_out << "YES";
			}
		}
		if (str != str1){
			if (i < A.size()-1){
				palin_out << "NO" << endl;
			}
			else{
				palin_out << "NO";
			} 
		}
	}
}

int main()
{
	vector<string> A;
	string str;
	long n;
	
	palin_inp.open("C:\\bt_c++\\de_hsg\\PALIN.INP");
	palin_out.open("C:\\bt_c++\\de_hsg\\PALIN.OUT");
	
	palin_inp >> n;
	
	for (long i = 0; i < n; i++){
		palin_inp >> str;
		A.push_back(str);	
	}
	
	Solve(A);
		
	palin_inp.close();
	palin_out.close();
	
}
