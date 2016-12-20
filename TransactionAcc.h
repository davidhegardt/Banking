/* Utvecklad av : David Hegardt
Uppgift : C++ Objektorienterad - Lab 2 Bankaffärer
Filnamn : TransactionAcc.h
*/

#include "Konto.h"

/*Derived class Transaction inherited from class Konto */

class Transaction : public Konto {
private:
	float kredit = 0.0;
	float interest = 0.0;
public:
	Transaction(int pKontoNr, string pAccType);
	/*Constructor for Longterm class,
	inherited from Base class*/

	virtual ~Transaction() {}
	/*Virtual destructor for class*/

	virtual float currKredit() const;
	/* Return the current kredit amount
	Pure virtual function
	*/

	virtual void changeKred(int belopp);
	/* Input : new value for kredit
	Pure virtual function
	*/

	virtual float getInterestRate() { return interest; } // not used for this class
	virtual float disponibel() const;
	/* Redefined function also using credit*/

	virtual bool checkUttag() { return true; } // not used for this class
};
