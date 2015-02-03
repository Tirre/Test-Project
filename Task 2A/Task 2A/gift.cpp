#include "gift.h"

Gift::Gift(){
	this->cost = 12345;
	this->toWho = "God";
	this->itemType = "Test Toy";
}

Gift::Gift(string item, string recipient = "God", int price = 12345){
	this->cost = price;
	this->toWho = recipient;
	this->itemType = item;
}

Gift::Gift(string item, int price = 12345, string recipient = "God"){
	this->itemType = item;
	this->cost = price;
	this->toWho = recipient;
}

Gift::Gift(int price, string item = "Test Toy", string recipient = "God"){
	this->cost = price;
	this->itemType = item;
	this->toWho = recipient;
}

Gift::Gift(const Gift& original){
	this->cost = original.cost;
	this->itemType = original.itemType;
	this->toWho = original.toWho;
}

Gift& Gift::operator=(const Gift& original){
	this->cost = original.cost;
	this->itemType = original.itemType;
	this->toWho = original.toWho;
	return *this;
}


Gift::~Gift(){

}

//Returnerar typ/kostnad/till vem på objektet som frågar efter det.
string Gift::getItemType() const{
	return this->itemType;
}

string Gift::getToWho() const{
	return this->toWho;
}

int Gift::getCost() const{
	return this->cost;
}

//Gör inmatningen utav typ/kostnad/till vem lokalt i funktionen så slipper man skriva kod massa gånger.
//Måste setXXX vara const?
void Gift::setItemType() {
	cout << "What type of item is it?\n";
	string item;
	cin >> item;
	this->itemType = item;
	cout << "Item saved with item = " << this->itemType << ".\n";
}

void Gift::setToWho() {
	cout << "To who is this item?\n";
	string to;
	cin >> to;
	this->toWho = to;
	cout << "Item saved with recipient = " << this->toWho << ".\n";
}

void Gift::setCost() {
	cout << "What does this item cost?\n";
	string strPrice;
	cin >> strPrice;
	this->cost = atoi(strPrice.c_str());
	cout << "Item saved with cost = " << this->cost << "\n";
}

void Gift::setCost(int x){
	this->cost = x;
}

void Gift::setItemType(string s){
	this->itemType = s;
}

void Gift::setToWho(string s){
	this->toWho = s;
}

string Gift::getString(){
	stringstream ss;
	ss << "\nType of item: " << this->itemType << "\nRecipient: " << this->toWho << "\nCost of item: " << this->cost << "\n";
	return ss.str();
}