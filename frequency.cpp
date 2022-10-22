/**************************
*						  *
*	Луговских Данил		  *
*	ПИ-221				  *
*	Частота повторов	  *
*						  *
**************************/

#include <fstream>
#include <iostream>
using namespace std;

int main() {
  int letterFrequency[128];
  ifstream currentFile;
  char character;

  currentFile.open("Hello World.txt");
  if (!currentFile) {
    cout << "File not found.";
    return 1;
    }

  for (int iterator = 0; iterator < 128; ++iterator) {
    letterFrequency[iterator] = 0;
    }

  character = currentFile.get();
  while (character != EOF) {
    character = toupper(character);
    ++letterFrequency[character];
    character = currentFile.get();
    }

  cout << endl << "Letter frequencies in this file are:" << endl;
  for (char character = 'A'; character <= 'Z'; ++character) {
    if (letterFrequency[character]) {
      cout << character << " : " << letterFrequency[character] << endl;
      }
    }
  return 0;
  }
