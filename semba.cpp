#include <iostream>
#include <vector>

using namespace std;

int n = 0;

void wypisz(vector <int>& t){
	for(int i=0; i<t.size(); i++){
		cout << t[i] << " ";
	}
	cout << "\n";
}

void dodawanie_elementow(vector <int>& tab);
void inkrementacja_elementow(vector <int>& tab);

int main() {
	cout << "Program generuje wszystkie k-elementowe kombinacje zbioru n-elementowego dla k={1,...,n} zgodnie z algorytmem Semby." << endl;
	cout << "Podaj liczbe elementow w zbiorze n: ";
	cin >> n;
	while(!n){
		cout << "Niepoprawne dane. Liczba elementow musi nalezec do zbioru liczb naturalnych. Sprobuj jeszcze raz." << endl;
		cout << "Podaj liczbe elementow w zbiorze n: ";
		cin >> n;
	}
	
	vector <int> tab;
	tab.push_back(1);
	wypisz(tab);
	dodawanie_elementow(tab);
	
	return 0;
}



void dodawanie_elementow(vector <int>& tab){
	while(tab.back() < n){
		tab.push_back(tab.back() + 1);
		wypisz(tab);
	}
	inkrementacja_elementow(tab);
}

void inkrementacja_elementow(vector <int>& tab){
	if(!tab.empty()){
		if(tab.front() <= n){
			tab.pop_back();
			tab.back()++;
			wypisz(tab);
			dodawanie_elementow(tab);
		}
		else{
			cout << "WYPISANE!" << endl;
		}
	}
}
