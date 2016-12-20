/* Utvecklad av : David Hegardt
Uppgift : C++ Objektorienterad - Lab 2 Bankaffärer
Filnamn : BankKund.h
*/

#ifndef BankKundH
#define BankKundH

#include "Konto.h"
#include <memory>

using namespace std;

class BankKund {
private:
	string lastName;
	string firstName;
	int persNr = 0;
	vector<unique_ptr<Konto>> accVec;

public:
	BankKund(string pFirstName, string pLastName, int pPersNr);
	/* Constructor for BankKund-class

	*/
	vector<string> getName() const;

	int getPersNr() const;

	int getAcc() const;

	vector<int> getAccNrs();
	/* Retrieve account numbers, output as vector

	*/

	vector<float> getAccInfo(int kontonr);
	/* Retrieve account saldo, credit, disponibelt output as vector

	*/

	float getTotal();
	/* Retrieve total Saldo for all accounts

	*/

	bool createAcc(string kontoTyp);
	/* Instansiate array and create Konto-objects on request

	*/

	bool removeAcc(int kontonr);
	/* Remove smart pointer objects from vector and delete values from array

	*/

	bool withDraw(float belopp, int kontonr);
	/* Function to remove belopp from kontonr from Konto objekt

	*/

	bool insert(float belopp, int kontonr);
	/* Function to insert belopp from kontonr to Konto objekt

	*/
	bool changeCredLim(int limit, int kontonr);
	/* Function to insert limit from kontonr to Konto objekt credit

	*/

	bool writeFile();
	/* Function to write BankKund data to file

	*/
	vector<string> readFile1(int persNr);
	/* Function to read name strings from file return as vector

	*/
	bool readFile2(int persNr);
	/* Function to read int values from file and add to Konto object

	*/	

	int getAccType(int i);
	
	string getAccString(int i);
};




#endif // !BankKundH

