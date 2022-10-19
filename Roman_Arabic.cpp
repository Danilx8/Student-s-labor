/***************************************************
*    Луговских Данил                               *
*    ПИ-221                                        *
*    Перевод арабских чисел в римские и обратно    *
***************************************************/
#include <string>
#include <stdio.h>

using namespace std;

int main() {
    int arabicNumber, currentNumeral;
    string romanOneToTenNumbers[10] =
        {" ", "I", "II", "III", "IV", "V", 
        "VI", "VII", "VIII", "IX"},
        romanTenToNintyNumbers[10] = 
        {" ", "X", "XX", "XXX", "XL", "L",
        "LX", "LXX", "LXXX", "XC"},
        romanOneToNineHunderNumbers[10] = 
        {" ", "C", "CC", "CCC", "CD", "D",
        "DC", "DCC", "DCCC", "CM"};
    
    
    scanf("%i", &arabicNumber);
    
    string result[arabicNumber.length()];
    
    int iteratedNumber = &arabicNumber;
    int iteration = 1;
    while (iteratedNumber > 0) {
        currentNumeral = iteratedNumber % 10;
        iteratedNumber /= 10;
        if (iteration == 1) {
            result[iteration] = romanOneToTenNumbers[iteration];
        }
        iteration++;
    }
    printf("%s", &result);
}
