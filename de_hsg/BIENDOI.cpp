#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Cut_column (vector<vector<int>> &T, int n)
{
	for(int i = 0; i < T.size(); i++){
		T[i].erase(T[i].begin()+n);
	}
}

bool Check_2l(vector<vector<int>> T,vector<int> &F, vector<int> &Y, int n)
{
	bool result = true;
	
	F = T[0];
	Y = T[n];
	
	for (int i = 0; i < F.size(); i++){
		for(int j = 0; j < Y.size(); j++){
			if(F[i] != Y[j]){
				result = false;
				if (j == Y.size()-1){
					Cut_column(T,j);
				}
			}
			else{
				result = true;
				break;
			}
		}
		Cut_column(T,j);
	}
	
	for (int i = 0; i < Y.size(); i++){
		for(int j = 0; j < F.size(); j++){
			if(F[i] != Y[j]){
				result = false;
				if (j == Y.size()-1){
					Cut_column(T,j);
				}
			}
			else{
				result = true;
				break;
			}
		}
		Cut_column(T,j);
	}	
	
	return result;
}

void check(vector<vector<int>> &T)
{
	
}

vector<vector<int>> Bien_doi(vector<vector<int>> &T)
{
	vector<int> F;
	vector<int> Y;
	bool result;
	
	int i = 1;
	
	while(true){
		result = Check_2l(T,F,Y,i);
		if (result == false){
			i++;
		}
		check()
	}
}

int Solve(vector<vector<int>> A, vector<int> &B)
{
	vector<vector<int>> T = A;
	
	Bien_doi(T);
}

int main()
{
	vector<vector<int>> A;
	vector<int> B;
	vector<int> T;
	int m,n,temp;
	
	ifstream bien_doi_inp;
	ofstream bien_doi_out;
	bien_doi_inp.open("C:\\bt_c++\\de_hsg\\BIENDOI.INP");
	bien_doi_out.open("C:\\bt_c++\\de_hsg\\BIENDOI.OUT");
	
	bien_doi_inp >> n;
	bien_doi_inp >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			bien_doi_inp >> temp;
			T.push_back(temp);
		}
		A.push_back(T);
		T.clear();
	}
	
	Solve(A,B);
}

