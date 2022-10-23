/************************
*						*
*	Луговских Данил		*
*	ПИ-221				*
*	Календарь			*
*						*
************************/

#include <iostream>
#include <string>

int firstDayOfYearInLoop[28] = {
	0, 1, 2, 3,    5, 6,
	0, 1,    3, 4, 5, 6,
	   1, 2, 3, 4,    6, 
	0, 1, 2,    4, 5, 6, 
	0,    2, 3, 4, 5
	};

std::string weekdays[7] = {
	"Monday", "Tuesday", "Wednesday", "Thursday",
	"Friday", "Saturday", "Sunday"
	};

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

std::string firstDayOfYear(int year) {
	int century = year / 100;
	int index = ((4 * century) + (year % 100)) % 28;
	int shift = (index + (index / 4)) % 7;
	
	return weekdays[firstDayOfYearInLoop[shift]];
}

int main() {
	int year;
	std::cin >> year;
	
	std::cout << isLeapYear(year) << std::endl;
	std::cout << firstDayOfYear(year);
	
	return 0;
}
