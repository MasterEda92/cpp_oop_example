#include "CliUpdateContactCommand.h"
#include "../CliCommandHelpers.h"

void CCliUpdateContactCommand::Update() {
  std::cout << "Geben Sie die Nummer des Kontakts ein, der geändert werden "
               "soll. (-1 für Abbrechen)"
            << std::endl;

  if (m_pHandler)
    m_pHandler->InvokeCommand("l");

  auto contacts = m_pContactService->GetContacts();
  int nNrToEdit = CCliCommandHelpers::GetContactIndex(contacts.size());
  if (nNrToEdit < 1)
    return;

  const CContact &contact = m_pContactService->GetContact(nNrToEdit);

  int nFeldId = GetFieldIndex();
  if (nFeldId < 1) {
    return;
  }

  auto updatedContact = CContact(contact.GetFirstName(), contact.GetLastName(),
                                 contact.GetAge(), contact.GetPhoneNr());

  std::string strNewValue = GetNewFieldValue();

  switch (nFeldId) {
  case 1: {
    updatedContact.SetFirstName(strNewValue);
    break;
  }
  case 2: {
    updatedContact.SetLastName(strNewValue);
    break;
  }
  case 3: {
    updatedContact.SetAge(std::stoi(strNewValue));
    break;
  }
  case 4: {
    updatedContact.SetPhoneNr(strNewValue);
    break;
  }
  }

  m_pContactService->UpdateContact(nNrToEdit, updatedContact);

  std::cout << "Der Kontakt mit der Nummer " << nNrToEdit << " wurde geändert."
            << std::endl;
}

int CCliUpdateContactCommand::GetFieldIndex() {
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

std::string CCliUpdateContactCommand::GetNewFieldValue() {
  std::cout << "Geben Sie den neuen Wert für das Feld ein:" << std::endl;
  std::string strNewValue = "";
  std::getline(std::cin, strNewValue);

  return strNewValue;
}
