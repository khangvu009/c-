#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

long Processing(){
	bool flag = true;
	long i = 0;
	long count = 1;
	long max = 0;
	long temp,temp1;
	
	while(i < A.size()-1){
		if (i+1 < A.size()){
			if(A[i]== A[i+1]){
				count++;
				i++;
			}
			else if (flag && A[i] != A[i+1]){
				count++;
//				cout << A[i] << " " << A[i+1] << " count = " << count << endl;
				flag = false;
				temp1 = A[i+1];
				A[i+1] = A[i];
				temp = i+1;
				i++;
			}
			else{
				if (max < count){
					max = count;
				}	
				else{
//					ko can xu li 
				}
				cout << "count = " << count;
				count = 1;
				i = temp;
				cout << " i = " << i << endl;
				flag = true;
				A[i] = temp1;
			}
		}
		else{
//			ko can xu li
		}
		cout << "i = " << i << endl;
	}
	return max;
}

void Solve(){
	long a = Processing();
	reverse(A.begin(),A.end());
	long b = Processing();
	if (a < b){
		a = b;
	}
	cout << a;
}

int main(){
	long n,input;
	
	inp.open("C:\\bt_c++\\HSG-2017-2018-ptnk\\LIGHTS.INP");
	out.open("C:\\bt_c++\\HSG-2017-2018-ptnk\\LIGHTS.OUT");
	
	inp >> n;
	
	for(long i = 1; i <= n; i++){
		inp >> input;
		A.push_back(input);
	}
	
	for(long i = 0; i < A.size(); i++){
		cout << A[i] << " ";
	}
	cout << endl;
	
	Solve();
	
	inp.close();
	out.close();
}
