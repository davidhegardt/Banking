/* Utvecklad av : David Hegardt
Uppgift : C++ Objektorienterad - Lab 2 Bankaffärer
Filnamn : main.cpp
*/

#include "BankKund.h"
#include "Bank.h"
#include "Interface.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

	setlocale(LC_ALL, "swedish"); // tillåter svenska tecken
	Interface newInterface;

	newInterface.run();

	system("pause");
}