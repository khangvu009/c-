#include<bits/stdc++.h>

using namespace std;

vector<vector<long>> A;

void Replace(string & str, long index , char temp1){
//	cout << "	index = " << index << " temp1 = " << temp1 << " str = " << str << endl;
	for(long i = 0; i < A[index].size(); i++){
		str[A[index][i]] = temp1;	
	}
}

void Swap(long index, char temp1){
	long index1 = (int)(temp1 - 'a');
	
//	cout << "	index = " << index << " temp1 = " << temp1 << " index1 = " << index1 << endl;
	
	A[index1].insert(A[index1].end(),A[index].begin(),A[index].end());
	A[index].clear();
}

void Solve(long cases, string &str, long &i) {
	long index;
    char temp,temp1;
    
    if (cases == 1) {
    	cout << "case 1" << endl;
        cin >> temp;
        str += temp;
        index = (int)(temp - 'a');
        cout << "	index = " << index << endl;
        cout << "		";
        A[index].push_back(i);
        i++;
        for(long j = 0; j < A[index].size(); j++){
        	cout << A[index][j] << " ";
		}
		cout << endl;
    } else if (cases == 2) {
    	cout << "case 2" << endl;
		cin >> temp >> temp1;
		index = (int)(temp - 'a');
		Replace(str,index,temp1);
		Swap(index,temp1);
	}
	
	cout << "	" << str << endl;
}


int main(){
	long n,cases,count = 0;
	string str = "";
	
	cin >> n;
	
	for(long i = 0; i < 26; i++){
		vector<long> Temp;
		A.push_back(Temp);
	}
	
	for(long i = 0; i < n; i++){
		cin >> cases;
		Solve(cases,str,count);
	}
	
	cout << str;
}
