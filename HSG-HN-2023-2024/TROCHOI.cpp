#include<bits/stdc++.h>
#define ll long long

using namespace std;

ifstream inp;
ofstream out;

struct Stat{
	long subskill;
	long skill;
	long total;
};


vector<Stat> A;

long FindMaxSkill(long &temp){
	long max1 = 0;
	for(long i = 0; i < A.size(); i++){
		if(max1 <= A[i].subskill){
			max1 = A[i].subskill;
			temp = max(temp,A[i].skill);
		}
	}
	
	return max1;
}

void Solve(long max2,long m){
	long temp = 0;
	ll result = max2;
	long max1 = FindMaxSkill(temp);
	
	cout << max1 << endl;
	
	if(m > 1) result += (m-1) * max1 + temp;
	
	cout << result;
}

int main(){
	long n,m,max1 = 0;
	Stat st;
	
	inp.open("TROCHOI.INP");
	out.open("TROCHOI.OUT");
	
	inp >> n >> m;
	
	for(long i = 0; i < n; i++){
		inp >> st.subskill >> st.skill;
		st.total = st.skill + st.subskill;
		max1 = max(max1,st.total);
		A.push_back(st);
	}	
	
	Solve(max1,m);
	
	inp.close();
	out.close();
}
