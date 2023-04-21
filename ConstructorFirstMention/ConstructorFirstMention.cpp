#include <iostream>

class numer {
	int liczba;
	char nazwa[40];
public:
	numer(int l, const char* opis);
	void schowaj(int l) {
		liczba = l;
		melduj();
	}
	int zwracaj() {
		return liczba;
	}
	void melduj() {
		std::cout << nazwa << liczba << std::endl;
	}
};
numer::numer(int l, const char* opis) {
	liczba = l;
	strcpy_s(nazwa, opis);
}
int main()
{
	numer samolot(1200, "Biezaca wysokosc");
	numer atmosfera(920, "Cisnienie atmosferyczne"), kurs(63, "Kierunek lotu");

	samolot.melduj();
	kurs.melduj();
	atmosfera.melduj();

	std::cout << "\nKorekta lotu----\n";
	samolot.schowaj(1201);

	//zmmiana kursu o 3 stopnie
	kurs.schowaj(kurs.zwracaj() + 3);

	//cisnienie  spada
	atmosfera.schowaj(919);
}