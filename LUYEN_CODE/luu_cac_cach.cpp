#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<long> > > T1;

void printV(vector <long>T) {
	
	for (long k = 0; k < T.size(); k++){\
		cout << " " << T[k];
	}
	cout << endl;
}

void Tinh_T3(vector<vector <long>> pT2, long w, vector<vector <long>> &T2)
{
	vector<long> T3;
	vector<vector <long>> newT2;
	
//	cout << "Tinh T3: " << w << endl;
	
	if(pT2.empty()) {
//		T3.push_back(w);
//		T2.push_back(T3);
//		printV(T3);
	} else {
		for (long k = 0; k < pT2.size(); k++){
			T3 = pT2[k];
			T3.push_back(w);
			T2.push_back(T3);
//			printV(T3);
		}
	}
}
	
vector<vector<long>> Amount_way (long n, long S, long *Dp, long *W, long j)
{
	vector<long> T3;
	vector<vector<long>> T2;
	vector<vector<long>> pT2;
	long previous = 0;
	
//	cout << "Amount_way: " << j << endl;
		
	for (long i = 0; i < n; i++){		
		if (j- W[i] >= 0){
			
		
			Dp[j] = Dp[j] + (Dp[j- W[i]]);
			previous = j- W[i];
			
			if (T1.size() > previous) {
				pT2 = T1[j- W[i]];
			
//				cout << " ---  " << previous << endl;
				
				Tinh_T3(pT2,W[i],T2);
			}
		}
	}		
	
	return T2;
}
	
void Prlong (vector<vector<vector<long>>> T1, long S)
{
	long i = S;
//		for(long i = 0; i < T1.size(); i++){
			for(long j = 0; j < T1[i].size(); j++){
				for(long k = 0; k < T1 [i][j].size(); k++){
					if (T1[i][j][k] > 0)
					cout << T1[i][j][k] << " ";
				}
				cout << endl;
			}
//		}
}

void Solve (long n, long S,long *W, long *Dp)
{		
//	vector<vector<vector<long> > > T1;

	vector<vector<long>> T2;
	vector<long> T3;
	T3.push_back(0);
	T2.push_back(T3);
	T1.push_back(T2);
	
	for (long j = 1; j <= S; j++){
		T2.clear();
		T2 = Amount_way(n,S,Dp,W,j);
		T1.push_back(T2);
	}
	
	Prlong(T1,S);
		
	cout << Dp[S];
//	for (long k = 0; k <= S; k++){
//		cout << k << " " << Dp[k] << endl;
//	}
//	cout << endl;
}
	
int main()
{	
	long n,S,result;
	
//	cin >> n;
	n = 4;
				
	long W[n];
	
//	cin >> S;
	S = 120;
	
	long Dp[S];
		
	Dp[0] = 1;
		
//	for (long i = 0; i < n; i++){
//		cin >> W[i];-
//	}
	W[0] = 7;
	W[1] = 31;
	W[2] = 21;
	W[3] = 43;
		
	for (long k = 1; k <= S; k++){
		Dp[k] = 0;
	}
			
	Solve(n,S,W,Dp);	
}

