#include <iostream>
#include <string>

class kwadrat;

class punkt {
	int x, y;
	char nazwa[30];
public:
	punkt(int a, int b, const char* opis);
	void ruch(int n, int m) {
		x += n;
		y += m;
	}
	friend int sedzia(punkt& p, kwadrat& k, int ile);
};
class kwadrat {
	int x, y, bok;
	char nazwa[30];
public:
	kwadrat(int a, int b, int dd, const char* opis);
	friend int sedzia(punkt& p, kwadrat& k, int ile);
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
int sedzia(punkt& pt, kwadrat& kw, int ile) {
	if ((pt.x >= kw.x) && (pt.x <= (kw.x + kw.bok)) &&
		(pt.y >= kw.y) && (pt.y <= (kw.y + kw.bok))) {
		std::cout << pt.nazwa << " lezy na tle " << kw.nazwa << std::endl;
		return 1;
	}
	else {
		std::cout << "AUT! " << pt.nazwa << " jest na zewnatrz " << kw.nazwa << std::endl;
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
	sedzia(pi, bo,ile);
	std::cout << "kopiemy pilke!\n";

	while (sedzia(pi, bo, ile)) {
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