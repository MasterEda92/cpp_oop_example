#pragma once
#include "../../Core/Interfaces/IContactService.h"
#include "../CliCommand.h"
#include <iostream>
#include <memory>

class CCliUpdateContactCommand : public CCliCommand {
public:
  CCliUpdateContactCommand(std::shared_ptr<IContactService> pContactService)
      : CCliCommand("e", "Kontakt bearbeiten",
                    std::bind(&CCliUpdateContactCommand::Update, this)),
        m_pContactService(pContactService) {}

private:
  void Update();

  int GetFieldIndex();
  std::string GetNewFieldValue();

private:
  std::shared_ptr<IContactService> m_pContactService;
};
