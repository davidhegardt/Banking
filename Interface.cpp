/* Utvecklad av : David Hegardt
Uppgift : C++ Objektorienterad - Lab 2 Bankaffärer
Filnamn : Interface.cpp
*/

#include "Interface.h"
#include <algorithm>
#include <string>

void Interface::run() {
	bool again = false;
	do {
		showMenu();
		system("pause");
	} while (again != true);
}

void Interface::showMenu() {
	
	system("cls");
	cout << "**** Välkommen till Ebberöds Bank ****" << endl;
	if (done == false) {
		cout << "1. Skapa och hantera ny kund" << endl;
		cout << "2. Hantera befintlig kund" << endl;
	}
	if (done == true) {
		cout << "* Visningsfunktioner *" << endl;
		cout << "1. Visa namn på kund" << endl;
		cout << "2. Visa personnummer för kund" << endl;
		cout << "3. Visa antal konton för kund" << endl;
		cout << "4. Visa kontononummer" << endl;
		cout << "5. Saldo, Kredit och disponibelt belopp för konto" << endl;
		cout << "6. Visa Totala tillgångar" << endl;
		cout << "---------------------------------" << endl;
		cout << "* Hantera konto funktioner *" << endl;
		cout << "7. Skapa nytt konto" << endl;
		cout << "8. Avsluta ett konto" << endl;
		cout << "9. Ta ut från konto" << endl;
		cout << "10. Sätt in på konto" << endl;
		cout << "11. Ändra kreditgräns" << endl;
		cout << "---------------------------------" << endl;
		cout << "* Filfunktioner *" << endl;
		cout << "12. Spara kontoinformation till fil" << endl;
		cout << "13. Läs in kontoinformation från fil" << endl;
		cout << "14. Visa kontobild" << endl;
		cout << "15. Avsluta" << endl;
	}
	int val;
	cout << "Enter Choice:";
	cin >> val;
	getMenuOption(val);

}

void Interface::getMenuOption(int val) {
	if(done == false) {
		switch (val) {
		case 1: createCustomer();
			break;
		case 2: readFile();
			break;
		default: cout << "Invalid choice!" << endl;
		}
	}
	if (done == true) {
			switch (val) {

			case 1: showName();
				break;
			case 2: showPersNr();
				break;
			case 3: showCount();
				break;
			case 4: showAccNrs();
				break;
			case 5: showAccInfo();
				break;
			case 6: showTotalSum();
				break;
			case 7: createAcc();
				break;
			case 8: removeAcc();
				break;
			case 9: withDraw();
				break;
			case 10: insert();
				break;
			case 11: changeCredLim();
				break;
			case 12: writeFile();
				break;
			case 13: readFile();
				break;
			case 14: showKontoBild();
				break;
			case 15: exit(0);
				break;
			default: cout << "Invalid choice!" << endl;
			}
		}
	
}

void Interface::createCustomer() {
	string fname;
	string lname;
	int persNr;
	cin.get();

	cout << "Enter firstname:" << endl;
	getline(cin, fname);

	cout << "Enter lastname:" << endl;
	getline(cin, lname);

	cout << "enter persnr";
	cin >> persNr;

	newBank.createCustomer(fname, lname, persNr);
	cout << "Ny kund skapad!" << endl;
	done = true;
}

void Interface::readFile() {

	int persNr;
	cin.get();
	cout << "*** Läs in Kund ***" << endl;
	cout << "Ange personnummer för kund att läsa in:" << endl;
	cin >>persNr;	

	if (newBank.readFile(persNr) == true) {
		cout << "Fil för " << persNr << " inläst" << endl;
		done = true;
	}
	else {
		cout << "Fel filnamn, fil inte inläst"; }
	
}

void Interface::writeFile() {
	cout << "Sparar till fil.." << endl;
	if (newBank.writeFile() == true) {
		cout << "fil sparad" << endl;
	}
	else cout << "Sparning misslyckades" << endl;
}

void Interface::showName() {

	cout << "Förnamn:" << newBank.getName()[0] << endl;
	cout << "Efternamn : " << newBank.getName()[1] << endl;
}

void Interface::showPersNr() {

	cout << "Personnummer : " << newBank.getPersNr() << endl;
}

void Interface::showCount() {

	cout << "Antal konton i banken:" << newBank.accCount() << endl;
}

void Interface::showAccNrs() {
	if (newBank.accCount() > 0) {
		for (int i = 0; i < newBank.accCount(); i++) {
			cout << "Kontonummer : " << newBank.getAccNrs()[i] << " ";
			cout << newBank.getAccString(newBank.getAccNrs()[i]) << " account" << endl;
		}
	}
	else cout << "Inga konton finns för kund" << endl;
}

