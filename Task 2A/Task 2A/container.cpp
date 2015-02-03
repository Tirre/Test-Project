#include "container.h"

	//Constructor
	//(Different depending on the information that the user has)
	Container::Container(){
		this->MAX = 5;
		this->nrOfGifts = 0;
		this->giftArray = new Gift*[this->MAX];
		
		for (int i = 0; i < this->MAX; i++){
			this->giftArray[i] = NULL;
		}
	}

	Container::Container(int x){
		if (x > 0){
			this->MAX = x;
			this->nrOfGifts = 0;
			this->giftArray = new Gift*[this->MAX];
		}else {
			cout << "\nError in Container(int x): X is a negative number or zero.\n";
			cout << "Created with X as 5 instead.\n";
			this->MAX = 5;
			this->nrOfGifts = 0;
			this->giftArray = new Gift*[this->MAX];
		}
	}

	Container::Container(Container& original){
		this->MAX = original.MAX;
		this->nrOfGifts = original.nrOfGifts;
		this->giftArray = new Gift*[this->MAX];
		this->clearFrom(0);

		for (int i = 0; i < this->nrOfGifts; i++){
			this->giftArray[i] = new Gift(original.getItem(i));
		}
		this->clearFrom(this->nrOfGifts);
	}

	Container& Container::operator=(const Container& original){
		if (this != &original){
			this->free();

			this->MAX = original.MAX;
			this->nrOfGifts = original.nrOfGifts;
			this->giftArray = new Gift*[this->MAX];
			this->clearFrom(0);

			for (int i = 0; i < this->nrOfGifts; i++){
				this->giftArray[i] = new Gift(original.getItem(i));
			}
			this->clearFrom(this->nrOfGifts);
		}
		return *this;
	}

	//Destructor
	Container::~Container(){
		this->free();
	}

	bool Container::moveGift(Container& source, int pos){
		this->addItem(source.getItem(pos));
		if (source.removeItem(pos)){
			return true;
		}
		return false;
	}

	//Helpfunction for the destructor
	void Container::free(){
		for (int i = 0 ; i < this->MAX; i++){
			delete this->giftArray[i];
		}
		delete[] this->giftArray;
	}

	void Container::clearFrom(int pos){
		for (int i = pos; i < this->MAX; i++){
			this->giftArray[i] = NULL;
		}
	}

	void Container::expand(){
		Gift **temp = new Gift*[this->MAX + 5];
		for (int i = 0; i < this->nrOfGifts; i++){
			temp[i] = this->giftArray[i];
		}
		delete[] this->giftArray;
		this->giftArray = temp;
		this->MAX = this->MAX + 5;
		this->clearFrom(this->nrOfGifts);
	}

	//Add an item
	void Container::addItem(Gift item){
		if (this->nrOfGifts >= this->MAX){
			this->expand();
		}
		this->giftArray[this->nrOfGifts] = new Gift(item);
		this->nrOfGifts++;
	}

	//Overloaded function to add an item
	void Container::addItem(string item, string recipient, int x){
		if (this->nrOfGifts >= this->MAX){
			this->expand();
		}
		this->giftArray[this->nrOfGifts] = new Gift();
		this->giftArray[this->nrOfGifts]->setCost(x);
		this->giftArray[this->nrOfGifts]->setItemType(item);
		this->giftArray[this->nrOfGifts]->setToWho(recipient);
		this->nrOfGifts++;

	}

	//Show all items the container contains
	string Container::showAllItems() const{
		stringstream ss;
		if (this->nrOfGifts == 0){
			ss << "\nContainer contains no gifts...\n";
		}else {
			for (int i = 0; i < this->nrOfGifts; i++){
				ss << "\nItem " << i << "." << this->giftArray[i]->getString();
			}
		}
		return ss.str();
	}

	//Return gift item
	Gift Container::getItem(int x) const{
		if (x < 0 || x > this->nrOfGifts){
			cout << "\nX has an invalid value.\n";
			cout << "\nExiting...\n";
			exit(0);
		}
		return *this->giftArray[x];
	}

	void Container::changeItem(int x){
		bool run = true;
		int choice = -1;
		int y = 0;
		while (run){
			system("cls");
			cout << "What do you want to change?";
			cout << "\n1. Item Type";
			cout << "\n2. Recipient";
			cout << "\n3. Price";
			cout << "\n4. Exit\n";
			cin >> choice;
			switch (choice){
			case 1:
				this->giftArray[x]->setItemType();
				break;
			case 2:
				this->giftArray[x]->setToWho();
				break;
			case 3:
				this->giftArray[x]->setCost();
				break;
			case 4:
				run = false;
				break;
			default:
				cout << "Invalid menu choice";
				break;
			}
		}
	}

	//Show item number x
	string Container::showItem(int x) const{
		if (x < 0 && x > this->nrOfGifts){
			stringstream ss;
			ss << "\nX has an invalid value.\nValid range is: 1-" << this->nrOfGifts << ".\n";
			return ss.str();
		}
		else {
			return this->giftArray[x]->getString();
		}
	}

	//Show items bought
	//Should it be different?
	//Right now it's similar to showAllItems()
	string Container::showBoughtItems() const{
		return this->showAllItems();
	}

	//Show "suggested" items
	//Should it be different?
	//Right now it's similar to showAllItems()
	string Container::showSuggestedItems() const{
		return this->showAllItems();
	}

	//Show items for specific person
	string Container::showForRecipient(string name) const{
		stringstream ss;
		int hits = 0;
		for (int i = 0; i < this->nrOfGifts; i++){
			if (this->getItem(i).getToWho() == name){
				ss << this->getItem(i).getString();
				hits++;
			}
		}
		if (hits == 0){
			ss << "\nNo entries were found for showForRecipient(" << name << ").\n";
		}
		return ss.str();
	}

	//Show "suggested" items between X and Y in price
	string Container::showInPriceRange(int x, int y ) const{
		stringstream ss;
		if ((x<0 || y<0) || x>y){
			ss << "\nX and/or Y has an invalid value.\nY must be higher than X and none of them can be negative.\n";
		}else {
			for (int i = 0; i < this->nrOfGifts; i++){
				if (this->giftArray[i]->getCost() >= x && this->giftArray[i]->getCost() <= y){
					ss << this->giftArray[i]->getString();
				}
			}
		}
		return ss.str();
	}

	/*
	############## FUNCTIONS THAT RETURNS A VALUE
	*/

	//Shows value of all presents bought
	int Container::showValueOfGifts() const{
		int sum = 0;
		for (int i = 0; i < this->nrOfGifts; i++){
			sum += this->giftArray[i]->getCost();
		}
		return sum;
	}

	int Container::getNrOfGifts() const{
		return this->nrOfGifts;
	}

	int Container::getMAX() const{
		return this->MAX;
	}

	//Remove an item
	bool Container::removeItem(int x){
		if (x < 0 || x > this->nrOfGifts){
			cout << "\nX has an invalid value.\n";
			cout << "Valid range is 0-" << this->nrOfGifts-1 << ".\n";
			return false;
		}
		else{
			delete this->giftArray[x];
		}
		this->nrOfGifts--;
		this->moveAllOne(x);
		return true;
	}

	//Move all items one place back, to keep the array from having empty slots
	void Container::moveAllOne(int x){
		for (x; x < this->nrOfGifts; x++){
			this->giftArray[x] = this->giftArray[x + 1];
		}
		this->clearFrom(this->nrOfGifts);
	}
