#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void Reverse (string &str){
	reverse(str.begin(),str.end());	
}

int check (string S, string X)
{
	string subs1 = S;
	string subs2;
	int sosanh;
	
	subs1 = subs1 + X;
	subs2 = subs1;
	Reverse(subs1);
	if (subs2 == subs1){
		return 0;
	}
	else{
		return 1;
	}
}

string Tim_str_X(string S) {
    string shortest = S;
    long len = S.length();
    long len1;
    int kt;

    for (int i = 1; i < len; i++) {
        string substring = S.substr(0, i);
        Reverse(substring);
        len1 = substring.length();
        kt = check(S, substring);
        if (kt == 0) {
            if (len1 < shortest.length() || (len1 == shortest.length() && substring < shortest)) {
                shortest = substring;
            }
        }
    }
    return shortest;
}

string Solve(string S1, string S2)
{
	string str1,str2;
	long sum_S1,sum_S2;
	
	str1 = Tim_str_X(S1);
	str2 = Tim_str_X(S2);
	
	if (str1 == "" && str2 == ""){
		return "No Caption";
	}
	
	if (str1 == "") { 
        return str2;
    }

    if (str2 == "") {  
        return str1;
    }
    
    if (str1.length() < str2.length() || (str1.length() == str2.length() && str1 < str2)) {
        return str1;
    }

    return str2;
}
	
int main()
{
	string S1,S2,result;
	
	cin >> S1;
	cin >> S2;
	
	result = Solve(S1,S2);
	
	cout << result;
}
