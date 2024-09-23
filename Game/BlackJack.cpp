#include<bits/stdc++.h>

using namespace std;

int GetRandom(){
    int n = rand() % (13 - 1 + 1) + 1;
    return n;
}
int GetRandom1(){
    int n = rand() % (4 - 1 + 1) + 1;
    return n;
}

void CreateCard(long card, long nuoc){
	cout << "_______" << endl;
	cout << "|";
	if (card <= 10 && card > 1) cout << card;
	if (card == 11) cout << "J";
	if (card == 12) cout << "Q";
	if (card == 13 ) cout << "K";
	if (card == 1) cout << "A";
	if (nuoc == 1) cout << "+";
	if (nuoc == 2)  cout << "-";
	if (nuoc == 3) cout << "*";
	if (nuoc == 4) cout << "&";
	if (card != 10) cout << "   " << "|" << endl;
	if (card == 10) cout << "  " << "|" << endl;
	cout << "|" << "     " << "|" << endl;
	cout << "|" << "_____" << "|" << endl;           
}

void Processing(long card, long nuoc){
	if (card == 1) CreateCard(card,nuoc);
	else if (card == 2) CreateCard(card,nuoc);
	else if (card == 3) CreateCard(card,nuoc);
	else if (card == 4) CreateCard(card,nuoc);
	else if (card == 5) CreateCard(card,nuoc);
	else if (card == 6) CreateCard(card,nuoc);
	else if (card == 7) CreateCard(card,nuoc);
	else if (card == 8) CreateCard(card,nuoc);
	else if (card == 9) CreateCard(card,nuoc);
	else if (card == 10) CreateCard(card,nuoc);
	else if (card == 11) CreateCard(card,nuoc);
	else if (card == 12) CreateCard(card,nuoc);
	else if (card == 13) CreateCard(card,nuoc);
}

void BlackJack(){
	long card = GetRandom();
	long nuoc = GetRandom1();
	Processing(card,nuoc);	
	card = GetRandom();
	nuoc = GetRandom1();
	Processing(card,nuoc);
}

void Solve(){
	string str;
//	cin >> str;
	
	BlackJack();
//	if (str == "black jack");	
//	if (str = "baccarat")  Baccarat();
}

int main(){
	srand(time(NULL));
	Solve();
}
