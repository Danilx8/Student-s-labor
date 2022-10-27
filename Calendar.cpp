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

int daysInMonths[12] = {
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

struct monthLine {
  std::string months;
  std::string weekLine;
  std::string days[10] = {"", "", "", "", "", "", "", "", "", ""};
  int amountOfWeeks = 0;
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

  blocks[0].months += "January" + std::string(40, ' ') +
                      "February" + std::string(39, ' ') + "March";
  blocks[1].months += "April" + std::string(42, ' ') +
                      "May" + std::string(44, ' ') + "June";
  blocks[2].months += "July" + std::string(43, ' ') +
                      "August" + std::string(41, ' ') + "September";
  blocks[3].months += "October" + std::string(40, ' ') +
                      "November" + std::string(39, ' ') + "December";

  for (int blockIndex = 0; blockIndex < 4; ++blockIndex) {
    for (int weekColumns = 0; weekColumns < 3; ++weekColumns) {
      for (int weekdayIndex = 0; weekdayIndex < 7; ++weekdayIndex) {
        blocks[blockIndex].weekLine += weekdays[weekdayIndex] + std::string(3, ' ');
      }
      blocks[blockIndex].weekLine += std::string(5, ' ');
    }
  }

  int blockIndex = 0;
  int weekIndex;

  for (int monthIndex = 1; monthIndex < 13; ++monthIndex) {
    weekIndex = 0;

    int numberInWeek = 0;
    int spacesBeforeFirstDayMultiplier = firstDayOfMonth(year, monthIndex);
    while (spacesBeforeFirstDayMultiplier) {
      blocks[blockIndex].days[weekIndex] += std::string(6, ' ');
      --spacesBeforeFirstDayMultiplier;
      ++numberInWeek;
    }

    for (int dayIndex = 1; dayIndex < daysInMonths[monthIndex-1] + 1; ++dayIndex) {
      if (dayIndex < 10) {
        blocks[blockIndex].days[weekIndex] += std::to_string(dayIndex);
        blocks[blockIndex].days[weekIndex] += std::string(5, ' ');
      } else {
        blocks[blockIndex].days[weekIndex] += std::to_string(dayIndex);
        blocks[blockIndex].days[weekIndex] += std::string(4, ' ');
      }
      ++numberInWeek;

      if (numberInWeek == 7) {
        blocks[blockIndex].days[weekIndex] += std::string(5, ' ');
        numberInWeek = 0;
        ++weekIndex;
      }

      int spacesAfterLastDay;
      if (monthIndex == 2 && isLeapYear(year) && dayIndex == 28) {
        blocks[blockIndex].days[weekIndex] += std::to_string(dayIndex);
        spacesAfterLastDay = (7 - numberInWeek + 1) * 6 + 1 + 4;
        blocks[blockIndex].days[weekIndex] += std::string(spacesAfterLastDay, ' ');
      } else if (dayIndex + 1 > daysInMonths[monthIndex - 1]) {
        spacesAfterLastDay = (7 - numberInWeek) * 6 + 1 + 4;
        blocks[blockIndex].days[weekIndex] += std::string(spacesAfterLastDay, ' ');
      }
    }

    if (weekIndex > blocks[blockIndex].amountOfWeeks) {
      blocks[blockIndex].amountOfWeeks = weekIndex;
    }

    if (monthIndex % 3 == 0) {
      ++blockIndex;
    }
  }

  for (int blockIndex = 0; blockIndex < 4; ++blockIndex) {
    std::cout << std::endl << std::endl << blocks[blockIndex].months << std::endl <<
              blocks[blockIndex].weekLine << std::endl;
    for (int line = 0; line < blocks[blockIndex].amountOfWeeks; ++line) {
      std::cout << blocks[blockIndex].days[line] << std::endl;
    }
  }

  return 0;
}
