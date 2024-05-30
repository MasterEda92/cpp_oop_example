#include "CliListContactsCommand.h"

void CCliListContactsCommand::List() {
  int nNr = 1;
  auto vecContacts = m_pContactService->GetContacts();
  for (auto &it : vecContacts) {
    std::cout << "Nr. " << nNr << "; ";
    std::cout << "Vorname: " << it.GetFirstName() << "; ";
    std::cout << "Nachname: " << it.GetLastName() << "; ";
    std::cout << "Alter: " << it.GetAge() << "; ";
    std::cout << "Telefonnummer: " << it.GetPhoneNr() << std::endl;
    ++nNr;
  }
  if (vecContacts.size() == 0)
    std::cout << "Die Kontaktliste ist momentan leer." << std::endl;
}
