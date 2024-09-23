	#include<bits/stdc++.h>
	
	using namespace std;
	
	ifstream inp;
	ofstream out;
	
	vector<long> A;
	
	
	bool Check(long n, long k) {
		if (n < k ) return false;
		
    	while (n > 0) {
	        if (n % 10 != 1 && n % 10 != 2) return false;
	        n /= 10;
	        k--;
	        if (k == 0) break;
	    }
	   	 return true;
	}
	
	void Solve(long k){
		long long condition = pow(10,k),backdigits = 1,count = 0;
		
		while(true){
			backdigits = (backdigits * 2) % condition;
	//		cout << backdigits << endl;
			count++;
			if (count % 1000000 == 0 ) cout << "count = " << count << endl;
			if(Check(backdigits,k)) break;
		}
		
		cout << backdigits << endl;
		cout << count;
	}
	
	int main(){	
		long k;
		
		inp.open("C:\\bt_c++\\HSG-2009-2010\\CHUSO.INP");
		out.open("C:\\bt_c++\\HSG-2009-2010\\CHUSO.OUT");
		
		
		inp >> k;
		
		Solve(k);
		
		inp.close();
		out.close();
	}
