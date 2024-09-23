#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> addMang_mot_chieu(int add, int n)
{
	vector<int> B;
	for(int i = 0; i < n; i++){
		B.push_back(i+1+add);	
	}
	
	return B;
}

int Give_num_of_space (int n)
{
	int phan_du,phan_nguyen;
	int count = 0;
	
	while(n > 0){
		phan_du = n % 10;
		phan_nguyen = n / 10;
		n = phan_nguyen;
		count++;
	}
	
	return count;
}

string Give_str_of_space(int Mcount, int count, int padding =2)
{
	string str = "";
	
	for (int i = 0; i <= Mcount-count+padding; i++){
		str = str + " ";
	}
	
	return str;
}

void Print(vector<vector<int>> A, int n)
{
	string str;
	int Mcount = Give_num_of_space(n*n);
	int count;
	int w = 1;
	for(int i = 0; i < A.size(); i++){
		for(int j = 0; j < A[i].size(); j++){
//			A[i][j] = i*n + j + 1;
			A[i][j] = ++w;
			cout << A[i][j];
			count = Give_num_of_space(A[i][j]);
			str = Give_str_of_space(Mcount,count);
			cout << str;
		}
		cout << endl;
	}
}

void Solve(int n)
{
	vector<vector<int>> A;
	vector<int> B;
	int add = 0;
	
	for(int i = 0; i < n; i++){
		B = addMang_mot_chieu(add,n);
		A.push_back(B);
		add = add + n;
	}
	
	Print(A,n);
}

int main()
{
	int n;
	cin >> n;
	
	Solve(n);
}
