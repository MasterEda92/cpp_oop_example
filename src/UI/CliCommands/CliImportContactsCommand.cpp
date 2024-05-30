#include "CliImportContactsCommand.h"
#include <fstream>

void CCliImportContactCommand::Import() {
  std::string strFileName;
  std::cout << "Bitte geben Sie die Datei (mit Pfad) an aus der die Kontakte "
               "geladen werden sollen:"
            << std::endl;
  std::getline(std::cin, strFileName);

  std::string line;
  std::ifstream aContactsFile(strFileName);
  if (aContactsFile.is_open()) {
    while (getline(aContactsFile, line)) {
      auto contact = m_pDeserializer->Deserialize(line);
      m_pContactService->CreateContact(contact);
    }
    aContactsFile.close();
  }
  std::cout << "Kontakte wurde aus der Datei " << strFileName << " geladen."
            << std::endl;
}
