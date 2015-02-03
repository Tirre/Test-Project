/*

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "gift.h"
#include "container.h"

int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	

	//Step 1
	Container C1(0);

	//Step 2
	cout << "\n\n\n########STEP 2############\n";
	cout << "Add 2 items to the container";
	C1.addItem("Item 1", "Person 1", 1);
	C1.addItem("Item 2", "Person 2", 2);
	for (int i = 0; i < C1.getNrOfGifts(); i++){
		cout << C1.showItem(i);
	}
	cout << "\nC1.nrOfGifts = " << C1.getNrOfGifts() << ".\n";
	cout << "C1.MAX = " << C1.getMAX() << ".\n";

	//Step 3
	cout << "\n\n\n########STEP 3############\n";
	cout << "Add another item so the inre array expands.\n";
	C1.addItem("Item 3", "Person 3", 3);
	for (int i = 0; i < C1.getNrOfGifts(); i++){
		cout << C1.showItem(i);
	}
	cout << "\nC1.nrOfGifts = " << C1.getNrOfGifts() << ".\n";
	cout << "C1.MAX = " << C1.getMAX() << ".\n";

	//Step 4
	cout << "\n\n\n########STEP 4############\n";
	cout << "removeItem(5).\n";
	C1.removeItem(5);
	for (int i = 0; i < C1.getNrOfGifts(); i++){
		cout << C1.showItem(i);
	}
	cout << "\nC1.nrOfGifts = " << C1.getNrOfGifts() << ".\n";
	cout << "C1.MAX = " << C1.getMAX() << ".\n";

	//Step 5
	cout << "\n\n\n########STEP 5 AND 6############\n";
	cout << "removeItem(1).\n";
	C1.removeItem(1);
	for (int i = 0; i < C1.getNrOfGifts(); i++){
		cout << C1.showItem(i);
	}
	cout << "\nC1.nrOfGifts = " << C1.getNrOfGifts() << ".\n";
	cout << "C1.MAX = " << C1.getMAX() << ".\n";

	//Step 7
	cout << "\n\n\n########STEP 7############\n";
	cout << "Remove last 2 objects and look so the container is empty.\n";
	C1.removeItem(0);
	C1.removeItem(0);
	for (int i = 0; i < C1.getNrOfGifts(); i++){
		cout << C1.showItem(i);
	}
	cout << "\nC1.nrOfGifts = " << C1.getNrOfGifts() << ".\n";
	cout << "C1.MAX = " << C1.getMAX() << ".\n";

	//Step 8
	cout << "\n\n\n########STEP 8############\n";
	cout << "Add 2 items to the container and check so they exist.\n";
	C1.addItem("Item 1", "Person 1", 1);
	C1.addItem("Item 2", "Person 2", 2);
	for (int i = 0; i < C1.getNrOfGifts(); i++){
		cout << C1.showItem(i);
	}
	cout << "\nC1.nrOfGifts = " << C1.getNrOfGifts() << ".\n";
	cout << "C1.MAX = " << C1.getMAX() << ".\n";

	//Step 9
	cout << "\n\n\n########STEP 9############\n";
	cout << "Check so copyconstructor and assignment operator work.\n";
	C1.addItem("Item 1", "Person 1", 399);
	C1.addItem("Item 2", "Person 1", 30);
	C1.addItem("Item 3", "person 2", 100);
	Container C2(C1);
	C1.removeItem(0);
	Container C3 = C1;
	C3.addItem("Item 4", "Person 3", 831);

	cout << "\n\nContainer 1:";
	for (int i = 0; i < C1.getNrOfGifts(); i++){
		cout << C1.showItem(i);
	}
	cout << "\n\nContainer 2:";
	for (int i = 0; i < C2.getNrOfGifts(); i++){
		cout << C2.showItem(i);
	}
	cout << "\n\nContainer 3:";
	for (int i = 0; i < C3.getNrOfGifts(); i++){
		cout << C3.showItem(i);
	}
	
	
	cout << "\n\nContainer 3 showForRecipient(Person 1):";
	cout << C3.showForRecipient("Person 1");
	2-1-2-3
	1-2-1-2-3
	2-1-2-3-4
	
	
	if (C1.moveGift(C3, 4)){
		cout << "\nMove successful!\n";
	}

	cout << "\n\nContainer 1:";
	for (int i = 0; i < C1.getNrOfGifts(); i++){
		cout << C1.showItem(i);
	}
	cout << "\n\nContainer 2:";
	for (int i = 0; i < C2.getNrOfGifts(); i++){
		cout << C2.showItem(i);
	}
	cout << "\n\nContainer 3:";
	for (int i = 0; i < C3.getNrOfGifts(); i++){
		cout << C3.showItem(i);
	}


	system("PAUSE");
	return 0;
}
*/