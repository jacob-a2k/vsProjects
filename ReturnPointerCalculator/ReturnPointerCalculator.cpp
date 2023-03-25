#include <iostream>

using namespace std;

float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
float (*PointerToMathOperation(char sign))(float, float);

int main()
{
	cout << "Witaj podaj znak wykonywanej operacji: ";
	char sign;
	cin >> sign;
	float(*pointer)(float, float) = PointerToMathOperation(sign);
	if (pointer != nullptr) {
		cout << "Podaj dwie wartosci, a ja wykonam na nich operacje: ";
		float x, y;
		cin >> x >> y;
		float total = pointer(x, y);
		cout << "Wynik dzialania wynosi " << total << " ." << endl;
	}
	else {
		cout << "Sprobuj ponownie" << endl;
	}

	return 0;
}
float add(float a, float b) {
	return a + b;
}
float subtract(float a, float b) {
	return a - b;
}
float multiply(float a, float b) {
	return a * b;
}
float divide(float a, float b) {
	return a / b;
}
float (*PointerToMathOperation(char sign))(float, float) {

	switch (sign) {
	case '+':
		return &add;
	case '-':
		return &subtract;
	case'*':
		return &multiply;
	case '/':
		return &divide;
	default:
		cout << "Nie ma takiej opcji!" << endl;
		return nullptr;
	}
}