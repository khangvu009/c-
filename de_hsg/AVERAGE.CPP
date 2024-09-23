#include<bits/stdc++.h>

using namespace std;

ifstream average_inp;
ofstream average_out;

bool Check (long sum , long len, long divisor)
{
	if (sum / len == divisor){
		return true;
	}
	
	
	
	return false;
}

long Solve (long k, long n, vector<long> A)
{
	long tam = 0;
	long max = 0;
	
	for (long i = 0; i < A.size()-1; i++){
		long sum = A[i];
		for (long j = i+1; j < A.size(); j++){
			sum = sum + A[j];
			if (Check(sum,j-i+1,k) == true){
				tam = j-i+1;
				if (max <= tam){
					max = tam;
				} 
			}
		}
	}
	
	return max;
}

int main()
{
	long n,k,input,result;
	vector<long> A;
	
	average_inp.open("C:\\bt_c++\\de_hsg\\AVERAGE.INP");
	average_out.open("C:\\bt_c++\\de_hsg\\AVERAGE.OUT");
	
	average_inp >> n;
	average_inp >> k;
	
	for (long i = 0; i < n; i++){
		average_inp >> input;
		A.push_back(input);
	}
	
	result = Solve(k,n,A);
	average_out << result;
	
	average_inp.close();
	average_out.close();
}
