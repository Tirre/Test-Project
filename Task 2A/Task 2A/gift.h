#ifndef GIFT_H
#define GIFT_H

#include "string.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::cin;
using std::stringstream;

class Gift{

	private:
		string itemType;
		string toWho;
		int cost;
		
	public:
		//Konstruktor
		// (Olika beroende på informationen som användaren har?)
		Gift();
		Gift(string, string , int);
		Gift(string, int, string);
		Gift(int, string, string);
		Gift(const Gift&);

		//Overloading = operator for Gift objects
		Gift& operator=(const Gift&);

		virtual ~Gift();

		//Returnerar typ/kostnad/till vem på objektet som frågar efter det.
		string getItemType() const;
		string getToWho() const;
		int getCost() const;

		//Gör inmatningen utav typ/kostnad/till vem lokalt i funktionen så slipper man skriva kod massa gånger.
		void setItemType();
		void setToWho();
		void setCost();

		//Skickar med sträng eller tal till setXXX
		void setItemType(string);
		void setToWho(string);
		void setCost(int);

		string getString();
};

#endif