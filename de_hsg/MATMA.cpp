#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream mat_ma_inp;
ofstream mat_ma_out;

	
void Sort(vector<vector<char>> A)
{
	char temp;
	
	for(int i = 0; i < A.size(); i++){
		for(int j = 0;  j < A[i].size()-1; j++){
			for(int k = j+1; k < A[i].size(); k++){
				if (A[i][j] <= A[i][k]){
					A[i][j] = A[i][k];
					temp = A[i][j];
					A[i][k] = temp;
				}
			}
		}
	}	
}

vector <int> Bo_dem(vector<vector<char>> A, int x)
{
	vector<int> B;
	int len,lenR;
	
	for (int i = 0; i < A.size(); i++){
		B.push_back(0);
	}
	
	len = A.size()-1;
	lenR = A[len].size()-1;
	
	for (int k = 2; k <= x; k++){	
		B[len]++;
		while(B[len] == lenR+1){
			B[len] = 0;
			if(len-1 >= 0){
				B[len-1]++;
			}
			else{
				break;
			}
			len--;
			lenR = A[len].size()-1;
		}
	}
	
	return B;
	
}

vector<char> Get_result (vector<vector<char>> A, vector<int> B)
{
	vector<char> C;
	
	for(int i = 0; i < A.size(); i++){
		C.push_back(A[i][B[i]]);
	}
	
	for(int i = 0; i < B.size(); i++){
	}
	
	return C;
}

void Print(string str, vector<char> C)
{
	int sl = 0;
	
	
	for(int i = 0; i < str.length(); i++){
		if (str[i] == '#'){
			str[i] = C[sl];
			sl++;
		}
	}	
	cout << str;
	mat_ma_out << str;
	
}

void Solve(string str, vector<vector<char>> A, int x)
{
	vector<int> B;
	vector<char> C;
	Sort(A);
	B = Bo_dem(A,x);
	C = Get_result(A,B);
	Print(str,C);
}

int main()
{
	vector<vector<char>> A;
	vector<char> T;
	
	mat_ma_inp.open("C:\\bt_c++\\de_hsg\\MATMA.INP");
	mat_ma_out.open("C:\\bt_c++\\de_hsg\\MATMA.OUT");
	
	int n,k,m,x;
	string str;
	char input;
	
	mat_ma_inp >> n;
	mat_ma_inp >> k;
	mat_ma_inp >> m;
	mat_ma_inp >> x;
	
	mat_ma_inp >> str;
	
	for(int i = 0; i <= m; i++){
		for(int j = 0; j < k; j++){
			mat_ma_inp >> input;
			T.push_back(input);
		}
		A.push_back(T);
		T.clear();
	}
	
	Solve(str,A,x);
	
	mat_ma_inp.close();
	mat_ma_out.close();
	
}
