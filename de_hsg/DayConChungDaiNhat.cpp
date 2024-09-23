#include<bits/stdc++.h>

using namespace std;

long LCSLength(string str1, string str2) {
	str1 = "0" + str1;
	str2 = "0" + str2;
	
    long m = str1.length();
    long n = str2.length();

    vector<vector<int>> A;
	vector<vector<string> >LCS;
	
    for (int i = 0; i < m; i++) {
        vector<int> row;
        vector<string> rowS;
        for (int j = 0; j < n; j++) {
            row.push_back(0);
            rowS.push_back("*");
        }
        A.push_back(row);
        LCS.push_back(rowS);
    }
	
    
    for (long i = 1; i < m; i++) {
        for (long j = 1; j < n; j++) {
            if (str1[i] == str2[j]) {
//            	cout << " -- i = " << i << " -- j = " << j << " --str = " << str1[i] << endl; 
                A[i][j] = A[i - 1][j - 1] + 1;
                LCS[i][j] = LCS[i - 1][j - 1] + str1[i];
            } else {
                A[i][j] = max(A[i][j - 1], A[i - 1][j]);
                if (A[i][j - 1] > A[ i - 1 ][j]){
                	LCS[i][j] = LCS[i][ j - 1];
				}
				else{
					LCS[i][j] = LCS[i - 1][j];
				}
            }
        }
    }
    
    for (long i = 0; i < m; i++) {
        for (long j = 0; j < n; j++) {
        	cout << A[i][j] << " ";
        }
        cout << endl;
    }
	for (long i = 0; i < m; i++) {
        for (long j = 0; j < n; j++) {
        	cout << LCS[i][j] << " ";
        }
        cout << endl;
    }
    
    return A[m-1][n-1];
    
    
}

int main() {
    string str1 = "ABCDEFGHIJKLMNOPQR";
    string str2 = "KLMNOPQRSTUVWXYZ";

    long result = LCSLength(str1, str2);

    cout << result << endl;
}
