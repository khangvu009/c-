#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<string> Q,A;

long CountLetter (string str, long &index, char &c){
	long count = 0;
	
	for (long i = 0; i < str.length(); i++){
		if (str[i] != '0') count++;
		if (str[i] >= 'A' && str[i] <= 'Z'){
			index = count-1;
			c = str[i];
		}
	}
	
	cout << "count = " << count << " index = " << index << " char = " << c << endl; 
	return count;
}

bool IsLetterAtSameIndex (char c,long index, string str1){
	cout << " str1[index] = " << str1[index] << " char = " << c << endl;
	if (str1[index] == c) return true;
	return false;
}

string AddToVector(string str,string str1){
	string B;
	long temp = 0;
	
	B = str;
	
	for (long i = 0; i < B.length(); i++){
		if (B[i] != '0'){
			B[i] = str1[temp];
			temp++;
		}
	}
	
	cout << " strOut = " << str1 << endl;
	cout << " str = " << str << endl;
	return B;
}

void FindStringHasSameSize(long size,long index, char c, string str, vector<string> &B){
	for (long i = 0; i < A.size(); i++){
		if (A[i].length() == size){
			cout <<  "str = " << str << " str2 = " << A[i];
			cout << " c =  " << c << endl;
			if (IsLetterAtSameIndex(c,index,A[i])){
				B.push_back(AddToVector(str,A[i]));
				break;	
			}
		}
	}
}

void Print(vector<string> B){
	for (long i = 0; i < B.size(); i++){
		if (i == B.size()-1) cout << B[i];
		else cout << B[i] << endl;
	}
}

void Solve(){
	vector<string> B;
	long count,index;
	string str;
	char c;
	
	for (long i = 0; i < Q.size(); i++){
		count = CountLetter(Q[i],index,c);
		FindStringHasSameSize(count,index,c,Q[i],B);
	}	
	
	Print(B);
}

int main()
{
	long n,m;
	string str;
	
	inp.open("C:\\bt_c++\\HSG-2020-2021\\OCHU.INP");	
	out.open("C:\\bt_c++\\HSG-2020-2021\\OCHU.OUT");
	
	inp >> m >> n;
	
	
	for (long i = 0; i < m; i++){
		inp >> str;
		Q.push_back(str);
	}
	
	for (long i = 0; i < m; i++){
		inp >> str;
		A.push_back(str);
	}
	
	
	Solve();
	
	inp.close();
	out.close();
}
