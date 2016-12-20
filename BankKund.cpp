/* Utvecklad av : David Hegardt
Uppgift : C++ Objektorienterad - Lab 2 Bankaff�rer
Filnamn : BankKund.cpp
*/

#include "BankKund.h"
#include "TransactionAcc.h"
#include "SavingsAcc.h"
#include "LongtermAcc.h"
#include <random>
#include <fstream>
#include <algorithm>
#include <sstream>

vector<string> BankKund::getName() const {

	vector<string> nameVec;
	nameVec.push_back(firstName);
	nameVec.push_back(lastName);

	return nameVec;


}

int BankKund::getPersNr() const {

	return persNr;

}

int BankKund::getAcc() const {

	return accVec.size();
}

vector<int> BankKund::getAccNrs() {
	vector<int> nrVec;									// vector f�r att spara kontonummer

	for (int i = 0; i < getAcc(); i++) {		
			nrVec.push_back(accVec[i]->accNr());		// spara 1 kontonummer p� varje plats i nrVec
	} return nrVec;										// returnera vektor
}

int BankKund::getAccType(int i) {	
	
		if (accVec[i]->accType() == "transaction")
		{
			return 1;
		}
		if (accVec[i]->accType() == "savings")
		{
			return 2;
		}
		if (accVec[i]->accType() == "longterm")
		{
			return 3;
		}

	
}

string BankKund::getAccString(int kontonummer) {
	
	for (int i = 0; i < accVec.size(); i++) {				// 
		if (accVec[i]->accNr() == kontonummer) {
			return accVec[i]->accType();
		}
	}
}


vector<float> BankKund::getAccInfo(int kontonummer) {
	vector<float> infoVec;									// vector f�r att spara kontoinformation

	for (int i = 0; i < accVec.size(); i++) {				// 
		if (accVec[i]->accNr() == kontonummer) {
			infoVec.push_back(accVec[i]->currKredit());		// plats 0 i infoVec = kredit
			infoVec.push_back(accVec[i]->currSaldo());		// plats 1 i infoVec = saldo
			infoVec.push_back(accVec[i]->disponibel());		// plats 2 i infoVec = disponibelt belopp
			infoVec.push_back(accVec[i]->getInterestRate()); // plats 3 in infoVec = r�ntesats
		}
	} return infoVec;
}

float BankKund::getTotal() {

	float sum = 0;

	for (int i = 0; i < getAcc(); i++) {					// Loopa fram till antal konton 
		accVec[i]->currSaldo();								
		sum += accVec[i]->currSaldo();						// Summar saldo fr�n samtliga konton
	}
	return sum;
}

bool BankKund::createAcc(string kontoTyp) {

	std::random_device rd;     // initiatera seed
	std::mt19937 rng(rd());    // random-number engine 
	std::uniform_int_distribution<int> uni(1000, 5555); // start value and max value

	auto random_integer = uni(rng);

	int kontoNr = random_integer;

	if (getAcc() < 3 && kontoTyp == "transaction") {
		accVec.push_back(unique_ptr<Konto>(new Transaction(kontoNr, kontoTyp)));
		return true;
	}
	if (getAcc() < 3 && kontoTyp == "savings") {
		accVec.push_back(unique_ptr<Konto>(new Savings(kontoNr, kontoTyp)));
		return true;
	}
	if (getAcc() < 3 && kontoTyp == "longterm") {
		accVec.push_back(unique_ptr<Konto>(new Longterm(kontoNr, kontoTyp)));
		return true;
	}
	else return false;
}

bool BankKund::removeAcc(int kontonr) {
	bool found = false;

	for (int i = 0; i < accVec.size(); i++) {				// if kontonr matches, reset pointer and remove placeholder
		if (accVec[i]->accNr() == kontonr) {
			accVec[i].reset();
			accVec.erase(accVec.begin() + i);
			found = true;
		}
		
	} 
	return found;
}

bool BankKund::withDraw(float belopp, int kontonr) {
	bool found = false;
	for (int i = 0; i < getAcc(); i++) {
		if (accVec[i]->accNr() == kontonr) {				// Kolla f�rst att kontonr matchar
			if ((accVec[i]->remMoney(belopp)) && (accVec[i]->checkUttag() == true)) {				// Kolla sedan att antal uttag inte �r max
				found = true;								// returnera sant om �tg�rden lyckades
				if (getAccString(kontonr) == "savings") {
					accVec[i]->countUttag();
				}
				if (getAccString(kontonr) == "longterm") {
					accVec[i]->countUttag();
				}
			}

		}

	}
	return found;
}

bool BankKund::insert(float belopp, int kontonr) {
	bool found = false;

	for (int i = 0; i < getAcc(); i++) {
		if (accVec[i]->accNr() == kontonr) {				// Kolla att kontonummer matchar
			accVec[i]->addMoney(belopp);					// Anropa funktion f�r att l�gga till belopp
			found = true;									// returnera sant om det lyckades
		}
	} return found;
}

bool BankKund::changeCredLim(int limit, int kontonr) {
	bool found = false;
	if (getAccString(kontonr) == "transaction") {
		for (int i = 0; i < getAcc(); i++) {
			if (accVec[i]->accNr() == kontonr && limit > 0) {		// Kolla att kontonummer matchar samt att limit �r ett positivt tal
				accVec[i]->changeKred(limit);						// Anropa funktion f�r att �ndra kredit
				found = true;
			}

		}
	}
	return found;
}

