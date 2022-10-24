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
	"MON", "TUE", "WED", "THU",
	"FRI", "SAT", "SUN"
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

int firstDayOfYear(int year) {
	year = (year - 1) % 400;

    int century = year / 100;

    int index = ((4 * century) + (year % 100)) % 28;

    int weekday = (index + (index / 4));

    return (weekday % 7);
}

int main() {
	int year;
	std::cin >> year;
	
	
	for (int months = 0; months < 12; ++months) {
		std::cout << "\n\n\n";
		for (int weekdaysIndex = 0; weekdaysIndex < 7; ++weekdaysIndex) {
			std:: cout << weekdays[weekdaysIndex] << "   ";
		}
	}
	
	return 0;
}
