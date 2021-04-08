#ifndef STOS_HH
#define STOS_HH

// Klasa okreslajaca budowe modulu

template <typename T>
class Node{
public:
	T liczba;					//Wartosc zapisywana na stosie
	Node *next;					//Wskaznik na kolejny modul
	Node *newNode(T liczba);			//Funkcja nadaje odpowiednie wartosci poczatkowe
	int isEmpty(Node *N);				//Funkcja sprawdza czy stos jest pusty
	void push(Node ** N, T liczba); 		//Funkcja wstawia nowy elemnent na stos
	T pop(Node **N);				//Funkcja usuwa najwy¿szy element z stosu
	T top(Node *N);					//Funkcja zwraca element z gory stosu
	void delate(Node *N);				//Funkcja usuwa wszystkie lementy z stosu

};

#endif
