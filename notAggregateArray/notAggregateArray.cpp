#include <iostream>
#include <string>

class stacje_metra2 {
	float km;
	int glebokosc;
	char nazwa[40];
	char przesiadki[80];
public:
	stacje_metra2(float kk, int gg, const char* nn, const char* pp = "");
	stacje_metra2();
	void gdzie_jestesmy();
	void zmianaNazwyStacji(const char* nowaNazwa);
};
stacje_metra2::stacje_metra2(float kk, int gg, const char* nn, const char* pp) : km(kk), glebokosc(gg) {
	strcpy_s(nazwa, nn);
	strcpy_s(przesiadki, pp);
}
stacje_metra2::stacje_metra2() {
	km = 0;
	glebokosc = 0;
	strcpy_s(nazwa, "Nie nazwano jeszcze");
	przesiadki[0] = NULL;
}
void stacje_metra2::gdzie_jestesmy() {
	std::cout << "Stacja: " << nazwa << std::endl;
	if (przesiadki[0]) {
		std::cout << "\tPrzesiadki: " << przesiadki << std::endl;
	}
}
void stacje_metra2::zmianaNazwyStacji(const char* nowaNazwa) {
	strcpy_s(nazwa, nowaNazwa);
}
int main() {
	stacje_metra2 ostatnia = stacje_metra2(22, 0, "Wansee", "118 Bus");
	ostatnia.gdzie_jestesmy();
	std::cout << "***********************\n";
	const int ile_stacji = 7;
	stacje_metra2 przystanek[ile_stacji] =
	{ 
		stacje_metra2(0, 5, "Fre..", "Linia U6"),
		stacje_metra2(),
		stacje_metra2(),
		stacje_metra2(5.7, 4, "Tier..."),
		stacje_metra2(8, 4, "ZOO", "Linie U1 i U9")
	};
	std::cout << "Stacja druga jest odnawiana. Podaj nowa nazwe: ";
	char nazwa[20];
	std::cin >> nazwa;
	przystanek[1].zmianaNazwyStacji(nazwa);

	for (int i = 0; i < ile_stacji; i++) {
		przystanek[i].gdzie_jestesmy();
	}
}