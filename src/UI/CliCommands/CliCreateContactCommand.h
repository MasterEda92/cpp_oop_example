#pragma once
#include "../../Core/Interfaces/IContactService.h"
#include "../CliCommand.h"
#include <iostream>
#include <memory>

class CCliCreateContactCommand : public CCliCommand {
public:
  CCliCreateContactCommand(std::shared_ptr<IContactService> pContactService)
      : CCliCommand("c", "Neuen Kontakt erstellen",
                    std::bind(&CCliCreateContactCommand::Create, this)),
        m_pContactService(pContactService) {}

private:
  void Create();

  std::string GetFirstNameFromInput();
  std::string GetLastNameFromInput();
  int GetAgeFromInput();
  std::string GetPhoneNrFromInput();

private:
  std::shared_ptr<IContactService> m_pContactService;
};
