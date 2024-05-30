#include "CliDeleteContactCommand.h"
#include "../CliCommandHelpers.h"

void CCliDeleteContactCommand::Delete() {
  std::cout << "Geben Sie die Nummer des Kontakts ein, der gelöscht werden "
               "soll. (-1 für Abbrechen)"
            << std::endl;

  if (m_pHandler)
    m_pHandler->InvokeCommand("l");

  auto contacts = m_pContactService->GetContacts();
  int nNrToDelete = CCliCommandHelpers::GetContactIndex(contacts.size());
  if (nNrToDelete < 1)
    return;

  m_pContactService->DeleteContact(nNrToDelete);
  std::cout << "Der Kontakt mit der Nummer " << nNrToDelete
            << " wurde gelöscht." << std::endl;
}
