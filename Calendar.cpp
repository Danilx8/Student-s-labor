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

int daysInMonths[12] {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
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

int firstDayOfYear(int year, int month) {	
	int shifts[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    int shift = shifts[month - 1];
    
    if (isLeapYear(year) and (month >2))
    {
        shift += 1;
    };
    
	year = (year - 1) % 400;
    int century = year / 100;
    int index = ((4 * century) + (year % 100)) % 28;

    int weekday = (index + (index / 4)) + shift;
    
    return (weekday % 7);
}

int main() {
	int year;
	std::cin >> year;
	
	for (int monthIndex = 1; monthIndex < 13; ++monthIndex) {
		for (int weekdaysIndex = 0; weekdaysIndex < 7; ++weekdaysIndex) {
			std::cout << weekdays[weekdaysIndex] << '\t';
		}
		std::cout << '\n';
		
		int numberInWeek = 0;
		
		int spacesBeforeFirstDayMultiplier = firstDayOfYear(year, monthIndex);
		while (spacesBeforeFirstDayMultiplier) {
				std::cout << '\t';
				--spacesBeforeFirstDayMultiplier;
				++numberInWeek;
			}
			
		for (int dayIndex = 1; dayIndex < daysInMonths[monthIndex-1] + 1; ++dayIndex) {
			std::cout << dayIndex << '\t';
			++numberInWeek;
			if (numberInWeek == 7) {
				std::cout << '\n';
				numberInWeek = 0;
			}
		}
		std::cout << "\n\n\n";
	}
	
	return 0;
}
