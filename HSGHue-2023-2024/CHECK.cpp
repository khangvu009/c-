#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out,out1;

vector<string> A;

double Sum(string str, long & condition){
	long temp = 0;
	double sum = 0,temp1 = 0,mul = 1;
	bool flag = false;
	
	for(long i = 0; i < str.length(); i++){
		if (flag && str[i] >= '0' && str[i] <= '9'){
			temp1 = (double)(str[i] - '0');
			mul *= 10;
		}
		else if(str[i] >= '0' && str[i] <= '9'){
			temp = temp * 10 + (int)(str[i] - '0');
		}
		else if (str[i] == '.'){
			flag = true;
		}
		else{
			flag = false;
			if(temp1 != 0){
				sum += (double)(temp) + (temp1 / mul);
			}
			else{
				sum += temp;
			}
			temp = 0;
			temp1 = 0;
		}
	}
	
	sum += (double)(temp);
	return sum;
}

void Solve(){
	double sum;
	long condition;
	
	for(long i = 1; i < A.size(); i++){
		sum = Sum(A[i],condition);
		out << sum << endl;
		if(A[i].size() > 10 || sum > 20) out1 << i << endl;
	}
}

int main(){
	string str;
	int n;
	long input;
	
	inp.open("CHECK.INP");
	out.open("CHECK1.OUT");
	out1.open("CHECK2.OUT");
	
	inp >> n;
	
	for(long i = 0; i <= n; i++){
		getline(inp,str);
		A.push_back(str);		
	}	
	
	
	Solve();
	
	inp.close();
	out.close();
	out1.close();
}
