#include "Duelist.hpp"
using namespace std;


int main() {
	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500);
	MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100);
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", CardType::SPELL);
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.",CardType::TRAP);
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 1200, 600, 8, CardType::SPELL);
	Duelist firstDuelist("Ivan Ivanov");
	firstDuelist.getDeck().setDeckname("Magician Deck");
	firstDuelist.getDeck().addMonsterCard(dragon);
	firstDuelist.getDeck().addMagicCard(swords);
	firstDuelist.getDeck().addMonsterCard(magician);
	firstDuelist.getDeck().addMagicCard(cylinder);
	firstDuelist.getDeck().addPendulumCard(timegazer);
	cout << firstDuelist.getDeck() << endl;
    cout << "First Duelist SaveDeck Test: " << firstDuelist.saveDeck("magician_deck.txt") << endl; 
	cout <<"First Duelist LoadDeck Test: "<< firstDuelist.loadDeck("magician.txt") << endl;
	cout <<"The Deck after loadDeck: \n"<< firstDuelist.getDeck() << endl;
	MagicCard box("Mystic Box", "Destroy one monster.", CardType::SPELL);
	firstDuelist.getDeck().changeMagicCard(1, box);
	cout <<"The Deck after change magic card: \n" << firstDuelist.getDeck() << endl;

	MonsterCard bug("Man-Eater bug", "Target monster on the field, destroy that target", 450, 600);
	MagicCard hole("Dark hole", "Destroy all monsters on the field", CardType::SPELL);
	MagicCard sword("Sword of dark destruction", "A dark monster equpped with this card increases its ATK point by 400 and decreases its DEF by 200", CardType::BUFF);
	PendulumCard pendulum("Dragon Capture Jar", "Change all face-up Dragon-Type monsters on the field to Defense positions", 2000, 5500, 10, CardType::TRAP);

	Duelist secondDuelist("Petq Simova");
	secondDuelist.getDeck().setDeckname("Yami Deck");
	secondDuelist.getDeck().addMonsterCard(bug);
	secondDuelist.getDeck().addMonsterCard(bug);
	secondDuelist.getDeck().changeMonsterCard(1,dragon);
	secondDuelist.getDeck().addMagicCard(hole);
	secondDuelist.getDeck().addMagicCard(sword);
	secondDuelist.getDeck().addMagicCard(cylinder);
	secondDuelist.getDeck().addPendulumCard(pendulum);
	secondDuelist.getDeck().addPendulumCard(pendulum);
	secondDuelist.getDeck().changePendulumCard(0, timegazer);
	cout << "Second Duelist SaveDeck Test: " << secondDuelist.saveDeck("Yami_deck.txt") << endl;
	cout << "Second Duelist LoadDeck Test: " << secondDuelist.loadDeck("Yami_deck.txt") << endl;
	cout << "Second Duelist Deck : \n" << secondDuelist.getDeck() << endl;

	return 0;
}