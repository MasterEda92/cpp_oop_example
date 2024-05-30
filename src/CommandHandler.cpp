#include "CommandHandler.h"
#include "Contact.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

CCommandHandler::CCommandHandler() {}

void CCommandHandler::ListCommands() {
  std::cout << "l -> Alle Kontakte auflisten" << std::endl;
  std::cout << "n -> Neuen Kontakt erstellen" << std::endl;
  std::cout << "d -> Kontakt löschen" << std::endl;
  std::cout << "e -> Kontakt bearbeiten" << std::endl;
  std::cout << "h -> Hilfe anzeigen" << std::endl;
  std::cout << "q -> Programm beenden" << std::endl;
  std::cout << "s -> Kontakte speichern" << std::endl;
  std::cout << "i -> Kontakte importieren" << std::endl;
}

bool CCommandHandler::Handle() {
  bool bContinue = true;
  std::string strInput;
  std::getline(std::cin, strInput);

  switch (strInput.c_str()[0]) {
  case 'l': {
    List();
    break;
  }
  case 'n': {
    Create();
    break;
  }
  case 'd': {
    Delete();
    break;
  }
  case 'e': {
    Edit();
    break;
  }
  case 'h': {
    Help();
    break;
  }
  case 's': {
    Save();
    break;
  }
  case 'i': {
    Load();
    break;
  }
  case 'q': {
    bContinue = false;
    break;
  }
  }
  return bContinue;
}

void CCommandHandler::List() {
  int nNr = 1;
  for (auto &it : m_vecContacts) {
    std::cout << "Nr. " << nNr << "; ";
    std::cout << "Vorname: " << it->GetFirstName() << "; ";
    std::cout << "Nachname: " << it->GetLastName() << "; ";
    std::cout << "Alter: " << it->GetAge() << "; ";
    std::cout << "Telefonnummer: " << it->GetPhoneNr() << std::endl;
    ++nNr;
  }
  if (m_vecContacts.size() == 0)
    std::cout << "Die Kontaktliste ist momentan leer." << std::endl;
}

void CCommandHandler::Create() {
  std::string strFirstName = FirstNameFromInput();
  std::string strLastName = LastNameFromInput();
  int nAge = AgeFromInput();
  std::string strPhoneNr = PhoneNrFromInput();

  auto pContact =
      std::make_shared<CContact>(strFirstName, strLastName, nAge, strPhoneNr);

  m_vecContacts.push_back(pContact);
  std::cout << "Der Kontakt wurde neu angelegt." << std::endl;
}

void CCommandHandler::Edit() {
  std::cout << "Geben Sie die Nummer des Kontakts ein, der geändert werden "
               "soll. (-1 für Abbrechen)"
            << std::endl;

  List();

  int nNrToEdit = GetContactIndex();
  if (nNrToEdit < 1)
    return;

  int nFeldId = GetFieldIndex();
  if (nFeldId < 1) {
    return;
  }

  std::string strNewValue = GetNewFieldValue();

  switch (nFeldId) {
  case 1: {
    m_vecContacts.at(nNrToEdit - 1)->SetFirstName(strNewValue);
    break;
  }
  case 2: {
    m_vecContacts.at(nNrToEdit - 1)->SetLastName(strNewValue);
    break;
  }
  case 3: {
    m_vecContacts.at(nNrToEdit - 1)->SetAge(std::stoi(strNewValue));
    break;
  }
  case 4: {
    m_vecContacts.at(nNrToEdit - 1)->SetPhoneNr(strNewValue);
    break;
  }
  }
  std::cout << "Der Kontakt mit der Nummer " << nNrToEdit << " wurde geändert."
            << std::endl;
}

void CCommandHandler::Delete() {
  std::cout << "Geben Sie die Nummer des Kontakts ein, der gelöscht werden "
               "soll. (-1 für Abbrechen)"
            << std::endl;

  List();

  int nNrToDelete = GetContactIndex();
  if (nNrToDelete < 1)
    return;

  m_vecContacts.erase(m_vecContacts.begin() + (nNrToDelete - 1));
  std::cout << "Der Kontakt mit der Nummer " << nNrToDelete
            << " wurde gelöscht." << std::endl;
}

