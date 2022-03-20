#include <iostream>
# include <vector>
#include <map>
#include <typeinfo>
using namespace std;

struct Deck {
	string productName;
	string productID;
	double price = 800;
	bool isMeta = false;
};


struct Card {
	
	string cardName;
	string id;
	string rarity;
	bool isMeta;
	double price;
};


string Choices() {
	
	string choices = "\nA.) Add Product\nB.) Sell\nC.) Show Total Sales\nD.) Exit\n";
	
	return choices;
}


/** This function is for Card only. */
void SetRarityAndPrice(Card &card, string rarity, double price) {
	card.rarity = rarity;
	card.price = price;
}


/**
	A function that adds a deck to the specified @param list.
	
	@param list
	- A list that holds all of the added products. 
*/
void AddDeck(map<string, Deck> &decksList) {
	
	struct Deck deck;
	string isMeta = "";
	
	cout << "\nDeck Name: ";
	getline(cin.ignore(), deck.productName);
	
	cout << "\nProduct ID: ";
	cin >> deck.productID;
	
	cout << "\nIs Meta? [Y/N]: ";
	cin >> isMeta;
	
	if (isMeta == "Y") {
		deck.isMeta = true;
		double additional = 800 * (double) (30.0 / 100);
		deck.price = 800  + additional;
	}
	
	decksList[deck.productID] = deck;
}


void AddCard(map<string, Card> &cardsList) {

	struct Card card;
	char isMeta = '\n';
	char rarity = '\n';
	
	cout << "\nCard Name: "	;
	getline(cin.ignore(), card.cardName);
	
	cout << "\Card ID: ";
	cin >> card.id;
	
	cout << "\nRarity: [C - Common, R- Rare, P - Promotional]: ";
	cin >> rarity;
	
	switch (rarity) {
		
		case 'C':
			SetRarityAndPrice(card, "Common", 50.0); break;
		case 'R':
			SetRarityAndPrice(card, "Rare", 100.0); break;
		default:
			SetRarityAndPrice(card, "Promotional", 200.0); break;
	}
	
	cout << "\nIs Meta? [Y/N]: ";
	cin >> isMeta;
	
	if (isMeta == 'Y') {
		card.isMeta = true;
		double additional = card.price * (double) (50.0 / 100);
		card.price = card.price  + additional;
	}
	
	cardsList[card.id] = card;
}

void AddProducts(map<string, Deck> &decksList, map<string, Card> &cardsList) {
	
	char addingChoice = '\n';
	
	cout << "\n1.) Add Deck\n2.) Add Card\nChoose: ";
	cin >> addingChoice;
	
	switch (addingChoice) {
		case '1': {
			AddDeck(decksList);
			break;
		}
		case '2': {
			AddCard(cardsList);
			break;
		}
	}
}


/** MAIN */
int main() {
	
	map<string, Deck> decksList;
	map<string, Card> cardsList;
	
	bool exit = false;
	char choice = '\n';
	
	while (exit != true) {
		
		cout << Choices() << endl;
		cout << "\nEnter your choice: ";
		cin >> choice;
		
		switch (choice) {
			case 'A': {
				AddProducts(decksList, cardsList);
				break;
			}
			case 'B':
				cout << "B is your choice" << endl;
				break;
			case 'C':
				cout  << "C is your choice" << endl;
				break;
			default:
				cout << "Thank you, beach!" << endl;
				exit = true;
		}
		
		for (auto itr = decksList.begin(); itr != decksList.end(); ++itr) {
			cout << (*itr).first + " " + (*itr).second.productName + " " + to_string((*itr).second.price) << endl;
		}
		
		for (auto itr = cardsList.begin(); itr != cardsList.end(); ++itr) {
			cout << (*itr).first + " " + (*itr).second.cardName + " " + to_string((*itr).second.price) << endl;
		}
	}
	return 0;
}
