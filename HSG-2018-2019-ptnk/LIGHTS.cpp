#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

void FixCount(long &count, long index, long condition){
	for(long i = index; i < A.size(); i++){
		if(A[i] != condition){
			break;
		}
		count++;
	}
}

long CountBulb(long &index){
	long count = 0;
	bool flag = true, flag1 = true;
	
	while (index < A.size() -1 && (flag)){
		if(A[index] != A[index+1]){
			flag = false;
			if (A[index+2] == A[index]){
				count++;
				FixCount(count,index+2,A[index]);
			}
			else{
				count++;
			}
		}
		else{
//			xu li roi 
		}
		count++;
		index++;
	}
	cout << "count = " << count << endl;
	return count;
}

void Solve(){
	long index = 0,count,max = 0;
	
	while(index < A.size() -1){
		count = CountBulb(index);
		if (max < count){
			max = count;
		}
		else{
//			xu li roi 
		}
	}
	cout << max;
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
