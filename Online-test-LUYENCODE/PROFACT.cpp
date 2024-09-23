#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;


vector<long long> A;

bool Check(long long n){
	long long count = 0;
    long long type = 0;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (type == 0) {
                type = i;
                count++;
            } else {
                if (i == type) count++;
                else return false;
            }
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        if (type == 0) {
            type = n;
            count++;
        } else {
            if (n == type) count++;
            else return false;
        }
    }
    return count == 2;
}

void Solve(long long n){
	if(Check(n) || n == 2) out << "YES" << endl;
		else out << "NO" << endl;
}

int main(){
	long long n,input;
	
	inp.open("PROFACT.inp");
	out.open("PROFACT.out");
	
	inp >> n;
	
	for(long i = 0; i < n; i++){
		inp >> input;
		Solve(input);
	}
	
	
	inp.close();
	out.close();
}
