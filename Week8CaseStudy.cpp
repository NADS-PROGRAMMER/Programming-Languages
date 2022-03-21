#include <iostream>
# include <vector>
#include <map>
#include <typeinfo>
#include <iomanip>
#include <bits/stdc++.h>
#include <string>

using namespace std;

/** A structure for a Deck. */
struct Deck {
	string name;
	string id;
	double price = 800;
	bool isMeta = false;
};

/** A structure for a Card */
struct Card {
	
	string name;
	string id;
	string rarity;
	bool isMeta;
	double price;
};

/** A structure for a Transaction
	
	@NOTE:
	- It has Card and Deck as a property since we can
	check if the user sells a Card or a Deck.
 */
struct Transaction {
	
	struct Card card;
	struct Deck deck;
	int quantity;
	double subtotal;
};


/** A function that returns the default choices of the program **/
string Choices() {
	
	string choices = "\n\nA.) Add Product\nB.) Sell\nC.) Show Total Sales\nD.) Exit\n";
	
	return choices;
}


/** A function that computes the subtotal of the bought product.
	
	@param quantity : int
	- quantity of the product
	
	@param price : double
	- price of the product.
 **/
double ComputeSubtotal(int quantity, double price) {
	return quantity * price;
}


/** A function that generates a sequence of numbers based on the specified @param numberOfSequence
	@param numberOfSequence : int
	- length or number of numeric characters to be generated.
*/
string generateNumber(int numberOfSequence) {
	
	int characters[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	string id = "";
	
	srand(time(0));  // Initialize random number generator.
    
    for(int i=0; i < numberOfSequence; i++) {
    	    		
    	id += to_string(characters[(rand() % 9) + 1]);
	}
	return id;
}


/** A function that generates a sequence of letters based on the specified @param numberOfSequence
	@param numberOfSequence : int
	- length or number of characters to be generated.
*/
string generateCharacters(int numberOfSequence) {
		
	char characters[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	
	string id = "";
	
	srand(time(0));  // Initialize random number generator.
    
    for(int i=0; i < numberOfSequence; i++) {
    	
    	id += characters[(rand() % 25) + 1];
	}
	return id;
}


/** 
	This function sets the rarirty and price of the specified card
	@NOTE: This function is for Card only. 
*/
void SetRarityAndPrice(Card &card, string rarity, double price) {
	card.rarity = rarity;
	card.price = price;
}


/**
	A function that adds a deck to the specified @param map.
	
	@param map<string, Card> cardsList
	- @key - deck id
	- @value - struct Deck @NOTE see the definition of struct Deck above.
*/
void AddDeck(map<string, Deck> &decksList) {
	
	struct Deck deck;
	string isMeta = "";
	
	deck.id = generateNumber(5); // ID of each Deck is only NUMERIC.
	
	cout << "\nDeck Name: ";
	getline(cin.ignore(), deck.name);
	
	cout << "\nIs Meta? [Y/N]: ";
	cin >> isMeta;
	
	// IF IT IS META, THEN UPDATE THE PRICE.
	if (isMeta == "Y") {
		deck.isMeta = true;
		double additional = 800 * (double) (30.0 / 100);
		deck.price = 800  + additional;
	}
	
	decksList[deck.id] = deck;
}


/** A function that adds a card to the specified @param map.
	
	@param map<string, Card> cardsList
	- @key - card id
	- @value - struct Card @NOTE see the definition of struct Card above.
 */
void AddCard(map<string, Card> &cardsList) {

	struct Card card;
	char isMeta = '\n';
	char rarity = '\n';
	
	card.id = generateNumber(2) + generateCharacters(3); // ID of each individual Card is ALPHANUMERIC.
	
	cout << "\nCard Name: "	;
	getline(cin.ignore(), card.name);
	
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
	
	// IF IT IS META, THEN UPDATE THE PRICE.
	if (isMeta == 'Y') {
		card.isMeta = true;
		double additional = card.price * (double) (50.0 / 100);
		card.price = card.price  + additional;
	}
	
	cardsList[card.id] = card;
}


/** A function that is been called when the user wants to add a product. */
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
	
	cout << "\nSuccesfully Added!" << endl;
}


void DisplayDecks(map<string, Deck> &decksList) {
	
	if (decksList.size() > 0) {
		cout << "\n=== Decks ===\n" << endl;
	
		cout.setf(ios::left);
		cout << setw(10) << "ID" << setw(10) << "Deck Name\t" << setw(10) << "Price" << endl;
		
		for (auto itr = decksList.begin(); itr != decksList.end(); ++itr) {
			cout.setf(ios::left);
			cout << setw(10) << (*itr).first << setw(10) << (*itr).second.name << "\t";
			cout << fixed << setw(10) << setprecision(2) << (*itr).second.price << endl;
		}
	}
}


void DisplayCards(map<string, Card> &cardsList) {
	
	if (cardsList.size() > 0) {
		cout << "\n\n=== Cards ===\n" << endl;
		
		cout.setf(ios::left);
		cout << setw(10) << "ID" << setw(10) << "Card Name\t" << setw(10) << "Price" << endl;
		
		for (auto itr = cardsList.begin(); itr != cardsList.end(); ++itr) {
			cout.setf(ios::left);
			cout << setw(10) << (*itr).first << setw(10) << (*itr).second.name << "\t";
			cout << fixed << setw(10) << setprecision(2) << (*itr).second.price << endl;
		}	
	}
}


/** 
	A function that displays the details of each element inside the specified @aparam previousTransactions 
	
	@param previousTransactions
	- consist of all the items sold to customer.
*/
void DisplayTransactionDetails(vector<Transaction> &previousTransactions) {
	
	string detail = "";
	string isMeta = "No";
	
	// HEADER
	cout.setf(ios::left);
	cout << "\n=== Transaction ===\n";
	cout << setw(10) << "\nTYPE" << setw(10) << "META" << setw(10) << "ID" << setw(10) 
		<< "NAME" << setw(10) << "PRICE" << setw(10) << "QUANTITY" << setw(10) << "SUBTOTAL\n\n";
	
	for (Transaction &transaction : previousTransactions) {
		
		if (transaction.card.name.length() != 0) {
			
			Card card = transaction.card;
			
			if (card.isMeta)
				isMeta = "Yes";
			
			cout.setf(ios::left);
			cout << setw(10) << "Card" << setw(10) << isMeta << setw(10) << card.id 
			<< setw(10) << card.name;
			cout << setw(10) << fixed << setprecision(2) << card.price;
			cout << setw(10) << to_string(transaction.quantity);
			cout << setw(10) << fixed << setprecision(2) << ComputeSubtotal(transaction.quantity, card.price);
			cout << endl;
		}
		else if (transaction.deck.name.length() != 0) {
			
			Deck deck = transaction.deck;
			
			if (deck.isMeta)
				isMeta = "Yes";
			
			cout.setf(ios::left);
			cout << setw(10) << "Deck" << setw(10) << isMeta << setw(10) << deck.id 
			<< setw(10) << deck.name;
			cout << setw(10) << fixed << setprecision(2) << deck.price;
			cout << setw(10) << to_string(transaction.quantity);
			cout << setw(10) << fixed << setprecision(2) << ComputeSubtotal(transaction.quantity, deck.price);
			cout << endl;
		}
	}
}


/** A function that is for sell functionality
	
	@param decksList
	- a map that consist of all the added decks.
	
	@param cardsList
	- a map that consist of all the added individual cards.
	
	@param previousTransactions
	- a list of previous transactions happened throughout the execution of the program.
*/
void Sell(map<string, Deck> &decksList , map<string, Card> &cardsList, vector<Transaction> &previousTransactions) {
	
	struct Transaction transaction;
	vector<Transaction> currentTransaction;
	
	char isContinue = 'Y';
	string id = "";
	int quantity;
	
	while (isContinue != 'N') {
		
		/* Displays the list of decks and cards. @NOTE see the implementation above. 
		(Ctrl + Click to the name of the function to redirect to function definition.) */
		DisplayDecks(decksList);
		DisplayCards(cardsList);
				
		cout << "\nEnter the ID: Press C to Cancel. ";
		cin >> id;
		
		if (id == "C")
			break;
			
		auto foundInDeck = decksList.find(id);
		auto foundInCard = cardsList.find(id);
		
		/** Check if the foundInDeck and foundInCard is not null 
			.end() returns the end of pointer, which is a 'null'.
		*/
		if (foundInDeck == decksList.end() && foundInCard == cardsList.end()) {
			
			cout << "\n ID does not exist. Please input a valid ID stated above." << endl;
			continue;	
		}
		
		cout << "\nQuantity: ";
		cin >> quantity;
		
		/** Check which of the two is not null,
		then initialize the property of a struct Transaction **/
		if (foundInDeck != decksList.end()) {
			transaction.deck = foundInDeck->second;
			transaction.quantity = quantity;
		}
		else if (foundInCard != cardsList.end()) {
			transaction.card = foundInCard->second;
			transaction.quantity = quantity;
		}
		
		currentTransaction.push_back(transaction);
		transaction; // set it to null for another transaction.
		
		cout << "\nContinue? [Y/N] ";
		cin >> isContinue;
	}
	
	if (id != "C" || currentTransaction.size() > 0)
		DisplayTransactionDetails(currentTransaction);
}


/** MAIN */
int main() {
	
	map<string, Deck> decksList;
	map<string, Card> cardsList;
	vector<Transaction> previousTransactions;
	
	bool exit = false;
	char choice = '\n';
	
	while (exit != true) {
		
		cout << Choices() << endl;
		cout << "\nEnter your choice: ";
		cin >> choice;
		
		switch (choice) {
			case 'A': 
				AddProducts(decksList, cardsList);
				break;
				
			case 'B':
				
				if (decksList.size() == 0 && cardsList.size() == 0) {
					cout << "\nThere are no added products.\n";
					break;
				} 
				Sell(decksList, cardsList, previousTransactions);
				break;
				
			case 'C':
				cout  << generateNumber(2) << endl;
				cout << generateCharacters(3) << endl;
				break;
				
			default:
				cout << "Thank you!" << endl;
				exit = true;
		}
	}
	return 0;
}
