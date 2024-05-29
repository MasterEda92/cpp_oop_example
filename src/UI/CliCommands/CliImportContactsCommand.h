#pragma once
#include "../../Core/Interfaces/IContactService.h"
#include "../CliCommand.h"
#include <iostream>
#include <memory>

class CCliImportContactCommand : public CCliCommand {
public:
  CCliImportContactCommand(std::shared_ptr<IContactService> pContactService)
      : CCliCommand("i", "Kontakte aus Datei laden",
                    std::bind(&CCliImportContactCommand::Import, this)),
        m_pContactService(pContactService) {}

private:
  void Import();

private:
  std::shared_ptr<IContactService> m_pContactService;
};
