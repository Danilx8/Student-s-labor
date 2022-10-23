/************************
*						*
*	Луговских Данил		*
*	ПИ-221				*
*	Календарь			*
*						*
************************/

#include <iostream>


bool isLeapYear(int year) {
	if (year % 400 == 0) {
		return true;
	}
	if (year % 100 == 0) {
		return false;
	}
	if (year % 4 == 0) {
		return true;
	}
	return false;
}


int main() {
	int yearNumber;
	std::cin >> yearNumber;
	
	std::cout << isLeapYear(yearNumber);
}
