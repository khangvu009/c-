#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

bool Shake(string &str, long &condition,long &count){
	char temp;
	bool flag = false;
	
	for(long i = 0; i < str.length(); i++){
		cout << "str[i] = " << str[i] << " str[i+1] = " << str[i+1] <<endl;
		if(str[i] == 'R' && str[i+1] == 'L'){
			temp = str[i];
			str[i] = str[i+1];
			str[i+1] = temp;
			count++;
			flag = true;
			condition = 1;
		}
	}
	
	cout << str << endl;
	
	return flag;
}

void Solve(string str){
	long count = 0,condition = 0;
	
	cout << str << endl;
	
	while(!Shake(str,condition,count))
	
	if(condition == 0) cout << "ENDLESS";
	else cout << count << " " << count+1;
}

int main(){
	string str;
	
	inp.open("C:\\bt_c++\\HSG-2015-2016-ptnk\\HANDS.INP");	
	out.open("C:\\bt_c++\\HSG-2015-2016-ptnk\\HANDS.OUT");
		
	inp >> str;
	
	Solve(str);
	
	inp.close();
	out.close();
}
