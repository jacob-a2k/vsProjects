#include <iostream>
#include <string>
class Osoba {
	char nazwisko[80];
	int wiek;
public:
	void zapamietaj(const char* napis, int lata);
	void wypisz() {
		std::cout << "\t" << nazwisko << ", lat: " << wiek << std::endl;
	}
};
void Osoba::zapamietaj(const char* napis, int lata) {
	strcpy_s(nazwisko,20, napis); // strcpy_s allows us to specify size of destination buffer in case when source is bigger
	wiek = lata;
}
int main() {
	Osoba student, profesor, pilot;
	std::cout << "Dla informacji podaje, ze jeden obiekt klasy Osoba \n ma rozmiar: " << sizeof(student) << "bajty. To samo inaczej: " << sizeof(profesor) << std::endl;
	profesor.zapamietaj("Jakub Abramczyk", 25);
	student.zapamietaj("Aleksandra Materna", 20);
	pilot.zapamietaj("Andrzej Demirov", 30);

	std::cout << "Dane z obiektu profesor\n";
	profesor.wypisz();
	std::cout << "Dane z obiektu student\n";
	student.wypisz();

	std::cout << "Podaj tylko nowe nazwisko: ";
	char tmp[80];
	std::cin >> tmp;

	std::cout << "Podaj nowy wiek: ";
	int ile;
	std::cin >> ile;
	
	student.zapamietaj(tmp, ile);
	std::cout << "Dane z obiektow profesor i student" << std::endl;
	profesor.wypisz();
	student.wypisz();

}