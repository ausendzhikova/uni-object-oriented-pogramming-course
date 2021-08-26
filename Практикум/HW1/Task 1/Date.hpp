/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Aylin Usendzhikova
* @idnumber 62582
* @task 1
* @compiler VC
*/

#pragma once
class Date {
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int day, int month, int year);
	void addDays(int n);
	void removeDays(int n);
	bool isLeapYear();
	int countLeapYears();
	int daysToChristmas();
	int daysToYearEnd();
	int daysToEvent(Date& d);	
	bool isLatterThen(Date& d);
	void printDate(Date& d);
};

