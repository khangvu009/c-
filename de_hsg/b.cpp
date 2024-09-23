#include <iostream>
#include <vector>

using namespace std;

void Create_new_element_of_Dp (vector<int> &Dp , int j)
{
	vector<int> W{2,3,5};
	
	for(int i = W.size()-1; i >= 0; i--){
		if (j - W[i] >= 0 && j-W[i] != 1){
			Dp.push_back(1+Dp[j-W[i]]);
			cout << "-- Dp[" << j << "] = " << Dp[j] << endl;
			break;
		}
	}
}

long Solve(long n)
{
	
	long tong;
	vector <int> Dp;
	
	Dp.push_back(0);
	Dp.push_back(0);
		
	for(int j = 2; j <= n; j++){
		Create_new_element_of_Dp(Dp,j);
	}
	
	tong = Dp[n];
	
	return tong;
}

int main()
{
	long n,result;
	
	cin >> n;
	
	result = Solve(n);
	
	cout << result;
}
