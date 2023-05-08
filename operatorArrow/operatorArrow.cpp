#include <iostream>

class wekt {
public:
	float x, y, z;
	wekt(float a, float b, float c) :x(a), y(b), z(c) {}
	void podwojenie() {
		x *= 2; y *= 2; z *= 2;
	}
	void pokaz() {
		std::cout << "x= " << x << ", y= " << y << ", z= " << z << std::endl;
	}
};
class spryciarz {
	wekt* wsk;
	wekt* (pamietnik[10]);
	int uzycie;
public:
	void operator=(wekt* w) {
		wsk = w;
	}
	spryciarz(wekt* adr = NULL);
	wekt* operator->();
	void statystyka(void);
};
spryciarz::spryciarz(wekt* adr) :wsk(adr), uzycie(0) {
	for (int i = 0; i < 10; i++) {
		pamietnik[i] = NULL;
	}
}
wekt* spryciarz::operator->() {
	pamietnik[uzycie] = wsk;
	uzycie = (++uzycie) % 10;
	return wsk;
}
void spryciarz::statystyka(void) {
	std::cout << "Ostatnie 10 wypadkow uzycie odbylo sie dla obiektow \n o adresach: \n";
	for (int i = 0; i < 10; i++) {
		std::cout << pamietnik[((uzycie)+i) % 10] << ((i == 4) ? "\n" : ", ");
	}
	std::cout << std::endl;
}

int main()
{
	float m;
	wekt www(1, 1, 1);

	wekt* zwykly_wsk;
	spryciarz zreczny_wsk;

	zwykly_wsk = &www;
	zreczny_wsk = &www;
	std::cout << "Operacja za pomoca zwyklego wskaznika \n";
	m = zwykly_wsk->x;
	std::cout << "m= " << m << std::endl;
	std::cout << "Operacja za pomoca zreczneoo wskaznika \n";
	m = zreczny_wsk->x;
	std::cout << "m= " << m << std::endl;

	wekt w2(2, 2, 2),
		w3(3, 3, 3),
		w4(44, 10, 1);

	zreczny_wsk = &w2;
	zreczny_wsk->podwojenie();
	zreczny_wsk->pokaz();

	zreczny_wsk = &w3;
	zreczny_wsk->podwojenie();
	zreczny_wsk->pokaz();

	zreczny_wsk = &w4;
	zreczny_wsk->podwojenie();
	zreczny_wsk->pokaz();

	zreczny_wsk.statystyka();
	zreczny_wsk = &www;
	zreczny_wsk->pokaz();

	zreczny_wsk.statystyka();

}