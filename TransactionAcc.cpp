#include "TransactionAcc.h"

float Transaction::currKredit() const {

	return kredit;
}

Transaction::Transaction(int pKontoNr, string pAccType)
	: Konto(pKontoNr, pAccType) { }


void Transaction::changeKred(int belopp) {

	kredit = belopp;

}

float Transaction::disponibel() const {

	float disponibel;
	disponibel = currSaldo() + kredit;
	return disponibel;

}


