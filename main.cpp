#include <iostream>
#include <chrono>
#include "stos.hh"
using namespace std;

int main() {

	Node<int> *N = NULL;
	int a;
			//Proste MENU
	cout << "Wybierz opcje: " << endl << endl;
	cout << "1 - Driver" << endl;
	cout << "2 - Test szybkosci programu" << endl << endl;
	cin >> a;
	while((a != 1)&&(a != 2)){
		cout << endl;
		cout << "!!!! Podano zla opce !!!!" << endl;
		cout << "Wybierz opcje: " << endl << endl;
		cout << "1 - Driver" << endl;
		cout << "2 - Test szybkosci programu" << endl << endl;
		cin >> a;
	}
						//DRIVER
	if (a == 1){
		cout << endl;
		N->push(&N, 4);			//Dodawanie kolejnych wartosci na stos
		N->push(&N, 6);
		N->push(&N, 10);
		N->push(&N, 14);
		N->push(&N, 18);

		cout << "Usunieto:  " << N->pop(&N) << endl << endl;	//Usuwanie lementu z stosu
		cout << "Na gorze jest: " << N->top(N) << endl << endl;	//Sprawdzanie gornego elementu

		N->delate(N);											//Usuwanie wszystkich elementow z stosu
	}
	else {
						//POMIAR CZASU TRWANIA ALGORYTMU

		int zakres = 0;
		cout << "Podaj zakres: ";
		cin >> zakres;

		//Poczatek mierzenia czasu
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();

		int a = 1;
		for (int i = 1; i <= zakres; i++){

			a = a + 1;
			N->push(&N,a);	//Wstawianie nowych elementow na stos
		}

		chrono::steady_clock::time_point end = chrono::steady_clock::now();
		//Koniec mierzenia czasu
		cout << endl << endl;
		//Wypisywanie czasu trwania algorytmu
		cout << "Time = " << chrono::duration_cast<chrono::seconds>(end - begin).count() << " [s]  10^(-6)s" << endl;
		cout << "Time = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " [ms]  10^(-6)s" << endl;
		cout << "Time = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << " [us]  10^(-6)s" << endl;
		cout << "Time = " << chrono::duration_cast<chrono::nanoseconds> (end - begin).count() << " [ns]  10^(-9)s" << endl;
	}


	return 0;
}
