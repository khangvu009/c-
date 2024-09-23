#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 100;

int Tim_max (int *A, int num_element)
{
	int result = 0;
	
	for (int i = 0; i < num_element; i++){
		if (i % 2 == 0 && result < A[i]){
			result = A[i];
		}
	}
	cout << result << endl;
	return result;
}

int Tim_min (int *A, int num_element)
{
	int result = INT_MAX;
	
	for (int i = 0; i < num_element; i++ ){
		if (i % 2 != 0 && result > A[i]){
			result = A[i];
		}
	}
	cout << result << endl;
	return result;
}

int Solve (int *A, int m, int num_element)
{
	int max,min,result;
	
	max = Tim_max(A,num_element);
	min = Tim_min(A,num_element);
	return result = max + (abs(max - min)) + (m - min);
}

int main ()
{
	int num_element = 0;
	int n,m,result;
	int A[MAX_SIZE];
	
	ifstream giao_hang_inp;
	giao_hang_inp.open("C:\\bt_c++\\LUYEN_CODE\\GIAOHANG.INP");
	ofstream giao_hang_out;
	giao_hang_out.open("C:\\bt_c++\\LUYEN_CODE\\GIAOHANG.OUT");
	
	giao_hang_inp >> n;
	giao_hang_inp >> m;
	
	while (num_element < MAX_SIZE &&  giao_hang_inp >> A[num_element] ){
		num_element++;
	}
	
	result = Solve(A,m,num_element);
	cout << result;
	giao_hang_out << result;
	
	giao_hang_inp.close();	
	giao_hang_out.close();
}
