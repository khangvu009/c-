#include <bits/stdc++.h>

using namespace std;

ifstream vdl_inp;

struct P{
	int c;
	int d;
}; 

struct Path{
	vector<P> arrP;
	int len;
	P end;	
};

int A[100][100];
int minLen = 0;
vector<Path> Paths;
Path MinPa;

bool check (Path pa, P p)
{
	for (int i = 0; i < pa.arrP.size(); i++){
		if (pa.arrP[i].c == p.c && pa.arrP[i].d == p.d){
//			cout << " -- p.d = " << pa.arrP[i].d << " -- p.c = " << pa.arrP[i].c << endl;
			return false;
		}
	}
	
	return true;
}

vector<P> Walk(Path pa, int c, int d)
{
	P p;
	vector<P> Ps;
	
//	tren
	p.d = pa.end.d-1;
	p.c = pa.end.c;
	if (p.d >= 0){ 
		if (check(pa,p) == true){
//			cout << " tren: -- p.d = " << p.d << " -- p.c = " << p.c << endl;
			Ps.push_back(p);
		}
	}
	
//	duoi
	p.d = pa.end.d+1;
	p.c = pa.end.c;
	if (p.d < d){
		if (check(pa,p) == true){
//			cout << " duoi: -- p.d = " << p.d << " -- p.c = " << p.c << endl;
			Ps.push_back(p);
		}
	}
	
//	phai
	p.c = pa.end.c+1;
	p.d = pa.end.d;
		if (p.c < c){
			if (check(pa,p) == true){
//				cout << " phai: -- p.d = " << p.d << " -- p.c = " << p.c << endl;
				Ps.push_back(p);
			}
		}
		
//	trai
	p.c = pa.end.c-1;
	p.d = pa.end.d;
	if (p.c >= 0){
		if (check(pa,p) == true){
//			cout << " trai: -- p.d = " << p.d << " -- p.c = " << p.c << endl;
			Ps.push_back(p);
		}
	}
//	phai tren
	p.d = pa.end.d-1;
	p.c = pa.end.c+1;
	if (p.d >= 0 && p.c < c){
		if (check(pa,p) == true){
//			cout << " phai tren: -- p.d = " << p.d << " -- p.c = " << p.c << endl;
			Ps.push_back(p);
		}
	}
	
//	phai duoi
	p.d = pa.end.d+1;
	p.c = pa.end.c+1;
	if (p.d < d && p.c < c){
		if (check(pa,p) == true){
//			cout << " phai duoi: -- p.d = " << p.d << " -- p.c = " << p.c << endl;
			Ps.push_back(p);
		}
	}
	
//	trai tren
	p.d = pa.end.d-1;
	p.c = pa.end.c-1;
	if (p.d >= 0 && p.c >= 0){
		if (check(pa,p) == true){
//			cout << " trai tren: -- p.d = " << p.d << " -- p.c = " << p.c << endl;
			Ps.push_back(p);
		}
	}
	
//	trai duoi
	p.d = pa.end.d+1;
	p.c = pa.end.c-1;
	if (p.d < d && p.c >= 0){
		if (check(pa,p) == true){
//			cout << " trai duoi: -- p.d = " << p.d << " -- p.c = " << p.c << endl;
			Ps.push_back(p);
		}
	}
	
	return Ps;
}

void Loang(vector <P> Ps,Path pa, P endP)
{
	
	P p;
	Path Pn = pa;
	
	for (int i = 0; i < Ps.size(); i++){
		p.c = Ps[i].c;

		p.d = Ps[i].d;
		Pn.arrP.push_back(p);
		Pn.end = p;
		Pn.len += A[p.d][p.c];
		
//		cout << "-- EndD = " << EndD << " -- EndC = " << EndC << " -- d = " << p.d << " -- c = " << p.c << " -- A[p.d][p.c] = " << A[p.d][p.c] << " -- Pn.len = " << Pn.len << endl;
		if (p.c == endP.c && p.d == endP.d){
			if (minLen == 0 || minLen > Pn.len){
				MinPa = Pn;
				minLen = Pn.len;
			}
		}
		Paths.push_back(Pn);
		Pn = pa;	
	}	
}

void Solve (int x, int y, P startP, P endP)
{
	int index = 0;
	vector<P> Ps;
	Path pa;
	P p;
	p = startP;
	pa.arrP.push_back(p);
	pa.end = p;
	pa.len = A[p.d][p.c];
	Paths.push_back(pa);
	
	while (index < Paths.size()){
//		cout << " --index = " << index << endl;
		pa = Paths[index];
		Ps = Walk(pa,x,y);
		Loang(Ps,pa,endP);
		index++;
	}
	cout << minLen << endl;
	int len = 0;
	
	for (int i = 0; i < MinPa.arrP.size(); i++){
		P p1;
		p1 = MinPa.arrP[i];
		len = len + A[p1.d][p1.c];
		cout << MinPa.arrP[i].d + 1 << "," << MinPa.arrP[i].c + 1 << " len = " << len <<endl;
	}
}

int main()
{
//	x cot
//	y dong
	int y,x,StartX,StartY,EndX,EndY;
	P startP, endP;
	vdl_inp.open("C:\\bt_c++\\de_hsg\\VDL.INP");
	
	vdl_inp >> y;
	vdl_inp >> x;
	vdl_inp >> startP.c;
	vdl_inp >> startP.d;
	vdl_inp >> endP.c;
	vdl_inp >> endP.d;
	
	
	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			vdl_inp >> A[i][j]; 
		}
	}
	
	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			cout << A[i][j] << " "; 
		}
		cout << endl;
	}
	
	startP.c--;
	startP.d--;
	endP.c--; 
	endP.d--; 
	Solve(x,y,startP,endP);		
	vdl_inp.close();
}
