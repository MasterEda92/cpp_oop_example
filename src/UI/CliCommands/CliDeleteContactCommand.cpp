#include "CliDeleteContactCommand.h"
#include "../CliCommandHelpers.h"

void CCliDeleteContactCommand::Delete() {
  std::cout << "Geben Sie die Nummer des Kontakts ein, der gelöscht werden "
               "soll. (-1 für Abbrechen)"
            << std::endl;
  // TODO: Das hier einbauen, wenn man das ganze Konstrukt auf einen
  //  allgemeinen Command-Handler umbaut.
  //  List();

  auto contacts = m_pContactService->GetContacts();
  int nNrToDelete = CCliCommandHelpers::GetContactIndex(contacts.size());
  if (nNrToDelete < 1)
    return;

  m_pContactService->DeleteContact(nNrToDelete);
  std::cout << "Der Kontakt mit der Nummer " << nNrToDelete
            << " wurde gelöscht." << std::endl;
}
