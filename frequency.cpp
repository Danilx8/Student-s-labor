/******************************
*                             *
*      Lugovskih Danil        *
*           PI-221            *
*     Chastota Povtoreniy     *
*                             *
******************************/

#include <fstream>
#include <iostream>
using namespace std;

int main() {
  int singleLetterFrequency[128];
  fstream singlesFile;
  char character;

  singlesFile.open("Cleopatra.txt");
  if (!singlesFile) {
    cout << "File not found.";
    return 0;
  }

  for (int singleLetterIndex = 0; singleLetterIndex < 128; ++singleLetterIndex) {
    singleLetterFrequency[singleLetterIndex] = 0;
  }

  character = singlesFile.get();
  while (character != EOF) {
    character = toupper(character);
    ++singleLetterFrequency[character];
    character = singlesFile.get();
  }

  cout << endl << "Single letters frequencies in this file are:" << endl;
  for (char character = 'A'; character <= 'Z'; ++character) {
    if (singleLetterFrequency[character]) {
      cout << character << " : " << singleLetterFrequency[character] << endl;
    }
  }


  int doubleLetterFrequency[128][128];
  fstream doublesFile;

  doublesFile.open("Cleopatra.txt");

  for (int firstIterator = 0; firstIterator < 128; ++firstIterator) {
    for (int secondIterator = 0; secondIterator < 128; ++secondIterator) {
      doubleLetterFrequency[firstIterator][secondIterator] = 0;
    }
  }

  char firstCharacter, secondCharacter;
  firstCharacter = doublesFile.get();
  secondCharacter = doublesFile.get();

  while (secondCharacter != EOF) {
    firstCharacter = toupper(firstCharacter);
    secondCharacter = toupper(secondCharacter);
    ++doubleLetterFrequency[firstCharacter][secondCharacter];
    firstCharacter = secondCharacter;
    secondCharacter = doublesFile.get();
  }

  cout << endl << "Double letter frequencies in this file are:" << endl;
  for (char firstCharacter = 'A'; firstCharacter <= 'Z'; ++firstCharacter) {
    for (char secondCharacter = 'A'; secondCharacter <= 'Z'; ++secondCharacter) {

      if (doubleLetterFrequency[firstCharacter][secondCharacter]) {
        cout << firstCharacter << secondCharacter << " : " << doubleLetterFrequency[firstCharacter][secondCharacter] << endl;
      }
    }
  }

  return 0;
}
