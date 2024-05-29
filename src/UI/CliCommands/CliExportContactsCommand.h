#pragma once
#include "../../Core/Interfaces/IContactService.h"
#include "../CliCommand.h"
#include <iostream>
#include <memory>

class CCliExportContactCommand : public CCliCommand {
public:
  CCliExportContactCommand(std::shared_ptr<IContactService> pContactService)
      : CCliCommand("s", "Kontakte in Datei speichern",
                    std::bind(&CCliExportContactCommand::Export, this)),
        m_pContactService(pContactService) {}

private:
  void Export();

private:
  std::shared_ptr<IContactService> m_pContactService;
};
