#include <iostream>

int balkon = 77;
void spiew();

class Opera {
public:
	int n;
	float balkon;

	void funkcja();
	void spiew() {
		std::cout << "funkcja spiew (z opery) : tra-la-la !\n";
	}
};
void Opera::funkcja() {
	std::cout << "balkon (skladnik klasy) = " << balkon << std::endl;
	std::cout << "balkon (zmienna globana) = " << ::balkon << std::endl;
	
	char balkon = 'M';
	std::cout << "\nPo definicji zmiennej lokalnej ---\n";
	std::cout << "balkon (zmienna lokalna) = " << balkon << std::endl;
	std::cout << "balkon (skladnik klasy) = " << Opera::balkon << std::endl;
	std::cout << "balkon (zmienna globalna) = " << ::balkon << std::endl;

	spiew();
	int spiew;
	spiew = 7;
	//spiew() <- error

	std::cout << "Po zaslonieciu da sie wywolac funkcje spiew tylko tak\n";
	Opera::spiew();
}
int main() {
	Opera Lohengrin;
	Lohengrin.balkon = 6;
	Lohengrin.funkcja();
	spiew();
}
void spiew() {
	std::cout << "Zwykla funkcja spiew nei majaca nic wspolnego z klasa" << std::endl;
}