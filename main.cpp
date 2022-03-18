#include <iostream>
# include <vector>
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


void SetRarityAndPrice(Card &card, string rarity, double price) {
	card.rarity = rarity;
	card.price = price;
}
/**
	A function that adds a deck to the specified @param list.
	
	@param list
	- A list that holds all of the added products. 
*/
void AddDeck(vector<Deck> &decksList) {
	
	struct Deck deck;
	string isMeta = "";
	
	cout << "\nDeck Name: ";
	cin >> deck.productName;
	
	cout << "\nProduct ID: ";
	cin >> deck.productID;
	
	cout << "\nIs Meta? [Y/N]: ";
	cin >> isMeta;
	
	if (isMeta == "Y") {
		deck.isMeta = true;
		deck.price = 800 * (30 / 100);
	}
	
	decksList.push_back(deck);
}



void AddCard(vector<Card> &cardsList) {
	
	struct Card card;
	
	string isMeta = ""; 
	char rarity = '\n';
	
	cout << "\nCard Name: ";
	cin >> card.cardName;
	
	cout << "\nID: ";
	cin >> card.id;
	
	cout << "\nRarity: (C = Common, R = Rare, P = Promotional): ";
	cin >> rarity;
	
	switch(rarity) {
		
		case 'C': {
			SetRarityAndPrice(card, "Common", 50 * (50 / 100));
			break;
		}
		case 'R': {
			SetRarityAndPrice(card, "Rare", 100 * (100 / 100));
			break;
		}
		case 'P': {
			SetRarityAndPrice(card, "Promotional", 100 * (100 / 100));
			break;
		}
	}
	
	cardsList.push_back(card);	
} 


void AddProducts(vector<Deck> &decksList, vector<Card> &cardsList) {
	
	char addingChoice = '\n';
	
	cout << "\n1.) Add Deck\n2.) Add Card\n";
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
	  
	vector<Deck> decksList;
	vector<Card> cardsList;
	
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
		}
		
		// For testing only
		cout << "\nDECKS: " << endl;
		for (Deck deck : decksList) {
			cout << deck.productName << endl;
		}
		
		// For testing only
		cout << "\nCARDS: " << endl;
		for (Card card : cardsList) {
			cout << card.cardName << endl;
		}
	}
	return 0;
}
