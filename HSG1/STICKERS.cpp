#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

bool Check(char c, char c1)
{
	if (c != 'a'){
		if (c == c1){
			return true;
		}
		if (c == '5'){
			c = '2';
		}
		else if (c == '2'){
			c = '5';
		}
		else if (c == '6'){
			c = '9';
		}
		else if (c == '9'){
			c = '6';
		}
		if (c == c1){
			return true;
		}
	}
	return false;
}

long Match (string T, string S)
{
	string str;
	long count = 0;
	long result = 0;
	long i = 0;
	long j = 0;
	
	while (i < T.length() && j < S.length()){
		if (Check(T[i],S[j]) == true){
				j++;
				T[i] = 'a';
				i = -1;
				count++;
				if (count == S.length()){
					result++;
					count = 0;
					j = 0;
					i = -1;
				}
			}
		i++;
	}
	
	cout << T << endl;
	return result;
	
}

void Solve(string T, string S)
{
	long count;
	
	count = Match(T,S);
	
	cout << count;
	out << count;
}

int main()
{
	string T,S;
	
	inp.open("C:\\HSG1\\STICKERS.INP");
	out.open("C:\\HSG1\\STICKERS.OUT");
	
	inp >> T;
	inp >> S;
	
	Solve(T,S);
	
	inp.close();
	out.close();
}	
