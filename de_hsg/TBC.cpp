#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long Multiple (long n, long m)
{
	long nhan = n*m;
	
	return nhan;	
}

vector<long> Solve(vector<long> B)
{
	vector <long> A;
	
	long multiple;
	long tong = 0;
	
	for (long i = 0; i < B.size(); i++){
		multiple = Multiple(i+1,B[i]);
		A.push_back(multiple-tong);
		tong = tong + A[i];		
	}	
	
	return A;
} 

int main()
{
	vector <long> A;
	vector <long> B;
	long n,chuyen;
	long num_element = 0;
	
	ifstream tbc_inp;
	tbc_inp.open("C:\\bt_c++\\de_hsg\\TBC.INP");
	ofstream tbc_out;
	tbc_out.open("C:\\bt_c++\\de_hsg\\TBC.OUT");
	
	tbc_inp >> n;
	
	while (num_element < n && tbc_inp >> chuyen){
		B.push_back(chuyen);
		num_element++;
	}
	
	A = Solve(B);
	
	for (long i = 0; i < A.size(); i++){
		tbc_out << A[i] << " ";
	}
}
