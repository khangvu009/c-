#include <iostream>
#include <fstream>

using namespace std;
const int MAX_SIZE = 300000;

int ghep (int n, int *A, char *C, int m)
{
	int count = 0;
	long long  tong = 0;
	
	for (int i = 0; i < n; i++){
		cout << A[i] << " ";
		if (A[i] == 1 ){
			tong = (tong *10) + (int)C[i] - '0';	
		}
	}
	tong = tong * 10 + m;
	if (tong % 4 == 0){
		count = 1;
	}
	cout << " : " << count;
	cout << "" << endl;
	cout << tong << endl;
	return count;
}

int I_count (int *A, int m, int dem, char *C)
{
	int i,j,tam,kq,count;
    long long tong;
    
	for (int i =0; i <= dem-1; i++){
		A[i] = 0;
	}
	
	i = dem-1;
	tam = 0;
	count = 0;
	
	while (true){
		j = i;
		A[i]++;
		while(true){
			if (j-1 < -1){
				tam = 1;
				break;
			}	
			if(A[j] > 1){
				A[j] = 0;
				j--;
				A[j]++;
			}
			else{
				break;
			}
		}
		if (tam == 1){
			break;
		}
		tong = ghep(dem,A,C,m);
		count = count + tong;
	}
}

int main() {
    int num_element = 0;
    char C[MAX_SIZE];
    int A[MAX_SIZE],m,kq,n;
    
    ifstream xau_inp;
    xau_inp.open("C:\\bt_c++\\2018-2019\\XAU.INP");
    ofstream xau_out;
    xau_out.open("C:\\bt_c++\\2018-2019\\XAU.OUT");

    while (num_element < MAX_SIZE && xau_inp >> C[num_element]) {
        num_element++;
    }
	
	for (int i = 0; i < num_element; i++){
		m = (int)C[i] - '0';    
		if (m % 2 == 0){
			kq = I_count (A,m,i,C);
		}
	}
//	xau_out << count;
	
    xau_inp.close();
    xau_out.close();
}
