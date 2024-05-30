#include "CliCommandHelpers.h"
#include <iostream>
#include <string>

int CCliCommandHelpers::GetContactIndex(int nCountContacts) {
  int nNrToDelete = -1;

  do {
    std::string strInput;
    std::getline(std::cin, strInput);
    nNrToDelete = std::stoi(strInput);

    if (nNrToDelete < 0) {
      return -1;
    }
    if (nNrToDelete > nCountContacts)
      std::cout << "Die eingegebene Nummer ist zu groß, bitte geben Sie eine "
                   "korrekte Nummer ein."
                << std::endl;
  } while (nNrToDelete > nCountContacts);

  return nNrToDelete;
}
