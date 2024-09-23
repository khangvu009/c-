#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

struct Book{
	long h;
	long w;
	long count = 1;
};

vector<Book> Shelf;

void Sort(){
	Book bk;
	
	for(long i = 0; i < Shelf.size()-1; i++){
		for(long j = i + 1; j < Shelf.size(); j++){
			if(Shelf[i].w > Shelf[j].w){
				bk = Shelf[i];
				Shelf[i] = Shelf[j];
				Shelf[j] = bk;
			}
		}
	}	
}

void Solve(){
	long result = 0;
	
	Sort();
	
	for(long i = 1; i < Shelf.size(); i++){
		for(long j = 0; j < i; j++){
			if(Shelf[j].h < Shelf[i].h && Shelf[j].w < Shelf[i].w){
				Shelf[i].count = max(Shelf[i].count,Shelf[j].count+1);
			}
		}
		result = max(result,Shelf[i].count);
	}
	
	out << result;
}

int main(){
	long n;
	Book bk;
	
	inp.open("ChonSach.inp");
	out.open("ChonSach.out");
	
	inp >> n;
	
	for(long i = 0; i < n; i++){
		inp >> bk.h >> bk.w;
		Shelf.push_back(bk);
	}
	
	Solve();
	
	inp.close();
	out.close();
}
