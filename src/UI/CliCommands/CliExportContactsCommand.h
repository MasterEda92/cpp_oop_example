#pragma once
#include "../../Core/Interfaces/IContactSerializer.h"
#include "../../Core/Interfaces/IContactService.h"
#include "../CliCommand.h"
#include <iostream>
#include <memory>

class CCliExportContactCommand : public CCliCommand {
public:
  CCliExportContactCommand(
      std::shared_ptr<IContactService> pContactService,
      std::shared_ptr<IContactSerializer<std::string>> pSerializer)
      : CCliCommand("s", "Kontakte in Datei speichern",
                    std::bind(&CCliExportContactCommand::Export, this)),
        m_pContactService(pContactService), m_pSerializer(pSerializer) {}

private:
  void Export();

private:
  std::shared_ptr<IContactService> m_pContactService;
  std::shared_ptr<IContactSerializer<std::string>> m_pSerializer;
};
