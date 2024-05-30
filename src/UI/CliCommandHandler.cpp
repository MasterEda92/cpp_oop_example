#include "CliCommandHandler.h"
#include "CliCommand.h"
#include <iostream>

CCliCommandHandler::CCliCommandHandler(std::string strWelcomeMsg)
    : m_strWelcomeMsg(strWelcomeMsg) {}

void CCliCommandHandler::AddCommand(std::shared_ptr<CCliCommand> pCommand) {
  pCommand->SetCommandHandler(this);
  m_mapCommands.insert_or_assign(pCommand->GetCommand(), pCommand);
}
void CCliCommandHandler::ListCommands() const {
  std::cout << "h -> Hilfe anzeigen" << std::endl;
  std::cout << "q -> Programm beenden" << std::endl;
  for (auto &it : m_mapCommands) {
    std::cout << it.first << " -> " << it.second->GetDescription() << std::endl;
  }
}
void CCliCommandHandler::RunCli() const {
  std::cout << m_strWelcomeMsg << std::endl
            << "Folende Aktionen können durchgeführt werden:" << std::endl;
  ListCommands();

  bool bContinue = false;
  do {
    bContinue = HandleCommand();
  } while (bContinue);
}

void CCliCommandHandler::InvokeCommand(std::string strCommand) {
  auto it = m_mapCommands.find(strCommand);
  it->second->Run();
}

bool CCliCommandHandler::HandleCommand() const {
  bool bContinue = true;
  std::string strInput;
  std::getline(std::cin, strInput);

  switch (strInput.c_str()[0]) {
  case 'h': {
    Help();
    break;
  }
  case 'q': {
    bContinue = false;
    break;
  }
  default: {
    auto it = m_mapCommands.find(strInput);
    it->second->Run();
    break;
  }
  }
  return bContinue;
}

void CCliCommandHandler::Help() const { ListCommands(); }
