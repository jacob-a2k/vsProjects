#include <iostream>

using namespace std;

class Math {
	float x;
	float y;
public:
	Math(float a = 0, float b = 0) : x(a), y(b) {}
	Math add(const Math& number)const;
	Math operator+(const Math& number) const;
	Math multiply(const Math& number) const;
	Math operator*(const Math& number) const;
	Math subtract(const Math& number) const;
	Math operator-(const Math& number) const;
	Math divide(const Math& number) const;
	Math operator/(const Math& number) const;
	Math operator=(const Math& number);
	friend ostream& operator<<(std::ostream& out, const Math& number);
	bool operator==(const Math& number) const;
	bool operator!=(const Math& number) const;

	void display()const;
};
Math Math::add(const Math& number) const {
	return Math(x + number.x, y + number.y);	// I - style of syntax
}
Math Math::operator+(const Math& number) const{
	cout << "Overload operator+ execute!" << endl;
	return add(number);		// I - style of syntax
}
Math Math::multiply(const Math& number)const {
	return operator*(number);		// II - style of syntax
}
Math Math::operator*(const Math& number) const {
	cout << "Overload operator* execute!" << endl;
	return Math(x * number.x, y * number.y);	// II - style of syntax
}
Math Math::subtract(const Math& number) const {
	return *this - number;		// III - style of syntax
}
Math Math::operator-(const Math& number) const {
	cout << "Overload operator- execute!" << endl;
	return Math(x - number.x, y - number.y);	// III - style of syntax
}
Math Math::divide(const Math& number) const {
	return Math(x / number.x, y / number.y);	
}
Math Math::operator/(const Math& number) const {
	cout << "Overload operator/ execute!" << endl;
	return divide(number);
}
Math Math::operator=(const Math& number) {
	cout << "Overload operator= execute!" << endl;
	//if (this == &number) return *this;		// dont have dynamic allocation
	return Math(this->x = number.x, this->y = number.y);
}
ostream& operator<<(std::ostream& stream, const Math & number) {
	cout << "Overload left shift operator execute! " << endl;
	stream << number.x << ", " << number.y << endl;
	return stream;
}
bool Math::operator==(const Math& number) const {
	return x == number.x && y == number.y;
}
bool Math::operator!=(const Math& number) const {
	return !(*this == number);
}
void Math::display() const {
	cout << x << ", ";
	cout << y << endl;
}

int main()
{
	Math first(2, 3);
	Math second(4, 6);
	Math third(2, 4);

	Math total;
	//total = first + second;
	//total = first * second;
	//total = first - second;
	total = first / second;
	if (first != third) {
		cout << total << endl;
	}
	//total.display();


	return 0;
}