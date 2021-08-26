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
class MagicCard {
private:
	char* name=new char[25];
	char* effect = new char[100];
	char* type = new char[6];
	static int count;
public:

	MagicCard();
	MagicCard(char* name, char* effect, char* type);
	const char* getName() const;
	const char* getEffect()const;
	const char* getType() const;
	void setName(char* name);
	void setEffect(char *effect);
	void setType(char* type);
	MagicCard(const MagicCard& rhs);
	MagicCard& operator=(const MagicCard& rhs);
	~MagicCard();
	static int totalObject(void);


};

