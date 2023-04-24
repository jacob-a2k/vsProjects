#include <iostream>

int xyz = 10;
void zwykla();

int main()
{
	zwykla();
	//lokalik BBB; - error
}
void zwykla() {
	int xyz = 15;
	int lokal_autom;
	static float lokal_stat = 77;

	class lokalik {
	public:
		//static int sss; - error
		void lok_funskl() {
			std::cout << "to jest inline xyz = " << ::xyz << std::endl;		// we can acces only global variable by range operator ::
			std::cout << "lokal_stat = " << lokal_stat << std::endl;
		}
	};
	std::cout << "jestem w zwyklej funkcji \n";
	lokalik A;
	A.lok_funskl();
}