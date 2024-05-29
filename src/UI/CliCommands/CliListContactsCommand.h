#pragma once
#include "../../Core/Interfaces/IContactService.h"
#include "../CliCommand.h"
#include <iostream>
#include <memory>

class CCliListContactsCommand : public CCliCommand {
public:
  CCliListContactsCommand(std::shared_ptr<IContactService> pContactService)
      : CCliCommand("l", "Alle Kontakte anzeigen",
                    std::bind(&CCliListContactsCommand::List, this)),
        m_pContactService(pContactService) {}

private:
  void List();

private:
  std::shared_ptr<IContactService> m_pContactService;
};