void Interface::showAccInfo() {

	int kontoNr;
	showAccNrs();
	cout << "Ange kontonummer att se information om:" << endl;
	cin >> kontoNr;
	vector<float> tmpVec = newBank.getAccInfo(kontoNr);
	if (!tmpVec.empty()) {
			cout << newBank.getAccString(kontoNr) << " account " << endl;
			cout << "Kredit:" << tmpVec[0] << endl;
			cout << "Saldo:" << tmpVec[1] << endl;
			cout << "Disponibelt belopp:" << tmpVec[2] << endl;
			cout << "Interest Rate:" << tmpVec[3]*100 << "%" << endl;
			if (newBank.getAccString(kontoNr) == "savings") {
				cout << "Max 4 annual withdrawls" << endl;
			}

	}
	else cout << "Fel kontonummer" << endl;
}

void Interface::showTotalSum() {
	
	cout << "Totalt Saldo samtliga konton:" << endl;
	cout << newBank.getTotal() << endl;
}

void Interface::createAcc() {
	cout << "Vilken typ av konto vill du öppna?" << endl;
	cout << "1. Transaction Account" << endl;
	cout << "2. Savings account" << endl;
	cout << "3. Longterm savings account" << endl;
	int kontotyp;
	cout << "Ange Kontotyp:" << endl;
	cin >> kontotyp;

	string kontonamn;
	switch (kontotyp) {

	case 1: kontonamn = "transaction";
		break;
	case 2: kontonamn = "savings";
		break;
	case 3: kontonamn = "longterm";
		break;
	}

	if (newBank.createAcc(kontonamn) == true) {
		cout << "Nytt konto skapat!" << endl;
	}
	else cout << "Antal konton fullt, kan inte skapa nytt konto" << endl;
}

void Interface::removeAcc() {

	int kontoNr;
	showAccNrs();
	cout << "Ange kontonummer för borttagning:";
	cin >> kontoNr;

	if (newBank.removeAcc(kontoNr) == true) {
		cout << "Konto" << kontoNr << " borttaget" << endl;
	}
	else cout << "Felaktigt kontonummer" << endl;
}

void Interface::withDraw() {
	
	int kontoNr;
	float belopp;

	cout << "*** Uttag ***" << endl;
	showAccNrs();
	cout << "Ange kontonummer:" << endl;
	cin >> kontoNr;
	cout << "Ange belopp att ta ut" << endl;
	cin >> belopp;

	if (newBank.withDraw(belopp, kontoNr) == true) {
		cout << "Belopp uttaget" << endl;
	}
	else cout << "Fel kontonummer eller för lite pengar på konto eller max antal uttag" << endl;
}

void Interface::insert() {
	
	int kontoNr;
	float belopp;

	cout << "*** Insättning ***" << endl;
	showAccNrs();
	cout << "Ange kontonummer:" << endl;
	cin >> kontoNr;
	cout << "Ange belopp att sätta in" << endl;
	cin >> belopp;

	if (newBank.insert(belopp,kontoNr) == true) {
		cout << "Belopp insatt" << endl;
	}
	else cout << "Fel kontonummer" << endl;
}

void Interface::changeCredLim() {

	int kontoNr;
	float limit;

	cout << "*** Ändra Kredit ***" << endl;
	showAccNrs();
	cout << "Ange kontonummer:" << endl;
	cin >> kontoNr;
	cout << "Ange kredit limit" << endl;
	cin >> limit;

	if (newBank.changeCredLim(limit, kontoNr) == true) {
		cout << "Kredit ändrad" << endl;
	}
	else cout << "fel kontonummer eller kontotypen tillåter inte Kredit" << endl;
}

void Interface::showKontoBild() {
	vector<float> tmpVec;
	string accStr;

	for (int i = 0; i < newBank.accCount(); i++) {
		tmpVec = newBank.subKontoBild(i); // vector med 5 poster

		accStr = newBank.getAccString(newBank.getAccNrs()[i]) + " account";
		transform(accStr.begin(), accStr.end(), accStr.begin(), ::toupper);

		cout << accStr;																//kontonamn
		cout << " " << tmpVec[0] << endl;											//Kontonummer
		if (newBank.getAccString(newBank.getAccNrs()[i]) != "transaction") {
			cout << "No credit allowed" << endl;
		}
		else {
			cout << "Kredit:" << tmpVec[1] << endl;
		}				
		cout << "Saldo:" << tmpVec[2] << endl;										//saldo
		cout << "Disponibelt:" << tmpVec[3] << endl;								//disponibelt
		cout << "Interest rate:" << tmpVec[4]*100 << "%" << endl;					//ränta

		if (newBank.getAccString(newBank.getAccNrs()[i]) == "savings") {			//Om kontotyp är savings
			cout << "Max 4 annual withdrawls" << endl;								//skriv max uttag
		}

		if (newBank.getAccString(newBank.getAccNrs()[i]) == "longterm") {			//Om kontotyp är longterm
			cout << "Max 1 annual withdrawl" << endl;								//skriv max uttag
		}

		cout << "**********************" << endl;
	}
	cout << "Totalt Saldo alla konton:" << newBank.getTotal() << endl;
}

