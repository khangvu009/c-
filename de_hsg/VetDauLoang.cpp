#include <bits/stdc++.h>

using namespace std;


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

ifstream vdl_inp;

bool check (Path pa, P p)
{	
	for (int i = 0; i < pa.arrP.size(); i++){
		if (pa.arrP[i].c == p.c && pa.arrP[i].d == p.d){
			return false;
		}
	}
	
	return true;
}

vector<P> Walk (Path pa,int c,int d)
{
	vector<P> Ps;
	P p;
	
	//	phai 
	p.c = pa.end.c + 1;
	p.d = pa.end.d;
		
	if (p.c < c){
		if (check(pa,p) == true){
			Ps.push_back(p);
		}
	}
	
	//	trai 
	p.c = pa.end.c - 1;
	p.d = pa.end.d;
	
	if (p.c >= 0){
		if (check(pa,p) == true){
			Ps.push_back(p);
		}
	}
	
	// 	tren
	p.c = pa.end.c;
	p.d = pa.end.d - 1;
	if (p.d >= 0){
		if (check(pa,p) == true){
			Ps.push_back(p);
		}
	}
	
	//	duoi
	p.c = pa.end.c;
	p.d = pa.end.d + 1;
	if (p.d < d){
		if (check(pa,p) == true){
			Ps.push_back(p);
		}
	}
	
	// phai duoi
	p.c = pa.end.c + 1;
	p.d = pa.end.d + 1;
	if (p.d < d && p.c < c){
		if (check(pa,p) == true){
			Ps.push_back(p);
		}
	}
	
	// phai tren
	p.c = pa.end.c + 1;
	p.d = pa.end.d - 1 ;
	if (p.d >= 0 && p.c < c){
		if (check(pa,p) == true){
			Ps.push_back(p);
		}
	}
	
	// trai duoi
	p.c = pa.end.c - 1;
	p.d = pa.end.d + 1;
	if (p.d < d && p.c >= 0){
		if (check(pa,p) == true){
			Ps.push_back(p);
		}
	}
	
	// trai tren
	p.c = pa.end.c - 1;
	p.d = pa.end.d - 1;
	if (p.d >= 0 && p.c >= 0){
		if (check(pa,p) == true){
			Ps.push_back(p);
		}
	}
	
	for (int i = 0; i < Ps.size(); i++){
		cout << Ps[i].d << " " <<  Ps[i].c << endl;
	}
	return Ps;
}



void Solve (int StartC, int StartD, int c, int d, int EndC, int EndD)
{
	vector<Path> Paths;
	vector <P> Ps;
	Path pa;
	P p;
	int index = 0;
	
	p.c = StartC;
	p.d = StartD;
	pa.arrP.push_back(p);
	pa.len = A[p.d][p.c];
	pa.end = p;
	Paths.push_back(pa);
	
	while (index < Paths.size()){
		pa = Paths[index];
		Ps = Walk(pa,c,d);
//		Loang(pa,&Paths,Ps);
		index++;
	}          
	
}

int main()
{
	int d,c,StartC,StartD,EndC,EndD;
	
	vdl_inp.open("C:\\bt_c++\\de_hsg\\VDL.INP");
	
	vdl_inp >> d;
	vdl_inp >> c;
	vdl_inp >> StartC;
	vdl_inp >> StartD;
	vdl_inp >> EndC;
	vdl_inp >> EndD;
	
	for (int i = 0; i < d; i++){
		for (int j = 0; j < c; j++){
			vdl_inp >> A[i][j]; 
		}
	}
	
	Solve (StartC,StartD,c,d,EndC,EndD);
		
	vdl_inp.close();
}


//	Path.arrP.push_back(StartC);
//	Path.arrP.push_back(StartD);
