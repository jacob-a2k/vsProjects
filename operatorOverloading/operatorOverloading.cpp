#include <iostream>
const int rozmiar = 1024;

class widmo {
public:
	int kanal[rozmiar];
	widmo(int wart = 0);
	widmo operator+(int);
	widmo operator=(widmo);
};
widmo::widmo(int wart) {
	for (int i = 0; i < rozmiar; i++) {
		kanal[i] = wart;
	}
}
widmo widmo::operator+(int liczba) {
	widmo rezultat;
	for (int i = 0; i < rozmiar; i++) {
		rezultat.kanal[i] = kanal[i] + liczba;
	}
	return rezultat;
}

widmo widmo::operator=(widmo obj) {
	for (int i = 0; i < rozmiar; i++) {
		this->kanal[i] = obj.kanal[i];
	}
	return *this;
}

int main()
{
	widmo kobalt(5);
	widmo nowe;
	nowe = (kobalt + 100);
	std::cout << "Przykldowo patrzymy na na kanal 44. \n"
		"Widmo 'kobalt' ma tam: " << kobalt.kanal[44] << "\n"
		"na widmie 'nowe' jest tam: " << nowe.kanal[44] << std::endl;
	nowe = (nowe + 700);
	std::cout << "A teraz w kanale 44 obiektu 'nowe' jest: " << nowe.kanal[44] << std::endl;
}
