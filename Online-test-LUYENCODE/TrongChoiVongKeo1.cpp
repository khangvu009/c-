#include<bits/stdc++.h>

using namespace std;

struct Point {
    long left;
    long right;
};

vector<Point> A;

void Solve(long n, long m){
	vector<long> Dp(n+3,0);
	Point p;
	
	cout << endl << endl;
	for(Point &p: A){
		cout << "left = " << p.left <<  " right = " << p.right << endl;
		if(p.left <= p.right){
			Dp[p.left]++;
			Dp[p.right+1]--;
		}
		else{
			Dp[1]++;
			Dp[p.right+1]--;
			Dp[p.left]++;
			Dp[n+1]--;
		}
		for(long i = 1; i < Dp.size(); i++){
			cout << "       " << i << ": " << Dp[i] << endl;
		}
			cout << endl << endl;
	}
	
	cout << endl << endl;
	
	for(long i = 1; i < Dp.size(); i++){
		Dp[i] = Dp[i] + Dp[i-1];
	}
	
	for(long i = 1; i < Dp.size(); i++){
		cout << i << ": " << Dp[i] << endl;
	}
	cout << endl;
	cout << *max_element(Dp.begin(),Dp.end());
}

int main() {
    long n, m;
    Point p;
    cin >> n >> m;
    
    for (long i = 0; i < m; i++) {
        cin >> p.left >> p.right;
        A.push_back(p);
    }
    
    Solve(n,m);    
}

