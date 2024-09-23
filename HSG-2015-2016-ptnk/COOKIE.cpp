#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<vector<long>> A;

void AddV(string str){
	vector<long> B;
	long temp = 0;
		
	for(long i = 0; i < str.length(); i++){
		if(str[i] != ' '){
			temp = temp * 10 + (int)(str[i]-'0');
		}	
		else{
			B.push_back(temp);
			temp = 0;
		}
	}
	B.push_back(temp);
	A.push_back(B);
}

bool Check(vector<long> B, vector<long> C){
	for(long i = 0; i < C.size(); i++){
//		cout << "---" << C[i] << " " << B[i] << endl;
		if(C[i] != B[i]) return false;
	}
	return true;
}


long WhichCase(vector<long> C, long max, long index1){
	if(C[C.size()-1-index1] == max) return 0;
	if(C[0] == max) return 1;
	return 2;
}

Swap(vector<long> &C, long index){
	long i = 0,j = index;
	long temp;
	
	while(i < j){
		temp = C[i];
		C[i] = C[j];
		C[j] = temp;
		i++;
		j--;
	}	
}

FindeIndexMax(long max, vector<long> C){
	for(long i = 0; i < C.size(); i++){
		if(C[i] == max) return i;
	}
}

Swap1(vector<long> &C, long index2){
	long i = 0,j = index2;
	long temp;
	
	while(i < j){
		temp = C[i];
		C[i] = C[j];
		C[j] = temp;
		i++;
		j--;
	}
}

void SwapCake(vector<long> &C, long &max, long Icase, long &index,long &index1){	
	long index2;
	if(Icase == 1){
		cout << C.size()-index << " ";
		Swap(C,index);
		index--;
		max--;
		index1++;
	}
	else if(Icase == 2){
		index2 = FindeIndexMax(max,C);
		Swap1(C,index2);
		cout << C.size()-index2 << " ";
	}
}

void Processing(vector<long> B,vector<long> C){
	long Icase,max = B[B.size()-1],index = max-1,index1 = 0;
	
	if(Check(B,C)){
		for(long i = 0; i < C.size()-1; i++){
			cout << C[i] << " ";
		}
		cout << C[C.size()-1] << endl;
	}
	else{
		for(long i = 0; i < C.size()-1; i++){
			cout << C[i] << " ";
		}
		cout << C[C.size()-1] << endl;
		
		while(!(Check(B,C))){
			Icase = WhichCase(C,max,index1);
			SwapCake(C,max,Icase,index,index1);
		}	
	}
	cout << 0 << endl;
}

void Solve(vector<string> S){
	vector<long> B;
		
	for(long i = 0; i < S.size()-1; i++){
		AddV(S[i]);
	}
	
	B = A[0];
	
	sort(B.begin(),B.end());
	
	for(long i = 0; i < A.size(); i++){
		Processing(B,A[i]);
	}
	
}

int main(){
	string input;
	vector<string> S;
	
	inp.open("C:\\bt_c++\\HSG-2015-2016-ptnk\\COOKIE.INP");	
	out.open("C:\\bt_c++\\HSG-2015-2016-ptnk\\COOKIE.OUT");
		
	while(!inp.	eof()){
		getline(inp,input);
		S.push_back(input);
	}
	
	Solve(S);
	
	inp.close();
	out.close();
}
