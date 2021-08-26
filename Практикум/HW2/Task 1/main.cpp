/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Aylin Usendzhikova
* @idnumber 62582
* @task 1
* @compiler VC
*/

#include <iostream>
#include "Inventory.hpp"
#include"Equipment.hpp"
#include"Backpack.hpp"
#include "Armor.hpp"
#include "Weapon.hpp"
#include "Materials.hpp"
#include "Money.hpp"
using namespace std;

int main() {
	//Armor test
	vector<pair<string, double>> armorEffects;
	armorEffects.push_back(make_pair("Buckler", 65.7));
	Armor armor1(ArmorType::mail, 34, armorEffects);
	armor1.add_effect(make_pair("Glassmail", 45.79));
	armor1.add_effect(make_pair("Glassmail", 45.79));
	armor1.erase_effect("Glassmail");
	Armor armor2(ArmorType::mail, 34, armorEffects);
	cout <<"Armor2 defense: "<< armor2.getDefense() << endl;
	cout<<"Armor2 score: "<<armor2.getScore() << endl;
	bool result = armor1 == armor2;
	cout << "Armor operator== test: " << result << endl;
	result = armor1 != armor2;
	cout << "Armor operator != test: " << result << endl;
	Equipment<Armor> equipment1;
	cout << "Is equipment empty? " << equipment1 << endl;
	Equipment<Armor> equipment2;
	equipment1.addInEquipment(armor1);
	equipment1.addInEquipment(armor2);
	equipment2.addInEquipment(armor2);
	equipment1.eraseFromEquipment(1);
	cout << "Equipment slots: " << equipment1.getSlots() << endl;
	result = equipment1 == equipment2;
	cout << "Equipment operator== test: " << result << endl;
	Armor armor3(armor2);
	cout << "Armor3 - gear score: " << armor3.getScore() << endl;
	equipment2.addInEquipment(armor3);
	result = equipment1 != equipment2;
	cout << "Equipment operator!= test: " << result << endl;
	Inventory<Equipment<Armor>> inventory1(equipment1);
	Inventory<Equipment<Armor>> inventory2(equipment2);
	cout << "Inventory slots: " << inventory1.getSlots() << endl;
	result = inventory1 == inventory2;
	cout << "Inventory operator= test: " << result << endl;
	cout << armor2 << endl;
	cout << equipment1 << endl;
	cout << inventory1 << endl;

	//Weapon test
	vector<pair<string, double>> weaponEffects;
	weaponEffects.push_back(make_pair("Sharp", 42.6));
	weaponEffects.push_back(make_pair("Huge", 58.7));
	Weapon weapon1(WeaponType::OneHanded, WeaponKind::dagger, weaponEffects, make_pair(45.2, 89.3));
	Weapon weapon2(WeaponType::TwoHanded, WeaponKind::axe, weaponEffects, make_pair(58.9, 115.6));
	Equipment<Weapon> equipment3;
	Equipment<Weapon> equipment4;
	equipment3.addInEquipment(weapon1);
	equipment4.addInEquipment(weapon2);
     result = equipment3 == equipment4;
	cout << "Equipment<Weapon> operator== test: " << result << endl;
	cout << weapon1 << endl;
	cout << equipment3 << endl;

	Inventory<Equipment<Weapon>> inventory3(equipment3);
	Inventory <Equipment<Weapon>> inventory4(equipment4);
	result = inventory3 != inventory4;
	cout << "Inevnotry operator!= test: " << result<<endl;

	weapon1.erase_effect("Sharp");
	result = weapon1 == weapon2;
	cout << "Weapon operator== test: " <<result<< endl;

	cout << weapon2 << endl;
	cout << inventory3 << endl;
	
	//Materials tests
	Materials m1(MaterialType::herbs,43);
	m1.addMaterial(7);
	Materials m2(MaterialType::essence,10);
	Materials m3(MaterialType::ores, 36);
	Backpack<Materials> b1;
	b1.addInBackpack(m1);
	b1.addInBackpack(m2);
	cout << "Backpack<Materials> slots: " << b1.getSlots() << endl;
	Backpack<Materials> b2;
	b2.addInBackpack(m1);
	cout << m1 << endl;
	cout << "Full backpack test: " <<b2.isFull()<< endl;
	cout << "Empty backpack test: " <<b2.isEmpty()<< endl;
	

	//Money test
	Money money1(105, 2);
	money1.addMoney(5, 1);
	Backpack<Money> b3;
	b3.addInBackpack(money1);
	Money money2(201, 0);
	b3.addInBackpack(money2);
	cout << "Backpack<Money> slots: " << b3.getSlots() << endl;
	cout << b3 << endl;
	Inventory<Backpack<Money>> in1(b3);
	Inventory<Backpack<Money>> in2(b3);
		result = in1 == in2;
		cout << "Inventory<Backpack<Money>> operator== test: " << result << endl;
	return 0;
}