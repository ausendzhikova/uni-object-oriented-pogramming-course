#include "Duelist.hpp"
using namespace std;


int main() {

	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.",43, 3000, 2500);
	MonsterCard magician("Dark Magician", "The ultimate wizard.",23, 2500, 2100);
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 123,CardType::SPELL);
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.",9,CardType::TRAP);
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards",3, 1200, 600, 8, CardType::SPELL);
	Duelist firstDuelist("Ivan Ivanov");
	firstDuelist.getDeck().setDeckname("Magician Deck");
	firstDuelist.getDeck().addCard(&dragon);
	firstDuelist.getDeck().addCard(&swords);
	firstDuelist.getDeck().addCard(&magician);
	firstDuelist.getDeck().addCard(&cylinder);
	firstDuelist.getDeck().addCard(&timegazer);
	cout << firstDuelist.getDeck() << endl;
	cout << "First Duelist SaveDeck Test: " << firstDuelist.saveDeck("magician_deck.txt") << endl;
	cout <<"First Duelist LoadDeck Test: "<< firstDuelist.loadDeck("magician_deck.txt") << endl;
	cout <<"The Deck after loadDeck: \n"<< firstDuelist.getDeck() << endl;

	MagicCard box("Mystic Box", "Destroy one monster.",0, CardType::SPELL);
	firstDuelist.getDeck().changeCard(1, &box);
	cout <<"The Deck after change magic card: \n" << firstDuelist.getDeck() << endl;

	MonsterCard bug("Man-Eater bug", "Target monster on the field, destroy that target",3, 450, 600);
	MagicCard hole("Dark hole", "Destroy all monsters on the field",15, CardType::SPELL);
	MagicCard sword("Sword of dark destruction", "A dark monster equpped with this card increases its ATK point by 400 and decreases its DEF.",78, CardType::BUFF);
	PendulumCard pendulum("Dragon Capture Jar", "Change all face-up Dragon-Type monsters on the field to Defense positions",56, 2000, 5500, 10, CardType::TRAP);

	Duelist secondDuelist("Petq Simova");
	secondDuelist.getDeck().setDeckname("Yami Deck");
	secondDuelist.getDeck().addCard(&bug);
	secondDuelist.getDeck().addCard(&bug);
	secondDuelist.getDeck().changeCard(1,&dragon);
	secondDuelist.getDeck().addCard(&hole);
	secondDuelist.getDeck().addCard(&sword);
	secondDuelist.getDeck().addCard(&cylinder);
	secondDuelist.getDeck().addCard(&pendulum);
	secondDuelist.getDeck().addCard(&pendulum);
	secondDuelist.getDeck().changeCard(0, &timegazer);
	cout << "Second Duelist SaveDeck Test: " << secondDuelist.saveDeck("Yami_deck.txt") << endl;
	cout << "Second Duelist LoadDeck Test: " << secondDuelist.loadDeck("Yami_deck.txt") << endl;
	cout << "Second Duelist Deck : \n" << secondDuelist.getDeck() << endl;

	firstDuelist.duel(secondDuelist);

	firstDuelist.getDeck().addCard(&bug);
	firstDuelist.getDeck().addCard(&hole);
	firstDuelist.duel(secondDuelist);
	
	firstDuelist.getDeck().clearDeck();
	secondDuelist.getDeck().clearDeck();
	firstDuelist.getDeck().setDeckname("Magician");
	secondDuelist.getDeck().setDeckname("Yami");
	firstDuelist.getDeck().addCard(&timegazer);
	secondDuelist.getDeck().addCard(&bug);
	cout << firstDuelist.getDeck() << endl;
	cout << secondDuelist.getDeck() << endl;
	Duelist::duel(firstDuelist, secondDuelist);

	secondDuelist.getDeck().changeCard(0, &pendulum);
	secondDuelist.getDeck().changeCard(0, &dragon);
	firstDuelist.getDeck().addCard(&hole);
	firstDuelist.getDeck().addCard(&cylinder);
	secondDuelist.getDeck().addCard(&timegazer);
	secondDuelist.getDeck().addCard(&magician);
	cout<<firstDuelist.getDeck() << endl;
	cout << secondDuelist.getDeck() << endl;
	Duelist::duel(firstDuelist, secondDuelist);

	firstDuelist.getDeck().addCard(&pendulum);
	firstDuelist.getDeck().addCard(&swords);
	secondDuelist.getDeck().addCard(&bug);
	secondDuelist.getDeck().addCard(&hole);
	secondDuelist.getDeck().changeCard(4, &box);
	cout << firstDuelist.getDeck() << endl;
	cout << secondDuelist.getDeck() << endl;
	secondDuelist.duel(firstDuelist);

	firstDuelist.getDeck().changeCard(5, &bug);
	cout << "FirstDuelistDeck After change\n"<<firstDuelist.getDeck() << endl;
	firstDuelist.duel(secondDuelist);

	cout << "First Duelist Load Deck: " << firstDuelist.loadDeck("magician_deck.txt") << endl;
	cout << "Second Duelist Load Deck: " << secondDuelist.loadDeck("magician_deck.txt") << endl;
	secondDuelist.duel(firstDuelist);

	secondDuelist.getDeck().addCard(&pendulum);
	firstDuelist.getDeck().addCard(&pendulum);
	firstDuelist.duel(secondDuelist);
	Duelist::duel(firstDuelist, secondDuelist);
	return 0;
}