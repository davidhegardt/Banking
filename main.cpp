/* Utvecklad av : David Hegardt
Uppgift : C++ Objektorienterad - Lab 2 Bankaff�rer
Filnamn : main.cpp
*/

#include "BankKund.h"
#include "Bank.h"
#include "Interface.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

	setlocale(LC_ALL, "swedish"); // till�ter svenska tecken
	Interface newInterface;

	newInterface.run();

	system("pause");
}