#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<long>>> T1;

void Print_T3 (vector<long> T3)
{
	cout << "--- T3 size = " << T3.size() << endl;
	
	for (int i = 0; i < T3.size(); i++){
		cout << "---" << T3[i] << " ";
	}
	cout << endl;
}

vector<vector<long>> NT2(vector<vector<long>> OT2, long long w, long previous)
{
	vector<vector<long>> T2;
	
	for (long i = 0; i < OT2.size(); i++){
		vector <long> T3;
		T3 = OT2[i];
		
		T3.push_back(w);
		Print_T3(T3);
		Print_T3(OT2[i]);
		T2.push_back(T3);

	}	
	return T2;
} 

vector<vector<long>> Amount_way (long long n, long long S, long long *Dp, long long *W, long long j)
{
	vector <vector<long>> OT2;
	vector <vector<long>> T2;
	long OT2_I,previous;
	
	for (long long i = 0; i < n; i++){
		if (j- W[i] >= 0){	
			Dp[j] = Dp[j] + (Dp[j- W[i]]);
			previous = j-W[i];
			
			if (previous < T1.size()){
				OT2 = NT2(T1[previous],W[i],previous); 
				cout << OT2.size() << endl;
				T2.insert(T2.begin(),OT2.begin(),OT2.end());
			}
		}
	}	
	
	return T2;	
}

void Print (vector<vector<vector<long>>> T1, long long S)
{
	long long i = S;
	for (long long j = 0; j < T1[i].size(); j++){
		for (long long k = 0; k < T1[i][j].size(); k++){
			if (T1[i][j][k] != 0){
				cout << T1[i][j][k] << " ";
			}
		}
		cout << endl;
	}
}
	
void Solve (long long n, long long S,long long *W, long long *Dp)
{
	vector<vector<long>> T2;
	vector<long> T3;
	
	T3.push_back(0);
	T2.push_back(T3);
	T1.push_back(T2);
	
	long long result,j;			
	for (j = 1; j <= S; j++){
		cout << "j = "  << j <<endl;
		T2 = Amount_way(n,S,Dp,W,j);
		T1.push_back(T2);
		T2.clear();
	}
	
	cout << Dp[S] << endl;
	Print(T1,S);
}
	
int main()
{
	long long n,S,result;
	
//	cin >> n;
//			
//	long long W[n];
//	
//	cin >> S;
//		
//	long long Dp[S];
//		
//	Dp[0] = 1;
//		
//	for (long long i = 0; i < n; i++){
//		cin >> W[i];
//	}

//	cin >> n;
	n = 3;
				
	long long W[n];
	
//	cin >> S;
	S = 6;
	
	long long Dp[S];
		
	Dp[0] = 1;
		
//	for (long i = 0; i < n; i++){
//		cin >> W[i];-
//	}
	W[0] = 1;
	W[1] = 3;
	W[2] = 5;
//	W[3] = 43;
		
	for (long long k = 1; k <= S; k++){
		Dp[k] = 0;
	}
			
	Solve(n,S,W,Dp);	
}

