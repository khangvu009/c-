#include<bits/stdc++.h>

using namespace std;

struct Point{
	char rby;
	char rwi;
};

void Solve(long cases, string &str, Point &cur, Point &pre) {
	Point temp1;
    char temp;
    
    if (cases == 1) {
//    	cout << "case: 1" << endl;
        cin >> temp;
        if (cur.rby != '\0'){
//            replace(str.begin(), str.end(), cur.rby,cur.rwi);
        }
        cur.rby = '\0';
        cur.rwi = '\0';
        pre = cur;
        str += temp;
    } else if (cases == 2) {
//    	cout << "case: 2" << endl;
    	pre = cur;
        cin >> cur.rby >> cur.rwi;
//        cout << pre.rby << " " << pre.rwi << "				" << cur.rby << " " << cur.rwi << endl;
        if(pre.rwi != cur.rby && pre.rby != '\0'){
//        	cout << "	replace " << endl;
//        	replace(str.begin(), str.end(), cur.rby,cur.rwi);
	        pre = cur;
        	cur.rby = '\0';
    	    cur.rwi = '\0';
		}
		else{
	        if (pre.rby != '\0' && pre.rwi == cur.rby) {
//	        	cout << "	AB BC -> AC " << endl;
	            cur.rby = pre.rby;
	        }
	    }
    }
//    cout << "	str = " << str << endl;
}


int main(){
	long n,cases;
	Point cur, pre;
	string str = "";
	
	cur.rby = '\0';
    cur.rwi = '\0';
    pre = cur;
	
	cin >> n;
	
	for(long i = 0; i < n; i++){
		cin >> cases;
		Solve(cases,str,cur,pre);
	}
	
	cout << str;
}
