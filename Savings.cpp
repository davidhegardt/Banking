#include "SavingsAcc.h"

Savings::Savings(int pKontoNr, string pAccType) 
	: Konto(pKontoNr, pAccType) { }

bool Savings::checkUttag() {
	if (antUttag == maxUttag) {
		return false;
	}
	else return true;
}

void Savings::countUttag() {
	
	antUttag++;
}

float Savings::getInterestRate() {
	return interest;
}