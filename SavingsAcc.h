/* Utvecklad av : David Hegardt
Uppgift : C++ Objektorienterad - Lab 2 Bankaffärer
Filnamn : SavingsAcc.h
*/
#include "Konto.h"

/*Derived class Savings inherited from class Konto */

class Savings : public Konto {
private:
	const float interest = 0.02;
	const int maxUttag = 4;
	int antUttag = 0;
	float kredit = 0.0;
public:
	Savings(int pKontoNr, string pAccType);
	/*Constructor for Savings class,
	inherited from Base class*/

	virtual ~Savings() {}
	/*Virtual destructor for class*/

	virtual bool checkUttag();
	/* Virtual - check that number for antUttag does not equal maxUttag

	*/
	virtual void countUttag();
	/* Virtual - count number of uttag and increment antUttag

	*/
	virtual float currKredit() const { return kredit;}		//not used for this class
	virtual void changeKred(int belopp) { }					//not used for this class
	float getInterestRate();
	/* Return current interest rate*/
};
