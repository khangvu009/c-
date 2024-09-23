#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

struct point{
	long s;
	long e;
};

vector<point> A;

long Sum(long n, long &temp, long & count1){
	long result = 0,count = 0;
	
	temp = 0;
	
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
//	cout << result;
	return result;
}

bool IsPrime(long n){
	if (n == 1) return false;
	if (n == 2) return true;
//	if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) return true;
//	if(n % 2 != 0 || n % 3 != 0 || n % 5 != 0 || n % 7 != 0) return false;
	for(long i = 2; i <= sqrt(n)+1; i++){
		if(n % i == 0) return false;
	}
	
	return true;
}

long Processing(point p){
	long start,end,count = 0,sum,temp,count1,dem,sum1,heso,len;
	
	if (p.s == 1){
		start = 1;
	}
	else{
		start = pow(10,p.s-1)+1;
	}
	end = pow(10,p.e)-1;
	
		
	sum = Sum(start,temp,count1);
	printf("-start=%i--sum1 = %i \n",start,sum);
	dem = 1;
	heso = 10;
	len = 0;
	cout << "start = " << start << " end = " << end << endl;
	for(long i = start; i <= end; i++){
		sum1 = Sum(i,temp,count1);
		printf("-%i-sum = %i --- %i --- heso=%i--len=%i \n",i,sum,sum1,heso,len);
		if(IsPrime(sum)){
			count++;
		}
		if ((i+1) % heso == 0) {
			heso= heso * 10;
			len++;
		}
//		printf("-sum = %i \n",sum);
		if (dem == 9) {
			dem = 0;
			sum = sum + 1 - 9*len;
		} else {
			sum ++;
			dem ++;
		}
	}
	
	return count;
}

void Solve(){
	long result;
	
	for(long i = 0; i < A.size()-1; i++){
		result  = Processing(A[i]);
		cout << result << endl;
	}
	result = Processing(A[A.size()-1]);
	cout << result;
	
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
