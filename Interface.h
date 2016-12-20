/* Utvecklad av : David Hegardt
Uppgift : C++ Objektorienterad - Lab 2 Bankaffärer
Filnamn : Interface.h
*/

#ifndef InterfaceH
#define InterfaceH
#include "Bank.h"

using namespace std;

class Interface {
private:
	Bank newBank;
	bool done = false;

public:
	void showMenu();
	void getMenuOption(int val);

	void showName();
	void showPersNr();
	void showCount();
	void showAccNrs();
	void showAccInfo();
	void showTotalSum();

	void createCustomer();
	void createAcc();
	void removeAcc();
	void withDraw();
	void insert();
	void changeCredLim();
	void writeFile();
	void readFile();
	void showKontoBild();

	void run();

};


#endif // !InterfaceH

