/* Utvecklad av : David Hegardt
Uppgift : C++ Objektorienterad - Lab 2 Bankaffärer
Filnamn : LongtermAcc.h
*/
#include "Konto.h"

/*Derived class Longterm inherited from class Konto */

class Longterm : public Konto {
private:
	float interest = 0.04;
	const int maxUttag = 1;
	int antUttag = 0;
	float kredit = 0.0;
public:
	Longterm(int pKontoNr, string pAccType);
	/*Constructor for Longterm class,
	inherited from Base class*/

	virtual ~Longterm() {}
	/*Virtual destructor for class*/

	virtual bool checkUttag();
	/* Virtual - check that number for antUttag does not equal maxUttag

	*/
	virtual void countUttag();
	/* Virtual - count number of uttag and increment antUttag
	
	*/
	virtual float currKredit() const { return kredit; } // not used for this class
	virtual void changeKred(int belopp) { }				// not used for this classs
	float getInterestRate();
	/* Return current interest rate*/

};