#include <bits/stdc++.h>

using namespace std;

ifstream robot_inp;
ofstream robot_out;

void Create_A (vector<vector<long long >> &A, long n)
{
	vector <long long > T;
	
	long long input = 1;
	
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			T.push_back(input);
			input++;
		}
		A.push_back(T);
		T.clear();
	}	
}

void Take(vector<vector<long long>> &A)
{
	
}

void Ways (char c, long x, long y)
{
	if (c == 'E'){
		y++;
		Take()
	}
}

void Solve(long n, long x, long y, string str)
{
	long result = 0;
	
	vector<vector<int>> A;
	
	Create_A(A,n);
	
	result = A[x][y];
	
	for(int i = 0; i < str.length(); i++){
		Ways(str[i],x,y,A);
	}
}

int main()
{
	
	long n,x,y;
	string str;
	
	robot_inp.open("C:\\bt_c++\\de_hsg\\REWARD.INP");
	robot_out.open("C:\\bt_c++\\de_hsg\\REWARD.OUT");
	
	robot_inp >> n;
	robot_inp >> x;
	robot_inp >> y;
	robot_inp >> str;
	
}