bool BankKund::writeFile() {
	
	string fileName = to_string(getPersNr()) + ".txt";
	
	vector<int> utskriftVec;
	vector<string> nameVec = (getName());
	

	utskriftVec.push_back(getAcc());
	
	for (int i = 0; i < getAcc(); i++) {
		utskriftVec.push_back(getAccNrs()[i]);				// Anropa funktion f�r att f� fram kontonummer, loopa dessa och l�gg
		utskriftVec.push_back(getAccType(i));
	}														// i vektor
	vector<float> tempVec;
	vector<float> allKontonVec;
	
		for (int i = 0; i < getAcc(); i++) {				// L�gg in kontonummer till getAccInfo, f� tillbaka vector med uppgifter
			tempVec = getAccInfo(getAccNrs()[i]);			// L�gg till saldo, kredit och disponibelt belopp till vektor
			allKontonVec.push_back(tempVec[0]);				// f�r samtliga konton
			allKontonVec.push_back(tempVec[1]);
			allKontonVec.push_back(tempVec[2]);
		} 
	

	for (int i = 0; i < allKontonVec.size(); i++) {			// L�gg till all kontoinformation till utskriftsvektor
		utskriftVec.push_back(allKontonVec[i]);
	}

	const char DELIM = '|';

	fstream outFile(fileName, ios::out);					// Skapa ny fil med filnamn = personnr + .txt
	if (outFile.is_open())
	{
		for (int i = 0; i < nameVec.size(); i++)
		{
			outFile << nameVec[i] << DELIM;					// Skriv ut v�rdena i namnvektor till fil
		}

		for (auto it : utskriftVec)
		{
			outFile << it << DELIM;							// Skriv ut v�rdena i utskriftsvektor till fil
		}
	}
	outFile.close();
	return true;
}

vector<string> BankKund::readFile1(int persNr) {
	string fileName = to_string(persNr) + ".txt";
	ifstream is(fileName);
	vector<string> personInfo;
	if (!is.fail()) {
		string tmpFirstName;
		string tmpLastName;
		string tmpString;


		const char DELIM = '|';
		getline(is, tmpFirstName, DELIM);						//l�s in f�rnamn fr�n fil till vector
		getline(is, tmpLastName, DELIM);						//l�s in efternamn fr�n til till vector
		personInfo.push_back(tmpFirstName);
		personInfo.push_back(tmpLastName);

	}
		return personInfo;										//Returnera vektor med str�ngar, f�rnamn och efternamn
	
}


bool BankKund::readFile2(int persNr) {
		string fileName = to_string(persNr) + ".txt";
		ifstream is(fileName);
		string tmpFirstName;
		string tmpLastName;
		
		string tmpString;
		string tmpString2;
		string tmpKontoTyp;

		int kontoCount = 0;
		int kontoNr = 0;
		int kontoTypNr = 0;
		vector<int> numVec;
		int tmpNum;
		int dontUse;

		const char DELIM = '|';

		getline(is, tmpFirstName, DELIM);						//L�s in de f�rsta raderna inneh�llande namn f�r att 
		getline(is, tmpLastName, DELIM);						//sedan kunna l�sa f�ljande rader
		

		getline(is, tmpString, DELIM);
		stringstream numbers(tmpString);
		numbers >> kontoCount;

		for (int i = 0; i < kontoCount; i++) {					// Loopa genom textfil efter samtliga kontonummer
			getline(is, tmpString, DELIM);
			getline(is, tmpString2, DELIM);
			stringstream numbers(tmpString);
			stringstream numbers2(tmpString2);
			numbers >> kontoNr;
			numbers2 >> kontoTypNr;

			switch (kontoTypNr) {
				case 1: tmpKontoTyp = "transaction";
					accVec.push_back(unique_ptr<Konto>(new Transaction(kontoNr, tmpKontoTyp)));
					break;
				case 2: tmpKontoTyp = "savings";
					accVec.push_back(unique_ptr<Konto>(new Savings(kontoNr, tmpKontoTyp)));
					break;
				case 3: tmpKontoTyp = "longterm";
					accVec.push_back(unique_ptr<Konto>(new Longterm(kontoNr, tmpKontoTyp)));
					break;
			}
			
			

		}

		for (int i = 0; i < kontoCount; i++)					//Loopa och l�s in kontoinformation f�r varje konto
		{
			getline(is, tmpString, DELIM);
			stringstream numbers(tmpString);
			numbers >> tmpNum;
			changeCredLim(tmpNum, accVec[i]->accNr());			//L�s in kredit f�r konto

			getline(is, tmpString, DELIM);
			stringstream numbers2(tmpString);
			numbers2 >> tmpNum;
			insert(tmpNum, accVec[i]->accNr());					//L�s in saldo f�r konto

			getline(is, tmpString, DELIM);
			stringstream numbers3(tmpString);
			numbers3 >> dontUse;								//Anv�nd inte v�rde f�r disponibelt belopp,detta r�knas ut
																//av programmet
		}
		return true;
	
}


BankKund::BankKund(string pFirstName, string pLastName, int pPersNr) {			//Konstruktor f�r BankKund
	
	firstName = pFirstName;
	lastName = pLastName;
	persNr = pPersNr;
}

