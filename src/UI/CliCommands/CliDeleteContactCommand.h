#pragma once
#include "../../Core/Interfaces/IContactService.h"
#include "../CliCommand.h"
#include <iostream>
#include <memory>

class CCliDeleteContactCommand : public CCliCommand {
public:
  CCliDeleteContactCommand(std::shared_ptr<IContactService> pContactService)
      : CCliCommand("d", "Kontakt löschen",
                    std::bind(&CCliDeleteContactCommand::Delete, this)),
        m_pContactService(pContactService) {}

private:
  void Delete();

private:
  std::shared_ptr<IContactService> m_pContactService;
};
