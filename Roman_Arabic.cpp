/***************************************************
*    ��������� �����                               *
*    ��-221                                        *
*    ������� �������� ����� � ������� � �������    *
***************************************************/
#include <string>
#include <iostream>

using namespace std;

int main() {
    int arabicNumber, currentNumeral;
    string romanOneToTenNumbers[10] =
        {"", "I", "II", "III", "IV", "V", 
        "VI", "VII", "VIII", "IX"},
        romanTenToNintyNumbers[10] = 
        {"", "X", "XX", "XXX", "XL", "L",
        "LX", "LXX", "LXXX", "XC"},
        romanOneToNineHundertNumbers[10] = 
        {"", "C", "CC", "CCC", "CD", "D",
        "DC", "DCC", "DCCC", "CM"};
    
    
	cin >> arabicNumber;
	int iteratedNumber = arabicNumber;
    
    string result = "";
    
    int iteration = 1;
    while (iteratedNumber) {
        currentNumeral = iteratedNumber % 10;
        if (iteration == 1) {
            result = romanOneToTenNumbers[currentNumeral] + result;
        } else if (iteration == 2) {
        	result = romanTenToNintyNumbers[currentNumeral] + result;
		} else if (iteration == 3) {
			result = romanOneToNineHundertNumbers[currentNumeral] + result;
		} else {
			while (iteratedNumber) {
				result = "M" + result;
				--iteratedNumber;
			}
			break;
		}
		iteratedNumber /= 10;
        iteration++;
    }
	cout << result;
}
