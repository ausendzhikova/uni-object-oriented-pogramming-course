/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Aylin Usendzhikova
* @idnumber 62582
* @task 2
* @compiler VC
*/


#pragma once
class MonsterCard {
private:
	char* name = new char[25];
	int attackPoints;
	int securityPoints;
	static int count;
public:
	MonsterCard();
	MonsterCard(char* name, int attackPoints, int securityPoints);
	const char* getName()const;
	const int getAttackPoints() const;
	const int getSecutityPoints() const;
	void setName(char* name);
	void setAttackPoints(int attackPoints);
	void setSecurityPoints(int securityPoints);
	MonsterCard& operator=(const MonsterCard& rhs);
	MonsterCard(const MonsterCard& rhs);
	~MonsterCard();
	static int totalObject(void);

};

