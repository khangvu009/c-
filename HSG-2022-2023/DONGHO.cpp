#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<string> A;

void Filter(string str, long &h, long &m){
	bool flag = true;
	for (long i = 0; i  < str.length(); i++){
		if (str[i] == ':') flag = false;
		if (flag && str[i] != ':') h = h * 10 + ((int)(str[i]) - '0');
		if(!flag && str[i] != ':') m = m * 10 + ((int)(str[i]) - '0');
	}
	
	cout << "h = " << h << " m = " << m << endl; 
}

long FindAngle(long h, long m){
	long angle;
	
	if (m <= 30) angle = ((60+m)-(h*5)) * 6;
	else angle = ((h*5) - m) * 6;
	
	return angle;
}

string FormatInt2String(double fix_angle){
	string str = to_string(fix_angle);
	string str1 = "";
	long countdown = 4;
	bool flag = true;
	
	for (long i = 0; i < str.length(); i++){
		if (countdown > 0) str1 = str1 + str[i];
		if (str[i] == '.') flag = false;
		if (!flag) countdown--;
	}
	
	
	return str1;
}

double FixAngle(long h, long m, long angle){
	double fix_angle = (double)(angle)- (double(((double)(m)* 0.5)));
	return fix_angle;
}

string Processing (long h , long m){
	long angle;
	double fix_angle;
	
	string str = "";
	
	angle = FindAngle(h,m);
	cout << "angle = " << angle << endl;
	fix_angle = FixAngle(h,m,angle);
	cout << "fix_angle = " << fix_angle << endl;
	str = FormatInt2String(fix_angle);
	cout << "str = " << str << endl;
	return str;
}

void Print(vector<string> B){
	long i;
	
	for (i = 0; i < B.size()-1; i++){
		cout << B[i] << endl;
	}
	cout << B[i];
}

void Solve(){
	string str;
	vector<string> B;
	
	for (long i = 0; i < A.size(); i++){
		long h = 0,m = 0;
		Filter(A[i],h,m);
		str = Processing(h,m);
		B.push_back(str);	
	}
	
	Print(B);
}

int main(){
	inp.open("C:\\bt_c++\\HSG-2022-2023\\DONGHO.INP");	
	out.open("C:\\bt_c++\\HSG-2022-2023\\DONGHO.OUT");
	
	string str;
	
	while (str != "0:00"){
		inp >> str;
		if (str != "0:00") A.push_back(str);	
	}
	
	for (long i = 0; i < A.size(); i++){
		cout << A[i] << endl;
	}
	
	Solve();
	
	inp.close();
	out.close();
}

