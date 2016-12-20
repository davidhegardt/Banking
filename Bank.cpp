/* Utvecklad av : David Hegardt
Uppgift : C++ Objektorienterad - Lab 2 Bankaffärer
Filnamn : Bank.cpp
*/

#include "Bank.h"

void Bank::createCustomer(string pFirstName, string pLastName, int pPersNr) {

	newKund.reset(new BankKund(pFirstName, pLastName, pPersNr));

}

bool Bank::createAcc(string kontoTyp) {
	if (newKund->createAcc(kontoTyp) == true) {
		return true;
	}
	else return false;
}

bool Bank::removeAcc(int kontoNr) {
	if (newKund->removeAcc(kontoNr) == true) {
		return true;
	}
	else return false;
}

vector<string> Bank::getName() const {

	return newKund->getName();
}

int Bank::getPersNr() {

	return newKund->getPersNr();
}

int Bank::accCount() {
	
	return newKund->getAcc();
}

vector<int> Bank::getAccNrs() {
	
	return newKund->getAccNrs();
}

vector<float> Bank::getAccInfo(int kontonummer) {

	return newKund->getAccInfo(kontonummer);
}

string Bank::getAccString(int kontonummer) {

	return newKund->getAccString(kontonummer);
}

float Bank::getTotal() {

	return newKund->getTotal();
}

bool Bank::withDraw(float belopp, int kontonr) {
	if (newKund->withDraw(belopp, kontonr) == true) {
		return true;
	}
	else return false;
}

bool Bank::insert(float belopp, int kontonr) {
	if (newKund->insert(belopp, kontonr) == true) {
		return true;
	}
	else return false;
}

bool Bank::changeCredLim(int limit, int kontonr) {
	if (newKund->changeCredLim(limit, kontonr) == true) {
		return true;
	}
	else return false;
}

bool Bank::writeFile() {
	if (newKund->writeFile() == true) {
		return true;
	}
	else return false;
}

bool Bank::readFile(int persNr) {

	vector<string> vecInfo = newKund->readFile1(persNr);
	if (!vecInfo.empty()) {
		createCustomer(vecInfo[0], vecInfo[1], persNr);

		newKund->readFile2(persNr);

		return true;
	}
	else return false;

}


vector<float> Bank::subKontoBild(int count) {

	vector<float> kontoInfo;

	kontoInfo.push_back(getAccNrs()[count]);

	vector<float> accInfo = getAccInfo(getAccNrs()[count]);
	for (int i = 0; i < accInfo.size(); i++) {
		kontoInfo.push_back(accInfo[i]);
	}
	return kontoInfo;
}