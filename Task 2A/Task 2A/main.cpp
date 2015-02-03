#include "container.h"

int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	string itemType, recipient, s;
	int price, price2, y = 0;
	bool run = true;
	Container boughtGifts;
	Container suggestGifts;

	bool stop = false;
	while (!stop){
		cout << "\n\nMenu";
		cout << "\n1. Add suggestion to a gift";
		cout << "\n2. Show all suggested gifts";
		cout << "\n3. Show all bought gifts";
		cout << "\n4. Show suggested gifts for specific person";
		cout << "\n5. Show total sum of bought gifts";
		cout << "\n6. Show suggested gifts in a certain price-range";
		cout << "\n7. Show bought gifts for specific person aswell as the total price of the gifts";
		cout << "\n8. Remove a suggested gift";
		cout << "\n9. Remove a bough gift";
		cout << "\n10. Move a gift from suggested to bought";
		cout << "\n11. Change specifics for a gift";
		cout << "\n12. Exit\n\n";

		int choice = -1;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice){
		case 1:
			system("cls");
			cout << "Item: ";
			cin >> itemType;
			cout << "Recipient: ";
			cin >> recipient;
			cout << "Price: ";
			cin >> s;
			price = atoi(s.c_str());
			suggestGifts.addItem(itemType, recipient, price);
			break;
		case 2:
			system("cls");
			cout << suggestGifts.showAllItems();
			break;
		case 3:
			system("cls");
			cout << boughtGifts.showAllItems();
			break;
		case 4:
			system("cls");
			cout << "Gifts to who?: ";
			cin >> recipient;
			cout << suggestGifts.showForRecipient(recipient);
			break;
		case 5:
			system("cls");
			cout << "Total value of bought gifts: " << boughtGifts.showValueOfGifts();
			break;
		case 6:
			system("cls");
			cout << "Low price: ";
			cin >> itemType;
			price = atoi(itemType.c_str());
			cout << "High price: ";
			cin >> itemType;
			price2 = atoi(itemType.c_str());
			cout << suggestGifts.showInPriceRange(price, price2);
			break;
		case 7:
			system("cls");
			cout << "LOL, NOT DONE YET";
			break;
		case 8:
			system("cls");
			cout << "Which gift to remove?: ";
			cin >> price;
			suggestGifts.removeItem(price);
			break;
		case 9:
			system("cls");
			cout << "Which gift to remove?: ";
			cin >> price;
			boughtGifts.removeItem(price);
			break;
		case 10:
			system("cls");
			cout << "What item do you want to move?: ";
			cin >> price;
			if (boughtGifts.moveGift(suggestGifts, price)){
				cout << "Movement of gift completed without any trouble";
			}
			else {
				cout << "Something went wrong...";
			}
			break;
		case 11:
			system("cls");
			cout << "Which item do you want to change?: ";
			cin >> y;
			suggestGifts.changeItem(y);
			break;
		case 12:
			system("cls");
			stop = true;
			break;
		default:
			cout << "\n\n#########ERROR#########\nInvalid number";
			cout << "\nValid range is 1-12\n";
			cout <<"#########ERROR#########\n";
			break;
		}
	}
	return 0;
}