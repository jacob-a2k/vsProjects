#include <iostream>
#include <string>

enum tak_czy_nie {nie,tak};

class Piorko {
	int poz_x, poz_y;
	static int zezwolenie;
	char kolor[30];
public:
	void jazda(int x, int  y) {
		std::cout << "Tu " << kolor << " piorko: ";
		if (zezwolenie) {
			poz_x = x;
			poz_y = y;
			std::cout << "Jade do punktu (" << poz_x << ", " << poz_y << ") \n";
		}
		else {
			std::cout << "Nie wolno mi jechac!!!!!!!!!!!" << std::endl;
		}
	}
	static void mozna(tak_czy_nie odp) {
		zezwolenie = odp;
		//poz_x = 5;  --- blad! Nie mozna dzialac na skaldnikach zwyklych( niestatycznych )
	}
	Piorko(const char* kol) {
		strcpy_s(kolor, kol);
		poz_x = poz_y = 0;
	}
	void przesun(int x, int y) {
		poz_x += x;
		poz_y += y;
		std::cout << "Tu " << kolor << " piorko: ";
		if (zezwolenie) {
			std::cout << "Zmiana trasy do punktu (" << poz_x << ", " << poz_y << ") \n";
		}
		else {
			std::cout << "Nie wolno mi jechac!!!!!!!!!!!" << std::endl;
		}
	}
};
int Piorko::zezwolenie; // wywolanie funkcji statycznej na rzecz KLASY!!!!!!!!!!!

int main() {
	Piorko::mozna(tak);
	Piorko czarne("SMOLISTE"), zielone("ZIELONIUTKIE");
	czarne.jazda(0, 0);
	zielone.jazda(1100, 1100);

	//zabraniam ruchu piorkom
	Piorko::mozna(nie);
	czarne.jazda(10, 10);
	zielone.jazda(1020, 1020);

	//zezwalam w taki sposob
	zielone.mozna(tak);
	czarne.jazda(50, 50);
	zielone.jazda(1060, 1060);

	zielone.przesun(25, 25);
}