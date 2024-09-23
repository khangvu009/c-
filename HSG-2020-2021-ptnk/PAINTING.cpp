#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;


struct P{
	long x;
	long y;
};

vector<P> Points;

void Solve(long n){
	long median,distance,distance1,minimum;
	if (n % 2 == 0) median = n / 2;
	else median = n / 2 + 1;
	
	
	for(long i = 0; i < Points.size()-1; i++){
		if(Points[i].x <= median) distance = Points[i].x;
		if (Points[i].x > median ) distance = (n - median) + 1;
		if(Points[i].y <= median) distance1 = Points[i].y;
		if (Points[i].y > median ) distance1 = (n- median) + 1;
		minimum = min(distance, distance1) % 3;
		if(minimum == 0) cout << "YELLOW" << endl;
		if (minimum == 1) cout << "RED" << endl;
		if(minimum == 2) cout << "BLUE" << endl;
	}
	
	if(Points[Points.size()-1].x <= median) distance = Points[Points.size()-1].x;
	if (Points[Points.size()-1].x > median ) distance = (n - median + 1);
	if(Points[Points.size()-1].y <= median) distance1 = Points[Points.size()-1].y;
	if (Points[Points.size()-1].y > median ) distance1 = (n - median + 1);
	minimum = min(distance, distance1);
	if(minimum == 0) cout << "YELLOW" << endl;
	if (minimum == 1) cout << "BLUE" << endl;
	if(minimum == 2) cout << "RED" << endl;
}

int main(){
	long n,k;
	P p;
	
	inp.open("C:\\bt_c++\\HSG-2020-2021-ptnk\\PAINTING.INP");
	out.open("C:\\bt_c++\\HSG-2020-2021-ptnk\\PAINTING.OUT");
	
	inp >> n >> k;
	
	for(long i = 0; i <= k; i++){
		inp >> p.x;
		inp >> p.y;
		Points.push_back(p);
	}
	
	Solve(n);
	
	inp.close();
	out.close();
}
