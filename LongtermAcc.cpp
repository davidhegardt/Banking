#include "LongtermAcc.h"

Longterm::Longterm(int pKontoNr, string pAccType)
	: Konto(pKontoNr, pAccType) { }

bool Longterm::checkUttag() {
	if (antUttag == maxUttag) {
		return false;
	}
	else return true;
}

void Longterm::countUttag() {

	antUttag++;
}

float Longterm::getInterestRate() {
	return interest;
}