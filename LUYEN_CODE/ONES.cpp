		#include <iostream>
		
		using namespace std;
		
		long long C1_KT_uoc_ones(long long n, long long &ones)
		{
			while (ones * 10 + 1 <= n){
				if (n % ones == 0){
					return 1;
				}	
				
				ones = ones * 10 + 1;
			}
			
			return 0;
		}
		
		
		long long C2_kt_uoc_ones(long long n)
		{
			long long C1;
			long long hieu = n;
			long long ones = 11;
				C1 = C1_KT_uoc_ones(n,ones);
				if (C1 == 0){
					while (true){
		//				cout << ones << endl;
						if (hieu == 0){
							return 1;
						}
						if (hieu < 0){
							return 0;
						}
						hieu = hieu - ones;
						if (hieu - ones < 0 && ones >= 111){
							ones = ones / 10;
						}
						cout << hieu << endl;
					}
				}
				else{
					return 1;
				}
					
				
			
		}
		
		long long Solve (long long n)
		{
			long long C2,result;
			
			C2 = C2_kt_uoc_ones(n);
			
			if (C2 == 1){
				result = 1;
			}
			else{
				result = 0;
			}
			
			return result;
		}
		
		int main()
		{
			long long n,result;
			
			cin >> n;
			result = Solve(n);
			if (result == 1){
				cout << "YES";
			}
			else{
				cout << "NO";
			}
		}
