#include <iostream>

class wektorek {
public:
	float x, y, z;
	wektorek(float a = 0, float b = 0, float c = 0) : x(a), y(b), z(c) {}
};
std::ostream& operator<<(std::ostream& ekran, wektorek& w) {
	ekran << "wspolrzedne wektora: ";
	ekran << " (" << w.x << ", " << w.y << ", " << w.z << ") ";
	return ekran;
}
int main()
{
	wektorek w(1, 2, 3),
		v,
		k(-10, -20, 100);
	std::cout << "Oto nasze wektory \nwektor w - " << w;
	std::cout << "\nwektor v - " << v;
	std::cout << "\nwektor k - " << k << std::endl;

	std::cout << "Wywolanie jawne \n";
	operator<<(std::cout, w);

}