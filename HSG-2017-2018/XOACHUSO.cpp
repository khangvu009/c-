#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

long FindFirstIndexMax(string str, long k,long index1){
	long index, max = -1;
	
	for(long i = index1; i <= index1+k; i++){
//		cout << "i = " << i << endl;
		if (str[i] != 'a'){
			if (max < (int)(str[i])-'0'){
				max = (int)(str[i])-'0';
				index = i;
			}
		}
	}	
	
	return index;
}

MinusK(long &k, string str, long temp){
	long count = 0;
	
	for(long i = 0; i < str.length(); i++){
		if (str[i] == 'a') count++;
	}
	k = temp - count;
}

void PatternBeforeMax(string &str, long &k, long index,long index1,long temp){
//	cout << "index1 = " << index1 << " index = " << index << endl; 
	for(long i = index1; i < index; i++) str[i] = 'a';
//	cout << "str = " << str << endl;
	MinusK(k,str,temp);
}

void Print(string str){
	string str1 = "";
	
	for(long i = 0; i < str.length(); i++){
		if (str[i] != 'a') str1 += str[i];
	}	
	
	cout << str1;
}


void Solve(string str, long k, long temp){	
	long index1 = 0;
	long count = 0;
	
	while(k > 0){
		long index = FindFirstIndexMax(str,k,index1);
		PatternBeforeMax(str,k,index,index1,temp);
		index1 = index+1;
//		cout << "index1 = " << index1 << endl;
//		cout << "k = " << k << endl;
		count++;
		if (count == 2) break;
	}
	Print(str);	
}

int main(){
	string str;
	long k;
	
	inp.open("C:\\bt_c++\\HSG-2017-2018\\XOACHUSO.INP");
	out.open("C:\\bt_c++\\HSG-2017-2018\\XOACHUSO.OUT");
	
	inp >> str >> k;
	long temp = k;
	Solve(str,k,temp);
	
	inp.close();
	out.close();
}
