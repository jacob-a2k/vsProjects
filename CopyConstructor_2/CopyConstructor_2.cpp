#include <iostream>
#include <string>

using namespace std;

class Person {
	char* fullName;
	int age;
public:
	Person(int x, const char* name);
	Person(const Person& other);
	~Person();
	friend ostream& operator <<(ostream& stream, const Person& string);
	char& operator[](int index);
	void changeString(const char* string);
};
Person::Person(int x, const char* name) {	// konstuktor inicjalizuje pola klasy
	age = x;
	int size = strlen(name);
	fullName = new char[size + 1];
	memcpy(fullName, name, size);
	fullName[size] = 0;
}
Person::Person(const Person& other) :age(other.age) {	// konstruktor inicjalizuje obiekt klasy
	int size = strlen(other.fullName);
	fullName = new char[size + 1];
	memcpy(fullName, other.fullName, size + 1);
}
Person::~Person() {
	delete[] fullName;
}
ostream& operator<<(ostream& stream, const Person& string) {		// przelakowanie operatora strumienia wyjscia '<<'
	stream << string.fullName;
	return stream;
}
char& Person::operator[](int index) {		// przeladowanie operatora indeksowania '[]'
	return fullName[index];
}
void Person::changeString(const char* string) {		// usuniecie starej tablicy i stworzeniej nowej odpowiednio dlugiej do podanego napisu
	delete[] fullName;
	int size = strlen(string);
	fullName = new char[size + 1];
	strcpy_s(fullName, size + 1, string);
	fullName[size] = 0;
}
void display(const Person& string) {
	Person copy = string;
	cout << string << endl;
}
int main()
{
	Person jacob(24, "Jakub Abramczyk");
	Person simon = jacob;
	simon[3] = 'a';
	simon.changeString("Wladyslaw Jagiello");

	display(jacob);
	display(simon);

	cin.get();
	return 0;
}