#include <iostream>
#include <string>

class kalibracja {
	float a, b;
	char nazwa[80];
public:
	kalibracja(float wsp_a, float wsp_b, const char* txt);
	kalibracja(const kalibracja& wzor);
	float energia(int kanal) {
		return ((a * kanal) + b);
	}
	char* opis() {
		return (nazwa);
	}
};
kalibracja::kalibracja(float wsp_a, float wsp_b, const char* txt) : a(wsp_a), b(wsp_b) {
	strcpy_s(nazwa, txt);
}
kalibracja::kalibracja(const kalibracja& wzorzec) {
	a = wzorzec.a;
	b = wzorzec.b;
	std::cout << "+++++++++PRACUJE++++++++++" << std::endl;
	strcpy_s(nazwa, "--To ja, konstruktor kopiujacy!--");
}
void fun_pierwsza(kalibracja odebrana);
kalibracja fun_druga(void);

int main() {
	kalibracja kobalt(1.07, 2.4, " ORYGINALNA KOBALTOWA ");
	kalibracja europ = kalibracja(kobalt);

	std::cout << "O ktory kanal widmo chodzi? :";
	int kanal;
	std::cin >> kanal;
	std::cout << "Wedlug kalibracji kobalt , \nopisanej jako" << kobalt.opis() << "\nkanalowi nr " << kanal << " odpowiada energia " << kobalt.energia(kanal) << std::endl;
	std::cout << "Wedlug kalibracji europ , \nopisanej jako" << europ.opis() << "\nkanalowi nr " << kanal << " odpowiada energia " << europ.energia(kanal) << std::endl;
	std::cout << "Do funkcji pierwszaj wysylam kalibracje " << kobalt.opis() << std::endl;
	fun_pierwsza(kobalt);
	std::cout << "Teraz wywolem funkcje druga, a jej rezultat \npodstawie do innej kalibracji \n";
	std::cout << "Obliekt chwilowy zwrocony jako rezultat funkcji \nma opis " << fun_druga().opis() << std::endl; // powinno byc inaczej
}
void fun_pierwsza(kalibracja odebrana) {
	std::cout << "Natomiast w funkcji pierwszej odebralem te kalibracje \nopisane jako " << odebrana.opis() << std::endl;
}
kalibracja fun_druga(void) {
	kalibracja wewn(2, 1, "WEWNETRZNA");
	std::cout << "W funkcji fun_druga definiuje kalibracje i ma \nona opis: " << wewn.opis() << std::endl;
	return wewn;
}
