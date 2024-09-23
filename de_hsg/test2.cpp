#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<long>>> Weight(long j, vector<long> W, vector<vector<vector<long>>> Paths) {
    vector<vector<long>> Path;
    vector<long> T;
    vector<vector<long>> Previous;

    for (long i = 0; i < W.size(); i++){
        if (j - W[i] >= 0) {
            Previous = Paths[j - W[i]];
            if (j - W[i] == 0){
                Path.push_back({W[i]});
            } 
			else{
                for (long index = 0; index < Previous.size(); index++) {
    				vector<long> p = Previous[index];
  					p.push_back(W[i]);
	    			Path.push_back(p);
				}
            }
        }
    }

    Paths[j] = Path;
    return Paths;
}

void Solve(long n, vector<long> W) {
    vector<vector<vector<long>>> Paths(n+1);

    for (long j = 0; j <= n; j++) {
        Paths = Weight(j, W, Paths);
    }

    for (long i = 0; i < Paths[n].size(); i++) {
        for (long j = 0; j < Paths[n][i].size(); j++) {
            cout << Paths[n][i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    long n = 8;
    vector<long> W {1, 3, 5};
    Solve(n, W);

    return 0;
}

