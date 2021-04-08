#include <iostream>
#include "stos.hh"
using namespace std;

//Funkcja nadaje odpowiednie wartosci poczatkowe
template <class T>
Node<T> *Node<T>::newNode(T liczba){

	Node *Stos = new Node();
	Stos->liczba = liczba;		//Nadanie odpowiedniej wartosci elementowi
	Stos->next = NULL;			//Wskaznik zaczyna wskazywac na NULL
	return Stos;
}

//Funkcja sprawdza czy stos jest pusty
template <class T>
int Node<T>::isEmpty(Node *N){

	return !N;
}

//Funkcja umozliwia wstawianie nowego elementu na stos
template <class T>
void Node<T>::push(Node ** N, T liczba){

	Node *Stos = newNode(liczba);
	Stos -> next = *N;				//Wskaznik zaczyna wskazywac na poprzeni element
	*N = Stos;						//Wstawienie lementu na stos
	cout << "Dodano na stos: " << liczba << endl;
}

//Funkcja umozliwia wyswietlenie gornego elementu z stosu
template <class T>
T Node<T>::top(Node *N){

	if(isEmpty(N)){				//Sprawdzanie czy stos jest pusty
		cout << "Stos jest juz pusty!" << endl;
		return 0;
	}
	else{						//Zwraca wartosc gornego elementu
		return N->liczba;
	}
}

//Funkcja umozliwia usuniecie gorengo elementu
template <class T>
T Node<T>::pop(Node **N){

	if(isEmpty(*N)){				//Sprawdzanie czy stos jest pusty
		cout << "Stos jest juz pusty!" << endl;
		return 0;
	}
	else{
		Node *temp = *N; 			//Pomocniczy wskaznik
		*N = (*N)-> next;			//Wskaznik zaczyna wskazywac na poprzeni element
		T usun = temp -> liczba;	//Skopiowanie wartosci elementu
		free(temp);					//Zwalnianie pamiêci

		return usun;				//Zwraca wartosc usunietego elementu
	}

}

//Funkcja usuwa wszystkie lementy z stosu
template <class T>
void Node<T>::delate(Node *N){
										//Sprawdzanie czy stos jest pusty
	while(!isEmpty(N)){					//Pêtla WHILE dziala tak dlugo az nie dojdzie do ostatniego elemntu
		cout << "Usunieto z stosu:  " << top(N) << endl;
		pop(&N);						//Usuwanie lementow
	}
	cout << "Stos jest pusty!" << endl;
}

//Umozliwia korzystanie z okreslonych typow danych
template class Node<int>;
template class Node<float>;
template class Node<char>;
template class Node<const char*>;
