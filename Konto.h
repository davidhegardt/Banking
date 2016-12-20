/* Utvecklad av : David Hegardt
Uppgift : C++ Objektorienterad - Lab 2 Bankaffärer
Filnamn : Konto.h
*/

#ifndef KontoH
#define KontoH

#include <iostream>
#include <vector>

using namespace std;

/*Base class Konto */

class Konto {
private:

		int kontoNr;
		string kontoTyp;
		float saldo = 0.0;
		
public:
		
		Konto(int pKontoNr, string pAccType);
		/* Constructor for Konto-class

		*/

		virtual ~Konto() {}		

		void addMoney(int belopp);
		/* Input : money value, add to current saldo
		
		*/

		bool remMoney(int belopp);
		/* Input : remove selected amount from saldo
		
		*/

		virtual float currKredit() const=0; 
		/* Return the current kredit amount
		   Pure virtual function
		*/

		virtual void changeKred(int belopp)=0; 
		/* Input : new value for kredit
		   Pure virtual function
		*/

		virtual float getInterestRate() = 0; 
		/* Pure virtual function*/

		virtual bool checkUttag() = 0;
		/* Pure virtual function*/

		virtual void countUttag() {}
		/* Virtual function*/

		float currSaldo() const;
		/* Return current saldo
		
		*/

		virtual float disponibel() const;
		/* Return disponibelt belopp
		
		*/

		int accNr() ;
		/* Return account number
		
		*/
		string accType();

};

















#endif // !1

