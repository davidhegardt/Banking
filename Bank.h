/* Utvecklad av : David Hegardt
Uppgift : C++ Objektorienterad - Lab 2 Bankaffärer
Filnamn : Bank.h
*/

#ifndef BankH
#define BankH
#include "BankKund.h"
#include <memory>

using namespace std;

class Bank {
private:
	unique_ptr<BankKund>newKund;

public:
	vector<string> getName() const;
	int getPersNr();
	int accCount();
	vector<int> getAccNrs();
	/* Retrieve account numbers, output as vector

	*/
	vector<float> getAccInfo(int kontonummer);
	/* Retrieve account saldo, credit, disponibelt output as vector

	*/
	float getTotal();
	/* Retrieve total Saldo for all accounts

	*/
	void createCustomer(string pFirstName, string pLastName, int pPersNr);
	/* Function to instatiate new BankKund object from smart pointer
	
	*/
	bool createAcc(string kontoTyp);
	/* Call function to create account and return true if successfull

	*/
	bool removeAcc(int kontoNr);
	/* Call function to remove account and return true if successfull

	*/
	bool withDraw(float belopp, int kontonr);
	/* Call function to remove money and return true if successfull

	*/
	bool insert(float belopp, int kontonr);
	/* Call function to insert money to account and return true if successfull

	*/
	bool changeCredLim(int limit, int kontonr);
	/* Call function to change cred and return true if successfull

	*/
	bool writeFile();
	/* Call function to write to file and and return true if successfull

	*/
	bool readFile(int persNr);
	/* Call function to read from file, call function to createCustomer and call function
	   to add integers to Konto objekt, readFile2

	*/
	//vector<int> kontoBild();
	
	vector<float> subKontoBild(int count);
	/* Creates vector of data stored for every Konto object

	*/

	string getAccString(int i);
};






#endif // 
