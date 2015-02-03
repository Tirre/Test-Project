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
		// (Olika beroende p� informationen som anv�ndaren har?)
		Gift();
		Gift(string, string , int);
		Gift(string, int, string);
		Gift(int, string, string);
		Gift(const Gift&);

		//Overloading = operator for Gift objects
		Gift& operator=(const Gift&);

		virtual ~Gift();

		//Returnerar typ/kostnad/till vem p� objektet som fr�gar efter det.
		string getItemType() const;
		string getToWho() const;
		int getCost() const;

		//G�r inmatningen utav typ/kostnad/till vem lokalt i funktionen s� slipper man skriva kod massa g�nger.
		void setItemType();
		void setToWho();
		void setCost();

		//Skickar med str�ng eller tal till setXXX
		void setItemType(string);
		void setToWho(string);
		void setCost(int);

		string getString();
};

#endif