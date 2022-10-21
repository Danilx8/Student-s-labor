/***************************************************
*    Луговских Данил                               *
*    ПИ-221                                        *
*    Перевод арабских чисел в римские и обратно    *
***************************************************/
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string romanOneToTenNumbers[10] =
        {"", "I", "II", "III", "IV", "V", 
        "VI", "VII", "VIII", "IX"},
        romanTenToNintyNumbers[10] = 
        {"", "X", "XX", "XXX", "XL", "L",
        "LX", "LXX", "LXXX", "XC"},
        romanOneToNineHundertNumbers[10] = 
        {"", "C", "CC", "CCC", "CD", "D",
        "DC", "DCC", "DCCC", "CM"};

int arabicEquivalentToRomanNumeral(string number) {
	int readyReturn;
	int equivalentIndex;
	
	if (number != "M") {
		for (int i = 0; i < 10; ++i) {
			if (number == romanOneToTenNumbers[i]) {
				readyReturn = i;
				return readyReturn;
			} 
			if (number == romanTenToNintyNumbers[i]) {
				readyReturn = i*10;
				return readyReturn;
			}
			if (number == romanOneToNineHundertNumbers[i]) {
				readyReturn = i*100;
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
    setlocale(LC_ALL, "ru");

    
    cout << "Choose the transition task: Arabic to Roman - push 1, Roman to Arabic - push 0:  ";
    cin >> choice;
    
    if(choice){
    	int arabicNumber;
    	cout << "Enter an Arabic number: ";
		cin >> arabicNumber;
		int iteratedNumber = arabicNumber;
	    
	    string arabicToRomanResult = "";
	    int currentNumeral;
	    
	    int iteration = 1;
	    while (iteratedNumber) {
	        currentNumeral = iteratedNumber % 10;
	        if (iteration == 1) {
	            arabicToRomanResult = romanOneToTenNumbers[currentNumeral] + arabicToRomanResult;
	        } else if (iteration == 2) {
	        	arabicToRomanResult = romanTenToNintyNumbers[currentNumeral] + arabicToRomanResult;
			} else if (iteration == 3) {
				arabicToRomanResult = romanOneToNineHundertNumbers[currentNumeral] + arabicToRomanResult;
			} else {
				while (iteratedNumber) {
					arabicToRomanResult = "M" + arabicToRomanResult;
					--iteratedNumber;
				}
				break;
			}
			iteratedNumber /= 10;
	        iteration++;
	    }
		cout << arabicToRomanResult;
		return 0;
		
		
	} else {
		string romanNumber;
		
		cout << "Enter a Roman number: ";
		cin >> romanNumber;
		
		int iteration = 0;
		string currentNumber;
		
		currentNumber = romanNumber[iteration];
		int romanToArabicResult = arabicEquivalentToRomanNumeral(currentNumber);
		++iteration;
		
		string previousNumber;
		
		while(iteration < romanNumber.size()) {
			previousNumber = currentNumber;
			currentNumber = romanNumber[iteration];			
			if(arabicEquivalentToRomanNumeral(currentNumber) >= arabicEquivalentToRomanNumeral(previousNumber)) {
				romanToArabicResult += arabicEquivalentToRomanNumeral(currentNumber);
			} else {
				romanToArabicResult -= arabicEquivalentToRomanNumeral(currentNumber);
			}
			++iteration;
		}
		cout << romanToArabicResult;
	}
	return 0;
}
