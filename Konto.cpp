/* Utvecklad av : David Hegardt
Uppgift : C++ Objektorienterad - Lab 2 Bankaffärer
Filnamn : Konto.cpp
*/

#include "Konto.h"

void Konto::addMoney(int belopp) {
	
	saldo = belopp;

}

bool Konto::remMoney(int belopp) {
	
	if (disponibel() >= belopp) {
		saldo = currSaldo() - belopp;
		return true;
	}
	else return false;
}
/*
float Konto::currKredit() const {
	
	return kredit;
}

void Konto::changeKred(int belopp) {

	kredit = belopp;

}
*/
float Konto::currSaldo() const {

	return saldo;
}

float Konto::disponibel() const {

	float disponibel;
	//disponibel = saldo + kredit;
	disponibel = saldo;
	return disponibel;

}

int Konto::accNr() {

	return kontoNr;

}

Konto::Konto(int pKontoNr, string pAccType) {

	kontoNr = pKontoNr;
	kontoTyp = pAccType;
}

string Konto::accType(){

	return kontoTyp;
}