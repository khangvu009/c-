#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<int> ConvertStoAInt(string str){
	vector<int> A;
	int temp;
	
	for(int i = 0; i < str.length(); i++){
		temp = (int)(str[i]) - '0'; 
		A.push_back(temp);
	}
	
	return A;
	
}

vector<int> MultiplyBigNum(vector<int> A){
	
	vector<int> B;
	int nho = 0;
	int temp = 0;
	
	for(int i = A.size()-1; i >= 0; i--){
		temp = (A[i] * 4) % 10;
		B.push_back(temp+nho);
		nho = (A[i] * 4) / 10;	
	}
	
	if (nho > 0) B.push_back(nho);
	reverse(B.begin(),B.end());
	
	return B;
}

vector<int> MinusBigNum(vector<int> A){
	bool flag = true;
	int count = 0;
	
	vector<int> B;
	int nho = 0;
	int temp = 0;
	
	for(int i = A.size()-1; i >= 0; i--){
		if (A[i] - 3 >= 0 && flag){
			A[i] = A[i] - 3;
			return A;
		} 
		if (A[i] - 3 < 0 && flag){
			flag = false;
			temp = A[i] + 10 -3;
			nho = 1;
			B.push_back(temp);
			
		}
		if (nho == 1 && count == 1){
			if (A[i] - nho >= 0){
				B.push_back(A[i]-nho);
				nho = 0;
			}
			else{
				temp = A[i] + 10 - nho;
				B.push_back(temp);
			}
		}
		if(nho == 0) break;
		count = 1;
	}
	
	reverse(B.begin(),B.end());
	
	return B;
}

void Print(vector<int> A){
	for(long i = 0; i < A.size(); i++) cout << A[i];
}

void Solve(string str){
	vector<int> A,B,C;
	
	A = ConvertStoAInt(str);
	C = MinusBigNum(A);
	B = MultiplyBigNum(C);
	Print(B);
}

int main(){
	string str;
	
	inp.open("C:\\bt_c++\\HSG-2019-2020\\XUATHIEN.INP");
	out.open("C:\\bt_c++\\HSG-2019-2020\\XUATHIEN.OUT");
	
	inp >> str;
	
	Solve(str);
	
	inp.close();
	out.close();
}
