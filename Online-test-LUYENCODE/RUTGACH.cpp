#include<bits/stdc++.h>

using namespace std;


void Count(string str, long & black, long & red, long & yellow){
	for(long i = 0; i < str.length(); i++){
		if(str[i] == 'B') black++;
		else if (str == 'R') red++;
		else yellow++;
	}
}

long Detach(string str, long mcolor,vector<string> &A,char type){
	string temp = "";
	long i = 0;
	long j = 0;
	
	while(i < str.length()){
		temp = "";
		j = i;
		while(str[j] != type){
			temp += str[j];
			j++;
		}
		if(temp.length() != 0) A.push_back(temp);
		i = j;
		i++;
	}		
}

long Proc(string str, long mcolor,long color1,long color2,char type){
	vector<string> A;
	
	Detach(str,mcolor,A,type);
	
	for(long i = 0; i < A.size(); i++){
		Count(str,black,red,yellow);
	}
}

void Solve(string str){
	long black = 0,red = 0,yellow = 0,point,point1,point2,result;
	
	Count(str,black,red,yellow);
	point = Proc(str,yellow,red,black,'Y');
	point1 = Proc(str,black,red,yellow,'B');
	point2 = Proc(str,red,black,yellow,'R');
	result = max(point,point1);
	result = max(result,point2);
}

int main(){
	string str;
	
	str = "BRRYYYRRB";
	
	Solve(str);
//	cin >> str;
}
//0 = yellow
//1 = black
//2 = red
