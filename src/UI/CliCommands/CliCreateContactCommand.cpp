#include "CliCreateContactCommand.h"

void CCliCreateContactCommand::Create() {
  std::string strFirstName = GetFirstNameFromInput();
  std::string strLastName = GetLastNameFromInput();
  int nAge = GetAgeFromInput();

  auto pContact = CContact(strFirstName, strLastName, nAge);
  m_pContactService->CreateContact(pContact);
  std::cout << "Der Kontakt wurde neu angelegt." << std::endl;
}

std::string CCliCreateContactCommand::GetFirstNameFromInput() {
  std::cout << "Bitte geben Sie den Vornamen ein:";
  std::string strFirstName;
  std::getline(std::cin, strFirstName);
  return strFirstName;
}

std::string CCliCreateContactCommand::GetLastNameFromInput() {
  std::cout << "Bitte geben Sie den Nachnamen ein:";
  std::string strLastName;
  std::getline(std::cin, strLastName);
  return strLastName;
}

int CCliCreateContactCommand::GetAgeFromInput() {
  std::cout << "Bitte geben Sie das Alter ein:";
  std::string strAge;
  std::getline(std::cin, strAge);
  int nAge = std::stoi(strAge);
  return nAge;
}
