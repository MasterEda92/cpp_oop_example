#include "Application/ContactService.h"
#include "Core/Interfaces/IContactRepository.h"
#include "Core/Interfaces/IContactService.h"
#include "Storage/MemoryContactRepository.h"
#include "UI/CliCommandHandler.h"
#include "UI/CliCommands/CliCreateContactCommand.h"
#include "UI/CliCommands/CliDeleteContactCommand.h"
#include "UI/CliCommands/CliExportContactsCommand.h"
#include "UI/CliCommands/CliImportContactsCommand.h"
#include "UI/CliCommands/CliListContactsCommand.h"
#include "UI/CliCommands/CliUpdateContactCommand.h"
#include <memory>

int main() {
  std::shared_ptr<IContactRepository> pContactRepository =
      std::make_shared<CMemoryContactRepository>();
  std::shared_ptr<IContactService> pContactService =
      std::make_shared<CContactService>(pContactRepository);

  CCliCommandHandler aCliCmdHandler("Willkommen zum Kontaktplaner :)");

  // Register Commands
  aCliCmdHandler.AddCommand(
      std::make_shared<CCliListContactsCommand>(pContactService));
  aCliCmdHandler.AddCommand(
      std::make_shared<CCliCreateContactCommand>(pContactService));
  aCliCmdHandler.AddCommand(
      std::make_shared<CCliDeleteContactCommand>(pContactService));
  aCliCmdHandler.AddCommand(
      std::make_shared<CCliUpdateContactCommand>(pContactService));
  aCliCmdHandler.AddCommand(
      std::make_shared<CCliImportContactCommand>(pContactService));
  aCliCmdHandler.AddCommand(
      std::make_shared<CCliExportContactCommand>(pContactService));

  // Run CLI
  aCliCmdHandler.RunCli();

  return 0;
}
