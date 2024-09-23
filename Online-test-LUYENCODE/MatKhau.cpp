#include <bits/stdc++.h>
using namespace std;

ifstream inp;
ofstream out;

struct Character{
	char c;
	int count = 0;
};

char Solve(string str) {
	vector<Character> A,B;
	Character cha;
	
	for (char ch = 'A'; ch <= 'Z'; ++ch) {
		cha.c = ch;
        A.push_back(cha);
    }
        
	for(long i = 0; i < str.length(); i++){
		for(long j = 0; j < A.size(); j++){
			if(str[i] == A[j].c){
				A[j].count++;
				break;
			}
		}
	}
	
	for(long i = 0; i < A.size(); i++){
		if(A[i].count == 1) return A[i].c;
	}
}

int main() {
    long n;
    char c;
    string str,result = "";
    
    inp.open("matkhau.inp");
    out.open("matkhau.out");
    
	inp >> n;
    
    for(long i = 0; i < n; i++){
    	inp >> str;
    	c = Solve(str);
    	result += c;
	}
	
	out << result;
    
	inp.close();	
    out.close();
}
