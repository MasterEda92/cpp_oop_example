#pragma once
#include "../../Core/Interfaces/IContactDeserializer.h"
#include "../../Core/Interfaces/IContactService.h"
#include "../CliCommand.h"
#include <iostream>
#include <memory>

class CCliImportContactCommand : public CCliCommand {
public:
  CCliImportContactCommand(
      std::shared_ptr<IContactService> pContactService,
      std::shared_ptr<IContactDeserializer<std::string>> pDeserializer)
      : CCliCommand("i", "Kontakte aus Datei laden",
                    std::bind(&CCliImportContactCommand::Import, this)),
        m_pContactService(pContactService), m_pDeserializer(pDeserializer) {}

private:
  void Import();

private:
  std::shared_ptr<IContactService> m_pContactService;
  std::shared_ptr<IContactDeserializer<std::string>> m_pDeserializer;
};
