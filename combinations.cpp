#include <iostream>
#include <fstream>

using namespace std;

int n,k;
fstream plik;

void wypisz_LEX(int *t, bool f, int w){
	if(w == 1){
		if(f == false){
			plik.open("kombinacje_bez_powt.txt", ios::out|ios::app);
		}
		else{
			plik.open("kombinacje_bez_powt.txt", ios::out);
		}
	}
	else if(w == 2){
		if(f == false){
			plik.open("kombinacje_z_powt.txt", ios::out|ios::app);
		}
		else{
			plik.open("kombinacje_z_powt.txt", ios::out);
		}
	}


	for(int i=0; i<k; i++){
		cout << t[i] << " ";
		plik << t[i] << " ";	
	}
	cout << '\n';
	plik << '\n';
	plik.close();
}

void kombinacje_bez_powt_LEX(int n, int k, int wybor){
		int *tab = new int[k];
		bool flaga_start = true;

		for(int i=0; i<k; i++){
			tab[i] = i+1;
		}
		if(k < n){
			int p = k - 1;
			while(p>=0){
				wypisz_LEX(tab, flaga_start, wybor);
				flaga_start = false;
				if(tab[k - 1] == n){
					p--;	
				}
				else{
					p = k - 1;	
				}
				if(p >= 0){
					for(int a = k-1; a >= p; a--){
						tab[a] = tab[p] + a - p + 1;
					} 
				}
			}
		}
		else{
			wypisz_LEX(tab, flaga_start, wybor);
		}

		delete[] tab;
}

void kombinacje_z_powt_LEX(int n, int k, int wybor){
		int *tab = new int[k];
		bool flaga_start = true;

		for(int i=0; i<k; i++){
			tab[i] = 1;
		}
		int p = k - 1;
		while(p>=0){
			wypisz_LEX(tab, flaga_start, wybor);
			flaga_start = false;
			if(tab[k - 1]==n){
				p--;
				tab[p] = tab[p] + 1;
				for(int a = k - 1; a > p; a--){
					tab[a] = tab[p];
				} 	
			}
			else{
				p = k - 1;
				if(p>=0){
					for(int a=k; a>=p; a--){
						tab[a] = tab[p] + a - p + 1;
					} 
				}
			}
		}
		delete[] tab;
}

int main() {
	int wybor = 0;
	cout << "Program generuje k-elementowe podzbiory kombinacji zbioru n-elementowego w porzadku leksykograficznym." << endl;
	cout << "Podaj liczbe n dlugosci zbioru: ";
	cin >> n;
	cout << "\nPodaj liczbe k dlugosci ciagu podzbiorow n-elementowych: ";
	cin >> k;
	cout << endl;
	while(n<k){
		cout << "Niepoprawne dane. Wprowadz jeszcze raz.";
		cout << "Podaj liczbe n dlugosci zbioru: ";
		cin >> n;
		cout << "\nPodaj liczbe k dlugosci ciagu podzbiorow n-elementowych: ";
		cin >> k;
		cout << endl;
	}
	cout << "Wybierz rodzaj generowanych obiektow:\n\t1 dla kombinacji bez powtorzen\n\t2 dla kombinacji z powtorzeniami" << endl;
	cout << "Twoj wybor: ";
	cin >> wybor;
	while(wybor != 1 && wybor != 2){
		cout << "Niepoprawne dane wyboru. Wybierz jeszcze raz." << endl;
		cout << "Wybierz rodzaj generowanych obiektow:\n\t1 dla kombinacji bez powtorzen\n\t2 dla kombinacji z powtorzeniami" << endl;
		cout << "Twoj wybor: ";
		cin >> wybor;
	}
	if(wybor == 1){
		cout << "\tGeneruje kombinacje bez powtorzen...\n" << endl;
		kombinacje_bez_powt_LEX(n,k, wybor);
		cout << "\nWygenerowane wyniki zapisano do pliku: kombinacje_bez_powt.txt\n" << endl;
	}
	else if(wybor == 2){
		cout << "\tGeneruje kombinacje z powtorzeniami...\n" << endl;
		kombinacje_z_powt_LEX(n,k,wybor);
		cout << "\nWygenerowane wyniki zapisano do pliku: kombinacje_z_powt.txt\n" << endl;
	}	
	return 0;
}