void CCommandHandler::Help() { ListCommands(); }

void CCommandHandler::Save() {
  std::string strFileName;
  std::cout << "Bitte geben Sie die Datei (mit Pfad) an in der die Kontakte "
               "gespeichert werden:"
            << std::endl;
  std::getline(std::cin, strFileName);

  std::ofstream aContactsFile(strFileName);
  if (aContactsFile.is_open()) {
    for (auto &it : m_vecContacts) {
      aContactsFile << it->ToCsv() << std::endl;
    }
    aContactsFile.close();
  }
  std::cout << "Kontakte wurde in die Datei " << strFileName << " geschrieben."
            << std::endl;
}

void CCommandHandler::Load() {
  std::string strFileName;
  std::cout << "Bitte geben Sie die Datei (mit Pfad) an aus der die Kontakte "
               "geladen werden sollen:"
            << std::endl;
  std::getline(std::cin, strFileName);

  std::string line;
  std::ifstream aContactsFile(strFileName);
  if (aContactsFile.is_open()) {
    while (getline(aContactsFile, line)) {
      m_vecContacts.push_back(std::make_shared<CContact>(line));
    }
    aContactsFile.close();
  }
  std::cout << "Kontakte wurde aus der Datei " << strFileName << " geladen."
            << std::endl;
}

std::string CCommandHandler::FirstNameFromInput() {
  std::cout << "Bitte geben Sie den Vornamen ein:";
  std::string strFirstName;
  std::getline(std::cin, strFirstName);
  return strFirstName;
}

std::string CCommandHandler::LastNameFromInput() {
  std::cout << "Bitte geben Sie den Nachnamen ein:";
  std::string strLastName;
  std::getline(std::cin, strLastName);
  return strLastName;
}

int CCommandHandler::AgeFromInput() {
  std::cout << "Bitte geben Sie das Alter ein:";
  std::string strAge;
  std::getline(std::cin, strAge);
  int nAge = std::stoi(strAge);
  return nAge;
}

std::string CCommandHandler::PhoneNrFromInput() {
  std::cout << "Bitte geben Sie den Telefonnummer ein:";
  std::string strPhoneNr;
  std::getline(std::cin, strPhoneNr);
  return strPhoneNr;
}
int CCommandHandler::GetContactIndex() {
  int nNrToDelete = -1;

  do {
    std::string strInput;
    std::getline(std::cin, strInput);
    nNrToDelete = std::stoi(strInput);

    if (nNrToDelete < 0) {
      return -1;
    }
    if (nNrToDelete > m_vecContacts.size())
      std::cout << "Die eingegebene Nummer ist zu groß, bitte geben Sie eine "
                   "korrekte Nummer ein."
                << std::endl;
  } while (nNrToDelete > m_vecContacts.size());

  return nNrToDelete;
}

int CCommandHandler::GetFieldIndex() {
  std::cout << "Geben Sie die Nummer des Feldes ein, dass geändert werden soll:"
            << std::endl;

  std::cout << "1 - Vorname" << std::endl;
  std::cout << "2 - Nachname" << std::endl;
  std::cout << "3 - Alter" << std::endl;
  std::cout << "4 - Telefonnummer" << std::endl;

  int nFeldId = -1;
  do {
    std::string strInput;
    std::getline(std::cin, strInput);
    nFeldId = std::stoi(strInput);
    if (nFeldId < 1)
      return -1;

    if (nFeldId > 4)
      std::cout << "Das eingegebene Feld ist ungültig. Bitte geben Sie eine "
                   "korrekte Nummer ein."
                << std::endl;
  } while (nFeldId < 1 && nFeldId > 4);

  return nFeldId;
}

std::string CCommandHandler::GetNewFieldValue() {
  std::cout << "Geben Sie den neuen Wert für das Feld ein:" << std::endl;
  std::string strNewValue = "";
  std::getline(std::cin, strNewValue);

  return strNewValue;
}
