#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

class przyrzad {
	char nazwa[20];
	char jednostki[10];
	int pokazuje;
	int x, y;	// coordinate przyrzad
	static int ile_nieznanych;
public:
	przyrzad(int, int, const char*, const char*, int = 0);
	przyrzad(void);

	void gotoxy(int x, int y);
	void zmien(int w);
	void narysuj(void);
};
przyrzad::przyrzad(int xx, int yy,const char* nnn,const char* jedn, int w) {
	strcpy_s(nazwa, nnn);
	strcpy_s(jednostki, jedn);
	x = xx;
	y = yy;
	narysuj();
}
przyrzad::przyrzad(void) {
	char tmp[10];
	++ile_nieznanych;
	strcpy_s(jednostki, " ");

	//wypelnienie tablicy tekstem - wsk numer
	strcpy_s(nazwa, "Wskaznik nr ");
	_itoa_s(ile_nieznanych, tmp, 10);
	strcat_s(nazwa, tmp);

	// wymyslenie dla przyrzadu jego pozycji na ekranie
	x = 45;
	y = 1 + (ile_nieznanych - 1) * 4;
	pokazuje = 0;	// na co ma pokazywac

	// narysowanie go na ekranie
	narysuj();
}
void przyrzad::zmien(int w) {
	pokazuje = w;
	narysuj();
}
void przyrzad::narysuj() {
	// Markuje wyswietlacz cyfrowy
	gotoxy(x, y);
	std::cout << ("_________________________________");
	gotoxy(x, y + 1);
	std::cout << ("I %-20s I", pokazuje, jednostki);
	gotoxy(x, y + 2);
	std::cout << ("I &5d %10s I", pokazuje, jednostki);
	gotoxy(x, y + 3);
	std::cout << ("I_______________________________I");
}
int przyrzad::ile_nieznanych;

int main() {
	system("cls");
	przyrzad Pred( 2, 1, "Predkosc", "wezlow", 110);
	przyrzad Vari( 2, 6, "Wznoszenie", "stopy/sec");
	przyrzad A;
	przyrzad B;
	volatile przyrzad C;
	const przyrzad Udzw(2, 11, "Udzwig maksymalny", "ton", 1500);

	//symulcja normalnego ciaglego wyswielania
	for (int i = 0; i < 30; i++) {
		Vari.zmien(i);
		Pred.zmien(110 + i);
		A.zmien(-i);
		B.zmien(i % 4);
		//C.zmien(i % 3);	//obiekt volatile - error
		//Udzw.zmien(230);	//obekt const - error
		Sleep(2);
	}
}
void przyrzad::gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}