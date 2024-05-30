#pragma once
#include <map>
#include <memory>

class CCliCommand;
class CCliCommandHandler {
public:
  CCliCommandHandler(std::string strWelcomeMsg);
  void AddCommand(std::shared_ptr<CCliCommand> pCommand);
  void ListCommands() const;
  void RunCli() const;
  void InvokeCommand(std::string strCommand);

protected:
  bool HandleCommand() const;
  void Help() const;

protected:
  std::string m_strWelcomeMsg;
  std::map<std::string, std::shared_ptr<CCliCommand>> m_mapCommands;
};
