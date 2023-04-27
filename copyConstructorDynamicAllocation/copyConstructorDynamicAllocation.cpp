#include <iostream>
#include <string>

class wizytowka {
public:
	char* nazw;
	char* imie;
	wizytowka(const char* na, const char* im);
	wizytowka(wizytowka& wzor);
	~wizytowka();
	void personalia() {
		std::cout << imie << " " << nazw << std::endl;
	}
	void zmiana_nazwiska(const char* nowe) {
		strcpy_s(nazw,80, nowe);
	}
};
wizytowka::wizytowka(wizytowka& wzor) {
	nazw = new char[80];
	strcpy_s(nazw,80, wzor.nazw);
	imie = new char[80];
	strcpy_s(imie,80, wzor.imie);
}
wizytowka::wizytowka(const char* im,const char* na) {
	nazw = new char[80];
	strcpy_s(nazw,80, na);

	imie = new char[80];
	strcpy_s(imie,80, im);
}
wizytowka::~wizytowka() {
	delete nazw;
	delete imie;
}
int main() {
	wizytowka fizyk("Albert", "Einstein");
	wizytowka kolega = fizyk;
	std::cout << "Po utworzeniu blizniaczego obiektu oba zwieraja nazwiska\n";
	fizyk.personalia();
	kolega.personalia();
	kolega.zmiana_nazwiska("Metz");
	std::cout << "\nPo zmianie nazwiska kolegi brzmi ono: " << std::endl;
	kolega.personalia();
	std::cout << "Tymczasem niemodyfikowany fizyk nazywa sie: " << std::endl;
	fizyk.personalia();
}