#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

struct point{
	long s;
	long e;
};

vector<point> A;
map<int, bool> primeCache;
	    
long Sum(long n, long &temp, long & count1){
	long result;
	
	temp = 0;
	long count = 0;
	
	while(n > 0){
		result = result + (n % 10); 
//		temp = temp * 10 + (n % 10);
		n = n / 10;
		count++;
	}
	if (count1 != count){
		cout << "count = " << count << endl;
		count1 = count;
	}	
	
	return result;
}

bool IsPrime(long n){
	if (n == 1) return false;
	if (n == 2) return true;
	if(n == 2 || n  == 3 || n  == 5 || n ==7) return true;
	if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) return false;
	for(long i = 2; i <= sqrt(n)+1; i++){
		if(n % i == 0) return false;
	}
	
	return true;
}

void Init(long n) {
    // Populate the cache with prime numbers up to a certain limit
    int limit = n*9;
    printf(" - Init %i - limit= %i ",n,limit);
    for (int i = 0; i <= limit; ++i) {
    	primeCache[i] = false;
        if (IsPrime(i)) {
            primeCache[i] = true;
//            cout << i << " ";
            printf(" - %i ",i);
        }
    }
}

long Processing(point p){
	long start,end,count = 0,sum,temp,count1,dem;
	
	if (p.s == 1){
		start = 1;
	}
	else{
		start = pow(10,p.s-1)+1;
	}
	end = pow(10,p.e)-1;
	
	cout << "start = " << start << " end = " << end << endl;
	sum = Sum(start,temp,count1);
	dem = 1;
	for(long i = start; i <= end; i++){
		if (i % 1000000 == 0 ) cout << i << endl;
//		printf ("i = %i -- sum = %i -- dem = %i \n",i,sum,dem);
		if(IsPrime(sum)){
			count++;
		}
		if (dem ==9) {
			dem = 0;
			sum = sum + 1 - 9;
		} else {
			sum ++;
			dem ++;
		}

	}
	
	return count;
}

void Solve(){
	long result;

	for(long i = 0; i <= A.size()-1; i++){
		cout << i << "-------";
//		Init(A[i].e);
		result  = Processing(A[i]);
		cout << result << endl;
	}
//	result = Processing(A[A.size()-1]);
//	cout << result;
	
}

int main(){
	long q;
	point p;
	
	inp.open("C:\\bt_c++\\HSG-2023-2024-tp\\SDIGIT.INP");
	out.open("C:\\bt_c++\\HSG-2023-2024-tp\\SDIGIT.OUT");
	
	inp >> q;
	
	for(long i = 0; i < q; i++){
		inp >> p.s >> p.e;
		A.push_back(p);
	}
	
	
	Solve();
	
	inp.close();
	out.close();
}
