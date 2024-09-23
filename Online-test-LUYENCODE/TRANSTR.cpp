#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

void Solve(string str){
	long count = 0,index,index1;
	bool flag = true;
	
	for(long i = 0; i < str.length(); i++){
		if(str[i] == 'B'){
			if(flag){
				index = i;
				flag = false;
				count++;
			}
			else{
				index1 = i;
				if(index1 - index > 1) count++;
				index = index1;
			}
		}
	}
	
	
	cout << count;
}

int main(){
	string str;
	
	inp.open("transtr.inp");
	out.open("transtr.out");
	
	inp >> str;
	
	Solve(str);
	
	inp.close();
	out.close();
}
