#include <iostream>
#include <string>

using namespace std;


long Solve(string A, string B)
{
	long count = 0;
	string substring = "";
	long len = A.length();
	long len1 = B.length();
	
	for(long i = 0; i < len-2; i++){
		substring = A.substr(i,len1);
		if (substring == B){
			count++;
		}
		substring = "";
	}	
	
	return count;
}

int main()
{
	long n;
	string A,B;
	
	
	cin >> A;
	cin >> B;
	
	cout << Solve(A,B);
}
