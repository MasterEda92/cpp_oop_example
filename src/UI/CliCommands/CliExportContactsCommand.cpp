#include "CliExportContactsCommand.h"
#include <fstream>

void CCliExportContactCommand::Export() {
  std::string strFileName;
  std::cout << "Bitte geben Sie die Datei (mit Pfad) an in der die Kontakte "
               "gespeichert werden:"
            << std::endl;
  std::getline(std::cin, strFileName);

  auto contacts = m_pContactService->GetContacts();

  std::ofstream aContactsFile(strFileName);
  if (aContactsFile.is_open()) {
    for (auto &it : contacts) {
      auto csvString = m_pSerializer->Serialize(it);
      aContactsFile << csvString << std::endl;
    }
    aContactsFile.close();
  }
  std::cout << "Kontakte wurde in die Datei " << strFileName << " geschrieben."
            << std::endl;
}
