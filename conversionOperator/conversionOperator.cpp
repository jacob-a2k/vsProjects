#include <iostream>
#include <string>

class numer;

class zespol {
	float rzeczyw;
	float urojon;
public:
	zespol(float r = 0, float i = 0) : rzeczyw(r), urojon(i) {}
	zespol(numer ob);
	operator float() {
		return rzeczyw;
	}
	operator numer();
	void pokaz() {
		std::cout << "\tLiczba zespolona: (" << rzeczyw << ", " << urojon << ") \n";
	}
	friend zespol dodaj(zespol a, zespol b);
};
class numer {
	float n;
	char opis[80];
	friend zespol::zespol(numer);
	friend void plakietka(numer);
public:
	numer(float k, const char* t = "opis domyslny") :n(k) {
		strcpy_s(opis, t);
	}
	operator float(){
		return n;
	}
};
zespol::zespol(numer ob) : rzeczyw(ob.n), urojon(0) {}
zespol::operator numer() {
	return numer(rzeczyw, "powstal z zespolonej");
}

void pole_kwadratu(float bok);
void plakietka(numer nnn);
zespol dodaj(zespol a, zespol b);

int main()
{
	float x = 3.21;
	numer nr(44, "a imie jego");
	zespol z(6, -2);

	pole_kwadratu(x);
	pole_kwadratu(nr);
	pole_kwadratu(z);

	zespol z2(4, 5), wynik;
	wynik = dodaj(z, z2);
	wynik.pokaz();

	wynik = dodaj(z, x);
	wynik.pokaz();

	wynik = dodaj(z, nr);
	wynik.pokaz();

	plakietka(nr);
	plakietka(x);
	plakietka(z);
}
zespol dodaj(zespol a, zespol b) {
	zespol chwilowy(a.rzeczyw + b.rzeczyw, a.urojon + b.urojon);
	return chwilowy;
}
void plakietka(numer nnn) {
	std::cout << "***************************************" << std::endl;
	std::cout << "*** ***\r" << "*** " << nnn.opis << std::endl;
	std::cout << "*** ***\r" << "*** " << nnn.n << std::endl;
	std::cout << "***************************************" << std::endl;
}
void pole_kwadratu(float bok) {
	std::cout << "Pole kwadratu o boku " << bok << " wynosi " << (bok * bok) << std::endl;
}
