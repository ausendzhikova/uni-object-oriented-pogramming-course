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
#include "Date.hpp"
#include <iostream>
using namespace std;

Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;
}

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

void Date::addDays(int n) {
	int monthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int yearDays = 365;
	if (isLeapYear()) {
		monthDays[1] = 29;
		yearDays = 366;
	}

	year += n / yearDays;
	int leftDays = n % yearDays;


	for (int i = 0; i < leftDays; i++) {
		if (day < monthDays[month-1]) {
			day++;
		}
		else if ((day == monthDays[month - 1]) && month < 12) {
			day = 1;
			month++;
		}
		else if ((day == monthDays[month - 1]) && month == 12) {
			day = 1;
			month = 1;
			year++;
		}
	}

	return;
}

void Date::removeDays(int n) {
	int monthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int yearDays = 365;
	if (isLeapYear()) {
		monthDays[1] = 29;
		yearDays = 366;
	}

	year -= n / yearDays;
	int leftDays = n % yearDays;


	for (int i = leftDays; i>0; i--) {
		if (day > 1) {
			day--;
		}
		else if (day == 1 && month > 1) {
			day = monthDays[month-2];
			month--;
		}
		else if (day == 1 && month == 1) {
			day = 31;
			month = 12;
			year--;
		}
	}
	
	return;
}

bool Date::isLeapYear(){ 
	if (year % 100 == 0 && year % 400 == 0) {
		return true;
	}
	if (year % 100 != 0 && year % 4 == 0) {
		return true;
	}
	return false;
}

int Date::countLeapYears() {
	int years = year;
	if (month <= 2) {
		years--;
	}
	int count = years / 4 - years / 100 + years / 400;
	return count;
}

int Date::daysToChristmas() {
	Date Christmas(25, 12, year);
	int days = daysToEvent(Christmas);
	return days;
}

int Date::daysToYearEnd() {
	Date yearEnd(31, 12, year);
	int days = daysToEvent(yearEnd);
	return days;
}

int Date::daysToEvent(Date& d) {
	if (!isLatterThen(d)) {
		return -1;
	}
	const int monthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	long int days_1 = this->year * 365 + this->day;
	for (int i = 0; i < this->month; i++) {
		days_1 += monthDays[i];
	}
	days_1 += countLeapYears();

	long int days_2 = d.year * 365 + d.day;
	for (int i = 0; i < d.month; ++i) {
		days_2 += monthDays[i];
	}
	days_2 += d.countLeapYears();


	return (days_2 - days_1);
}

bool Date::isLatterThen(Date &d) {
	if (d.year < this->year) {
		return false;
	}
	if (d.year == this->year) {
		if (d.month < this->month) {
			return false;
		}
		if (d.month == this->month) {
			if (d.day <= this->day) {
				return false;
			}
			return true;
		}
	}
	return true;
}

void Date::printDate(Date &d)
{
	if (day < 10) {
		cout << "0" << day << ".";
	}
	else {
		cout << day << ".";
	}
	if (month < 10) {
		cout << "0" << month << ".";
	}
	else {
		cout << month << ".";
	}
	cout <<year << endl;
	return;
}


