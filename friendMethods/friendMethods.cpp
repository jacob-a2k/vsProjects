#include <iostream>
#include <string>

class punkt;
class kwadrat {
	int x, y, bok;
	char nazwa[30];
public:
	kwadrat(int a, int b, int dd, const char* opis);
	int sedzia(punkt& p, int ile);
};
class punkt {
	int x, y;
	char nazwa[30];
public:
	punkt(int a, int b, const char* opis);
	void ruch(int n, int m) {
		x += n;
		y += m;
	}
	friend int kwadrat::sedzia(punkt& p, int ile);
};
punkt::punkt(int a, int b, const char* opis) {
	x = a;
	y = b;
	strcpy_s(nazwa, opis);
}
kwadrat::kwadrat(int a, int b, int dd, const char* opis) {
	x = a;
	y = b;
	bok = dd;
	strcpy_s(nazwa, opis);
}
int kwadrat::sedzia(punkt& pt, int ile) {
	if ((pt.x >= x) && (pt.x <= (x + bok)) &&
		(pt.y >= this->y) && (pt.y <= (this->y + this->bok))) {
		std::cout << pt.nazwa << " lezy na tle " << nazwa << std::endl;
		return 1;
	}
	else {
		std::cout << "AUT! " << pt.nazwa << " jest na zewnatrz " << nazwa << std::endl;
		std::cout << "Kolapismy ja " << ile << " razy" << std::endl;
		return 0;
	}
}
int losuj();

int main()
{
	kwadrat bo(10, 10, 40, "boiska");
	punkt pi(20, 20, "pilka");

	int ile = 0;
	bo.sedzia(pi,ile);
	std::cout << "kopiemy pilke!\n";

	while (bo.sedzia(pi, ile)) {
		pi.ruch(losuj(), losuj());
		ile++;
	}
}
#include <ctime>
int losuj() {
	srand(time(NULL));
	int los = rand() % 10 + 1;
	return los;
}