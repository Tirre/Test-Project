#ifndef CONTAINER_H
#define CONTAINER_H

#include "gift.h"

class Container{

private:
	Gift **giftArray;
	int nrOfGifts;
	int MAX;

public:
	//Constructor
	//(Different depending on the information that the user has)
	Container();
	Container(int);
	Container(Container&);

	//Overloading = operator for Container objects
	Container& operator=(const Container&);

	//Destructor
	virtual ~Container();

	//Function to move an item from one container to another
	//Deletes the entry in the original?
	bool moveGift(Container&, int);

	//Helpfunctions to free memory
	void free();
	void clearFrom(int);

	//Function to expand the array dynamically
	void expand();

	//Add an item
	void addItem(Gift);
	void addItem(string, string, int);
	
	//Show all items the container contains
	string showAllItems() const;
	string showItem(int) const;

	//Return Gift object
	Gift getItem(int) const;
	void changeItem(int);

	//2 Identical functions?
	//Serves no purpose, but they are there as placeholders, wasn't sure if I mis-read the lab memo or not
	string showSuggestedItems() const;
	string showBoughtItems() const;

	//Show items for specific person
	string showForRecipient(string) const;

	//Show "suggested" items between X and Y in price
	string showInPriceRange(int, int) const;

	/*
	############## FUNCTIONS THAT RETURNS A VALUE
	*/

	//Shows value of all presents bought
	int showValueOfGifts() const;

	//Returns the value of nrOfGifts
	int getNrOfGifts() const;
	int getMAX() const;

	//Remove an item
	bool removeItem(int);
	void moveAllOne(int);
};

#endif