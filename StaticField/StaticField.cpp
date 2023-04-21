#include <iostream>

class pion {
	int pozycja;
	static int pensja;
public:
	static int ile_pionkow;
	pion() {
		pozycja = 0;
		ile_pionkow++;
	}
	int przesun(int ile) {
		return (pozycja += ile);
	}
	int ile_zarabia() {
		return pensja - 800;
	}
	int aktualnaPozycja() {
		return pozycja;
	}
};
pion* wygrywa(pion* obj1, pion* obj2) {
	if (obj1->aktualnaPozycja() > obj2->aktualnaPozycja()) {
		return obj1;
	}
	return obj2;
}

int pion::pensja = 3000;
int pion::ile_pionkow;

int main()
{
	std::cout << "Poczatek programu, teraz jest pionkow = " << pion::ile_pionkow << std::endl;
	pion czerwony, zielony;
	std::cout << "\nPo definicji pionkow \n";
	std::cout << "Klasa mowi ze pionkow jest " << pion::ile_pionkow << std::endl;
	std::cout << "czerwony, ze " << czerwony.ile_pionkow << std::endl;
	std::cout << "zielony, ze " << zielony.ile_pionkow << std::endl;
	pion bialy;
	std::cout << "Po definicji jeszcze jednego jest ich: " << zielony.ile_pionkow << std::endl;
	//pionki ida do przodu
	zielony.przesun(6);
	czerwony.przesun(4);
	bialy.przesun(3);
	//ile zarabia pionek - statyczna prywatna
	std::cout << "Czerwony, ile zarabiacie ? " << czerwony.ile_zarabia() << std::endl;
	std::cout << "Bialy, ile zaarabiacie ?" << bialy.ile_zarabia() << std::endl;

	std::cout << "\nAktualna pozycja pionka zielonego: " << zielony.aktualnaPozycja() << std::endl;
	std::cout << "Aktualna pozycja pionka czerwonego: " << czerwony.aktualnaPozycja() << std::endl;

	std::cout << "Wygrywa pionek ";// << wygrywa(&zielony, &czerwony) << std::endl;	//return adres because it doesn't any name
	if (&zielony == wygrywa(&zielony, &czerwony)) {
		std::cout << "zielony" << std::endl;
	}
	else {
		std::cout << "czerwony" << std::endl;
	}
}