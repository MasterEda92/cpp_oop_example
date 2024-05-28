#include "CommandHandler.h"
#include <iostream>

int main() {
  CCommandHandler aHandler;

  std::cout << "Willkommen zum Kontaktplaner :)" << std::endl
            << "Folende Aktionen können durchgeführt werden:" << std::endl;
  aHandler.ListCommands();

  bool bContinue = false;
  do {
    bContinue = aHandler.Handle();
  } while (bContinue);
  return 0;
}
