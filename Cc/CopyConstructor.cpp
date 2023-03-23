#include <iostream>
#include <string>

using namespace std;

class Person {
	char* name;
	int length;
public:
	Person(const char* string) {
		length = strlen(string);
		name = new char[length + 1];
		memcpy(name, string, length);
		name[length] = 0;
	}
	Person(const Person& other)
		:length(other.length)
	{
		//cout << "Copy constructor!" << endl;
		name = new char[length + 1];
		memcpy(name, other.name, length + 1);  
	}
	~Person() {
		delete[] name;
	}
	char& operator[](int index) {
		return name[index];
	}

	friend ostream& operator<<(ostream& stream, const Person& name);

};
ostream& operator<<(ostream& stream, const Person& string) {
	stream << string.name;
	return stream;
}
void PrintString(const Person& string) {
	Person copy = string;
	cout << string << endl;
}

int main()
{
	Person one("Jakub");
	Person two = one;

	two[1] = 'o';

	PrintString(one);
	PrintString(two);

	cin.get();

	return 0;
}