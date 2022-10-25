/********************************
*                               *
*        Lugovskih Danil        *
*            PI-221             *
*         Roman numbers         *
*                               *
********************************/

#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

const string romanOneToTenNumbers[10] = {
  "", "I", "II", "III", "IV", "V",
  "VI", "VII", "VIII", "IX"
},
romanTenToNintyNumbers[10] = {
  "", "X", "XX", "XXX", "XL", "L",
  "LX", "LXX", "LXXX", "XC"
},
romanOneToNineHundertNumbers[10] = {
  "", "C", "CC", "CCC", "CD", "D",
  "DC", "DCC", "DCCC", "CM"
};

int arabicEquivalentToRomanNumeral(string number) {
  int readyReturn;
  int equivalentIndex;

  if (number != "M") {
    for (int numeralIndex = 0; numeralIndex < 10; ++numeralIndex) {
      if (number == romanOneToTenNumbers[numeralIndex]) {
        readyReturn = numeralIndex;
        return readyReturn;
      }
      if (number == romanTenToNintyNumbers[numeralIndex]) {
        readyReturn = numeralIndex*10;
        return readyReturn;
      }
      if (number == romanOneToNineHundertNumbers[numeralIndex]) {
        readyReturn = numeralIndex*100;
        return readyReturn;
      }
    }
  } else {
    return 1000;
  }
  return 0;
}

int main() {
  bool choice;

  cout << "Choose the transition task: Arabic to Roman - push 1, Roman to Arabic - push 0:  ";
  cin >> choice;
  
  int arabicNumber;
  string arabicToRomanResult = "";
  int currentDigit;
  int digitIndex;
  
  string romanNumber;
  int characterIndex;
  string currentCharacter;
  string previousCharacter;
  int romanToArabicResult;
  
  switch (choice) {
    case true:
      cout << "Enter an Arabic number: ";
      cin >> arabicNumber;
      
      digitIndex = 0;
      
      while (arabicNumber) {
        currentDigit = arabicNumber % 10;
        
        switch (digitIndex) {
          case 0:
            arabicToRomanResult = romanOneToTenNumbers[currentDigit] + arabicToRomanResult;
            break;
          
          case 1:
            arabicToRomanResult = romanTenToNintyNumbers[currentDigit] + arabicToRomanResult;
            break; 
          
          case 2:
            arabicToRomanResult = romanOneToNineHundertNumbers[currentDigit] + arabicToRomanResult;
            break;
            
          default:
            while (arabicNumber) {
              arabicToRomanResult = "M" + arabicToRomanResult;
              --arabicNumber;
            }
          }
          
        arabicNumber /= 10;
        ++digitIndex;
        }
      cout << arabicToRomanResult;
      break;
      
    case false:
      cout << "Enter a Roman number: ";
      cin >> romanNumber;
      transform(romanNumber.begin(), romanNumber.end(), romanNumber.begin(), ::toupper);
      
      characterIndex = 0;
      currentCharacter = romanNumber[characterIndex];
      romanToArabicResult = arabicEquivalentToRomanNumeral(currentCharacter);
      ++characterIndex;
  
      while (characterIndex < romanNumber.size()) {
        previousCharacter = currentCharacter;
        currentCharacter = romanNumber[characterIndex];                                               
        
        if (arabicEquivalentToRomanNumeral(currentCharacter) > arabicEquivalentToRomanNumeral(previousCharacter)) {
          romanToArabicResult = romanToArabicResult + arabicEquivalentToRomanNumeral(currentCharacter) - arabicEquivalentToRomanNumeral(previousCharacter) * 2;
        } else {
          romanToArabicResult += arabicEquivalentToRomanNumeral(currentCharacter);
        }
        ++characterIndex;
        }
      cout << romanToArabicResult;
       break;
      
    default:
      return 0;
  }
}
