#include<bits/stdc++.h>

using namespace std;

void PrintMonopolyBoard(const vector<string>& A, int rows, int cols) {
    int index = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                cout << setw(4) << A[index];
                index++;
            } else {
                cout << setw(4) << " ";
            }
        }
        cout << endl;
    }
}

void Solve(){
	vector<string> A{"Bd","A","Kv","B","Ttt","Bx1","C","Ch","D","E","Tt","F","Ct1","G","H","Bx2","I","Kv","K","L","Bdx","M","Ch","N","O","Bx3","P","Q","Ct2","R","Vt","S","T","Kv","U","Bx4","Ch","V","Tdb","W"};
    int rows = 4;
    int cols = 11;	
    PrintMonopolyBoard(A, rows, cols);
}

int main() {
	Solve();
}

