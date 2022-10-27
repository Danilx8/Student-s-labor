/****************************
*                           *
*	     Lugovskih Danil      *
*	         PI-221           *
*	        Calendar          *
*                           *
****************************/

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

std::string weekdays[7] = {
  "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
};

std:: string monthsNames[12] = {
  "January", "February", "March", "April", "May", "June",
  "July", "August", "September", "October", "November", "December"
};

int daysInMonths[12] = {
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

struct monthLine {
  std::string months;
  std::string weekLine;
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

int firstDayOfMonth(int year, int month) {
  int shifts[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
  int shift = shifts[month - 1];

  if (isLeapYear(year) and (month >2)) {
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
  
  monthLine blocks[4];
  
  for (int blockIndex = 0; blockIndex < 4; ++blockIndex) {
    for (int weekColumns = 0; weekColumns < 3; ++weekColumns) {
      for (int weekdayIndex = 0; weekdayIndex < 7; ++weekdayIndex) {
      blocks[blockIndex].weekLine += weekdays[weekdayIndex] + std::string(3, ' ');
      }
      blocks[blockIndex].weekLine += std::string(5, ' ');
    }
  }
  
  int blockIndex = 0;
  int daysLineIndex = 0;
  
  for (int monthIndex = 1; monthIndex < 13; ++monthIndex) {
    blocks[blockIndex].months += monthsNames[monthIndex-1] + std::string(42, ' ');

    int numberInWeek = 0;
    int spacesBeforeFirstDayMultiplier = firstDayOfMonth(year, monthIndex);
    while (spacesBeforeFirstDayMultiplier) {
      blocks[blockIndex].days << std::string(6, ' ');
      --spacesBeforeFirstDayMultiplier;
      ++numberInWeek;
    }
    
    std::ostringstream dayIndexAsString;
    for (int dayIndex = 1; dayIndex < daysInMonths[monthIndex-1] + 1; ++dayIndex) {
      //dayIndexAsString << dayIndex;
      //dayIndexAsString.str();
      if (dayIndex < 10) { 
        blocks[blockIndex].days << dayIndex;
        blocks[blockIndex].days << "      ";
      } else {
        blocks[blockIndex].days << dayIndex;
        blocks[blockIndex].days << "    ";
      }
      ++numberInWeek;
      
      if (numberInWeek == 7) {
        blocks[blockIndex].days << "     ";
        blocks[blockIndex].days << '\n';
        numberInWeek = 0;
      }
      
      if (monthIndex == 2 && isLeapYear(year) && dayIndex == 28) {
        //dayIndexAsString << ++dayIndex;
        //dayIndexAsString.str();
        blocks[blockIndex].days << dayIndex;
      }
    }
  
    if (monthIndex % 3 == 0) {
      ++blockIndex;
    }
    
    blocks[blockIndex].amountOfWeeks = daysLineIndex;
    daysLineIndex = 0;
  }
  
  
  for (int blockIndex = 0; blockIndex < 4; ++blockIndex) {
    std::cout << blocks[blockIndex].months << std::endl <<
    blocks[blockIndex].weekLine << std::endl;
    blocks[blockIndex].days.str();
    std::cout << '\n';
  }
  
  return 0;
}
