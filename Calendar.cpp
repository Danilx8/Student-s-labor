/************************
*						*
*	Луговских Данил		*
*	ПИ-221				*
*	Календарь			*
*						*
************************/

#include <iostream>
#include <string>

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
	year = (year - 1) % 400;

    int century = year / 100;

    int index   = ((4 * century) + (year % 100)) % 28;

    int weekday = (index + (index / 4));

    return weekdays[(weekday % 7)];
}

int main() {
	int year;
	std::cin >> year;
	
	std::cout << firstDayOfYear(year);
	
	return 0;
}
